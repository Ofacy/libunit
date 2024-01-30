/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:36:16 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/30 18:09:36 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "intercept.h"
#include <dlfcn.h>
#include <errno.h>
#include <unistd.h>

ssize_t	(*_read)(int fd, void *buf, size_t count) = NULL;

ssize_t read(int fd, void *buf, size_t count)
{
	t_error *error;
	ssize_t	out;

	if (!_read) {
		_read = (ssize_t (*)(int fd, void *buf, size_t count)) dlsym(RTLD_NEXT, "read");
	}
	error = get_error(method_read);
	if (error != NULL)
	{
		errno = error->errnooverride;
		return (error->returnvalue);
	}
	out = _read(fd, buf, count);
	if (out == -1)
		return (out);
	if (intercept_enabled)
		intercept_methods[method_read].successfullcall++;
	return (out);
}
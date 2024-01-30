/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:51:31 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/30 18:09:39 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "intercept.h"
#include <dlfcn.h>
#include <errno.h>
#include <unistd.h>

ssize_t	(*_write)(int fd, const void *buf, size_t count) = NULL;

ssize_t	write(int fd, const void *buf, size_t count)
{
	t_error *error;
	ssize_t	out;

	if (!_write) {
		_write = (ssize_t (*)(int fd, const void *buf, size_t count)) dlsym(RTLD_NEXT, "write");
	}
	error = get_error(method_write);
	if (error != NULL)
	{
		errno = error->errnooverride;
		return (error->returnvalue);
	}
	out = _write(fd, buf, count);
	if (out == -1)
		return (out);
	if (intercept_enabled)
		intercept_methods[method_write].successfullcall++;
	return (out);
}
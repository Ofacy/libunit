/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:58:13 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/30 19:58:54 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "intercept.h"
#include <dlfcn.h>
#include <errno.h>

int	(*_close)(int fd) = NULL;

int close(int fd) {
	t_error *error;
	int	out;

	if (!_close) {
		_close = (int (*)(int fd)) dlsym(RTLD_NEXT, "close");
	}
	error = get_error(method_close);
	out = _close(fd);
	if (out == -1)
		return (out);
	if (intercept_enabled)
		intercept_methods[method_close].successfullcall++;
	if (error != NULL)
	{
		errno = error->errnooverride;
		return (error->returnvalue);
	}
	return (out);
}
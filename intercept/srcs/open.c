/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:59:01 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/30 18:09:33 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "intercept.h"
#include "libft.h"
#include <dlfcn.h>
#include <sys/types.h>
#include <stddef.h>
#include <errno.h>

int	(*_open)(const char *pathname, int flags, ...) = NULL;

int open(const char *pathname, int flags, mode_t mode) {
	t_error *error;
	int		out;

	if (!_open) {
		_open = (int (*)(const char * pathname, int flags, ...)) dlsym(RTLD_NEXT, "open");
	}
	error = get_error(method_open);
	if (error != NULL)
	{
		errno = error->errnooverride;
		return (error->returnvalue);
	}
	out = _open(pathname, flags, mode);
	if (out == -1)
		return (out);
	if (intercept_enabled)
		intercept_methods[method_open].successfullcall++;
	return (out);
}

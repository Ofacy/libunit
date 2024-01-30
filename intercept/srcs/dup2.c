/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:56:19 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/30 18:09:44 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "intercept.h"
#include <dlfcn.h>
#include <errno.h>

int	(*_dup2)(int oldfd, int newfd) = NULL;

int	dup2(int oldfd, int newfd) {
	t_error *error;
	int		out;

	if (!_dup2) {
		_dup2 = (int (*)(int oldfd, int newfd)) dlsym(RTLD_NEXT, "dup2");
	}
	error = get_error(method_dup2);
	if (error != NULL)
	{
		errno = error->errnooverride;
		return (error->returnvalue);
	}
	out = _dup2(oldfd, newfd);
	if (out == -1)
		return (out);
	if (intercept_enabled)
		intercept_methods[method_dup2].successfullcall++;
	return (out);
}
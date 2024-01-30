/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:21:43 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/30 20:24:26 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#define _GNU_SOURCE
#include "intercept.h"
#include <dlfcn.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

pid_t	(*_wait)(int *status) = NULL;

pid_t	wait(int *status)
{
	t_error *error;
	pid_t		out;

	if (!_wait) {
		_wait = (pid_t (*)(int *status)) dlsym(RTLD_NEXT, "wait");
	}
	error = get_error(method_wait);
	if (error != NULL)
	{
		errno = error->errnooverride;
		return (error->returnvalue);
	}
	out = _wait(status);
	if (out == -1)
		return (out);
	if (intercept_enabled)
		intercept_methods[method_wait].successfullcall++;
	return (out);
}
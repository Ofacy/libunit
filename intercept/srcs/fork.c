/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:20:08 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/30 20:24:13 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#define _GNU_SOURCE
#include "intercept.h"
#include <dlfcn.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

pid_t	(*_fork)(void) = NULL;

pid_t	fork(void) {
	t_error *error;
	pid_t		out;

	if (!_fork) {
		_fork = (pid_t (*)(void)) dlsym(RTLD_NEXT, "fork");
	}
	error = get_error(method_fork);
	if (error != NULL)
	{
		errno = error->errnooverride;
		return (error->returnvalue);
	}
	out = _fork();
	if (out == -1)
		return (out);
	if (out > 0 && intercept_enabled)
		intercept_methods[method_fork].successfullcall++;
	return (out);
}
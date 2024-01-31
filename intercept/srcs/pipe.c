/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 01:23:37 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/31 01:25:56 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "intercept.h"
#include <dlfcn.h>
#include <errno.h>

int	(*_pipe)(int pipefd[2]) = NULL;

int pipe(int pipefd[2])
{
	t_error	*error;
	int		out;

	if (!_pipe) {
		_pipe = (int (*)(int pipefd[2])) dlsym(RTLD_NEXT, "pipe");
	}
	error = get_error(method_pipe);
	out = _pipe(pipefd);
	if (out == -1)
		return (out);
	if (intercept_enabled)
		intercept_methods[method_pipe].successfullcall++;
	if (error != NULL)
	{
		errno = error->errnooverride;
		return (error->returnvalue);
	}
	return (out);
}
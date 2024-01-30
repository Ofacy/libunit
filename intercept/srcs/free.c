/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:03:12 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/30 18:09:47 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "intercept.h"
#include <dlfcn.h>
#include <errno.h>

void	(*_free)(void *ptr) = NULL;

void	free(void *ptr)
{
	t_error *error;
	
	if (!_free) {
		_free = (void (*)(void *ptr)) dlsym(RTLD_NEXT, "free");
	}
	error = get_error(method_free);
	if (error != NULL)
	{
		errno = error->errnooverride;
		return ;
	}
	_free(ptr);
	if (intercept_enabled)
		intercept_methods[method_free].successfullcall++;
}
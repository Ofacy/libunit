/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:23:42 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/30 18:09:30 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "intercept.h"
#include "libft.h"
#include <dlfcn.h>
#include <errno.h>

void	*(*_malloc)(size_t size) = NULL;

void	*malloc(size_t size) {
	t_error *error;
	void	*out;

	if (!_malloc) {
		_malloc = (void *(*)(size_t size)) dlsym(RTLD_NEXT, "malloc");
	}
	error = get_error(method_malloc);
	if (error != NULL)
	{
		errno = error->errnooverride;
		return (NULL);
	}
	out = _malloc(size);
	if (!out)
		return (out);
	if (intercept_enabled)
		intercept_methods[method_malloc].successfullcall++;
	return (out);
}

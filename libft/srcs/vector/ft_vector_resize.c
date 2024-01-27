/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:50:29 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/20 18:49:43 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_vector.h"

int	ft_vector_resize(t_vector *v, size_t capacity)
{
	int		status;
	void	*new;

	if (!v)
		return (FAILURE);
	status = UNDEFINED;
	new = malloc(v->size * capacity);
	if (new)
	{
		ft_memcpy(new, v->ptr, v->size * v->total);
		ft_memset(new + v->size * v->total, '\0', v->size);
		v->capacity = capacity;
		status = SUCCESS;
	}
	free(v->ptr);
	v->ptr = new;
	return (status);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:55:07 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/20 18:48:46 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"

int	ft_vector_join(t_vector *v, void *items, size_t n)
{
	int	status;

	if (!v)
		return (FAILURE);
	while (v->total + n >= v->capacity - 1)
	{
		status = ft_vector_resize(v, v->capacity << 1);
		if (status != SUCCESS)
			return (status);
	}
	ft_memcpy(v->ptr + v->size * v->total, items, v->size * n);
	ft_memset(v->ptr + v->size * v->total + v->size * n, '\0', v->size);
	v->total += n;
	return (SUCCESS);
}

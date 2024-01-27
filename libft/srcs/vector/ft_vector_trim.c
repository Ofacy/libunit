/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_trim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 04:01:20 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/20 16:05:53 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_vector.h"
#include "libft.h"

int	ft_vector_trim(t_vector *v, size_t capacity)
{
	int		status;
	void	*new;

	if (!v || capacity > v->total + 1)
		return (FAILURE);
	status = UNDEFINED;
	new = malloc(v->size * capacity);
	if (new)
	{
		ft_memcpy(new, v->ptr, v->size * capacity);
		v->capacity = capacity;
		status = SUCCESS;
	}
	free(v->ptr);
	v->ptr = new;
	return (status);
}

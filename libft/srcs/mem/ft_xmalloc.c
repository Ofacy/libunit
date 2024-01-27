/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 00:52:30 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/11 00:57:10 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

void	*ft_xmalloc(size_t size)
{
	static int	i = 0;
	int			max;

	max = 42;
	if (i++ > max)
	{
		errno = ENOMEM;
		return (NULL);
	}
	return (malloc(size));
}

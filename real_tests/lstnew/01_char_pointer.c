/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_char_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:43:57 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/28 11:26:21 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_lst.h"
#include "libunit.h"
#include <stdlib.h>

int	lstnew_char_pointer(void)
{
	t_list		*new;
	const char	c;

	new = ft_lstnew((void *)&c);
	if (new && new->content == &c && new->next == NULL)
	{
		free(new);
		return (TEST_OK);
	}
	free(new);
	return (TEST_KO);
}

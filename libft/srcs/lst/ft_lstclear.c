/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:41:21 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/15 02:12:58 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft_lst.h"

void	ft_lstclear(t_list **head, void (*del)(void*))
{
	t_list	*curr;
	t_list	*temp;

	if (!head)
		return ;
	curr = *head;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		ft_lstdelone(temp, del);
	}
	*head = NULL;
}

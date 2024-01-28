/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_void_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:43:57 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/28 11:28:14 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_lst.h"
#include "libunit.h"
#include <stdlib.h>

int	lstnew_void_pointer(void)
{
	t_list	*new;
	void	*ptr;
	t_list	test;

	ptr = &test;
	new = ft_lstnew(ptr);
	if (new && new->content == ptr && new->next == NULL)
	{
		free(new);
		return (TEST_OK);
	}
	free(new);
	return (TEST_KO);
}

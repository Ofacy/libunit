/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:43:57 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/28 10:52:27 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_lst.h"
#include "libunit.h"
#include <stdlib.h>

int	lstnew_basic_test(void)
{
	t_list		*new;
	const int	nbr;

	new = ft_lstnew((void *)&nbr);
	if (new && new->content == &nbr && new->next == NULL)
	{
		free(new);
		return (TEST_OK);
	}
	free(new);
	return (TEST_KO);
}

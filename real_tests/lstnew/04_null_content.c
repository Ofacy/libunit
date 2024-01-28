/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_null_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:43:57 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/28 11:26:49 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_lst.h"
#include "libunit.h"
#include <stdlib.h>

int	lstnew_null_content(void)
{
	t_list		*new;

	new = ft_lstnew(NULL);
	if (new && new->content == NULL && new->next == NULL)
	{
		free(new);
		return (TEST_OK);
	}
	free(new);
	return (TEST_KO);
}

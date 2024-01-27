/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   framework.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:29:13 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 10:35:23 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "framework.h"

int	add_test(t_test **test, char *name, int (*testm)(void))
{
	t_test	*new;
	t_test	*tmp;

	new = malloc(sizeof(t_test));
	if (!new)
		return (0);
	new->name = name;
	new->test = testm;
	new->next = NULL;
	if (!*test)
		*test = new;
	else
	{
		tmp = *test;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}

int	run_tests(t_test *test)
{
	int		oks;
	int		kos;
	t_test	*tmp;

	oks = 0;
	kos = 0;
	tmp = test;
	while (tmp)
	{
		if (tmp->test() == 0)
			oks++;
		else
			kos++;
		tmp = tmp->next;
	}
	
	if (kos == 0)
		return (0);
	return (-1);
}

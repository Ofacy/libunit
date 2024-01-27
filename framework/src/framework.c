/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   framework.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:29:13 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 11:05:36 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "libunit.h"

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

int	run_test(t_test *test)
{
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
		if (run_test(tmp) == 0)
		{
			ft_printf("\033[32m[OK]\033[0m %s\n", tmp->name);
			oks++;
		}
		else
		{
			ft_printf("\033[31m[KO]\033[0m %s\n", tmp->name);
			kos++;
		}
		tmp = tmp->next;
	}
	ft_printf("\n%d/%d tests passed\n", oks, kos + oks);
	if (kos == 0)
		return (0);
	return (-1);
}

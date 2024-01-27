/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:19:50 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 14:30:27 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_BONUS_H
# define LIBUNIT_BONUS_H

typedef struct s_test
{
	char		*name;
	int			(*test)(void);
	t_params	params;
	t_test		*next;
}	t_test;

typedef struct s_params
{
	int		timeout;
	char	*stdout;
}	t_params;

t_params	param(int timeout, char *stdout);

int			add_test(t_test **test, char *name, int (*testm)(void), t_params params);
int			run_tests(t_test *test);

#endif

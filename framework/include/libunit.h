/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:17:00 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 10:45:12 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAMEWORK_H
# define FRAMEWORK_H

typedef struct s_test
{
	char	*name;
	int		(*test)(void);
	t_test	*next;
}	t_test;

int	add_test(t_test **test, char *name, int (*testm)(void));
int	run_tests(t_test *test);

#endif

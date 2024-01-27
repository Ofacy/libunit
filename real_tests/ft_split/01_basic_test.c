/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:55:54 by alermolo          #+#    #+#             */
/*   Updated: 2024/01/27 16:05:07 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libunit.h"

char	**ft_split(char const *s, char c);

int	split_basic_test(void)
{
	const char	*str = "Hello World!";
	char		**split;
	int			i;

	i = 0;
	split = ft_split(str, " ");
	if (strcmp(split[0], "Hello") == 0 && strcmp(split[1], "World!") == 0)
	{
		while (split[i])
			free(split[i++]);
		free(split);
		return (TEST_OK);
	}
	while (split[i])
		free(split[i++]);
	free(split);
	return (TEST_KO);
}

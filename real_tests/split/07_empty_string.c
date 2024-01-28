/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_empty_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:55:54 by alermolo          #+#    #+#             */
/*   Updated: 2024/01/28 11:18:09 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libunit.h"
#include "split.h"

char	**ft_split(char const *s, char c);

int	split_empty(void)
{
	const char	*str = "";
	char		**split;
	int			i;

	i = 0;
	split = ft_split(str, ' ');
	if (!split[0])
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:49:24 by lcottet           #+#    #+#             */
/*   Updated: 2023/11/20 13:00:55 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

int	ft_printchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_printstr(char *str)
{
	size_t	len;

	if (str == NULL)
		return (ft_printstr("(null)"));
	len = ft_strlen(str);
	return (write(1, str, len));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:48:01 by lcottet           #+#    #+#             */
/*   Updated: 2023/11/11 01:52:11 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclength;

	i = 0;
	srclength = 0;
	while (src[srclength])
	{
		if (i < size - 1 && size > 0)
		{
			dst[i] = src[i];
			i++;
		}
		srclength++;
	}
	if (size != 0)
	{
		dst[i] = '\0';
	}
	return (srclength);
}

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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = 0;
	while (dst[dest_len] && dest_len < size)
		dest_len++;
	src_len = ft_strlen(src);
	if (size - dest_len == 0)
		return (dest_len + src_len);
	i = 0;
	while (src[i] && size - dest_len - i != 1)
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	strlen;
	char	*str;

	strlen = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(strlen);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, strlen);
	ft_strlcat(str, s2, strlen);
	return (str);
}

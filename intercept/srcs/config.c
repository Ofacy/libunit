/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:50:51 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/30 17:44:58 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "intercept.h"

int	load_config(char *path)
{
	int 	fd;
	size_t	tofail;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	for (int i = 0; i <= method_open; i++)
	{
		if (read(fd, &tofail, sizeof(size_t)) == -1)
		{
			return (1);
		}
		for (unsigned long j = 0; j < tofail; j++)
		{
			t_error error;
			if (read(fd, &error.callindex, sizeof(unsigned long)) == -1)
			{
				return (1);
			}
			if (read(fd, &error.returnvalue, sizeof(int)) == -1)
			{
				return (1);
			}
			if (read(fd, &error.errnooverride, sizeof(int)) == -1)
			{
				return (1);
			}
			error.callindex = j;
			if (ft_vector_add(&intercept_methods[i].tofail, &error) == FAILURE)
				return (1);
		}
	}
	close(fd);
	return (0);
}

int	save_config(char *path)
{
	int	outfd;

	outfd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfd == -1)
		return (1);
	for (int i = 0; i <= method_open; i++)
	{
		if (write(outfd, &intercept_methods[i].tofail.total, sizeof(size_t)) == -1)
			return (close(outfd), 1);
		for (size_t j = 0; j < intercept_methods[i].tofail.total; j++)
		{
			t_error *error = ft_vector_get(&intercept_methods[i].tofail, j);
			if (write(outfd, &error->callindex, sizeof(unsigned long)) == -1)
			{
				return (close(outfd), 1);
			}
			if (write(outfd, &error->returnvalue, sizeof(int)) == -1)
			{
				return (close(outfd), 1);
			}
			if (write(outfd, &error->errnooverride, sizeof(int)) == -1)
			{
				return (close(outfd), 1);
			}
		}
	}
	close(outfd);
	return (0);
}

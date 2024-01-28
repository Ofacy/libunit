/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:34:14 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 22:39:22 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
#include "libunit_bonus.h"

int	open_logfile(t_unit_total *total, char *funcname)
{
	char	*logfile;

	logfile = ft_strjoin(funcname, ".log");
	if (!logfile)
		return (0);
	total->logfd = open(logfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	free(logfile);
	return (total->logfd);
}

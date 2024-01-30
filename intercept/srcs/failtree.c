/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   failtree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:17:03 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/30 19:58:40 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intercept.h"
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

#define WAIT_FOR_FORK 1
#define PRINT_EACH_CALL 1

t_error	intercept_errors[] = {
	[method_close]={-1, EIO, 0},
	[method_dup2]={-1, EIO, 0},
	[method_open]={-1, EIO, 0},
	[method_malloc]={0, ENOMEM, 0},
	[method_read]={-1, EIO, 0},
};

t_error *split_with_fork(int methodid, t_error *err)
{
	pid_t	pid;
	
	(void)err;
	intercept_enabled = 0;
	printf("Forked for FAILED \"%s\", call %ld, waiting for child\n", intercept_methods[methodid].name, intercept_methods[methodid].callcount);
	intercept_enabled = 1;
	pid = fork();
	if (!pid)
	{
		wait(NULL);
		intercept_enabled = 0;
		printf("Resuming NORMAL execution.\n");
		intercept_enabled = 1;
		return (NULL);
	}
	return (&intercept_errors[methodid]);
}

void	init_failtree(void)
{
	intercept_methods[method_close].hook = split_with_fork;
	intercept_methods[method_dup2].hook = split_with_fork;
	intercept_methods[method_open].hook = split_with_fork;
	intercept_methods[method_malloc].hook = split_with_fork;
	intercept_methods[method_read].hook = split_with_fork;
}
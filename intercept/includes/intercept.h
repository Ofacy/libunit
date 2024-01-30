/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intercept.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:36:53 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/30 18:46:44 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERCEPT_H
# define INTERCEPT_H

# include "libft.h"

# define KEYS_DEF \
	KEY_DEF( method_malloc, "malloc" ), \
	KEY_DEF( method_dup2, "dup2" ), \
	KEY_DEF( method_close, "close" ), \
	KEY_DEF( method_free, "free" ), \
	KEY_DEF( method_read, "read" ), \
	KEY_DEF( method_write, "write" ), \
	KEY_DEF( method_open, "open" ) \

# define KEY_DEF( identifier, name )  identifier
typedef enum e_methods {
	KEYS_DEF
}	t_methods;

# undef KEY_DEF
# define KEY_DEF( identifier, name )  { name, 0, 0, {NULL, 0, 0, 0}, NULL }

typedef struct s_error
{
	int				returnvalue;
	int				errnooverride;
	unsigned long	callindex;
}	t_error;

typedef struct s_method
{
	char			*name;
	unsigned long	callcount;
	unsigned long	successfullcall;
	t_vector		tofail;
	t_error			*(*hook)(int method_id, t_error *error);
}	t_method;

extern t_method intercept_methods[];
extern int		intercept_enabled;

t_error *get_error(int methodid);

int	save_config(char *path);
int	load_config(char *path);
int	init_intercept(void);
int	free_intercept(void);
t_error	new_error(unsigned long callindex, int err, int ret);
int	add_error(int methodid, unsigned long callindex, int err, int ret);
void	init_failtree(void);
int		print_potential_leaks(void);

#endif
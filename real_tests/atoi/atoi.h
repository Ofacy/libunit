/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:56:37 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/27 16:15:05 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATOI_H
# define ATOI_H
# include <stdlib.h>
# include "libunit.h"

int	ft_atoi(char *str);

int	atoi_basic_test(void);
int	atoi_maxint_test(void);
int	atoi_minint_test(void);
int	atoi_zero_test(void);
int	atoi_space_test(void);
int	atoi_space_more_test(void);
int	atoi_invalid_test(void);
int	atoi_overflow_test(void);
int	atoi_underflow_test(void);

#endif
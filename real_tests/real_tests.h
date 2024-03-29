/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_tests.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:45:07 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/28 11:01:16 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef REAL_TESTS_H
# define REAL_TESTS_H

# ifndef TEST_ALL
#  define TEST_ALL 1
# endif

# ifndef TEST_ATOI
#  define TEST_ATOI 0
# endif

# ifndef TEST_BZERO
#  define TEST_BZERO 0
# endif

# ifndef TEST_LSTNEW
#  define TEST_LSTNEW 0
# endif

# ifndef TEST_SPLIT
#  define TEST_SPLIT 0
# endif

int	atoi_launcher(void);
int	bzero_launcher(void);
int	lst_new_launcher(void);
int	split_launcher(void);

#endif

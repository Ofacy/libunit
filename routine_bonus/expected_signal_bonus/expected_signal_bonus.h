/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expected_signal_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:00:40 by lcottet           #+#    #+#             */
/*   Updated: 2024/01/28 14:09:48 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPECTED_SIGNAL_BONUS_H
# define EXPECTED_SIGNAL_BONUS_H

int	test_ok(void);
int	test_ko(void);
int	test_segfault(void);
int	test_buserror(void);
int	test_kosegfault(void);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:47:39 by sryou             #+#    #+#             */
/*   Updated: 2022/05/20 16:58:06 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_interpret(t_interpret *interpret)
{
	interpret->is_left = 0;
	interpret->is_zero = 0;
	interpret->is_precision = 0;
	interpret->is_base = 0;
	interpret->is_blank = 0;
	interpret->is_sign = 0;
	interpret->type = 0;
	interpret->precision_width = 0;
	interpret->width = 0;
}

int	interpret_flag(char *format, t_interpret *interpret)
{}

int	interpret_width(char *format, t_interpret *interpret)
{}

int	interpret_precision(char *format, t_interpret *interpret)
{}

int	interpret_type(char *format, t_interpret *interpret)
{}
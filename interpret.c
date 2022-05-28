/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:47:39 by sryou             #+#    #+#             */
/*   Updated: 2022/05/28 11:31:58 by sryou            ###   ########.fr       */
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
	interpret->is_plus = 0;
	interpret->type = 0;
	interpret->precision_width = 0;
	interpret->width = 0;
}

int	interpret_flag(char *format, t_interpret *interpret)
{
	int	len;

	len = 0;
	while(1)
	{
		if (format[len] == '-')
			interpret->is_left = 1;
		else if (format[len] == '0')
			interpret->is_zero = 1;
		else if (format[len] == '#')
			interpret->is_base = 1;
		else if (format[len] == ' ')
			interpret->is_blank = 1;
		else if (format[len] == '+')
			interpret->is_sign = 1;
		else
			break;
		len++;
	}
	return (len);
}

int	interpret_width(char *format, t_interpret *interpret)
{
	interpret->width = ft_atoi(format);
	return (ft_intlen(format));
}

int	interpret_precision(char *format, t_interpret *interpret)
{
	if (*format == '.')
	{
		interpret->is_precision = 1;
		interpret->precision_width = ft_atoi(format + 1);
		return (ft_intlen(format + 1) + 1);
	}
	return (0);
}

int	interpret_type(char *format, t_interpret *interpret)
{
	interpret->type = *format;
	return (1);
}

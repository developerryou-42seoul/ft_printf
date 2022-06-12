/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 11:22:10 by sryou             #+#    #+#             */
/*   Updated: 2022/06/12 09:57:03 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*make_address(t_interpret *interpret, va_list ap)
{
	unsigned long long	arg;

	arg = va_arg(ap, unsigned long long);
	interpret->is_base = 1;
	return (ft_itohex(arg, 0));
}

char	*make_lowhex(va_list ap)
{
	unsigned int	arg;

	arg = va_arg(ap, unsigned int);
	return (ft_itohex(arg, 0));
}

char	*make_uphex(va_list ap)
{
	unsigned int	arg;

	arg = va_arg(ap, unsigned int);
	return (ft_itohex(arg, 1));
}

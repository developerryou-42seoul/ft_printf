/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 11:22:10 by sryou             #+#    #+#             */
/*   Updated: 2022/05/28 13:10:06 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	make_address(char **str, va_list ap)
{
	unsigned long long	arg;

	arg = va_arg(ap, unsigned long long);
	*str = ft_itohex(arg, 0);
}

void	make_lowhex(char **str, va_list ap)
{
	unsigned int	arg;

	arg = va_arg(ap, unsigned int);
	*str = ft_itohex(arg, 0);
}

void	make_uphex(char **str, va_list ap)
{
	unsigned int	arg;

	arg = va_arg(ap, unsigned int);
	*str = ft_itohex(arg, 1);
}

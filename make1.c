/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 10:53:17 by sryou             #+#    #+#             */
/*   Updated: 2022/06/12 10:02:10 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*make_char(t_interpret *interpret, va_list ap)
{
	char	*str;
	char	arg;

	arg = va_arg(ap, int);
	if (arg == 0)
		interpret->nullchar = 1;
	str = (char *)malloc(sizeof(char) * 2);
	if (str == 0)
		return (0);
	str[0] = arg;
	str[1] = 0;
	return (str);
}

char	*make_str(va_list ap)
{
	char	*arg;

	arg = va_arg(ap, char *);
	if (arg == 0)
		return (ft_strdup("(null)"));
	return (ft_strdup(arg));
}

char	*make_int(t_interpret *interpret, va_list ap)
{
	int	arg;

	arg = va_arg(ap, int);
	if (arg >= 0)
		interpret->is_plus = 1;
	else
	{
		interpret->is_sign = 1;
		interpret->is_plus = -1;
		return (ft_utoa(-arg));
	}
	return (ft_utoa(arg));
}

char	*make_uint(va_list ap)
{
	unsigned int	arg;

	arg = va_arg(ap, unsigned int);
	return (ft_utoa(arg));
}

char	*make_percent(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (str == 0)
		return (0);
	str[0] = '%';
	str[1] = 0;
	return (str);
}

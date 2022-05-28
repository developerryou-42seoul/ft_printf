/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:32:33 by sryou             #+#    #+#             */
/*   Updated: 2022/05/28 13:26:41 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convent(char **format, va_list ap)
{
	t_interpret	interpret;
	int			res;
	char		*str;

	*format += 1;
	init_interpret(&interpret);
	*format += interpret_flag(*format, &interpret);
	*format += interpret_width(*format, &interpret);
	*format += interpret_precision(*format, &interpret);
	*format += interpret_type(*format, &interpret);
	str = process_str(&interpret, ap);
	if (str == 0)
		return (0);
	ft_putstr_fd(str, 1);
	res = ft_strlen(str);
	free(str);
	return (res);
}

int	parse(char *format, va_list ap)
{
	int	res;

	res = 0;
	while (*format)
	{
		if (*format == '%')
			res += convent(&format, ap);
		else
		{
			ft_putchar_fd(*format, 1);
			format++;
			res++;
		}
	}
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		res;

	va_start(ap, format);
	res = parse((char *)format, ap);
	va_end(ap);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 13:04:09 by sryou             #+#    #+#             */
/*   Updated: 2022/05/28 13:13:15 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	make_str_flags(char **str, t_interpret *interpret)
{
	char	*temp;

	if (interpret->is_sign && interpret->is_plus)
	{
		temp = ft_strjoin("+", *str);
		if (temp == 0)
			return ;
		free(*str);
		*str = temp;
	}
	if (interpret->is_base)
	{
		if (interpret->type == 'x')
			temp = ft_strjoin("0x", *str);
		else if (interpret->type == 'X')
			temp = ft_strjoin("0X", *str);
		if (temp == 0)
			return ;
		free(*str);
		*str = temp;
	}
}

void	make_str_width(char **str, t_interpret *interpret)
{
	int		len;
	char	*temp;
	char	*padding;

	len = ft_strlen(*str);
	if (interpret->width > len)
	{
		padding = (char *)malloc(sizeof(char) * (interpret->width - len + 1));
		if (padding == 0)
			return ;
		if (interpret->is_zero)
			ft_fillch(padding, interpret->width - len, '0');
		else
			ft_fillch(padding, interpret->width - len, ' ');
		if (interpret->is_left)
			temp = ft_strjoin(*str, padding);
		else
			temp = ft_strjoin(padding, *str);
		free(padding);
		if (temp == 0)
			return ;
		free(*str);
		*str = temp;
	}
}

void	make_str_type(char **str, t_interpret *interpret, va_list ap)
{
	if (interpret->type == 'c')
		make_char(str, ap);
	else if (interpret->type == 's')
		make_str(str, ap);
	else if (interpret->type == 'p')
		make_address(str, ap);
	else if (interpret->type == 'd' || interpret->type == 'i')
		make_int(str, interpret, ap);
	else if (interpret->type == 'u')
		make_uint(str, ap);
	else if (interpret->type == 'x')
		make_lowhex(str, ap);
	else if (interpret->type == 'X')
		make_uphex(str, ap);
	else if (interpret->type == '%')
		make_percent(str);
}

char	*process_str(t_interpret *interpret, va_list ap)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 1);
	make_str_type(&str, interpret, ap);
	if (str == 0)
		return (0);
	make_str_flags(&str, interpret);;
	make_str_width(&str, interpret);
	return (str);
}

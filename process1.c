/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 13:04:09 by sryou             #+#    #+#             */
/*   Updated: 2022/06/12 10:27:04 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	make_str_width(char **str, t_interpret *interpret)
{
	int		len;
	char	*temp;
	char	*padding;

	len = ft_strlen(*str) + interpret->nullchar;
	if (interpret->width == 0 && interpret->is_blank)
		interpret->width = len + 1;
	if (interpret->width > len)
	{
		padding = (char *)malloc(sizeof(char) * (interpret->width - len + 1));
		if (padding == 0)
			return ;
		ft_fillch(padding, interpret->width - len, interpret->is_zero);
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
		*str = make_char(interpret, ap);
	else if (interpret->type == 's')
		*str = make_str(ap);
	else if (interpret->type == 'p')
		*str = make_address(interpret, ap);
	else if (interpret->type == 'd' || interpret->type == 'i')
		*str = make_int(interpret, ap);
	else if (interpret->type == 'u')
		*str = make_uint(ap);
	else if (interpret->type == 'x')
		*str = make_lowhex(ap);
	else if (interpret->type == 'X')
		*str = make_uphex(ap);
	else if (interpret->type == '%')
		*str = make_percent();
}

char	*process_str(t_interpret *interpret, va_list ap)
{
	char	*str;

	make_str_type(&str, interpret, ap);
	if (str == 0)
		return (0);
	make_str_precision(&str, interpret);
	if (str == 0)
		return (0);
	make_str_width(&str, interpret);
	if (str == 0)
		return (0);
	make_str_sign(&str, interpret);
	if (str == 0)
		return (0);
	make_str_base(&str, interpret);
	return (str);
}

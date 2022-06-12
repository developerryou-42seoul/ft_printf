/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 10:05:00 by sryou             #+#    #+#             */
/*   Updated: 2022/06/12 10:21:45 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	make_str_precision_num(char **str, t_interpret *interpret)
{
	int		idx;
	char	*padding;
	char	*temp;

	idx = ft_strlen(*str);
	padding = (char *)malloc(sizeof(char) * \
		(interpret->precision_width - idx + 1));
	if (padding == 0)
		return ;
	ft_fillch(padding, interpret->precision_width - idx, '0');
	temp = ft_strjoin(padding, *str);
	free(padding);
	if (temp == 0)
		return ;
	free(*str);
	*str = temp;
}

void	make_str_precision(char **str, t_interpret *interpret)
{
	int		idx;

	if (interpret->is_precision)
	{
		idx = ft_strlen(*str);
		if (interpret->type == 's')
		{
			if (interpret->precision_width < idx)
				(*str)[interpret->precision_width] = '\0';
		}
		else if (interpret->precision_width - idx > 0 && \
			(interpret->type == 'd' || interpret->type == 'i' || \
			interpret->type == 'u' || interpret->type == 'x' || \
			interpret->type == 'X'))
			make_str_precision_num(str, interpret);
	}
}

void	make_str_sign(char **str, t_interpret *interpret)
{
	char	*temp;
	char	*sign;

	if (interpret->is_sign && interpret->is_plus != 0)
	{
		if (interpret->is_plus == 1)
			sign = "+";
		else if (interpret->is_plus == -1)
			sign = "-";
		if (((*str)[0] == ' ' || (*str)[0] == '0') && (int)ft_strlen(*str) != 1 \
		&& interpret->precision_width != (int)ft_strlen(*str))
			(*str)[0] = sign[0];
		else
		{
			temp = ft_strjoin(sign, *str);
			if (temp == 0)
				return ;
			free(*str);
			if (temp[ft_strlen(temp) - 1] == ' ')
				temp[ft_strlen(temp) - 1] = 0;
			*str = temp;
		}
	}
}

void	make_str_base_cut(char **str, t_interpret *interpret, int widthpointer)
{
	int		len;
	char	*temp;

	if (interpret->type == 'x' || interpret->type == 'p')
		temp = ft_strjoin("0x", (*str) + widthpointer);
	else if (interpret->type == 'X')
		temp = ft_strjoin("0X", (*str) + widthpointer);
	else
		temp = ft_strjoin("0", (*str) + widthpointer);
	if (temp == 0)
		return ;
	free(*str);
	len = ft_strlen(temp);
	if (temp[len - 1] == ' ')
		temp[len - 1] = 0;
	if ((interpret->type == 'x' || interpret->type == 'p' || \
		interpret->type == 'X') && temp[len - 2] == ' ')
		temp[len - 2] = 0;
	*str = temp;
}

void	make_str_base(char **str, t_interpret *interpret)
{
	int		len;
	int		widthpointer;

	widthpointer = 0;
	if (interpret->is_base)
	{
		len = ft_strlen(*str);
		if (interpret->type != 'p')
		{
			if (len == 0 || ((*str)[len - 1] == '0' && len == 1))
				return ;
			if ((*str)[0] == ' ' || (*str)[0] == '0')
				widthpointer++;
			if (widthpointer == 1 && len > 1 && \
				((*str)[1] == ' ' || (*str)[1] == '0'))
				widthpointer++;
		}
		make_str_base_cut(str, interpret, widthpointer);
	}
}

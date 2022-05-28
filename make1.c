/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 10:53:17 by sryou             #+#    #+#             */
/*   Updated: 2022/05/28 11:32:07 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	make_char(char **str, va_list ap)
{
	char	arg = va_arg(ap, int);

	*str = (char *)malloc(sizeof(char) * 2);
	if (*str == 0)
		return ;
	*str[0] = arg;
	*str[1] = 0;
}

void	make_str(char **str, va_list ap)
{
	char	*arg = va_arg(ap, char *);
	
	*str = ft_strdup(arg);
}

void	make_int(char **str, t_interpret *interpret,va_list ap)
{
	int	arg = va_arg(ap, int);

	if (arg > 0)
		interpret->is_plus = 1;
	*str = ft_itoa(arg);
}

void	make_uint(char **str, va_list ap)
{
	unsigned int	arg = va_arg(ap, unsigned int);

	*str = ft_itoa(arg);
}

void	make_percent(char **str)
{
	*str = (char *)malloc(sizeof(char) * 2);
	if (*str == 0)
		return ;
	*str[0] = '%';
	*str[1] = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 11:22:12 by sryou             #+#    #+#             */
/*   Updated: 2022/06/12 10:19:57 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen(char *str)
{
	int	len;

	len = 0;
	while (ft_isdigit(str[len]))
		len++;
	return (len);
}

int	ft_itohexlen(unsigned long long n)
{
	if (n < 16)
		return (1);
	return (1 + ft_itohexlen(n / 16));
}

char	*ft_itohex(unsigned long long n, int is_upper)
{
	int		len;
	char	*mkstr;

	len = ft_itohexlen(n);
	mkstr = (char *)malloc(sizeof(char) * (len + 1));
	if (mkstr == 0)
		return (0);
	mkstr[len] = '\0';
	len--;
	while (1)
	{
		if (is_upper)
			mkstr[len] = "0123456789ABCDEF"[n % 16];
		else
			mkstr[len] = "0123456789abcdef"[n % 16];
		n /= 16;
		if (len == 0)
			break ;
		len--;
	}
	return (mkstr);
}

void	ft_fillch(char *padding, int len, int is_zero)
{
	int		idx;
	char	ch;

	if (is_zero)
		ch = '0';
	else
		ch = ' ';
	idx = 0;
	while (idx < len)
	{
		padding[idx] = ch;
		idx++;
	}
	padding[idx] = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 22:32:07 by sryou             #+#    #+#             */
/*   Updated: 2022/06/11 22:51:37 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_itoalen(unsigned int n)
{
	if (n < 10)
		return (1);
	return (1 + ft_itoalen(n / 10));
}

static void	ft_putnbr_in_str(char *str, unsigned int n, int len)
{
	str[len] = '\0';
	len--;
	while (1)
	{
		str[len] = '0' + (n % 10);
		n /= 10;
		if (len == 0)
			return ;
		len--;
	}
}

char	*ft_utoa(unsigned int n)
{
	int		len;
	char	*mkstr;

	len = ft_itoalen(n);
	mkstr = (char *)malloc(sizeof(char) * (len + 1));
	if (mkstr == 0)
		return (0);
	mkstr[0] = '0';
	mkstr[1] = '\0';
	if (n > 0)
		ft_putnbr_in_str(mkstr, n, len);
	return (mkstr);
}

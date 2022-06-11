/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:32:56 by sryou             #+#    #+#             */
/*   Updated: 2022/06/11 22:51:49 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "Libft/libft.h"

typedef struct s_interpret{
	int		is_left;
	int		is_zero;
	int		is_precision;
	int		is_base;
	int		is_blank;
	int		is_sign;
	int		is_plus;
	char	type;
	int		precision_width;
	int		width;
	int		nullchar;
}	t_interpret;

int		ft_printf(const char *format, ...);
void	init_interpret(t_interpret *interpret);
int		interpret_flag(char *format, t_interpret *interpret);
int		interpret_width(char *format, t_interpret *interpret);
int		interpret_precision(char *format, t_interpret *interpret);
int		interpret_type(char *format, t_interpret *interpret);

char	*make_char(t_interpret *interpret, va_list ap);
char	*make_str(va_list ap);
char	*make_int(t_interpret *interpret, va_list ap);
char	*make_uint(va_list ap);
char	*make_percent(void);
char	*make_address(t_interpret *interpret, va_list ap);
char	*make_lowhex(va_list ap);
char	*make_uphex(va_list ap);

int		ft_intlen(char *str);
char	*ft_itohex(unsigned long long n, int is_upper);
char	*ft_utoa(unsigned int n);
void	ft_fillch(char *padding, int len, char ch);

char	*process_str(t_interpret *interpret, va_list ap);

#endif
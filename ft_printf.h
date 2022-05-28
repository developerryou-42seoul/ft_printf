/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:32:56 by sryou             #+#    #+#             */
/*   Updated: 2022/05/28 13:07:29 by sryou            ###   ########.fr       */
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
}	t_interpret;

void	init_interpret(t_interpret *interpret);
int		interpret_flag(char *format, t_interpret *interpret);
int		interpret_width(char *format, t_interpret *interpret);
int		interpret_precision(char *format, t_interpret *interpret);
int		interpret_type(char *format, t_interpret *interpret);

void	make_char(char **str, va_list ap);
void	make_str(char **str, va_list ap);
void	make_int(char **str, t_interpret *interpret, va_list ap);
void	make_uint(char **str, va_list ap);
void	make_percent(char **str);
void	make_address(char **str, va_list ap);
void	make_lowhex(char **str, va_list ap);
void	make_uphex(char **str, va_list ap);

int		ft_intlen(char *str);
char	*ft_itohex(unsigned long long n, int is_upper);
void	ft_fillch(char *padding, int len, char ch);

char	*process_str(t_interpret *interpret, va_list ap);

#endif
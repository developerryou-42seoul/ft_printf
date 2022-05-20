/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:32:56 by sryou             #+#    #+#             */
/*   Updated: 2022/05/20 17:03:46 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
typedef struct s_interpret{
	int		is_left;
	int		is_zero;
	int		is_precision;
	int		is_base;
	int		is_blank;
	int		is_sign;
	char	type;
	int		precision_width;
	int		width;
}	t_interpret;

void	init_interpret(t_interpret *interpret);
int		interpret_flag(char *format, t_interpret *interpret);
int		interpret_width(char *format, t_interpret *interpret);
int		interpret_precision(char *format, t_interpret *interpret);
int		interpret_type(char *format, t_interpret *interpret);

#endif
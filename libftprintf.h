/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoares- <gsoares-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 00:57:37 by gsoares-          #+#    #+#             */
/*   Updated: 2021/04/03 01:29:39 by gsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <stdio.h>

int		ft_printf(const char *s, ...);
char	*ft_itoa(int n);
char	*ft_pointer_conv(void *p);
char	*ft_hex_conv(int hex_num, char *s);
size_t	treat_s(va_list list, int width);
size_t 	treat_d_i(va_list list, int width);
size_t 	treat_p(va_list list, int width);
size_t	treat_x(va_list list, int width, char *s);
int		left_justify(char *s);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoares- <gsoares-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 01:18:35 by gsoares-          #+#    #+#             */
/*   Updated: 2021/04/03 01:50:03 by gsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		treat_x(va_list list, int width, char *s)
{
	int		printinteger;
	int		i;
	size_t 	length;
	char	*integerstring;

	i = 0;
	printinteger = va_arg(list, int);
	integerstring = ft_hex_conv(printinteger, (char *)s);
	length = strlen(integerstring);
	if (width > length)
	{
		while ((width - length) > i)
		{
			putchar(' ');
			i++;
		}
	}
	return (length + i);
}

int left_justify(char *s)
{
	char *size;
	int i;

	size = malloc(sizeof(char) * 100);
	i = 0;
	while (isdigit(*s))
		size[i++] = *s++;
	i = atoi(size);
	free(size);
	return (i);
}

void	ft_putnchar(char c, int i)
{
	if (!c || !i || i <= 0)
		return ;
	while (i--)
		putchar(c);
	return ;
}

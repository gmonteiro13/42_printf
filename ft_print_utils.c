/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoares- <gsoares-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 01:03:11 by gsoares-          #+#    #+#             */
/*   Updated: 2021/04/03 01:50:08 by gsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_pointer_conv(void *p)
{
	long int quot;
	long int rem;
	int i;
	int j;
	char *hex;

	putchar('0');
	putchar('x');
	j = 0;
	quot = (long int)p;
	hex = malloc(sizeof(long int));
	while (quot != 0)
	{
		rem = quot % 16;
		if (rem < 10)
			hex[j++] = 48 + rem;
		else
			hex[j++] = 55 + rem;
		quot = quot / 16;
	}
	i = j;
	while (i >= 0)
		putchar(tolower(hex[i--]));
	return (hex);
}

char *ft_hex_conv(int hex_num, char *s)
{
	unsigned int quot;
	unsigned int rem;
	int i;
	int j;
	char *hex_char;

	j = 0;
	quot = (unsigned int)hex_num;
	hex_char = malloc(sizeof(int));
	while (quot != 0)
	{
		rem = quot % 16;
		if (rem < 10)
			hex_char[j++] = 48 + rem;
		else
			hex_char[j++] = 55 + rem;
		quot = quot / 16;
	}
	i = j;
	while (i >= 0)
	{
		if (*s == 120)
			putchar(tolower(hex_char[i--]));
		else
			putchar(hex_char[i--]);
	}
	return (hex_char);
}

size_t treat_s(va_list list, int width)
{
	size_t length;
	int i;
	char *printstring;

	i = 0;
	printstring = va_arg(list, char *);
	length = strlen(printstring);
	while (*printstring)
		putchar(*printstring++);
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

size_t treat_d_i(va_list list, int width)
{
	int printinteger;
	int i;
	size_t length;
	char *integerstring;

	i = 0;
	printinteger = va_arg(list, int);
	integerstring = ft_itoa(printinteger);
	length = strlen(integerstring);
	while (*integerstring)
		putchar(*integerstring++);
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

size_t treat_p(va_list list, int width)
{
	void *p;
	char *printstring;
	int i;
	size_t length;

	i = 0;
	p = va_arg(list, char *);
	printstring = (char *)ft_pointer_conv(p);
	length = strlen(printstring) + 2;
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

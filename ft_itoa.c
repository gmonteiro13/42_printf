/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoares- <gsoares-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 21:59:34 by gabriel-scm       #+#    #+#             */
/*   Updated: 2021/04/01 20:21:58 by gsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static int ft_intlen(int n)
{
	int				len;
	unsigned int	result;

	len = 0;
	result = n;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		result *= -1;
		len++;
	}
	while (result > 0)
	{
		result /= 10;
		len++;
	}
	return (len);
}

static char			*n_negative(char *str, int n, int int_len)
{
	unsigned int	dig;

	dig = -n;
	str[0] = '-';
	str[int_len] = '\0';
	int_len--;
	while (int_len > 0)
	{
		str[int_len] = dig % 10 + '0';
		dig /= 10;
		int_len--;
	}
	return (str);
}

static char			*n_positive(char *str, int n, int int_len)
{
	unsigned int	dig;

	dig = n;
	str[int_len] = '\0';
	int_len--;
	while (int_len >= 0)
	{
		str[int_len] = dig % 10 + '0';
		dig /= 10;
		int_len--;
	}
	return (str);
}

char				*ft_itoa(int n)
{
	char			*str;
	int				int_len;

	int_len = ft_intlen(n);
	str = (char *)malloc(sizeof(char) * (int_len + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
		return (n_negative(str, n, int_len));
	else
		return (n_positive(str, n, int_len));
}

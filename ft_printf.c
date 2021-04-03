#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *ft_itoa(int n);

char *ft_pointer_conv(void *p)
{
	long int		quot;
	long int		rem;
	int				i;
	int				j;
	char			*hex;

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

char		*ft_hex_conv(int hex_num, char *s)
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

int			left_justify(char *s)
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

size_t		treat_s(va_list list, int width)
{
	size_t	length;
	int		i;
	char	*printstring;

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

size_t		treat_d_i(va_list list, int width)
{
	int		printinteger;
	int		i;
	size_t	length;
	char	*integerstring;

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

size_t		treat_p(va_list list, int width)
{	
	void	*p;
	char	*printstring;
	int		i;
	size_t	length;

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

int			ft_printf(const char *s, ...)
{
	va_list	list;
	size_t	charcount;
	int		width;

	va_start(list, s);
	charcount = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == '-')
			{
				width = left_justify((char *)++s);
				s++;
			}
			else
				width = 0;
			if (*s == 's')
			{
				charcount += treat_s(list, width);
				s++;
			}
			else if (*s == 'i' || *s == 'd')
			{
				charcount += treat_d_i(list, width);
				s++;
			}
			else if (*s == 'p')
			{
				charcount += treat_p(list, width);
				s++;
			}
			else if (*s == 'x' || *s == 'X')
			{
				charcount += treat_x(list, width, (char *)s);
				s++;
			}
		}
		else
		{
				putchar(*s);
				s++;
				charcount++;
		}
	}
	va_end(list);
	return (charcount);
}

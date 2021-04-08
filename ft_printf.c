#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ft_printf.h"

int			ft_printf(const char *s, ...)
{
	va_list	list;
	size_t	charcount;
	int		width;
	int		has_space;

	va_start(list, s);
	charcount = 0;
	while (*s)
	{
		has_space = 0;
		if (*s == '%')
		{
			s++;
			if (*s == '-')
			{
				s++;
				width = left_justify((char *)s);
				while(isdigit(*s))
					s++;
			}
			else
				width = 0;
			if (isdigit(*s))
			{
				has_space = 1;
				width = left_justify((char *)s);
				while (isdigit(*s))
					s++;
			}
			if (*s == 's')
			{
				charcount += treat_s(list, width, has_space);
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

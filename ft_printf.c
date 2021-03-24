#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char		*ft_itoa(int n);

int 		ft_tolower(int c);

char *ft_pointer_conv(void *p)
{
	long int		quot;
	long int		rem;
	int 			i;
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
		putchar(ft_tolower(hex[i--]));
}

int			ft_printf(const char *s, ...)
{
	/* 
	We need to use vararg to iterate through the arguments
	*/
	va_list	list;

	/*
	For this example, our function will print a string or a integer
	so we will declare two variables to help us
	*/
	char	*printstring;
	char	*integerstring;
	int		printinteger;
	void	*ptest;

	/*
	The return value is the number of characters printed, so we'll
	need to declare a variable that counts this number
	*/
	size_t	charcount;

	/*
	va_start takes two arguments: a va_list object and a reference to
	the function's last parameter
	*/
	va_start(list, s);

	/*
	Next, we will start iterating through the string (s).
	*/
	charcount = 0;
	while (*s)
	{
		/*
		Finding a "%" means that we'll need to check the next character
		to do the appropriate conversion (char, int, etc..)
		*/
		if (*s == '%')
		{
			s++;
			/* Goes to the next character */
			if (*s == 's')
			/* String conversion */
			{
				printstring = va_arg(list, char *);
				/* va_arg takes two arguments, a va_list (previously initialised)
				and a type descriptor. The current value stored in the list is "Hello" */
				charcount += strlen(printstring);
				/* This will add the length of the argument ("Hello" = 5)
				to the character count */
				while (*printstring)
					putchar(*printstring++);
				/* We have to print the argument character by character ("H", then
				"e", then "l"... */
				s++;
				/* When we're done, we have to go to the next character
				(which is "!") */
			}
			else if (*s == 'i')
			/* Integer conversion */
			{
				/*
				Invocating va_arg successively allow processing each
				of the variable arguments in turn.
				So it will automatically go to the next argument, which
				is "777"
				*/
				printinteger = va_arg(list, int);
				/*
				We need to convert the integer 777 into a string,
				so we can count the characters and print them.
				ft_itoa will be used.
				*/
				integerstring = ft_itoa(printinteger);
				charcount += strlen(integerstring);
				while (*integerstring)
					putchar(*integerstring++);
				s++;
			}
			else if (*s == 'p')
			/* Pointer conversion */
			{
				ptest = (char **)va_arg(list, char *);
				printstring = ft_pointer_conv(ptest);
			}
		}
		else
		{
			/*
			If we don't find a "%", we have to print the current character,
			move on to the next and add 1 to the character count
			*/
				putchar(*s);
				s++;
				charcount++;
		}
	}
	va_end(list);
	return (charcount);
}

int main()
{
	char	test[6] = "Mario";
	int		test2;
	int		original_return;
	int		my_return;

	test2 = 777;
	printf("Original function:\n");
	original_return = printf("Thank you, %s! But our princess is in castle %i.\n", test, test2);
	printf("This is the test2 address %p\n", &test2);
	printf("My function:\n");
	my_return = ft_printf("Thank you, %s! But our princess is in castle %i.\n", test, test2);
	ft_printf("This is test2 address %p\n", &test2);
	printf("The original printf read %d characters!\n", original_return);
	printf("My printf read %d characters!\n", my_return);
}

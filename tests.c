#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int			ft_printf(const char *s, ...);
char		*ft_itoa(int n);
int			ft_tolower(int c);

int			main()
{
	char	test[6] = "Mario";
	int		test2;
	int		original_return;
	int		my_return;

	test2 = 777;

	printf("Original function:\n");
	original_return = printf("Thank you, %s! But our princess is in castle %i.\n", test, test2);
	printf("The original printf read %i characters!\n", original_return);

	original_return = printf("Printing the address of test2: %p. \n", &test2);
	printf("The original read %i characters.\n", original_return);

	original_return = printf("Printing a hex value: %x %X. \n", -0x11D7, 0x11D7);
	printf("The original read %i characters.\n", original_return);

	printf("My function:\n");
	my_return = ft_printf("Thank you, %s! But our princess is in castle %i.\n", test, test2);
	printf("My printf read %i characters!\n", my_return);

	my_return = ft_printf("Printing the address of test2: %p. \n", &test2);
	printf("My function read %i characters.\n", my_return);

	my_return = ft_printf("Printing a hex value: %x %X. \n", -0x11D7, 0x11D7);
	printf("My function read %i characters.\n", my_return);

	printf("%-8d. I have a lot of spaces.\n", -test2);
	printf("%-8d. I have a lot of spaces.\n", test2);
}

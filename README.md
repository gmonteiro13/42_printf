The goal of this project is to recode libc's printf (print formatted) function
It will manage the following conversions: cspdiuxX%
It will manage any combination of the following flags: ’-0.*’ and minimum field width with all conversions

The conversions mentioned above works as follows:

c: Character
s: String of characters
p: Pointer address
d or i: Signed decimal integer
u: Unsigned decimal integer
x: Unsigned hexadecimal integer
X: Unsigned hexadecimal integer (capitalized)
%: Character

The flags mentioned above works as follows:

-: Left-justify within the given field width (right justification is the default)
0: Left-pads the number with zeroes (0) instead of spaces, where padding is specified
.*: The precision is not specified in the format string, but as an additional integer value argument...
... preceding the argument that has to be formatted

MUST ADD EXAMPLES

INTRODUCTION

Vararg: Variable argument functions

Printf and scanf are two functions that you will encounter to use any number of arguments. At first, it may seems to be an advance level trick but in fact, you can modify your functions as well to accept variable number of arguments. The answer is vararg.

We demonstrate this by an average() function that will accept any number of arguments. Example of using Vararg for average() function is as follows:

```c

#include <stdarg.h>
#include <stdio.h>

double average(int count, ...)
{
    va_list ap;
    int j;
    double sum = 0;

    va_start(ap, count); /* Requires the last fixed parameter (to get the address) */
    for (j = 0; j < count; j++) {
        sum += va_arg(ap, int); /* Increments ap to the next argument. */
    }
    va_end(ap);

    return sum / count;
}

int main(int argc, char const *argv[])
{
	printf("%f\n", average(3, 1, 2, 3) );
	return 0;
}
```

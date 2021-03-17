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
In the above code, the function average() can take in any number of input parameters.

Key points to note:

    Arguments are passed on the stack

    The va_start function contains the code to initialize the va_list with the correct stack pointer. It must be passed the last named argument in the function declaration or it will not work.

    va_arg uses this saved stack pointer and extract the correct amount of bytes for the type provided, and then modify ap so it points to the next argument on the stack.
	
    va_end holds to pointer to the end of the stack

    functions (va_start, va_arg and va_end) are implemented as preprocessor macros. The actual implementation also depends on the compiler, as different compilers can have different layout of the stack and how it pushes arguments on the stack.

Printf working principle

    Printf takes multiple arguments using vararg function.

    User supply a string and input arguments. Like printf("Hello, my name is %s having an id %d", name, id);

    Printf creates an internal buffer for constructing output string.

    Now printf iterates through each characters of user string and copies the character to the output string. Printf only stops at %. % means there is an argument to convert. Arguments are in the form of char, int, long, float, double or string. It converts it to string and appends to output buffer. If the argument is string then it does a string copy.

    Finally printf may reach at the end of user sting and it copies the entire buffer to the stdout file.

Consider this C code that demonstrates the internal functionality of printf:

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
int print (char * str, ...)
{
	va_list vl;
	int i = 0, j=0;
		char buff[100]={0}, tmp[20];
		va_start( vl, str ); 
		while (str && str[i])
		{
		  	if(str[i] == '%')
		  	{
 		    i++;
 		    switch (str[i]) 
 		    {
	 		    case 'c': 
	 		    {
	 		        buff[j] = (char)va_arg( vl, int );
	 		        j++;
	 		        break;
	 		    }
	 		    case 'd': 
	 		    {
	 		        itoa(va_arg( vl, int ), tmp, 10);
	 		        strcpy(&buff[j], tmp);
	 		        j += strlen(tmp);
		           break;
		        }
		        case 'x': 
		        {
		           itoa(va_arg( vl, int ), tmp, 16);
		           strcpy(&buff[j], tmp);
		           j += strlen(tmp);
		           break;
		        }
        	}
     	} 
     	else 
	    {
	       	buff[j] =str[i];
	       	j++;
	    }
	    i++;
	} 
    fwrite(buff, j, 1, stdout); 
    va_end(vl);
    return j;
 }
 ```

 stdarg.h declares a type, va_list, and defines four macros: va_start, va_arg, va_copy, and va_end. Each invocation of va_start and va_copy must be matched by a corresponding invocation of va_end. When working with variable arguments, a function normally declares a variable of type va_list (ap in the example) that will be manipulated by the macros.

    va_start takes two arguments, a va_list object and a reference to the function's last parameter (the one before the ellipsis; the macro uses this to get its bearings). It initialises the va_list object for use by va_arg or va_copy. The compiler will normally issue a warning if the reference is incorrect (e.g. a reference to a different parameter than the last one, or a reference to a wholly different object), but will not prevent compilation from completing normally.

    va_arg takes two arguments, a va_list object (previously initialised) and a type descriptor. It expands to the next variable argument, and has the specified type. Successive invocations of va_arg allow processing each of the variable arguments in turn. Unspecified behavior occurs if the type is incorrect or there is no next variable argument.

    va_end takes one argument, a va_list object. It serves to clean up. If you wanted to, for instance, scan the variable arguments more than once, you would re-initialise your va_list object by invoking va_end and then va_start again on it.
	
    va_copy takes two arguments, both of them va_list objects. It clones the second (which must have been initialised) into the first. Going back to the "scan the variable arguments more than once" example, this could be achieved by invoking va_start on a first va_list, then using va_copy to clone it into a second va_list. After scanning the variable arguments a first time with va_arg and the first va_list (disposing of it with va_end), you could scan the variable arguments a second time with va_arg and the second va_list. Don't forget to va_end the clone va_list.
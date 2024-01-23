/*Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n);*/

int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n % 2 == 0)
		n /= 2;
	return ((n == 1) ? 1 : 0);
}

#include <stdio.h>

int main()
{
    unsigned int number = 8;
    int result = is_power_of_2(number);

    if(result == 1)
    {
        printf("%u is a power of 2\n", number);
    }
    else
    {
        printf("%u is not a power of 2\n", number);
    }

    return 0;
}
/*Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>*/

#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while ((*str == ' ') || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}

int	is_prime(int n)
{
	int i = 2;

	if (n <= 1)
		return (0);
	while (i * i <= n)
	{
		if (n % i == 0)
			return(0);
		i++;
	}
	return (1);
}

void ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	char digit = n % 10 + '0';
	write(1, &digit, 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	n = ft_atoi(av[1]);
		int	sum = 0;

		while (n > 0)
		{
			if (is_prime(n))
				sum += n;
			n--;
		}
		ft_putnbr(sum);
	}
	write(1, "\n", 1);
	return (0);
}
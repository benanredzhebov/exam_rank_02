/*Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>*/

// #include <unistd.h>
// #include <stdlib.h>
// #include <stdio.h>

// int	main (int ac, char **av)
// {
// 	int	i;
// 	int	start;
// 	int	end;
// 	int	flag;

// 	flag = 0;
// 	if (ac > 1 && av[1][0])
// 	{
// 		i = 0;
// 		while (av[1][i] == ' ' || av[1][i] == '\t')
// 			i++;
// 		start = i;
// 		printf("Start index: %d\n", i);
// 		printf("Start word: %c\n", av[1][i]);
// 		while (av[1][i] != '\0' && av[1][i] != ' ' && av[1][i] != '\t')
// 			i++;
// 		end = i;
// 		printf("End index: %d\n", i);
// 		printf("End word: %c\n", av[1][i]);
// 		while (av[1][i] == ' ' || av[1][i] == '\t')
// 			i++;
// 		printf("Check: %d\n", i);
// 		printf("Check: %c\n", av[1][i]);
// 		while (av[1][i])
// 		{
// 			while ((av[1][i] == ' ' && av[1][i + 1] == ' ') \
// 				|| (av[1][i] == '\t' && av[1][i + 1] == '\t'))
// 				i++;
// 			printf("Inside while1: %d\n", i);
// 			printf("Inside while1: %c\n", av[1][i]);
// 			if (av[1][i] == ' ' || av[1][i] == '\t')
// 				flag = 1;
// 			printf("Inside while2: %d\n", i);
// 			printf("Inside while2: %c\n", av[1][i]);
// 			write(1, &av[1][i], 1);
// 			i++;
// 		}
// 		if (flag)
// 			write(1, " ", 1);
// 		while (start < end)
// 		{
// 				write(1, &av[1][start], 1);
// 				start++;
// 			}
// 		}
// 	}
// 	write (1, "\n", 1);
// 	return (0);
// }

#include <unistd.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	int	i;
	int	start;
	int	end;
	int	flag;
	int fd = open("test.txt", O_RDWR | O_TRUNC | O_CREAT, 0777);

	flag = 0;
	if (ac > 1 && av[1][0])
	{
		i = 0;
		while (av[1][i] == ' ' || av[1][i] == '\t')
		i++;
		start = i;
		while (av[1][i] != '\0' && av[1][i] != ' ' && av[1][i] != '\t')
			i++;
		end = i;
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		while (av[1][i])
		{
			while ((av[1][i] == ' ' || av[1][i] == '\t') \
			&& (av[1][i + 1] == '\t' || av[1][i + 1] == ' '))
				i++;
			if (!((av[1][i] == ' ' || av[1][i] == '\t') && av[1][i + 1] == '\0'))
			{
				write(fd, &av[1][i], 1);
				flag = 1;
			}
			i++;
		}
		if (flag)
			write(fd, " ", 1);
		while (start < end)
		{
			write(fd, &av[1][start], 1);
			start++;
		}
	}
	write(fd, "\n", 1);
	return (0);
}
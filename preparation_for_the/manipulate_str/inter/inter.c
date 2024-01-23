/*Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$*/

#include <unistd.h>

int	iter(char *str, char c, int len)
{
	int	i = 0;
	while (str[i] && (i < len || len == -1))
		if(str[i++] == c)
			return (1);
		return (0);
}

int	main (int ac, char **av)
{
	int	i;

	if (ac == 3)
	{
		i = 0;
		while (av[1][i])
		{
			if (!iter(av[1], av[1][i], i) && iter(av[2], av[1][i], -1))
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}


// #include <unistd.h>

// int	iter(char *str, char c, int len)
// {
// 	int	i = 0;

// 	while (str[i] != '\0' && (i < len || len == -1))
// 		if (str[i++] == c)
// 			return (1);
// 		return (0);
// }


// int	main(int ac, char **av)
// {
// 	int	i;

// 	if (ac == 3)
// 	{
// 		i = 0;
// 		while (av[1][i])
// 		{
// 			if (!iter(av[1], av[1][i], i) && iter(av[2], av[1][i], -1))
// 				write(1, &av[1][i], 1);
// 			i++;
// 		}
// 	}
// 	write(1, "\n", 1);
// 	return (0);
// }
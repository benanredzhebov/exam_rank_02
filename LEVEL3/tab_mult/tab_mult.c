/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:26:23 by beredzhe          #+#    #+#             */
/*   Updated: 2024/01/07 14:51:09 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>*/

#include <unistd.h>

int ft_atoi (const char *str)
{
	int	result;
	int sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' && *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);

	char c = (n % 10) + '0';
	write(1, &c, 1);
}

void	tab_mult(char *str)
{
	int n;
	int i = 1;

	n = ft_atoi(str);
	while (i <= 9)
	{
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putnbr(n);
		write(1, " = ", 3);
		ft_putnbr(i * n);
		write(1, "\n", 1);
		++i;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		tab_mult(argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}

#include <stdlib.h>
#include <stdio.h>

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int	main(void)
{
	t_point size = {8, 5};
	char *zone1[] = {
		"11111111",
		"10000001",
		"10010101",
		"10110001",
		"11101111",
	};
	char *zone2[] = {
		"11111111",
		"10011001",
		"10100101",
		"11000011",
		"11111111",
	};

	// Make area arrays
	char**  area1 = make_area(zone1, size);
	char**  area2 = make_area(zone1, size);
	char**  area3 = make_area(zone2, size);
	// Present map 1
	printf("Map 1\n");
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area1[i]);
	printf("\n");
	// Assign starting points
	t_point begin1 = {7, 4};
	t_point begin2 = {3, 1};
	t_point begin3 = {0, 0};
	// Perform first two operations
	flood_fill(area1, size, begin1);
	flood_fill(area2, size, begin2);
	printf("Start (7, 4)\n");
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area1[i]);
	printf("\n");
	printf("Start (3, 1)\n");
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area2[i]);
	printf("\n-----------\n");
	// Present map 2
	printf("Map 2\n");
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area3[i]);
	printf("\n");
	// Perform third operation
	flood_fill(area3, size, begin3);
	printf("Start (0, 0)\n");
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area3[i]);
	return (0);
}
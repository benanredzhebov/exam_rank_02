/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:59:40 by beredzhe          #+#    #+#             */
/*   Updated: 2024/01/03 19:40:20 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>*/

#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i] != '\0')
			i++;
		// printf("Before: %d\n", i);
		i--;
		// printf("After: %d\n", i);
		while ((av[1][i] == ' ' || av[1][i] == '\t') && i != 0)
			i--;
		// printf("1: %d\n", i);
		while (av[1][i] != ' ' && av[1][i] != '\t'  && i != 0)
			i--;
		// printf("2: %d\n", i);
		if (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		// printf("3: %d\n", i);
		while (av[1][i] != '\0' && av[1][i] != ' ' && av[1][i] != '\t')
		{	
			write(1, &av[1][i], 1);
			i++;
		}
		// printf("4: %d\n", i);
	}
	write(1, "\n", 1);
}
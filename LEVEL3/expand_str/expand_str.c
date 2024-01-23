/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:28:48 by beredzhe          #+#    #+#             */
/*   Updated: 2024/01/10 12:03:27 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	word_len(char *str)
{
	int	i = 0;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
		++i;
	return(i);
}

void	expand_str(char *str)
{
	int	len; //Length of the current word.
	int	first_word = 1; //Flag to determine if it's the first word.

	while (*str != '\0') //Iterates through each character in the input string.
	{
		while (*str == ' ' || *str == '\t') //Skips over consecutive spaces or tabs until a non-space, non-tab character is encountered.
			++str;
		len = word_len(str); //Calls the word_len function to calculate the length of the current word.
		if (len > 0 && first_word == 0) //If the length of the word is greater than 0 and it's not the first word, print three spaces.
			write(1, "   ", 3);
		first_word = 0;
		write(1, str, len); //Writes the current word to the standard output.
		str = str + len; //Moves the pointer to the next word in the input string.
	}
}

int	main (int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
		expand_str(av[1]);

	write(1, "\n", 1);
	return (0);
}
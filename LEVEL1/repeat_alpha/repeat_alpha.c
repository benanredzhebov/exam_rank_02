/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:13:05 by beredzhe          #+#    #+#             */
/*   Updated: 2024/01/02 10:52:36 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>*/

#include <unistd.h>

void	ft_putchar_n (char c, int i)
{
	while (i > 0)
	{
		write(1, &c, 1);
		--i;
	}
}

void	repeat_alpha(char *str)
{
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
			ft_putchar_n(*str, *str + 1 - 'a');
		else if (*str >= 'A' && *str <= 'Z')
			ft_putchar_n(*str, *str + 1 - 'A');
		else
			write(1, str, 1);
		++str;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		repeat_alpha(argv[1]);
	write(1, "\n", 1);
	return (0);
}

// int main()
// {
// 	char	character = 'A';  // You can choose any character
// 	int		repeatCount = 5;   // You can choose any positive integer

// 	// Call ft_putchar_n to print the character 'A' 5 times
// 	ft_putchar_n(character, repeatCount);

// 	return 0;  // Indicates successful completion
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:14:19 by beredzhe          #+#    #+#             */
/*   Updated: 2024/01/03 15:41:33 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);*/

#include <stdio.h>
#include <string.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (*s1)
	{
		i = 0;
		while (s2[i])
		{
			if (*s1 == s2[i])
				return ((char *) s1);
			i++;
		}
		s1++;
	}
	return (0);
}

#include <stdio.h>

// Your ft_strpbrk function declaration
char *ft_strpbrk(const char *s, const char *accept);

int main() {
    const char *str1 = "Hello, World!";
    const char *str2 = ", ";

    char *result = ft_strpbrk(str1, str2);

    if (result) {
        printf("Result: %s\n", result);
    } else {
        printf("No characters found\n");
    }

    return 0;
}
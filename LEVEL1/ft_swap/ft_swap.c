/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:02:02 by beredzhe          #+#    #+#             */
/*   Updated: 2024/01/02 10:12:10 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);
*/

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

#include <stdio.h>

int	main(void)
{
	int a = 6;
	int	b = 10;

	ft_swap(&a, &b);
	printf ("a = %d, b = %d", a, b);
	return (0);
}


// int	main(void)
// {
// 	int	a = 10;
// 	int	b = 5;

// 	ft_swap(&a, &b);
// 	printf("a = %d\n", a);
// 	printf("b = %d\n", b);
// 	return (0);
// }
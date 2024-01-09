/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:50:08 by beredzhe          #+#    #+#             */
/*   Updated: 2024/01/05 13:59:45 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.*/

int	max(int *tab, unsigned int len)
{
	unsigned int	i;
	unsigned int	result;

	if (len == 0)
		return (0);
	i = 0;
	result = tab[i];
	while (i < len)
	{
		if (result < tab[i])
			result = tab[i];
		i++;
	}
	return (result);
}

#include <stdio.h>

int main()
{
	int	arr[] = {3, 7, 2, 9, 1, 5, 10000};
	unsigned	int arr_length = sizeof(arr) / sizeof(arr[0]);

	int	maximum_value = max(arr, arr_length);

	printf("The maximum value in the array is: %d\n", maximum_value);

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:20:16 by beredzhe          #+#    #+#             */
/*   Updated: 2024/01/09 09:48:31 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_rrange(int start, int end)
{
	int *range;
	int i = 0;
	int step = 1;
	int n = end - start;

	if (n < 0)
		(n *= -1);
	n++;

	range = (int *)malloc(sizeof(int) * n);
	if (range)
	{
		if (start < end)
			step = -1;
		while (i < n)
		{
			range[i] = end;
			end = end + step;
			i++;
		}
	}
	return (range);
}

#include <stdio.h>

int	main()
{
	int	start = -1;
	int	end = 2;

	int *result = ft_rrange(start, end);
	if (result) 
	{
        printf("Array: ");
        for (int i = 0; i < abs(end - start) + 1; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");

        // Free the allocated memory
        free(result);
    } else {
        printf("Memory allocation failed\n");
    }

    return 0;
}
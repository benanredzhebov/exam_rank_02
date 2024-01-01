q/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:54:17 by beredzhe          #+#    #+#             */
/*   Updated: 2023/12/29 15:21:28 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	n1 = 0;
	int	n2 = 0;
	int	res = 0;
	
	if (argc == 4)
	{
		n1 = atoi(argv[1]);
		n2 = atoi(argv[3]);
		if (argv[2][0] == '+')
			res = n1 + n2;
		else if (argv[2][0] == '-')
			res = n1 - n2;
		else if (argv[2][0] == '*')
			res = n1 * n2;
		else if (argv[2][0] == '/')
			res = n1 / n2;
		else if (argv[2][0] == '%')
			res = n1 % n2;
		printf("%d\n", res);
	}
	else
		write(1, "\n", 1);
}

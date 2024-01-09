/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:36:10 by beredzhe          #+#    #+#             */
/*   Updated: 2024/01/08 09:53:09 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int	ft_list_size(t_list *begin_list)
{
	if (begin_list == 0)
		return (0);
	else
		return (1 + ft_list_size(begin_list->next));
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	int n = 0;

// 	t_list *c = malloc(sizeof(*c));
// 	c->next = 0;
// 	c->data = &n;

// 	t_list *b = malloc(sizeof(*b));
// 	b->next = c;
// 	b->data = &n;

// 	t_list *a = malloc(sizeof(*a));
// 	a->next = b;
// 	a->data = &n;

// 	printf("%d\n", ft_list_size(a));
// }
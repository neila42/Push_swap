/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:03:12 by nmuminov          #+#    #+#             */
/*   Updated: 2023/04/20 15:36:04 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_nb	*create_list(int data)
{
	t_list_nb	*list;

	list = malloc(sizeof(t_list_nb));
	if (!list)
		return (NULL);
	list->data = data;
	list->next = NULL;
	return (list);
}

void	free_list(t_list_nb *l)
{
	t_list_nb	*tmp;

	tmp = NULL;
	while (l)
	{
		tmp = l->next;
		free(l);
		l = tmp;
	}
}

void	print_list(t_list_nb *l)
{
	while (!is_empty_list(l))
	{	
		printf("%d ", l->data);
		l = l->next;
	}
	printf("\n");
}

t_list_nb	*create_empty_list(void)
{
	return (NULL);
}

int	is_empty_list(t_list_nb *l)
{
	return (l == NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:02:53 by nmuminov          #+#    #+#             */
/*   Updated: 2023/04/24 12:13:06 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_nb	*ft_lst_last(t_list_nb *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

t_list_nb	*ft_lst_new(int content)
{
	t_list_nb	*new;

	new = malloc(sizeof(t_list_nb));
	if (!new)
		return (NULL);
	new->data = content;
	new->next = NULL;
	return (new);
}

void	ft_lst_add_front(t_list_nb **lst, t_list_nb *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
	return ;
}

void	ft_lst_add_back(t_list_nb **lst, t_list_nb *new)
{
	t_list_nb	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lst_last(*lst);
	tmp->next = new;
}

t_list_nb	*create_pile(char **av, int a)
{
	t_list_nb	*pile;
	int			i;

	i = 0;
	pile = NULL;
	if (a <= 0)
	{
		while (av[i])
		{
			if (ft_atoi(av[i]) < -2147483648 || ft_atoi(av[i]) > 2147483647)
				error();
			ft_lst_add_back(&pile, ft_lst_new(ft_atoi(av[i])));
			i++;
		}
	}
	return (pile);
}

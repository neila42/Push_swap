/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:05:31 by nmuminov          #+#    #+#             */
/*   Updated: 2023/04/20 15:35:56 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_max_top_half(t_list_nb *pile)
{
	int			mid;
	int			count;
	t_list_nb	*head;

	if (!pile)
		return (-1);
	head = pile;
	count = 0;
	mid = lst_len(pile) / 2;
	while (pile && pile->data != data_max(pile))
	{
		count++;
		pile = pile->next;
	}
	pile = head;
	if (count > mid)
		return (1);
	else
		return (0);
}

int	get_last_data(t_list_nb *pile)
{
	int	res;

	if (!pile)
		return (2147483647);
	while (pile->next)
		pile = pile->next;
	res = pile->data;
	return (res);
}

int	lst_len(t_list_nb *list)
{
	t_list_nb	*tmp;
	int			i;

	if (!list)
		return (0);
	i = 0;
	tmp = list;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	is_sorted(t_env *env)
{
	t_list_nb	*tmp;

	tmp = env->a;
	while (tmp->next)
	{
		if (tmp->data < tmp->next->data)
			tmp = tmp->next;
		else
			return (1);
	}
	return (0);
}

void	free_tab(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}

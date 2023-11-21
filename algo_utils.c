/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:01:52 by nmuminov          #+#    #+#             */
/*   Updated: 2023/04/20 15:35:50 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_data(t_list_nb *pile, int data)
{
	t_list_nb	*tmp;

	tmp = pile;
	while (tmp)
	{
		if (tmp->data < data)
			data = tmp->data;
		tmp = tmp->next;
	}
	return (data);
}

int	data_max_utils(t_list_nb *pile, int data)
{
	t_list_nb	*tmp;

	tmp = pile;
	while (tmp)
	{
		if (tmp->data > data)
			data = tmp->data;
		tmp = tmp->next;
	}
	return (data);
}

int	data_max(t_list_nb *pile)
{
	int	max;

	if (!pile)
		return (2147483647);
	max = data_max_utils(pile, pile->data);
	while (max != data_max_utils(pile, max))
		max = data_max_utils(pile, pile->data);
	return (max);
}

int	secund_min(t_list_nb *pile, int first_min)
{
	t_list_nb	*head;
	t_list_nb	*tmp;
	t_min_info	info_min;

	info_min.save = first_min;
	tmp = pile;
	head = pile;
	info_min.count = 1;
	while (info_min.count != 0)
	{
		info_min.count = 0;
		while (tmp)
		{
			if ((first_min < tmp->data && info_min.save == first_min)
				|| (first_min > tmp->data && info_min.save < tmp->data))
			{
				first_min = tmp->data;
				info_min.count++;
			}
			tmp = tmp->next;
		}
		tmp = head;
	}
	pile = head;
	return (first_min);
}

int	x_min(t_list_nb *list, int x)
{
	int	min;
	int	i;

	i = 0;
	if (x == 0)
	{
		min = min_data(list, list->data);
		while (min != min_data(list, min))
			min = min_data(list, min);
		return (min);
	}
	min = min_data(list, list->data);
	while (min != min_data(list, min))
		min = min_data(list, min);
	while (i < x)
	{
		min = secund_min(list, min);
		i++;
	}
	return (min);
}

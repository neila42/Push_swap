/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:02:10 by nmuminov          #+#    #+#             */
/*   Updated: 2023/04/20 15:35:52 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_env *env, int range, int type)
{
	if (type == RA)
	{
		while (env->a->data >= range && lst_len(env->a) > 1)
			ra(env);
	}
	else if (type == RRA)
	{
		while (env->a->data >= range && lst_len(env->a) > 1)
		{
			rra(env);
		}
	}
	if (env->a->data >= env->set.pivot)
		pb(env);
	else
	{
		pb(env);
		rb(env);
	}
}

void	divide_and_push(t_env *env, t_list_nb *l, int range)
{
	int			mid;
	int			count;
	t_list_nb	*head;

	head = l;
	count = 0;
	mid = lst_len(l) / 2;
	while (l && l->data >= range)
	{
		count++;
		l = l->next;
	}
	l = head;
	if (count > mid)
		push_to_b(env, range, RRA);
	else
		push_to_b(env, range, RA);
}

void	initialize_chunk(t_env *env, t_setup chunk_size)
{
	t_setup	tmp;

	tmp = chunk_size;
	tmp.chunk_data = x_min(env->a, tmp.chunk_size);
	tmp.pivot = x_min(env->a, tmp.chunk_size / 2);
	env->set = tmp;
}

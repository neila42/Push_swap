/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:58:04 by nmuminov          #+#    #+#             */
/*   Updated: 2023/04/20 15:35:47 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_env *env)
{
	if (env->a->data == x_min(env->a, 3))
	{
		ra(env);
		if (env->a->next->data == x_min(env->a, 0))
			sa(env);
	}
	else if (env->a->data == x_min(env->a, 0))
	{
		if (env->a->next->data == x_min(env->a, 3))
		{
			rra(env);
			sa(env);
		}
	}
	else
	{
		if (env->a->next->data == x_min(env->a, 0))
			sa(env);
		else
			rra(env);
	}
}

void	sort_5(t_env *env)
{
	while (lst_len(env->a) > 3)
	{
		while (x_min(env->a, 0) != env->a->data)
			ra(env);
		pb(env);
	}
	sort_3(env);
	if (env->b->data < env->b->next->data)
		sa(env);
	pa(env);
	pa(env);
}

void	sort_100(t_env *env)
{
	int			loop;
	int			i;
	t_setup		tmp;

	tmp.chunk_size = lst_len(env->a) / 4;
	loop = 0;
	i = 1;
	while (loop < 4)
	{
		initialize_chunk(env, tmp);
		while (env->set.chunk_size >= i)
		{
			divide_and_push(env, env->a, env->set.chunk_data);
			i++;
		}
		loop++;
		i = 1;
	}
	if (lst_len(env->a) == 3)
		sort_3(env);
	else if (lst_len(env->a) == 2)
		if (env->a->data > env->a->next->data)
			sa(env);
	push_to_a(env);
}

void	sort_500(t_env *env)
{
	int			loop;
	int			i;
	t_setup		tmp;

	loop = 0;
	i = 1;
	while (lst_len(env->a) > 3)
	{
		if (loop < 5)
			tmp.chunk_size = lst_len(env->a) / (10 - loop);
		initialize_chunk(env, tmp);
		while (env->set.chunk_size >= i)
		{
			divide_and_push(env, env->a, env->set.chunk_data);
			i++;
		}
		loop++;
		i = 1;
	}
	if (lst_len(env->a) == 3)
		sort_3(env);
	else if (lst_len(env->a) == 2)
		if (env->a->data < env->a->next->data)
			sa(env);
	push_to_a(env);
}

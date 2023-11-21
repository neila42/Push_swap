/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:02:33 by nmuminov          #+#    #+#             */
/*   Updated: 2023/04/20 15:35:54 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	optimize_sort(t_env *env)
{
	if (env->b->data == data_max(env->b))
		return (0);
	if (data_max(env->a) == get_last_data(env->a) && lst_len(env->b) != 2)
	{
		pa(env);
		ra(env);
	}
	if (get_last_data(env->a) < env->b->data && lst_len(env->b) != 2)
	{
		pa(env);
		ra(env);
	}
	return (1);
}

void	push_to_a(t_env *env)
{
	while (env->b)
	{
		while (env->b->data != data_max(env->b) && lst_len(env->b) != 0)
		{
			optimize_sort(env);
			if (is_max_top_half(env->b) == 1)
				rrb(env);
			else if (is_max_top_half(env->b) == 0)
				rb(env);
		}
		if (lst_len(env->b) >= 1)
			optimize_sort(env);
		while (get_last_data(env->a) > env->b->data && get_last_data(env->a)
			!= 2147483647 && get_last_data(env->a) != data_max(env->a))
			rra(env);
		pa(env);
	}
	while (get_last_data(env->a) != data_max(env->a))
		rra(env);
}

void	sort_stack(t_env *env)
{
	int	model;

	model = sort_case(env);
	if (model == 0)
		sort_3(env);
	if (model == 5)
		if (env->a->data > env->a->next->data)
			sa(env);
	if (model == 1)
		sort_5(env);
	if (model == 3)
		sort_100(env);
	if (model == 4)
		sort_500(env);
}

int	sort_case(t_env *env)
{
	int	size;
	int	sort_case;

	size = lst_len(env->a);
	if (size == 5)
		sort_case = 1;
	else if (size == 3)
		sort_case = 0;
	else if ((size >= 6 && size <= 300) || size == 4)
		sort_case = 3;
	else if (size >= 301)
		sort_case = 4;
	else if (size == 2)
		sort_case = 5;
	else
		return (-1);
	return (sort_case);
}

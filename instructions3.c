/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:06:12 by nmuminov          #+#    #+#             */
/*   Updated: 2023/04/20 15:36:01 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_env *env)
{
	t_list_nb	*tmp;
	t_list_nb	*old_head;
	t_list_nb	*new_last;

	if (!env->a || lst_len(env->a) == 1)
		return ;
	tmp = env->a;
	old_head = env->a;
	while (tmp->next)
	{
		new_last = tmp;
		tmp = tmp->next;
	}
	ft_lst_add_front(&env->a, tmp);
	tmp->next = old_head;
	new_last->next = NULL;
	env->action++;
	write(1, "rra\n", 4);
}

void	rrb(t_env *env)
{
	t_list_nb	*tmp;
	t_list_nb	*old_head;
	t_list_nb	*new_last;

	if (!env->b || lst_len(env->b) == 1)
		return ;
	tmp = env->b;
	old_head = env->b;
	while (tmp->next)
	{
		new_last = tmp;
		tmp = tmp->next;
	}
	ft_lst_add_front(&env->b, tmp);
	tmp->next = old_head;
	new_last->next = NULL;
	env->action++;
	write(1, "rrb\n", 4);
}

void	rrr(t_env *env)
{
	rra(env);
	rrb(env);
	env->action++;
	write(1, "rrr\n", 4);
}

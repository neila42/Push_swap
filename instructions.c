/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:06:41 by nmuminov          #+#    #+#             */
/*   Updated: 2023/04/20 15:35:57 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_env *env)
{
	int			nex;
	int			cur;
	t_list_nb	*tmp;

	if (!env->a || lst_len(env->a) == 1)
		return ;
	tmp = env->a;
	nex = tmp->data;
	cur = tmp->next->data;
	env->a->data = cur;
	env->a->next->data = nex;
	env->action++;
	write(1, "sa\n", 3);
}

void	sb(t_env *env)
{
	int			nex;
	int			cur;
	t_list_nb	*tmp;

	if (!env->b || lst_len(env->b) == 1)
		return ;
	tmp = env->b;
	nex = tmp->data;
	cur = tmp->next->data;
	env->b->data = cur;
	env->b->next->data = nex;
	env->action++;
	write(1, "sb\n", 3);
}

void	rb(t_env *env)
{
	t_list_nb	*tmp;

	if (!env->b || lst_len(env->b) == 1)
		return ;
	tmp = env->b;
	tmp = tmp->next;
	env->b->next = NULL;
	ft_lst_add_back(&tmp, env->b);
	env->b = tmp;
	env->action++;
	write(1, "rb\n", 3);
}

void	ra(t_env *env)
{
	t_list_nb	*tmp;

	if (!env->a || lst_len(env->a) == 1)
		return ;
	tmp = env->a;
	tmp = tmp->next;
	env->a->next = NULL;
	ft_lst_add_back(&tmp, env->a);
	env->a = tmp;
	env->action++;
	write(1, "ra\n", 3);
}

void	rr(t_env *env)
{
	ra(env);
	rb(env);
	write(1, "rr\n", 3);
}

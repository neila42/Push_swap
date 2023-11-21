/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:05:58 by nmuminov          #+#    #+#             */
/*   Updated: 2023/04/20 15:36:00 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_env *env)
{
	sa(env);
	sb(env);
	env->action++;
}

void	pb(t_env *env)
{
	t_list_nb	*tmp;

	tmp = env->a;
	env->a = env->a->next;
	ft_lst_add_front(&env->b, tmp);
	env->action++;
	write(1, "pb\n", 3);
}

void	pa(t_env *env)
{
	t_list_nb	*tmp;

	tmp = env->b;
	env->b = env->b->next;
	ft_lst_add_front(&env->a, tmp);
	env->action++;
	write(1, "pa\n", 3);
}

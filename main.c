/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:03:27 by nmuminov          #+#    #+#             */
/*   Updated: 2023/04/24 12:13:12 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_env	env;
	char	**split_av;

	if (ac < 2)
		return (0);
	handle_error(ac, av);
	if (ac == 2)
	{
		split_av = ft_split(av[1], ' ');
		env.a = create_pile(split_av, 0);
		env.b = NULL;
		free_tab(split_av);
	}
	if (ac > 2)
	{
		env.a = create_pile(av + 1, 0);
		env.b = NULL;
	}
	if (!is_sorted(&env))
		exit(0);
	initialize_chunk(&env, env.set);
	sort_stack(&env);
	free_list(env.a);
	free_list(env.b);
	return (0);
}

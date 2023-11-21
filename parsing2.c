/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:04:36 by nmuminov          #+#    #+#             */
/*   Updated: 2023/04/27 12:47:55 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit_and_duplicates(char **av)
{
	if (contains_only_digits(av))
		error();
	if (check_for_duplicates(av))
		error();
	return (0);
}

int	handle_error(int ac, char **av)
{
	char	*tmp;

	if (ac == 1)
		error ();
	else if (ac == 2)
	{
		if (!av[1][0])
			error();
		tmp = ft_strjoin("./pushswap ", av[1]);
		check_digit_and_duplicates(ft_split(tmp, ' '));
	}
	else if (ac > 2)
		check_digit_and_duplicates(av);
	return (0);
}

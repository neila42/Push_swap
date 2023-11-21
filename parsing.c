/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:03:42 by nmuminov          #+#    #+#             */
/*   Updated: 2023/04/27 12:47:52 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	contains_only_digits(char **av)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	while (av[i])
	{
		if (av[i][k] == '-')
			k++;
		if (av[i][k] == '\0')
			return (1);
		while (av[i][k])
		{
			if (av[i][k] <= '9' && av[i][k] >= '0')
				k++;
			else
				return (1);
		}
		k = 0;
		i++;
	}
	return (0);
}

int	check_for_duplicates(char **av)
{
	int	k;
	int	i;
	int	l;

	i = 1;
	k = 1;
	l = 0;
	while (av[1 + l])
	{
		while (av[1 + l] && av[k + i])
		{
			if (ft_intcmp(ft_atoi(av[1 + l]), ft_atoi(av[k + i])))
				return (1);
			else
				i++;
		}
		l++;
		k++;
		i = 1;
	}
	return (0);
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	ft_intcmp(int a, int b)
{
	if (a == b)
		return (1);
	return (0);
}

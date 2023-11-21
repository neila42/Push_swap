/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:35:41 by nmuminov          #+#    #+#             */
/*   Updated: 2023/04/20 15:36:16 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

# define ERROR "Error\n"

# define RRA 2134
# define RA 3212

typedef struct s_list_nb {
	int					data;
	struct s_list_nb	*next;
}				t_list_nb;

typedef struct s_setup {
	int	chunk_data;
	int	pivot;
	int	chunk_size;
}				t_setup;

typedef struct s_env {
	t_list_nb	*a;
	t_list_nb	*b;
	int			action;
	t_setup		set;
}				t_env;

typedef struct s_min_info {
	int	save;
	int	count;
}				t_min_info;

int					handle_error(int ac, char **av);
int					check_for_duplicates(char **av);
int					ft_intcmp(int a, int b);
int					contains_only_digits(char **av);
int					min_max_check(char **av);
void				error(void);
int					check_digit_and_duplicates(char **av);
void				free_tab(char **split);
int					is_sorted(t_env *env);
t_list_nb			*add_at(t_list_nb *l, int data, int pos);
t_list_nb			*create_empty_list(void);
void				free_list(t_list_nb *l);
int					is_empty_list(t_list_nb *l);
t_list_nb			*create_list(int data);
void				print_list(t_list_nb *l);
t_list_nb			*create_pile(char **av, int a);
t_list_nb			*ft_lst_new(int content);
void				ft_lst_add_back(t_list_nb **lst, t_list_nb *new);
t_list_nb			*ft_lst_last(t_list_nb *lst);
void				ft_lst_add_front(t_list_nb **lst, t_list_nb *new);
int					lst_len(t_list_nb *list);
void				sa(t_env *env);
void				sb(t_env *env);
void				ss(t_env *env);
void				pa(t_env *env);
void				pb(t_env *env);
void				rrr(t_env *env);
void				rr(t_env *env);
void				ra(t_env *env);
void				rra(t_env *env);
void				rb(t_env *env);
void				rrb(t_env *env);
int					x_min(t_list_nb *list, int x);
int					secund_min(t_list_nb *pile, int first_min);
int					min_data(t_list_nb *pile, int min);
void				divide_and_push(t_env *env, t_list_nb *l, int range);
void				push_to_b(t_env *env, int data, int type);
void				initialize_chunk(t_env *env, t_setup chunk_size);
int					data_max(t_list_nb *pile);
int					data_max_utils(t_list_nb *pile, int data);
int					lst_len_modified(t_list_nb *list);
int					is_max_top_half(t_list_nb *pile);
int					get_last_data(t_list_nb *pile);
void				push_to_a(t_env *env);
int					optimize_sort(t_env *env);
void				sort_stack(t_env *env);
int					sort_case(t_env *env);
void				sort_3(t_env *env);
void				sort_5(t_env *env);
void				sort_100(t_env *env);
void				sort_500(t_env *env);

#endif

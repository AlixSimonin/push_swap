/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:11:12 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/12 17:03:49 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "srcs/get_next_line.h"

typedef struct s_stack
{
	int				content;
	int				index;
	int				pos;
	struct s_stack	*next;
}	t_stack;

typedef struct s_tabs
{
	int		*tab_int;
	char	**pars_arg;
	t_stack	*top_a;
	t_stack	*top_b;
	t_stack	*bottom_a;
	t_stack	*bottom_b;
	int		size_tab;
	int		size_a;
	int		size_b;
	int		max_a;
	int		max_b;
	int		min_a;
	int		min_b;
	int		cost_a;
	int		cost_b;
	int		best_cost_a;
	int		best_cost_b;
	int		tot_cost;
}	t_tabs;

void	init(t_tabs *var);
void	print_error(t_tabs *var);
void	char_to_int(t_tabs *var);
void	free_all(t_tabs *var);
void	check_empty_quote(char **argv);
void	fill_stack(t_tabs *var);
void	ft_stack_add_back(t_tabs *var, int nbr);
void	display(t_stack *head);
void	free_stack(t_stack *lst);
void	size(t_tabs *var);
void	min_max_a(t_tabs *var);
void	min_max_b(t_tabs *var);
void	sa(t_tabs *var, int nb);
void	sb(t_tabs *var, int nb);
void	ss(t_tabs *var, int nb);
void	pa(t_tabs *var, int nb);
void	pb(t_tabs *var, int nb);
void	ra(t_tabs *var, int nb);
void	rb(t_tabs *var, int nb);
void	rr(t_tabs *var, int nb);
void	rra(t_tabs *var, int nb);
void	rrb(t_tabs *var, int nb);
void	rrr(t_tabs *var, int nb);
void	is_sorted(t_tabs *var);
void	sort_int_tab(t_tabs *var);
void	which_sort(t_tabs *var);
void	sort_three(t_tabs *var);
void	sort_five(t_tabs *var);
void	big_sort(t_tabs *var);
void	get_cost(t_tabs *var);
void	get_pos(t_tabs *var);
void	get_index(t_tabs *var);
void	mvt(t_tabs *var, int best_cost_a, int best_cost_b);
void	mvt_suicide(t_tabs *var, int best_cost_a, int best_cost_b);
void	do_mvt(t_tabs *var, char *mvt);

int		main(int argc, char **argv);
int		amount_of_nbr(t_tabs *var);
int		is_number(char *argv);
int		check_if_zero(char *pars_arg);
int		good_arg(t_tabs *var);
int		no_doubles(t_tabs *var);
int		get_chunk(int size, int mult);
int		sup_nbr(t_tabs *var, int nbr);
int		cost(int size, int index);
int		tot_cost(t_tabs *var);
int		min_index(t_tabs *var);
int		max_index(t_tabs *var);

size_t	ft_strlen_pars(char *s);

t_stack	*ft_new_bloc(int nbr);
t_stack	*get_last(t_stack *head);
t_stack	*get_before_last(t_stack *head);

char	*ft_strjoin_pars(char *s1, char *s2, int nb);

char	**ft_parsing(int argc, char **argv, t_tabs *var);

#endif
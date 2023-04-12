/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:55:29 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/12 17:36:57 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	min_to_top(t_tabs *var)
{
	min_max_a(var);
	while (var->top_a->content != var->min_a)
		rra(var, 0);
}

void	big_sort(t_tabs *var)
{
	int	bot;
	int	size;

	size = var->size_a;
	bot = var->bottom_a->content;
	while (var->top_a->content != bot && var->size_a >= size / 2)
	{
		if (var->top_a->index <= size / 2)
			pb(var, 0);
		else
			ra(var, 0);
	}
	while (var->size_a > 3)
		pb(var, 0);
	sort_three(var);
	get_cost(var);
	min_to_top(var);
}

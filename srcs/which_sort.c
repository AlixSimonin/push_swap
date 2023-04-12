/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:06:01 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/12 17:01:30 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	which_sort(t_tabs *var)
{
	if (var->size_tab <= 3)
		sort_three(var);
	else if (var->size_tab <= 5)
		sort_five(var);
	else
		big_sort(var);
}

void	sort_three(t_tabs *var)
{
	int	top;
	int	mid;
	int	bot;

	top = var->top_a->content;
	mid = var->top_a->next->content;
	bot = var->bottom_a->content;
	if ((top > mid && mid < bot && top < bot) || mid == bot)
		sa(var, 0);
	else if (top > mid && mid < bot && bot < top)
		ra(var, 0);
	else if (top < mid && mid > bot && top > bot)
		rra(var, 0);
	else if (top > mid && mid > bot && top > bot)
	{
		sa(var, 0);
		rra(var, 0);
	}
	else if (top < mid && mid > bot && top < bot)
	{
		sa(var, 0);
		ra(var, 0);
	}
}

void	sort_five(t_tabs *var)
{
	while (var->size_a > 3)
	{
		if (var->top_a->content == var->max_a
			|| var->top_a->content == var->min_a)
			pb(var, 0);
		else
			ra(var, 0);
	}
	sort_three(var);
	while (var->top_b != NULL)
	{
		if (var->top_b->content == var->max_a)
		{
			pa(var, 0);
			ra(var, 0);
		}
		else if (var->top_b->content == var->min_a)
			pa(var, 0);
	}
}

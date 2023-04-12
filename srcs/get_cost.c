/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:55:58 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/12 17:02:24 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	cost(int size, int index)
{
	int	cost;

	if (index > size / 2)
		cost = size - index;
	else
		cost = -index;
	return (cost);
}

int	tot_cost(t_tabs *var)
{
	int	a;
	int	b;

	if (var->cost_a < 0)
		a = var->cost_a * -1;
	else
		a = var->cost_a;
	if (var->cost_b < 0)
		b = var->cost_b * -1;
	else
		b = var->cost_b;
	if ((var->cost_a < 0 && var->cost_b < 0)
		|| (var->cost_a > 0 && var->cost_a > 0))
	{
		if (a >= b)
			return (a);
		else
			return (b);
	}
	return (a + b);
}

void	mvt_suicide(t_tabs *var, int best_cost_a, int best_cost_b)
{
	while (best_cost_a < 0)
	{
		if (best_cost_b < 0)
		{
			rr(var, 0);
			best_cost_b++;
		}
		else
			ra(var, 0);
		best_cost_a++;
	}
	while (best_cost_b < 0)
	{
		rb(var, 0);
		best_cost_b++;
	}
	pa(var, 0);
}

void	mvt(t_tabs *var, int best_cost_a, int best_cost_b)
{
	while (best_cost_a > 0)
	{
		if (best_cost_b > 0)
		{
			rrr(var, 0);
			best_cost_b--;
		}
		else
			rra(var, 0);
		best_cost_a--;
	}
	while (best_cost_b > 0)
	{
		rrb(var, 0);
		best_cost_b--;
	}
	mvt_suicide(var, best_cost_a, best_cost_b);
}

void	get_cost(t_tabs *var)
{
	int		max;
	int		i;
	t_stack	*temp;

	while (var->size_b != 0)
	{
		i = -1;
		max = 2147483647;
		temp = var->top_b;
		while (++i < var->size_b)
		{
			var->cost_a = cost(var->size_a, sup_nbr(var, temp->content));
			var->cost_b = cost(var->size_b, i);
			var->tot_cost = tot_cost(var);
			if (max > var->tot_cost)
			{
				max = var->tot_cost;
				var->best_cost_b = var->cost_b;
				var->best_cost_a = var->cost_a;
			}
			temp = temp->next;
		}
		mvt(var, var->best_cost_a, var->best_cost_b);
	}
}

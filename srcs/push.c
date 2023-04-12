/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:58:03 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/12 17:00:41 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_tabs *var, int nb)
{
	t_stack	*new_top_a;

	if (var->size_b == 0)
		return ;
	else
	{
		new_top_a = var->top_b;
		var->top_b = var->top_b->next;
		new_top_a->next = var->top_a;
		var->top_a = new_top_a;
	}
	var->size_a += 1;
	var->size_b -= 1;
	if (nb == 0)
		ft_printf("pa\n");
}

void	pb(t_tabs *var, int nb)
{
	t_stack	*new_top_b;

	if (var->size_a == 0)
		return ;
	else
	{
		new_top_b = var->top_a;
		var->top_a = var->top_a->next;
		new_top_b->next = var->top_b;
		var->top_b = new_top_b;
	}
	var->size_a -= 1;
	var->size_b += 1;
	if (nb == 0)
		ft_printf("pb\n");
}

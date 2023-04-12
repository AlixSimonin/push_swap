/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:05:18 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/12 17:18:28 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_tabs *var,	int nb)
{
	t_stack	*newtop;

	if (var->size_a < 2)
		return ;
	else if (var->size_a == 2)
	{
		newtop = var->bottom_a;
		var->top_a->next = NULL;
		newtop->next = var->top_a;
		var->bottom_a = var->top_a;
		var->top_a = newtop;
	}
	else
	{
		newtop = var->top_a->next;
		var->top_a->next = var->top_a->next->next;
		newtop->next = var->top_a;
		var->top_a = newtop;
	}
	if (nb == 0)
		ft_printf("sa\n");
}

void	sb(t_tabs *var, int nb)
{
	t_stack	*newtop;

	if (var->size_b < 2)
		return ;
	else if (var->size_b == 2)
	{
		newtop = var->bottom_b;
		var->top_b->next = NULL;
		newtop->next = var->top_b;
		var->bottom_b = var->top_b;
		var->top_b = newtop;
	}
	else
	{
		newtop = var->top_b->next;
		var->top_b->next = var->top_b->next->next;
		newtop->next = var->top_b;
		var->top_b = newtop;
	}
	if (nb == 0)
		ft_printf("sb\n");
}

void	ss(t_tabs *var, int nb)
{
	sa(var, 1);
	sb(var, 1);
	if (nb == 0)
		ft_printf("ss\n");
}

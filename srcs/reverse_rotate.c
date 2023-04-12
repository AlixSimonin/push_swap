/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:05:58 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/12 19:24:56 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*get_before_last(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	while (temp->next->next != NULL)
		temp = temp->next;
	return (temp);
}

void	rra(t_tabs *var, int nb)
{
	t_stack	*newtop;

	if (var->size_a < 2)
		return ;
	newtop = var->bottom_a;
	var->bottom_a = get_before_last(var->top_a);
	var->bottom_a->next = NULL;
	newtop->next = var->top_a;
	var->top_a = newtop;
	if (nb == 0)
		ft_printf("rra\n");
}

void	rrb(t_tabs *var, int nb)
{
	t_stack	*temp;
	t_stack	*bot;
	t_stack	*before_bot;

	if (var->size_b < 2)
		return ;
	bot = get_last(var->top_b);
	before_bot = get_before_last(var->top_b);
	temp = var->top_b;
	var->top_b = bot;
	var->top_b->next = temp;
	before_bot->next = NULL;
	if (nb == 0)
		ft_printf("rrb\n");
}

void	rrr(t_tabs *var, int nb)
{
	rra(var, 1);
	rrb(var, 1);
	if (nb == 0)
		ft_printf("rrr\n");
}

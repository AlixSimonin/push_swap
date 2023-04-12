/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 06:13:59 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/12 19:24:33 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*get_last(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	ra(t_tabs *var, int nb)
{
	t_stack	*newtop;
	t_stack	*newbot;

	if (var->size_a < 2)
		return ;
	newtop = var->top_a->next;
	newbot = var->top_a;
	newbot->next = NULL;
	var->top_a = newtop;
	var->bottom_a->next = newbot;
	var->bottom_a = var->bottom_a->next;
	if (nb == 0)
		ft_printf("ra\n");
}

void	rb(t_tabs *var, int nb)
{
	t_stack	*temp;
	t_stack	*bot;

	if (var->size_b < 2)
		return ;
	temp = var->top_b;
	var->top_b = var->top_b->next;
	bot = get_last(var->top_b);
	temp->next = NULL;
	bot->next = temp;
	if (nb == 0)
		ft_printf("rb\n");
}

void	rr(t_tabs *var, int nb)
{
	ra(var, 1);
	rb(var, 1);
	if (nb == 0)
		ft_printf("rr\n");
}

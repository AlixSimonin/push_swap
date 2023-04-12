/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:55:34 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/11 16:35:31 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	is_sorted(t_tabs *var)
{
	t_stack	*temp;

	temp = var->top_a;
	while (temp->next != NULL && temp->content < temp->next->content)
		temp = temp->next;
	if (temp->next == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

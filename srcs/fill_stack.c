/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:23:39 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/11 16:35:43 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_new_bloc(int nbr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = nbr;
	new->next = NULL;
	return (new);
}

void	ft_stack_add_back(t_tabs *var, int nbr)
{
	t_stack	*temp;

	temp = ft_new_bloc(nbr);
	if (!temp)
		print_error(var);
	if (var -> top_a == NULL)
		var -> top_a = temp;
	else
		var -> bottom_a -> next = temp;
	var -> bottom_a = temp;
}

void	display(t_stack *head)
{
	if (head == NULL)
		ft_printf("NULL\n");
	else
	{
		ft_printf("%d\n", head->content);
		display(head->next);
	}
}

void	fill_stack(t_tabs *var)
{
	int	i;

	i = 0;
	while (i < var->size_tab)
	{
		ft_stack_add_back(var, var->tab_int[i]);
		i++;
	}
	var->top_b = NULL;
	var->bottom_b = NULL;
}

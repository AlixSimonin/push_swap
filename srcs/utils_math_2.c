/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 23:36:08 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/11 16:37:04 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	min_index(t_tabs *var)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = var->top_a;
	while (temp != NULL && temp-> content != var->min_a)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int	max_index(t_tabs *var)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = var->top_a;
	while (temp != NULL && temp-> content != var->max_a)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int	sup_nbr(t_tabs *var, int nbr)
{
	t_stack	*temp_a;
	int		i;
	int		tmp_max_a;

	temp_a = var->top_a;
	min_max_a(var);
	tmp_max_a = var->max_a;
	i = max_index(var);
	get_pos(var);
	if (nbr > var->max_a)
		return (min_index(var));
	while (temp_a != NULL)
	{
		if (temp_a->content > nbr && tmp_max_a > temp_a->content)
		{
			tmp_max_a = temp_a->content;
			i = temp_a->pos;
		}
		temp_a = temp_a->next;
	}
	return (i);
}

void	get_pos(t_tabs *var)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = var->top_a;
	while (temp != NULL)
	{
		temp->pos = i;
		temp = temp->next;
		i++;
	}
	i = 0;
	temp = var->top_b;
	while (temp != NULL)
	{
		temp->pos = i;
		temp = temp->next;
		i++;
	}
}

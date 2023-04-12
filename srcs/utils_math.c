/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:10:46 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/11 16:37:08 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_int_tab(t_tabs *var)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < var->size_tab -1)
	{
		j = i + 1;
		while (j < var->size_tab)
		{
			if (var->tab_int[i] > var->tab_int[j])
			{
				temp = var->tab_int[i];
				var->tab_int[i] = var->tab_int[j];
				var->tab_int[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	min_max_a(t_tabs *var)
{
	t_stack	*temp;

	temp = var->top_a;
	if (temp == NULL)
		return ;
	var->min_a = temp->content;
	var->max_a = temp->content;
	while (temp != NULL)
	{
		if (var->min_a > temp->content)
			var->min_a = temp->content;
		if (var->max_a < temp->content)
			var->max_a = temp->content;
		temp = temp->next;
	}
}

void	min_max_b(t_tabs *var)
{
	t_stack	*temp;

	temp = var->top_b;
	if (temp == NULL)
		return ;
	var->min_b = temp->content;
	var->max_b = temp->content;
	while (temp != NULL)
	{
		if (var->min_b > temp->content)
			var->min_b = temp->content;
		if (var->max_b < temp->content)
			var->max_b = temp->content;
		temp = temp->next;
	}
}

void	get_index(t_tabs *var)
{
	t_stack	*temp;
	int		i;
	int		j;

	i = 0;
	temp = var->top_a;
	sort_int_tab(var);
	while (temp != NULL)
	{
		j = 0;
		while (j < var->size_tab)
		{
			if (temp->content == var->tab_int[j])
				temp->index = i;
			else
				i++;
			j++;
		}
		i = 0;
		temp = temp->next;
	}
}

void	size(t_tabs *var)
{
	t_stack	*temp;

	var->size_a = 0;
	var->size_b = 0;
	temp = var->top_a;
	while (temp != NULL)
	{
		var->size_a++;
		temp = temp->next;
	}
	temp = var->top_b;
	while (temp != NULL)
	{
		var->size_b++;
		temp = temp->next;
	}
	min_max_a(var);
	min_max_b(var);
	get_index(var);
}

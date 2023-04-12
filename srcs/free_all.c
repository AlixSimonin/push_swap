/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:21:33 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/12 16:12:56 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_stack *lst)
{
	t_stack	*temp;

	while (lst != NULL)
	{
		temp = lst->next;
		free(lst);
		lst = temp;
	}
}

void	free_all(t_tabs *var)
{
	int	i;

	i = 0;
	free(var->tab_int);
	while (var->pars_arg[i])
	{
		free(var->pars_arg[i]);
		i++;
	}
	free(var->pars_arg);
	free_stack(var->top_a);
	free_stack(var->top_b);
}

void	print_error(t_tabs *var)
{
	write(2, "Error\n", 6);
	free_all(var);
	exit(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:50:10 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/11 16:35:22 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	char_to_int(t_tabs *var)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (var->pars_arg[len])
		len++;
	var->size_tab = len;
	var->tab_int = ft_calloc(len + 1, sizeof(int));
	while (var->pars_arg[i] != 0)
	{
		var->tab_int[i] = ft_atoi(var->pars_arg[i]);
		i++;
	}
	i = 0;
	while (i + 1 < var->size_tab && var->tab_int[i] < var->tab_int[i + 1])
		i++;
	if (i == var->size_tab - 1)
		print_error(var);
}

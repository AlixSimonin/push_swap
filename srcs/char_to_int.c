/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:50:10 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/12 18:51:30 by asimonin         ###   ########.fr       */
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
}

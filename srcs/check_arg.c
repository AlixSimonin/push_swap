/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:08:14 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/12 15:43:32 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_if_zero(char *pars_arg)
{
	int	i;

	i = 0;
	if (pars_arg[i] == '-' || pars_arg[i] == '+')
		i++;
	while (pars_arg[i] && pars_arg[i] == '0')
		i++;
	if (pars_arg[i] != '\0')
		return (0);
	return (1);
}

int	is_number(char *pars_arg)
{
	int	i;

	if (check_if_zero(pars_arg) == 0)
	{
		i = ft_atoi(pars_arg);
		if (i == 0)
			return (1);
	}
	return (0);
}

int	no_doubles(t_tabs *var)
{
	int	i;
	int	j;

	i = 0;
	while (var->tab_int[i])
	{
		j = i + 1;
		while (var->tab_int[j])
		{
			if (var->tab_int[i] == var->tab_int[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	good_arg(t_tabs *var)
{
	int	i;
	int	double_zero;

	i = 0;
	double_zero = 0;
	while (var->pars_arg[i])
	{
		if (is_number(var->pars_arg[i]) == 1)
			return (1);
		else
			double_zero += check_if_zero(var->pars_arg[i]);
		i++;
	}
	if (no_doubles(var) == 1 || double_zero > 1)
		return (1);
	return (0);
}

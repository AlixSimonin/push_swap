/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:28:26 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/12 19:23:27 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static
int	good_arg_tkt(t_tabs *var)
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

void	init(t_tabs *var)
{
	var->top_a = NULL;
	var->top_b = NULL;
}

int	main(int argc, char **argv)
{
	t_tabs	var;
	char	*mvt;

	ft_memset(&var, 0, sizeof(var));
	mvt = NULL;
	init(&var);
	var.pars_arg = ft_parsing(argc, argv, &var);
	char_to_int(&var);
	if (good_arg_tkt(&var) == 1)
		print_error(&var);
	fill_stack(&var);
	size(&var);
	mvt = get_next_line(0, 0);
	while (mvt != NULL)
	{
		do_mvt(&var, mvt);
		free (mvt);
		mvt = get_next_line(0, 0);
	}
	is_sorted(&var);
	free_all(&var);
	return (0);
}

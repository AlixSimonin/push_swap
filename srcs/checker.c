/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:28:26 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/12 16:51:12 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	if (good_arg(&var) == 1)
		print_error(&var);
	fill_stack(&var);
	size(&var);
	mvt = get_next_line(0);
	while (mvt != NULL)
	{
		do_mvt(&var, mvt);
		free (mvt);
		mvt = get_next_line(0);
	}
	is_sorted(&var);
	free_all(&var);
	return (0);
}

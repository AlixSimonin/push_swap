/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:24:56 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/12 17:23:37 by asimonin         ###   ########.fr       */
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

	ft_memset(&var, 0, sizeof(var));
	init(&var);
	var.pars_arg = ft_parsing(argc, argv, &var);
	char_to_int(&var);
	if (good_arg(&var) == 1)
		print_error(&var);
	fill_stack(&var);
	sort_int_tab(&var);
	size(&var);
	which_sort(&var);
	free_all(&var);
	return (0);
}

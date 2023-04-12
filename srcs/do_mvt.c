/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_mvt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:31:10 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/12 19:19:42 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	do_mvt_bis(t_tabs *var, char *mvt)
{
	if (ft_strcmp(mvt, "rra\n") == 0)
		rra(var, 1);
	else if (ft_strcmp(mvt, "rrb\n") == 0)
		rrb(var, 1);
	else if (ft_strcmp(mvt, "rrr\n") == 0)
		rrr(var, 1);
	else
	{
		get_next_line(1, 1);
		free(mvt);
		print_error(var);
	}
}

void	do_mvt(t_tabs *var, char *mvt)
{
	if (ft_strcmp(mvt, "sa\n") == 0)
		sa(var, 1);
	else if (ft_strcmp(mvt, "sb\n") == 0)
		sb(var, 1);
	else if (ft_strcmp(mvt, "ss\n") == 0)
		ss(var, 1);
	else if (ft_strcmp(mvt, "pa\n") == 0)
		pa(var, 1);
	else if (ft_strcmp(mvt, "pb\n") == 0)
		pb(var, 1);
	else if (ft_strcmp(mvt, "ra\n") == 0)
		ra(var, 1);
	else if (ft_strcmp(mvt, "rb\n") == 0)
		rb(var, 1);
	else if (ft_strcmp(mvt, "rr\n") == 0)
		rr(var, 1);
	else
		do_mvt_bis(var, mvt);
}

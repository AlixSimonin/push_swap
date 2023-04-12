/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:46:01 by asimonin          #+#    #+#             */
/*   Updated: 2022/11/11 18:12:52 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
			c -= 32;
	return (c);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%s\n",ft_toupper('c'));
	return (0);
}
*/

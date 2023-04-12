/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:20:36 by asimonin          #+#    #+#             */
/*   Updated: 2022/11/08 15:39:24 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
			c += 32;
	return (c);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_tolower(85));
	return (0);
}
*/

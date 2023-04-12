/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:03:29 by asimonin          #+#    #+#             */
/*   Updated: 2022/11/18 15:26:20 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
	}
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
	char str[] = "ouibaguetteaaaaaaaaaaaaaaumbhgjygloooolmaaaauytkhtfty";
	char src[] = "z";
	printf("%s\n", (char *)ft_memcpy(str, src, 1));

	printf("\n");
	printf("%s\n", (char *)memcpy(str, src, 1));
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:00:01 by asimonin          #+#    #+#             */
/*   Updated: 2022/11/15 17:11:39 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	int		i;
	void	*str;

	if (size > SIZE_MAX / nmemb)
		return (NULL);
	if (size == 0 || nmemb == 0)
		return (malloc(0));
	i = nmemb * size;
	str = malloc(i);
	if (!str)
		return (NULL);
	ft_bzero (str, i);
	return (str);
}

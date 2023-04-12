/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:44:45 by asimonin          #+#    #+#             */
/*   Updated: 2022/11/14 18:41:10 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	len2;

	i = 0;
	len2 = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		len2 = 0;
	else if (len < len2)
		len2 = len;
	str = malloc (sizeof (char) * (len2 + 1));
	if (!str)
		return (NULL);
	while (i < len2 && s[start])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

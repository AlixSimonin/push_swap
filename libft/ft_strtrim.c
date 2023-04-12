/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:49:38 by asimonin          #+#    #+#             */
/*   Updated: 2022/11/18 15:34:21 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		else
			i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_isset(s1[start], set))
		start++;
	while (end > start && ft_isset(s1[end], set))
		end--;
	str = malloc(sizeof(char) * (end - start + 2));
	if (!str)
		return (NULL);
	while (start <= end)
	{
		str[i] = s1[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

// #include <stdio.h>

// int	main()
// {
// 	char s1[] = " lorem ipsum dolor sit amet";
// 	printf("%s\n", ft_strtrim(s1, "tel"));
// }
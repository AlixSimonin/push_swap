/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:54:25 by asimonin          #+#    #+#             */
/*   Updated: 2023/02/04 00:54:34 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_int_len(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*printf_itoa(int n)
{
	long int	nbr;
	int			len;
	char		*str;
	int			end;

	end = 0;
	nbr = (long int)n;
	len = ft_int_len(nbr);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr < 0)
	{
		str[end] = '-';
		nbr *= -1;
		end++;
	}
	while (len > end)
	{
		str[len - 1] = (nbr % 10) + 48;
		nbr /= 10;
		len--;
	}
	return (str);
}

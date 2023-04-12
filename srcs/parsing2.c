/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:11:31 by asimonin          #+#    #+#             */
/*   Updated: 2023/04/12 15:42:25 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2, int nb)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen_gnl(s1) + ft_strlen_gnl(s2)] = '\0';
	if (nb == 1)
		free(s1);
	return (str);
}

void	check_empty_quote(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] == ' ')
			j++;
		if (argv[i][j] == '\0')
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

char	**ft_parsing(int argc, char **argv, t_tabs *var)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 1;
	tmp = NULL;
	str = NULL;
	if (argc < 2)
		exit(1);
	check_empty_quote(argv);
	while (i < argc)
	{
		tmp = ft_strjoin_gnl(argv[i], " ", 0);
		str = ft_strjoin_gnl(str, tmp, 1);
		free(tmp);
		i++;
	}
	var->pars_arg = ft_split(str, ' ');
	free(str);
	return (var->pars_arg);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:45:36 by abourdar          #+#    #+#             */
/*   Updated: 2021/09/08 22:45:38 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub.h"

int	ft_atoi_cub(char *str, int *j)
{
	long		res;

	res = 0;
	while (str[*j] == ' ' || (str[*j] > 8 && str[*j] < 14))
		(*j)++;
	if (str[*j] == '-' || str[*j] == '+')
		return (0);
	while (str[*j] >= '0' && str[*j] <= '9')
	{
		res = res * 10 + str[*j] - '0';
		(*j)++;
	}
	return (res);
}

char	*ft_strdup_cub(t_map *map, char *s1, int *j)
{
	int		p;
	int		size;
	char	*dest;

	p = 0;
	size = ft_strlen(s1);
	dest = malloc_list(map, (size + 1) * sizeof(char));
	if (!(dest))
		return (0);
	while (s1[*j])
	{
		dest[p] = s1[*j];
		p++;
		(*j)++;
	}
	dest[p] = '\0';
	return (dest);
}

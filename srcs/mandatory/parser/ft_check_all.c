/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:45:09 by abourdar          #+#    #+#             */
/*   Updated: 2021/09/08 22:45:10 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub.h"

int	ft_check_ext(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i--] == 'm')
		if (str[i--] == 'p')
			if (str[i--] == 'x')
				if (str[i--] == '.')
					return (0);
	return (-3);
}

int	ft_init_path(t_map *map, char **path, char *str, int *j)
{
	int	fd;

	while (str[*j] == ' ')
		(*j)++;
	*path = ft_strdup_cub(map, str, j);
	map->tab->error = ft_check_ext(*path);
	fd = open((*path), O_RDONLY);
	if ((fd < 0))
		return (-3);
	close(fd);
	return (0);
}

int	check_texture(t_map *map, char **path, int *j, int *check)
{
	if (((map->str[*j] == 'N' || map->str[*j] == 'S')
			&& map->str[(*j) + 1] == 'O')
		|| (map->str[*j] == 'W' && map->str[(*j) + 1] == 'E')
		|| (map->str[*j] == 'E' && map->str[(*j) + 1] == 'A')
		|| (map->str[*j] == 'S' && map->str[(*j) + 1] == ' '))
	{
		(*j) += 2;
		map->tab->error = ft_init_path(map, path, map->str, j);
	}
	else
		return (-3);
	if (!map->tab->error)
		(*check)++;
	return (map->tab->error);
}

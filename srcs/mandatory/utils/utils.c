/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:47:10 by abourdar          #+#    #+#             */
/*   Updated: 2021/09/08 22:47:11 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub.h"

int	ft_strlen2(char **map, int y)
{
	int	x;
	int	l;

	x = 0;
	l = 0;
	while (map[y])
	{
		while (map[y][x])
			x++;
		x = 0;
		y++;
		l++;
	}
	return (l);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	get_nb_line(t_map *map, char *file)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	while (get_next_line(map, fd, &line) == 1)
	{
		map->tab->l++;
	}
	map->tab->l++;
	close (fd);
	return (1);
}

float	f_ternaire(float cond, float a, float b)
{
	if (cond)
		return (a);
	return (b);
}

int	ft_strlong(char **str, int i)
{
	int	j;
	int	size;

	size = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
			j++;
		if ((j + 1) > size)
			size = j + 1;
		i++;
	}
	return (size);
}

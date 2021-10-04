/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:47:29 by abourdar          #+#    #+#             */
/*   Updated: 2021/09/09 10:27:39 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

int	ft_error(t_map *map, int err_arg)
{
	if (map->tab->error == -1)
		printf("Error\nID missing");
	else if (map->tab->error == -2)
		printf("Error\nResolution is not appropriate\n");
	else if (map->tab->error == -3)
		printf("Error\nTextures are badly initialized\n");
	else if (map->tab->error == -4)
		printf("Error\nColors are badly initialized\n");
	else if (map->tab->error == -5)
		printf("Error\nWrong map");
	else if (map->tab->error == -6)
		printf("Error\nWrong arguments");
	else if (map->tab->error == -7)
		printf("Error\nFile can't be opened");
	else if (map->tab->error == -8)
		printf("Error\nMalloc failed");
	else if (err_arg == 1)
		printf("Error\nWrong arguments");
	else
		printf("Game finished\n");
	free_malloc_lst(map);
	free(map);
	exit (0);
}

int	ft_check_argv(char *map_name)
{
	int	i;

	i = ft_strlen(map_name) - 1;
	if (map_name[i--] == 'b')
		if (map_name[i--] == 'u')
			if (map_name[i--] == 'c')
				if (map_name[i--] == '.')
					return (1);
	return (0);
}

int	all_id(t_map *map)
{
	return (map->tab->so == 1 && map->tab->we == 1
		&& map->tab->no == 1 && map->tab->ea == 1
		&& map->tab->c == 1
		&& map->tab->f == 1);
}

void	init_parser(t_map *map, char *s, int fd)
{
	char	*line;
	int		ret;
	int		i;

	i = 0;
	ret = 1;
	get_nb_line(map, s);
	map->tab->pars = malloc_list(map, (sizeof(char *) * (map->tab->l + 1)));
	while (ret != 0 && !map->tab->error)
	{
		ret = get_next_line(map, fd, &line);
		map->tab->pars[i] = ft_strdup(map, line);
		map->tab->error = ft_parsing_cub(map->tab, map->tab->pars[i], map);
		if (all_id(map))
			if (map->tab->pars[i][0] == '1' || map->tab->pars[i][0] == ' ')
				map->num_row++;
		i++;
	}
	map->tab->pars[i] = NULL;
	close(fd);
	if (!map->tab->error)
		init_map_struc(map, map->tab->pars, (i - map->num_row));
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	map = malloc(sizeof(t_map));
	map->ptrs = NULL;
	if (map)
		init_struc(map);
	if (argc > 2 || (argc == 2 && !ft_check_argv(argv[1])) || fd == -1)
		ft_error(map, 1);
	init_parser(map, argv[1], fd);
	ft_error(map, 0);
}

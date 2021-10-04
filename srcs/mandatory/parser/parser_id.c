/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:45:25 by abourdar          #+#    #+#             */
/*   Updated: 2021/09/08 22:45:27 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub.h"

int	check_id(t_map *map, t_cub *tab, char *str, int *j)
{
	map->str = ft_strdup(map, str);
	if (tab->no == 0 && str[*j] == 'N')
		tab->error = check_texture(map, &tab->path_no, j, &tab->no);
	else if (tab->so == 0 && str[*j] == 'S' && str[(*j) + 1] == 'O')
		tab->error = check_texture(map, &tab->path_so, j, &tab->so);
	else if (tab->we == 0 && str[*j] == 'W')
		tab->error = check_texture(map, &tab->path_we, j, &tab->we);
	else if (tab->ea == 0 && str[*j] == 'E')
		tab->error = check_texture(map, &tab->path_ea, j, &tab->ea);
	else if (tab->f == 0 && str[*j] == 'F')
		tab->error = check_color(map->color, map->str, &tab->f, j);
	else if (tab->c == 0 && str[*j] == 'C')
		tab->error = check_color(map->color, map->str, &tab->c, j);
	else if (str[*j] == '\0')
		return (tab->error = 0);
	else
		return (tab->error = -1);
	return (tab->error);
}

int	ft_id(int c)
{	
	return (c == 'N' || c == 'S' || c == 'F' || c == 'C' || c == 'W'
		|| c == 'E' || c == '\0' || c == '1');
}

void	fill_txt(t_map *map, t_img *txts, char *path)
{
	txts->mlx_img = mlx_xpm_file_to_image(map->mlx_ptr, path,
			&txts->x, &txts->y);
	txts->addr = mlx_get_data_addr(txts->mlx_img, &txts->bpp, &txts->line_len,
			&txts->endian);
}

int	ft_parsing_cub(t_cub *tab, char *str, t_map *map)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	check_id(map, tab, str, &i);
	if (str[i] == '1' && all_id(map))
		return (0);
	return (tab->error);
}

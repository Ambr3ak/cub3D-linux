/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_calcules.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:44:43 by abourdar          #+#    #+#             */
/*   Updated: 2021/09/08 22:44:45 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub.h"

void	scale_calc(t_map *map)
{
	if (map->num_col > map->num_row)
		map->scale = 0.35 / map->num_col * 8;
	else
		map->scale = 0.35 / map->num_row * 8;
}

void	load_textures(t_cub *tab, t_map *map)
{
	int	i;

	i = 0;
	map->txtrs = malloc_list(map, (sizeof(t_img) * 5) + 1);
	fill_txt(map, &map->txtrs[0], tab->path_no);
	fill_txt(map, &map->txtrs[1], tab->path_so);
	fill_txt(map, &map->txtrs[2], tab->path_ea);
	fill_txt(map, &map->txtrs[3], tab->path_we);
}

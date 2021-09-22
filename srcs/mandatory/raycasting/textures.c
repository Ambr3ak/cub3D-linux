/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:46:40 by abourdar          #+#    #+#             */
/*   Updated: 2021/09/08 22:46:42 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub.h"

void	load_textures(t_cub *tab, t_map *map)
{
	int	i;

	i = 0;
	map->txtrs = malloc_list(map, (sizeof(t_img) * 4) + 1);
	fill_txt(map, &map->txtrs[0], tab->path_no);
	fill_txt(map, &map->txtrs[1], tab->path_so);
	fill_txt(map, &map->txtrs[2], tab->path_ea);
	fill_txt(map, &map->txtrs[3], tab->path_we);
}

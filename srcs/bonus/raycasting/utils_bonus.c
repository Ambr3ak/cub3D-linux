/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:44:50 by abourdar          #+#    #+#             */
/*   Updated: 2021/09/08 22:44:52 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub.h"

void	draw_tiles(int x, int y, t_map *map, int color)
{
	draw_rect(&map->img, (t_rect){x * map->scale,
		y * map->scale, map->tile_sz * map->scale,
		map->tile_sz * map->scale, color});
}

void	draw_transparency(t_map *map, int x, int y, int color)
{
	if (color != sp_pixel_get_color(&map->txtrs[4], 0, 0))
		img_pix_put(&map->img, x, y, color);
}

int	has_sprite_at(float x, float y, t_map *map)
{
	int	map_index_x;
	int	map_index_y;

	if (x < 0 || y < 0)
		return (FALSE);
	map_index_x = floor(x / map->tile_sz);
	map_index_y = floor(y / map->tile_sz);
	if (x >= map->num_col * map->tile_sz || y >= map->num_row * map->tile_sz)
		return (FALSE);
	return (map->map[map_index_y][map_index_x] == '2');
}

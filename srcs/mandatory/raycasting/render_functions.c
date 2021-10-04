/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:46:33 by abourdar          #+#    #+#             */
/*   Updated: 2021/09/08 22:46:34 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub.h"
#include "../../../inc/constants.h"

void	top_bottom_calc(t_map *map, int *top, int *bottom, int height)
{
	*top = (map->win_h / 2) - (height / 2);
	if (*top < 0)
		*top = 0;
	*bottom = (map->win_h / 2) + (height / 2);
	if (*bottom > map->win_h)
		*bottom = map->win_h;
}

void	draw_texture(t_map *map, t_recup *recup, int x, int y)
{
	if (!map->rays[recup->i].hit_vertical
		 && map->rays[recup->i].ray_up)
		img_pix_put(&map->img, recup->i, recup->y,
			 pixel_get_color(&map->txtrs[0], x, y));
	else if (!map->rays[recup->i].hit_vertical
		 && map->rays[recup->i].ray_down)
		img_pix_put(&map->img, recup->i, recup->y,
			 pixel_get_color(&map->txtrs[1], x, y));
	if (map->rays[recup->i].hit_vertical
		 && map->rays[recup->i].ray_right)
		img_pix_put(&map->img, recup->i, recup->y,
			 pixel_get_color(&map->txtrs[2], x, y));
	else if (map->rays[recup->i].hit_vertical
		 && map->rays[recup->i].ray_left)
		img_pix_put(&map->img, recup->i, recup->y,
			 pixel_get_color(&map->txtrs[3], x, y));
}

void	calc_texture_position(t_map *map, t_recup *recup, t_render *proj, int h)
{
	if (map->rays[recup->i].hit_vertical)
		proj->txt_off_x = (int)map->rays[recup->i].wall_hit_y % map->tile_sz;
	else
		proj->txt_off_x = (int)map->rays[recup->i].wall_hit_x % map->tile_sz;
	proj->step = 1.0 * TEX_H / h;
	proj->txt_position = (proj->w_top_y - map->win_h / 2 + h / 2) * proj->step;
	recup->y = proj->w_top_y;
	while (recup->y < proj->w_bottom_y)
	{
		proj->dist_top = recup->y + (h / 2) - (map->win_h / 2);
		proj->txt_y = (int)proj->txt_position & (map->txtrs[0].y - 1);
		proj->txt_position += proj->step;
		draw_texture(map, recup, proj->txt_off_x, proj->txt_y);
		recup->y ++;
	}
}

void	generate_proj(t_map *map, t_recup *recup)
{
	float	prj_wall_h;
	float	perp_distance;

	recup->i = 0;
	while (recup->i < map->num_rays)
	{
		perp_distance = map->rays[recup->i].distance
			 * cos(map->rays[recup->i].ray_angle - map->play->rot_angle);
		if (perp_distance == 0)
			perp_distance = 1;
		prj_wall_h = (map->tile_sz / perp_distance)
			 * map->play->dist_proj_plane;
		top_bottom_calc(map, &map->proj->w_top_y,
			 &map->proj->w_bottom_y,
			 (int)prj_wall_h);
		draw_sky_floor(map, map->proj->w_top_y, 0, map->color[0].color);
		calc_texture_position(map, recup, map->proj, (int)prj_wall_h);
		draw_sky_floor(map, map->win_h, map->proj->w_bottom_y,
			map->color[1].color);
		recup->i++;
	}
}

int	render(t_map *map)
{
	if (map->win_ptr == NULL)
		return (1);
	move_play(map);
	cast_all_rays(map);
	generate_proj(map, map->recup);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.mlx_img, 0, 0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:45:54 by abourdar          #+#    #+#             */
/*   Updated: 2021/09/08 22:45:55 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub.h"
#include "../../../inc/constants.h"

void	init_collision(t_map *map, int *stripId)
{
	map->tmp->horz_dist = f_ternaire(map->tmp->horz_found,
			distance_points(map->play->x, map->play->y, map->tmp->horz_hit_x,
				map->tmp->horzwall_hit_y), FLT_MAX);
	map->tmp->vert_hit = f_ternaire(map->tmp->vert_found,
			 distance_points(map->play->x, map->play->y, map->tmp->vert_hit_x,
				map->tmp->vertwall_hit_y), FLT_MAX);
	if (map->tmp->vert_hit < map->tmp->horz_dist)
	{
		map->rays[*stripId].distance = map->tmp->vert_hit;
		map->rays[*stripId].wall_hit_x = map->tmp->vert_hit_x;
		map->rays[*stripId].wall_hit_y = map->tmp->vertwall_hit_y;
		map->rays[*stripId].wall_hit = map->tmp->vert_content;
		map->rays[*stripId].hit_vertical = TRUE;
	}
	else
	{
		map->rays[*stripId].distance = map->tmp->horz_dist;
		map->rays[*stripId].wall_hit_x = map->tmp->horz_hit_x;
		map->rays[*stripId].wall_hit_y = map->tmp->horzwall_hit_y;
		map->rays[*stripId].wall_hit = map->tmp->horz_content;
		map->rays[*stripId].hit_vertical = FALSE;
	}
}

void	cast_all_rays(t_map *map)
{
	int		col;
	float	ray_angle;

	col = 0;
	while (col < map->num_rays)
	{
		ray_angle = map->play->rot_angle
			+ atan((col - map->num_rays / 2) / map->play->dist_proj_plane);
		norm_angle(&ray_angle);
		init_horizontal_content(map, ray_angle);
		init_vertical_content(map, ray_angle);
		init_collision(map, &col);
		map->rays[col].ray_angle = ray_angle;
		map->rays[col].ray_down = ray_down(ray_angle);
		map->rays[col].ray_up = ray_up(ray_angle);
		map->rays[col].ray_left = ray_left(ray_angle);
		map->rays[col].ray_right = ray_right(ray_angle);
		col++;
	}
	printf("ray distance %f\n", map->rays[col/2].distance);
}

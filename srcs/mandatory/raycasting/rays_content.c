/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:46:26 by abourdar          #+#    #+#             */
/*   Updated: 2021/09/08 22:46:27 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub.h"
#include "../../../inc/constants.h"

void	init_horizontal_content(t_map *map, float ray_angle)
{
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;

	yintercept = floor(map->play->y / map->tile_sz) * map->tile_sz;
	yintercept += f_ternaire(ray_down(ray_angle), map->tile_sz, 0);
	xintercept = map->play->x + (yintercept - map->play->y) / tan(ray_angle);
	ystep = map->tile_sz;
	ystep *= f_ternaire(ray_up(ray_angle), -1, 1);
	xstep = map->tile_sz / tan(ray_angle);
	xstep *= f_ternaire((ray_left(ray_angle) && xstep > 0), -1, 1);
	xstep *= f_ternaire((ray_right(ray_angle) && xstep < 0), -1, 1);
	map->tmp->horz_hit_x = xintercept;
	map->tmp->horzwall_hit_y = yintercept;
	horz_map_content(map, ray_angle, &xstep, &ystep);
}

void	init_vertical_content(t_map *map, float ray_angle)
{
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;

	xintercept = floor(map->play->x / map->tile_sz) * map->tile_sz;
	xintercept += f_ternaire(ray_right(ray_angle), map->tile_sz, 0);
	yintercept = map->play->y + (xintercept - map->play->x) * tan(ray_angle);
	xstep = map->tile_sz;
	xstep *= f_ternaire(ray_left(ray_angle), -1, 1);
	ystep = map->tile_sz * tan(ray_angle);
	ystep *= f_ternaire((ray_up(ray_angle) && ystep > 0), -1, 1);
	ystep *= f_ternaire((ray_down(ray_angle) && ystep < 0), -1, 1);
	map->tmp->vert_hit_x = xintercept;
	map->tmp->vertwall_hit_y = yintercept;
	vert_map_content(map, ray_angle, &xstep, &ystep);
}

void	horz_map_content(t_map *map, float ray_angle, float *x, float *y)
{
	float	check_x;
	float	check_y;

	while (map->tmp->horz_hit_x >= 0 && map->tmp->horzwall_hit_y >= 0
		&& map->tmp->horz_hit_x <= (map->num_col * map->tile_sz)
		&& map->tmp->horzwall_hit_y <= (map->num_row * map->tile_sz))
	{
		check_x = map->tmp->horz_hit_x;
		check_y = map->tmp->horzwall_hit_y
			+ f_ternaire(ray_up(ray_angle), -1, 0);
		if (has_wall(check_x, check_y, map))
		{
			map->tmp->horz_content = map->map[(int)floor(check_y
					/ map->tile_sz)][(int)floor(check_x / map->tile_sz)];
			map->tmp->horz_found = TRUE;
			break ;
		}
		else
		{
			map->tmp->horz_hit_x += (*x);
			map->tmp->horzwall_hit_y += (*y);
		}
	}
}

void	vert_map_content(t_map *map, float ray_angle, float *x, float *y)
{
	float	check_x;
	float	check_y;

	while (map->tmp->vert_hit_x >= 0
		 && map->tmp->vertwall_hit_y >= 0
		 && map->tmp->vert_hit_x <= (map->num_col * map->tile_sz)
		 && map->tmp->vertwall_hit_y <= (map->num_row * map->tile_sz))
	{
		check_x = map->tmp->vert_hit_x
			+ f_ternaire(ray_left(ray_angle), -1, 0);
		check_y = map->tmp->vertwall_hit_y;
		if (has_wall(check_x, check_y, map))
		{
			map->tmp->vert_content = map->map[(int)floor(check_y
					/ map->tile_sz)][(int)floor(check_x / map->tile_sz)];
			map->tmp->vert_found = TRUE;
			break ;
		}
		else
		{
			map->tmp->vert_hit_x += (*x);
			map->tmp->vertwall_hit_y += (*y);
		}	
	}
}

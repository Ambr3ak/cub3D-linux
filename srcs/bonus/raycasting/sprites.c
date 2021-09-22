/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:44:31 by abourdar          #+#    #+#             */
/*   Updated: 2021/09/08 22:44:38 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub.h"

void	sorting_sprites(t_sprite *visible_sp, t_map *map)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = 0;
	while (i < map->nm_vsb_sp - 1)
	{
		j = i + 1;
		while (j < map->nm_vsb_sp)
		{
			if (visible_sp[i].distance < visible_sp[j].distance)
			{
				tmp = visible_sp[i];
				visible_sp[i] = visible_sp[j];
				visible_sp[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	draw_sprite(int x, int y, t_data *sp_data, t_map *map)
{
	while (x < sp_data->sprite_right_x)
	{
		y = sp_data->sprite_topy;
		sp_data->texel_w = (map->txtrs[4].x / sp_data->sprite_width);
		sp_data->offset_x = (x - sp_data->sprite_left_x) * sp_data->texel_w;
		while (y < sp_data->sprite_bottomy)
		{
			if (x > 0 && x < map->win_w && y > 0 && y < map->win_h)
			{
				sp_data->dist_top = y + (sp_data->sprite_height / 2);
				sp_data->dist_top -= (map->win_h / 2);
				sp_data->offset_y = sp_data->dist_top
					* (map->txtrs[4].y / sp_data->sprite_height);
				if (map->cur_sp.distance < map->rays[x].distance)
					draw_transparency(map, x, y,
						sp_pixel_get_color(&map->txtrs[4],
							sp_data->offset_x, sp_data->offset_y));
			}
			y++;
		}
		x++;
	}
}

void	show_vsb_sp(t_sprite *visible_sp, t_map *map)
{
	int			i;
	int			x;
	int			y;

	i = 0;
	y = 0;
	sorting_sprites(visible_sp, map);
	while (i < map->nm_vsb_sp)
	{
		map->cur_sp = visible_sp[i];
		sp_calc_width(map->sp_data, map->cur_sp, map);
		sp_display_calc(map->sp_data, map->cur_sp, map);
		x = map->sp_data->sprite_left_x;
		draw_sprite(x, y, map->sp_data, map);
		i++;
	}
}

void	angle_control(float *angle_sp_player, t_map *map, t_sprite *v_sp, int i)
{
	if (*angle_sp_player > PI)
		*angle_sp_player -= TWO_PI;
	if (*angle_sp_player < -PI)
		*angle_sp_player += TWO_PI;
	*angle_sp_player = fabs(*angle_sp_player);
	if (*angle_sp_player < (FOV_ANGLE / 2) + EPSILON)
	{
		map->sprite[i].visible = 1;
		map->sprite[i].angle = *angle_sp_player;
		map->sprite[i].distance = distance_points(map->sprite[i].x,
				map->sprite[i].y, map->play->x, map->play->y);
		v_sp[map->nm_vsb_sp] = map->sprite[i];
		map->nm_vsb_sp++;
	}
	else
		map->sprite[i].visible = 0;
}

void	show_sp_proj(t_map *map)
{
	t_sprite	*visible_sp;
	int			i;
	float		angle_sp_player;

	map->nm_vsb_sp = 0;
	i = -1;
	angle_sp_player = 0;
	visible_sp = malloc_list(map, sizeof(t_sprite) * map->num_sp);
	while (++i < map->num_sp)
	{
		angle_sp_player = map->play->rot_angle;
		angle_sp_player -= atan2(map->sprite[i].y - map->play->y,
				map->sprite[i].x - map->play->x);
		angle_control(&angle_sp_player, map, visible_sp, i);
	}
	show_vsb_sp(visible_sp, map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:44:26 by abourdar          #+#    #+#             */
/*   Updated: 2021/09/08 22:44:28 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub.h"

void	render_map(t_map *map)
{
	int	i;
	int	j;
	int	tyle_x;
	int	tyle_y;

	i = 0;
	scale_calc(map);
	while (i < map->num_row)
	{
		j = 0;
		while (j < map->num_col)
		{
			tyle_x = j * map->tile_sz;
			tyle_y = i * map->tile_sz;
			if (map->map[i][j] == '1' || map->map[i][j] == '3'
				|| map->map[i][j] == ' ')
				draw_tiles(tyle_x, tyle_y, map, DARK_PIXEL);
			else if (ft_strrchr("02NSWE", map->map[i][j]))
				draw_tiles(tyle_x, tyle_y, map, WHITE_PIXEL);
			j++;
		}
		i++;
	}
}

void	render_play(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->num_rays)
	{
		draw_line(&map->img,
			 (t_line){map->play->x * map->scale,
			 map->play->y * map->scale,
			 map->rays[i].wall_hit_x * map->scale,
			 map->rays[i].wall_hit_y * map->scale, RED_PIXEL, 0, 0});
		i++;
	}
	draw_rect(&map->img,
		(t_rect){map->play->x * map->scale,
		map->play->y * map->scale,
		map->play->width * map->scale,
		map->play->height * map->scale, RED_PIXEL});
}

int	render_bonus(t_map *map)
{
	if (map->win_ptr == NULL)
		return (1);
	move_play(map);
	cast_all_rays(map);
	generate_proj(map, map->recup);
	render_map(map);
	render_play(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.mlx_img, 0, 0);
	return (0);
}

void	draw_line(t_img *img, t_line line)
{
	int		j;
	int		i;
	int		steps;
	float	incx;
	float	incy;

	j = 0;
	i = 0;
	line.deltax = line.lenght_x - line.start_x;
	line.deltay = line.lenght_y - line.start_y;
	if (abs(line.deltax) > abs(line.deltay))
		steps = abs(line.deltax);
	else
		steps = abs(line.deltay);
	incx = line.deltax / (float)steps;
	incy = line.deltay / (float)steps;
	while (i < steps + 1)
	{
		img_pix_put(img, line.start_x, line.start_y, line.color);
		line.start_x += incx;
		line.start_y += incy;
		i++;
	}
}

int	draw_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = 0;
	while (i < rect.height + 1)
	{
		j = 0;
		while (j < rect.width + 1)
		{
			img_pix_put(img, j + rect.x, i + rect.y, rect.color);
			j++;
		}
		++i;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:44:21 by abourdar          #+#    #+#             */
/*   Updated: 2021/09/08 22:44:22 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub.h"

int	has_wall(float x, float y, t_map *map)
{
	int	map_grid_index_x;
	int	map_grid_index_y;

	if (x < 0 || y < 0)
		return (FALSE);
	map_grid_index_x = floor(x / map->tile_sz);
	map_grid_index_y = floor(y / map->tile_sz);
	if (x >= map->num_col * map->tile_sz || y >= map->num_row * map->tile_sz)
		return (FALSE);
	return (map->map[map_grid_index_y][map_grid_index_x] == '1');
}

void	move_play(t_map *map)
{
	float	move_step;
	float	new_player_x;
	float	new_player_y;

	map->play->rot_angle += map->play->turn_direct
		* map->play->turn_speed / 10;
	norm_angle(&map->play->rot_angle);
	move_step = map->play->walk_direct * map->play->turn_speed * 5;
	new_player_x = map->play->x + cos(map->play->rot_angle) * move_step;
	new_player_y = map->play->y + sin(map->play->rot_angle) * move_step;
	if (!has_wall(new_player_x, new_player_y, map))
	{
		map->play->x = new_player_x;
		map->play->y = new_player_y;
	}
}

int	initialize_win(t_map *map)
{
	map->mlx_ptr = mlx_init();
	if (map->mlx_ptr == NULL)
		return (FALSE);
	get_screen_size(map);
	map->win_ptr = mlx_new_window(map->mlx_ptr, map->win_w,
			map->win_h, "Rubik's Cub3D");
	if (map->win_ptr == NULL)
	{
		free(map->win_ptr);
		return (FALSE);
	}
	return (TRUE);
}

void	hooks(t_map *map)
{
	printf("Game is loaded\n");
	mlx_loop_hook(map->mlx_ptr, &render_bonus, map);
	mlx_hook(map->win_ptr, KeyPress, KeyPressMask, &handle_keypress, map);
	mlx_hook(map->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, map);
	mlx_hook(map->win_ptr, 33, 1L << 17, ft_exit, map);
	mlx_loop(map->mlx_ptr);
}

int	ft_raycasting(t_map *map, t_cub *tab)
{
	map->win_w = 900;
	map->win_h = 900;
	if (!(initialize_win(map)))
		return (-1);
	map->num_rays = map->win_w;
	map->rays = malloc_list(map, sizeof(t_rays) * map->num_rays);
	setup(map, map->play, map->tmp);
	load_textures(tab, map);
	hooks(map);
	mlx_destroy_image(map->mlx_ptr, map->img.mlx_img);
	mlx_destroy_display(map->mlx_ptr);
	free(map->mlx_ptr);
	return (0);
}

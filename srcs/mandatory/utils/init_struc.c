/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:47:00 by abourdar          #+#    #+#             */
/*   Updated: 2021/09/08 22:47:01 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub.h"

void	direction_player(t_map *map, t_play *play)
{
	if (map->tab->direction_player == 'N')
		play->rot_angle = -PI / 2;
	if (map->tab->direction_player == 'S')
		play->rot_angle = PI / 2;
	if (map->tab->direction_player == 'W')
		play->rot_angle = PI;
	if (map->tab->direction_player == 'E')
		play->rot_angle = PI * 2;
}

void	setup(t_map *map, t_play *play, t_tmp *tmp)
{
	play->x = map->pos_x * map->tile_sz;
	play->y = map->pos_y * map->tile_sz;
	play->width = 5;
	play->height = 5;
	play->turn_direct = 0;
	play->walk_direct = 0;
	direction_player(map, play);
	play->walk_speed = 100;
	play->turn_speed = 45 * (PI / 180);
	play->dist_proj_plane = ((map->win_w / 2) / tan(FOV_ANGLE / 2));
	map->img.mlx_img = mlx_new_image(map->mlx_ptr, map->win_w, map->win_h);
	map->img.addr = mlx_get_data_addr(map->img.mlx_img, &map->img.bpp,
			&map->img.line_len, &map->img.endian);
	tmp->horz_found = FALSE;
	tmp->horz_hit_x = 0;
	tmp->horzwall_hit_y = 0;
	tmp->horz_content = 0;
	tmp->vert_found = FALSE;
	tmp->vert_hit_x = 0;
	tmp->vertwall_hit_y = 0;
	tmp->vert_content = 0;
}

void	ft_malloc_struct(t_map *map)
{
	map->tmp = malloc_list(map, sizeof(t_tmp));
	map->recup = malloc_list(map, sizeof(t_recup));
	map->proj = malloc_list(map, sizeof(t_render));
	map->tab = malloc_list(map, sizeof(t_cub));
	map->play = malloc_list(map, sizeof(t_play));
	map->sp_data = malloc_list(map, sizeof(t_data));
	map->color = malloc_list(map, (sizeof(t_color) * 2) + 1);
	if (!map->tmp || !map->recup || !map->proj
		|| !map->tab || !map->play || !map->sp_data || !map->color)
		map->err = -8;
}

void	init_struc(t_map *map)
{
	ft_malloc_struct(map);
	map->tab->r = 0;
	map->tab->no = 0;
	map->tab->so = 0;
	map->tab->we = 0;
	map->tab->ea = 0;
	map->tab->sp = 0;
	map->tab->f = 0;
	map->tab->c = 0;
	map->tab->x = 0;
	map->tab->y = 0;
	map->tab->l = 0;
	map->color[0].r = 0;
	map->color[0].g = 0;
	map->color[0].b = 0;
	map->color[1].r = 0;
	map->color[1].g = 0;
	map->color[1].b = 0;
	map->tab->error = 0;
	map->num_row = 0;
	map->tile_sz = 64;
}

int	init_map_struc(t_map *map, char **str, int i)
{
	int	l;

	l = 0;
	map->num_col = ft_strlong(str, i);
	map->map = malloc_list(map, sizeof(char *) * (map->num_row + 1));
	if (!(map->map))
		return (0);
	while (l < map->num_row)
	{
		map->map[l] = ft_strdup_long(map, str[i], map->num_col);
		l++;
		i++;
	}
	map->map[l] = NULL;
	map->pos_x = 0;
	map->pos_y = 0;
	map->player = 0;
	map->num_sp = 0;
	map->tab->error = get_player_pos(map);
	if (!(map->tab->error))
		map->tab->error = ft_parse_map(map);
	return (1);
}

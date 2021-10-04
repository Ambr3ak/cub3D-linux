/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:22:56 by abourdar          #+#    #+#             */
/*   Updated: 2021/09/08 22:22:59 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include <limits.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# include "../mlx/mlx.h"
# include "constants.h"

# define BUFFER_SIZE 10

void	init_struc(t_map *map);
int		init_map_struc(t_map *map, char **str, int i);
void	setup(t_map *map, t_play *play, t_tmp *tmp);
int		all_id(t_map *map);

int		ft_strlen2(char **map, int y);
int		ft_strcmp(char *s1, char *s2);
int		get_nb_line(t_map *map, char *file);
float	f_ternaire(float cond, float a, float b);
int		ft_strlong(char **str, int i);
void	*malloc_list(t_map *map, int size);
void	*free_malloc_lst(t_map *map);

int		ft_get_color(char *str, int *i, t_color *color, int index);
int		check_color(t_color *color, char *str, int *check, int *j);
int		ft_atoi_color(char *str, int *i, int *res);
int		check_r(t_cub *tab, char *str, int *j);
int		check_texture(t_map *map, char **path, int *j, int *check);

int		get_player_pos(t_map *map);
int		ft_parse_map(t_map *map);

int		check_id(t_map *map, t_cub *tab, char *str, int *j);
int		ft_id(int c);
void	fill_txt(t_map *map, t_img *txts, char *path);
void	load_textures(t_cub *tab, t_map *map);
int		ft_parsing_cub(t_cub *tab, char *str, t_map *map);

int		ft_atoi_cub(char *str, int *j);
char	*ft_strdup_cub( t_map *map, char *s1, int *j);

void	cast_all_rays(t_map *map);

int		ft_exit(t_map *map);
int		handle_keypress(int keysym, t_map *map);
int		handle_keyrelease(int keysym, t_map *map);

int		has_wall(float x, float y, t_map *map);
void	move_play(t_map *map);
int		ft_raycasting(t_map *map, t_cub *tab);

void	init_horizontal_content(t_map *map, float ray_angle);
void	init_vertical_content(t_map *map, float ray_angle);
void	horz_map_content(t_map *map, float ray_angle, float *x, float *y);
void	vert_map_content(t_map *map, float ray_angle, float *x, float *y);

int		ray_up(float angle);
int		ray_down(float angle);
int		ray_left(float angle);
int		ray_right(float angle);

void	top_bottom_calc(t_map *map, int *top, int *bottom, int height);
int		render(t_map *map);
void	generate_proj(t_map *map, t_recup *recup);

void	img_pix_put(t_img *img, int x, int y, int color);
int		pixel_get_color(t_img *txtrs, int x, int y);
void	norm_angle(float *angle);
float	distance_points(float x1, float y1, float x2, float y2);

void	load_textures(t_cub *tab, t_map *map);

void	scale_calc(t_map *map);

void	draw_sky_floor(t_map *map, int size, int y, int color);

void	render_map(t_map *map);
void	render_play(t_map *map);
int		render_bonus(t_map *map);
void	draw_line(t_img *img, t_line line);
int		draw_rect(t_img *img, t_rect rect);

void	draw_tiles(int x, int y, t_map *map, int color);
void	draw_transparency(t_map *map, int x, int y, int color);

void	get_screen_size(t_map *map);

int		get_next_line(t_map *map, int fd, char **line);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(t_map *map, const char *s1);
char	*ft_strjoin(t_map *map, char *s1, char *s2);
int		ft_strlen(const char *s);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(t_map *map, char *s, unsigned int start, size_t len);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strdup_long(t_map *map, const char *s1, int size);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));

#endif

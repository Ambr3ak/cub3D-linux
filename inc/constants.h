/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:22:48 by abourdar          #+#    #+#             */
/*   Updated: 2021/09/08 22:22:51 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# define MLX_ERROR 1
# define RED_PIXEL 0xFF0000
# define WHITE_PIXEL 0xF8F8FF
# define DARK_PIXEL 0x000000
# define GREY_PIXEL 0x808080
# define MINI_MAP_SCALE_FACTOR 0.3
# define SIZE 1
# define FLT_MAX 3.402823e+38
# define EPSILON 0.2
# define FOV_ANGLE 1.04719755
# define PI 3.14159265
# define TWO_PI 6.28318530
# define FALSE 0
# define TRUE 1
# define TEX_H 64

typedef struct s_data
{
	float	texel_w;
	int		dist_top;
	int		offset_y;
	int		offset_x;
	float	perp_distance;
}				t_data;

typedef struct s_cub
{
	char	**pars;
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	int		no;
	int		so;
	int		r;
	int		we;
	int		ea;
	int		sp;
	int		f;
	int		c;
	int		x;
	int		y;
	int		l;
	int		error;
	char	direction_player;
}				t_cub;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	color;
}				t_color;

typedef struct s_img
{
	void	*mlx_img;
	void	*im1;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		*data;
	int		x;
	int		y;
}				t_img;

typedef struct s_line
{
	float	start_x;
	float	start_y;
	int		lenght_x;
	int		lenght_y;
	int		color;
	int		deltax;
	int		deltay;
}				t_line;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;

}				t_rect;

typedef struct s_ray
{
	float	ray_angle;
	float	wall_hit_x;
	float	wall_hit_y;
	float	distance;
	int		hit_vertical;
	int		ray_up;
	int		ray_down;
	int		ray_right;
	int		ray_left;
	int		wall_hit;
}				t_rays;

typedef struct s_tmp
{
	int		horz_found;
	float	horz_hit_x;
	float	horzwall_hit_y;
	int		horz_content;
	int		vert_found;
	float	vert_hit_x;
	float	vertwall_hit_y;
	int		vert_content;
	float	vert_hit;
	float	horz_dist;
}				t_tmp;

typedef struct s_recup
{
	int	i;
	int	y;
}				t_recup;

typedef struct s_render
{
	int		w_top_y;
	int		w_bottom_y;
	int		txt_off_x;
	int		dist_top;
	double	step;
	double	txt_position;
	int		txt_y;
}				t_render;

typedef struct s_play
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		turn_direct;
	int		walk_direct;
	float	rot_angle;
	float	walk_speed;
	float	turn_speed;
	float	dist_proj_plane;
}				t_play;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_map
{
	t_list		*ptrs;
	char		**map;
	int			tile_sz;
	int			win_w;
	int			win_h;
	int			num_rays;
	int			num_col;
	int			num_row;
	float		scale;
	char		*str;
	int			x;
	int			y;
	int			err;
	int			err_map;
	int			m;
	float		pos_x;
	float		pos_y;
	int			player;
	void		*mlx_ptr;
	void		*win_ptr;
	t_color		*color;
	t_img		img;
	t_img		*txtrs;
	t_play		*play;
	t_cub		*tab;
	t_rays		*rays;
	t_tmp		*tmp;
	t_recup		*recup;
	t_render	*proj;
}				t_map;

#endif

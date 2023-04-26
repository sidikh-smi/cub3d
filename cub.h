/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:30:49 by ebakchic          #+#    #+#             */
/*   Updated: 2023/04/15 10:11:04 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define BUFFER_SIZE 42

/////// KEYCODE ///////
# define ROTATE_LEFT	123
# define ROTATE_RIGHT	124
# define FORWARD		13
# define BACK			1
# define RIGHT			2
# define LEFT			0
# define RELOAD			15
/////// COLOR ///////
# define RED			0xFF0000
# define BLEU			0x00FFFF
# define WHITE			0xFFFFFF
# define BLACK			0x000000
# define GREEN			0x00FF00
# define ORANG			0xFFA500
# define PUR			0x800080
# define JD				0x62645d
# define GRAY			0xD3D3D3
/////// MACRO KEY ///////
# define KEYPRESS		2
# define KEYRELEASE		3
/////// SPEED ///////
# define MOVESPEED		2
# define ROTESPEED		0.05
/////// CALCUL ///////
# define IMGHEIGHT 25
# define IMGWIDTH 25
# define FOV 1.04719755
# define WINWIDTH 1280
# define WINHEIGHT 720
# define WALLHEIGHT 35

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

typedef struct s_color{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_vars{
	char				**map;
	int					j;
	int					*t;
	double				position;
	char				*path_so;
	char				*path_no;
	char				*path_we;
	char				*path_ea;
	t_color				*c_color;
	t_color				*f_color;
	int					c_r;
	int					c_g;
	int					c_b;
	int					f_r;
	int					f_g;
	int					f_b;
	int					color_c;
	int					color_f;
	int					x;
	int					y;
	unsigned long		max_lenght;
}	t_vars;

typedef struct s_anim
{
	int	rot_left;
	int	rot_right;
	int	rot_left_m;
	int	rot_right_m;
	int	forward;
	int	back;
	int	right;
	int	left;
	int	reload;
}	t_anim;

typedef struct s_calcul
{
	double	tmpx;
	double	tmpy;
	double	xp;
	double	yp;
	double	dp;
}	t_calcul;

typedef struct s_so
{
	char	*dst;
	int		hei;
	int		wid;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_so;

typedef struct s_no
{
	char	*dst;
	int		hei;
	int		wid;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_no;

typedef struct s_we
{
	char	*dst;
	int		hei;
	int		wid;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_we;

typedef struct s_ea
{
	char	*dst;
	int		hei;
	int		wid;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_ea;

typedef struct s_all
{
	char	*dst;
	int		hei;
	int		wid;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_all;

typedef struct s_img
{
	char	*dst;
	int		hei;
	int		wid;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_mini
{
	char	*dst;
	int		hei;
	int		wid;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_mini;

typedef struct s_list
{
	int		l;
	int		k;
	void	*tex;
	void	*tex2;
	void	*tex3;
	void	*tex4;
	void	*mini;
	char	**map;
	void	*mlx;
	void	*win;
	void	*img;
	char	**gun_path;
	void	**gun;
	void	*s;
	double	xp;
	double	yp;
	int		lenx;
	int		leny;
	double	ang;
	double	xr;
	double	yr;
	t_anim	*anim;
	t_vars	*d;
	t_ea	*ea;
	t_we	*we;
	t_no	*no;
	t_so	*so;
	t_all	*all;
	t_img	*ig;
	t_mini	*mn;
	double	wall_height;
	int		color;
	int		y2;
	int		i;
}	t_list;

int				ft_active_key(int keycode, t_anim *an);
int				ft_disable_key(int keycode, t_anim *an);
unsigned long	mlx_get_time(void);
void			ft_init(t_anim *an);
void			ft_init2(t_list *s, char **map, t_anim *an);
void			ft_run_game(t_list *s, char **map);
void			ft_rot_left_right(t_list *s);
void			ft_right_left(t_list *s);
void			ft_forward_back(t_list *s);
void			ft_render(t_list *s);
double			ft_calcul_dis(t_list *s, double ang);
char			**ft_add_map(int fd);
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_free_db(char **ptr);
void			ft_fill_map(t_list *s);
void			ft_put_pixel(t_list *s);
void			ft_put_player(t_list *s);
void			ft_move(int i, double x, double y, t_list *s);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *str);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strchr(const char *s, int c);
int				ft_manage_key(int k, t_list *s);
size_t			ft_strlen(const char *s);
void			ft_if_no_line(t_list *s, t_calcul *cal, double ang);
void			ft_if_no_line2(t_list *s, t_calcul *cal, double ang);
int				ft_check_wall(t_list *s, double x, double y, double ang);
int				ft_check_wall2(t_list *s, double x, double y, double ang);
void			ft_put_player(t_list *s);
void			ft_fill_map(t_list *s);
void			my_mlx_pixel_put(t_list *s, int x, int y, int color);
void			my_mlx_pixel_put3(t_list *s, int x, int y, int color);
unsigned int	ft_get_color(t_list *s, double y2);
void			ft_init_text(t_list *s, t_all *all, int x);
void			ft_check_dir(t_list *s, t_all *all, double ang);
void			ft_draw_map2(t_list *s, int y, int winheight, int color);
void			ft_draw(t_list *s);
void			path_texture(t_vars *s, char *c, char a, int i);
//////// parse /////////
int				isber(char *s);
void			error(char *s);
void			det_error(char *s, t_vars *d);
int				ft_strcmp(char *s1, char *s2);
size_t			ft_strlen(const char *s);
char			*get_next_line(int fd);
char			*read_file(int fd, char *str);
char			*new_line(char *str);
char			*ft_line(char *str);
void			check(t_vars *s, int fd);
void			components_cub(t_vars *h);
int				ft_size(char *e);
void			empty_map(char *s, t_vars *d);
void			check_walls(t_vars *d);
void			check_up_down(char *a, char *b);
void			position_player(t_vars *p);
void			trans_color(t_vars *p);
void			check_colors(t_vars *s, char *a, char c);
void			free_it(char **p);
void			ft_check_map(t_vars *s);			
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_atoi(const char *str);
void			lenght_line(t_vars *s);
void			check_p(t_vars *s);
void			textures(t_vars *s);
void			player_check(t_vars *s);
void			init(t_vars *s);			
void			path_north(int *t, int j, char *c, t_vars *s);
int				new_line_map(char *e);
void			check_line(char *h);
int				skip_space(int j, char *c);
void			path_south(int *t, int j, char *c, t_vars *s);
void			path_weast(int *t, int j, char *c, t_vars *s);
void			path_east(int *t, int j, char *c, t_vars *s);
void			check_texture(char *s);

#endif
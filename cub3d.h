/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:11:59 by skhaliff          #+#    #+#             */
/*   Updated: 2023/04/12 11:55:39 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define BUFFER_SIZE 42

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

int		isber(char *s);
void	error(char *s);
void	det_error(char *s, t_vars *d);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*read_file(int fd, char *str);
char	*new_line(char *str);
char	*ft_line(char *str);
void	check(t_vars *s, int fd);
void	components_cub(t_vars *h);
int		ft_size(char *e);
void	empty_map(char *s, t_vars *d);
void	check_walls(t_vars *d);
void	check_up_down(char *a, char *b);
void	position_player(t_vars *p);
void	trans_color(t_vars *p);
void	check_colors(t_vars *s, char *a, char c);
void	free_it(char **p);
void	ft_check_map(t_vars *s);
int		new_line_map(char *e);
void	check_p(t_vars *s);
void	lenght_line(t_vars *s);
void	player_check(t_vars *s);
void	check_line(char *h);
void	init(t_vars *s);
void	check_texture(char *s);
void	path_north(int *t, int j, char *c, t_vars *s);
int		skip_space(int j, char *c);
void	path_south(int *t, int j, char *c, t_vars *s);
void	path_weast(int *t, int j, char *c, t_vars *s);
void	path_east(int *t, int j, char *c, t_vars *s);
void	textures(t_vars *s);

#endif
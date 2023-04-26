/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:07:02 by ebakchic          #+#    #+#             */
/*   Updated: 2023/04/15 10:22:40 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	**ft_add_map(int fd)
{
	char	**map;
	char	*saver;
	char	*buff;
	int		rb;

	buff = ft_calloc(2, sizeof(char));
	if (!buff)
		return (NULL);
	saver = ft_strdup("");
	rb = 1;
	while (rb != 0)
	{
		rb = read(fd, buff, 1);
		if (rb == -1)
		{
			free(buff);
			return (NULL);
		}
		if (rb != 0)
			saver = ft_strjoin(saver, buff);
	}
	free(buff);
	map = ft_split(saver, '\n');
	free(saver);
	return (map);
}

void	ft_read_img(t_list *s)
{
	s->tex = mlx_xpm_file_to_image(s->mlx, s->d->path_so, \
	&s->so->wid, &s->so->hei);
	s->tex2 = mlx_xpm_file_to_image(s->mlx, s->d->path_no, \
	&s->no->wid, &s->no->hei);
	s->tex3 = mlx_xpm_file_to_image(s->mlx, s->d->path_we, \
	&s->we->wid, &s->we->hei);
	s->tex4 = mlx_xpm_file_to_image(s->mlx, s->d->path_ea, \
	&s->ea->wid, &s->ea->hei);
	if (s->tex == NULL || s->tex2 == NULL || s->tex3 == NULL || s->tex4 == NULL)
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	s->so->dst = mlx_get_data_addr(s->tex, &s->so->bits_per_pixel, \
	&s->so->size_line, &s->so->endian);
	s->no->dst = mlx_get_data_addr(s->tex2, &s->no->bits_per_pixel, \
	&s->no->size_line, &s->no->endian);
	s->we->dst = mlx_get_data_addr(s->tex3, &s->we->bits_per_pixel, \
	&s->we->size_line, &s->we->endian);
	s->ea->dst = mlx_get_data_addr(s->tex4, &s->ea->bits_per_pixel, \
	&s->ea->size_line, &s->ea->endian);
}

void	ft_init(t_anim *an)
{
	an->rot_left = 0;
	an->rot_left = 0;
	an->forward = 0;
	an->back = 0;
	an->right = 0;
	an->left = 0;
	an->reload = 0;
	an->rot_left_m = 0;
	an->rot_right_m = 0;
}

void	ft_init_gun(t_list *s)
{
	int		wid;
	int		hei;
	int		fd;
	int		i;

	fd = open("gun.txt", O_RDONLY);
	s->gun_path = ft_add_map(fd);
	close(fd);
	i = 0;
	while (s->gun_path[i])
		i++;
	s->gun = (void **)malloc(sizeof(void *) * (i + 1));
	i = 0;
	while (s->gun_path[i])
	{
		s->gun[i] = mlx_xpm_file_to_image(s->mlx, s->gun_path[i], &wid, &hei);
		if (s->gun[i] == NULL)
		{
			write(2, "Error\n", 6);
			exit (1);
		}
		i++;
	}
	s->gun[i] = NULL;
	ft_free_db(s->gun_path);
}

void	ft_init2(t_list *s, char **map, t_anim *an)
{
	s->l = 0;
	s->k = 84;
	s->map = map;
	s->mlx = mlx_init();
	s->leny = 0;
	while (map[s->leny])
		s->leny += 1;
	s->lenx = s->d->max_lenght;
	s->win = mlx_new_window(s->mlx, WINWIDTH, WINHEIGHT, "cub3D");
	s->img = mlx_new_image(s->mlx, WINWIDTH, WINHEIGHT);
	s->ig->dst = mlx_get_data_addr(s->img, &s->ig->bits_per_pixel, \
	&s->ig->size_line, &s->ig->endian);
	s->mini = mlx_new_image(s->mlx, s->lenx * 25, s->leny * 25);
	s->mn->dst = mlx_get_data_addr(s->mini, &s->mn->bits_per_pixel, \
	&s->mn->size_line, &s->mn->endian);
	ft_read_img(s);
	s->xp = s->d->y * IMGWIDTH;
	s->yp = (s->d->x - 6) * IMGHEIGHT;
	s->ang = s->d->position;
	s->anim = an;
	ft_init_gun(s);
}

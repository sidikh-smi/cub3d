/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:54:01 by ebakchic          #+#    #+#             */
/*   Updated: 2023/04/15 10:00:30 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(t_list *s, int x, int y, int color)
{
	int	offset;

	if (x >= 0 && x < WINWIDTH && y >= 0 && y < WINHEIGHT)
	{
		offset = y * s->mn->size_line + x * (s->mn->bits_per_pixel / 8);
		*(unsigned int *)(s->mn->dst + offset) = color;
	}
}

void	my_mlx_pixel_put3(t_list *s, int x, int y, int color)
{
	int	offset;

	if (x >= 0 && x < WINWIDTH && y >= 0 && y < WINHEIGHT)
	{
		offset = y * s->ig->size_line + x * (s->ig->bits_per_pixel / 8);
		*(unsigned int *)(s->ig->dst + offset) = color;
	}
}

void	ft_draw_fake3d(t_list *s, int a, int b, int x)
{
	s->y2 = (WINHEIGHT - s->wall_height) / 2;
	if (s->y2 < 0)
		s->y2 = 0;
	s->i = 0;
	if (x == 0)
	{
		while (s->i < s->wall_height)
		{
			s->color = ft_get_color(s, s->i);
			my_mlx_pixel_put3(s, b, s->y2, s->color);
			s->y2++;
			s->i++;
		}
	}
	else
	{
		while (s->i < s->wall_height)
		{
			s->color = ft_get_color(s, s->i);
			my_mlx_pixel_put3(s, a, s->y2, s->color);
			s->y2++;
			s->i++;
		}
	}
}

void	ft_draw_rays(t_list *s)
{
	t_all	all;
	double	ds;
	double	fov;
	int		a;
	int		b;

	a = 0;
	b = 1280;
	fov = FOV / 2;
	while (fov > 0)
	{
		ds = ft_calcul_dis(s, s->ang + fov);
		s->wall_height = (((WINHEIGHT) / ds) * WALLHEIGHT);
		ft_check_dir(s, &all, s->ang + fov);
		ft_draw_fake3d(s, a, b, 0);
		ds = ft_calcul_dis(s, s->ang - fov);
		s->wall_height = (((WINHEIGHT) / ds) * WALLHEIGHT);
		ft_check_dir(s, &all, s->ang - fov);
		ft_draw_fake3d(s, a, b, 1);
		fov -= 0.00081812308;
		a++;
		b--;
	}
}

void	ft_render(t_list *s)
{
	ft_draw_map2(s, 0, WINHEIGHT / 2, s->d->color_c);
	ft_draw_map2(s, 360, WINHEIGHT, s->d->color_f);
	ft_draw_rays(s);
	ft_fill_map(s);
	ft_put_player(s);
	ft_draw(s);
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
}

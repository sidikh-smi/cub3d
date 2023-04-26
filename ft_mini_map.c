/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:25:10 by ebakchic          #+#    #+#             */
/*   Updated: 2023/04/14 17:40:47 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_draw_ang(t_list *s)
{
	int		i;
	double	x;
	double	y;

	x = s->xp;
	y = s->yp;
	i = 0;
	while (i < 15)
	{
		my_mlx_pixel_put(s, (int)x, (int)y, RED);
		x += cos(s->ang);
		y += sin(s->ang);
		i++;
	}
}

void	ft_put_player(t_list *s)
{
	int		i;
	int		j;

	i = 0;
	while (i <= 4)
	{
		j = 0;
		while (j <= 4)
		{
			my_mlx_pixel_put(s, s->xp + j, s->yp + i, RED);
			my_mlx_pixel_put(s, s->xp - j, s->yp + i, RED);
			my_mlx_pixel_put(s, s->xp + j, s->yp - i, RED);
			my_mlx_pixel_put(s, s->xp - j, s->yp - i, RED);
			j++;
		}
		i++;
	}
	ft_draw_ang(s);
}

void	my_mlx_put_image_to_window(t_list *s, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < IMGHEIGHT - 1)
	{
		j = 0;
		while (j < IMGWIDTH - 1)
		{
			my_mlx_pixel_put(s, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	ft_draw_map(t_list *s)
{
	int	y;
	int	x;

	y = 0;
	while (y < s->leny * IMGHEIGHT)
	{
		x = 0;
		while (x < s->lenx * IMGWIDTH)
		{
			my_mlx_pixel_put(s, (int)x, (int)y, GRAY);
			x++;
		}
		y++;
	}
}

void	ft_fill_map(t_list *s)
{
	int	i;
	int	j;

	ft_draw_map(s);
	i = 0;
	while (s->map[i])
	{
		j = 0;
		while (s->map[i][j])
		{
			if (s->map[i][j] == '1')
				my_mlx_put_image_to_window(s, j * IMGWIDTH, \
				i * IMGHEIGHT, BLACK);
			j++;
		}
		i++;
	}
}

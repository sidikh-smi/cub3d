/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:41:27 by ebakchic          #+#    #+#             */
/*   Updated: 2023/04/14 17:17:16 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_if_no_line(t_list *s, t_calcul *cal, double ang)
{
	if (ft_check_wall(s, cal->xp, cal->yp, ang) == -1)
	{
		cal->xp = s->d->max_lenght * IMGHEIGHT * 2;
		cal->yp = s->leny * IMGHEIGHT * 2;
	}
}

void	ft_if_no_line2(t_list *s, t_calcul *cal, double ang)
{
	if (ft_check_wall2(s, cal->xp, cal->yp, ang) == -1)
	{
		cal->xp = s->d->max_lenght * IMGHEIGHT * 2;
		cal->yp = s->leny * IMGHEIGHT * 2;
	}
}

int	ft_get_data_color(t_list *s, int off, int yt)
{
	int		color;

	if (off < 0 || off >= s->lenx * 25 || yt < 0 || yt >= s->leny * 25)
		return (WHITE);
	color = *(unsigned int *)(s->mn->dst + (((yt * s->mn->size_line) \
	+ (off * (s->mn->bits_per_pixel / 8)))));
	return (color);
}

void	ft_draw(t_list *s)
{
	int		color;
	int		i;
	int		j;
	double	x;
	double	y;

	y = s->yp - 75;
	i = 0;
	while (i < 150)
	{
		x = s->xp - 150;
		j = 0;
		while (j < 300)
		{
			color = ft_get_data_color(s, x, y);
			my_mlx_pixel_put3(s, j, i, color);
			j++;
			x++;
		}
		i++;
		y++;
	}
}

void	ft_draw_map2(t_list *s, int y, int winheight, int color)
{
	int	x;

	while (y < winheight)
	{
		x = 0;
		while (x < WINWIDTH)
		{
			my_mlx_pixel_put3(s, (int)x, (int)y, color);
			x++;
		}
		y++;
	}
}

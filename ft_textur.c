/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:51:04 by ebakchic          #+#    #+#             */
/*   Updated: 2023/04/14 17:38:02 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

unsigned int	ft_get_color(t_list *s, double y2)
{
	int				off;
	int				yt;
	unsigned int	color;

		off = (s->xr + s->yr) * s->all->wid / IMGHEIGHT;
	if (off > s->all->wid)
		off = (int)off % s->all->wid;
	yt = 0;
	if (s->wall_height > WINHEIGHT)
		yt = (s->wall_height - WINHEIGHT) / 2;
	yt = yt * s->all->hei / s->wall_height;
	yt += y2 * s->all->hei / s->wall_height;
	if (yt >= s->all->hei)
		yt = yt % s->all->hei;
	color = *(unsigned int *)(s->all->dst + (((yt * s->all->size_line) \
	+ (off * (s->all->bits_per_pixel / 8)))));
	return (color);
}

void	ft_init_text2(t_list *s, t_all *all, int x)
{
	if (x == 2)
	{
		all->bits_per_pixel = s->so->bits_per_pixel;
		all->size_line = s->so->size_line;
		all->endian = s->so->endian;
		all->dst = s->so->dst;
		all->hei = s->so->hei;
		all->wid = s->so->wid;
	}
	else if (x == 3)
	{
		all->bits_per_pixel = s->no->bits_per_pixel;
		all->size_line = s->no->size_line;
		all->endian = s->no->endian;
		all->dst = s->no->dst;
		all->hei = s->no->hei;
		all->wid = s->no->wid;
	}
}

void	ft_init_text(t_list *s, t_all *all, int x)
{
	if (x == 0)
	{
		all->bits_per_pixel = s->ea->bits_per_pixel;
		all->size_line = s->ea->size_line;
		all->endian = s->ea->endian;
		all->dst = s->ea->dst;
		all->hei = s->ea->hei;
		all->wid = s->ea->wid;
	}
	else if (x == 1)
	{
		all->bits_per_pixel = s->we->bits_per_pixel;
		all->size_line = s->we->size_line;
		all->endian = s->we->endian;
		all->dst = s->we->dst;
		all->hei = s->we->hei;
		all->wid = s->we->wid;
	}
	else
		ft_init_text2(s, all, x);
}

void	ft_check_dir(t_list *s, t_all *all, double ang)
{
	if (s->map[(int)((s->yr) / IMGWIDTH)][(int)((s->xr - 1) \
	/ IMGWIDTH)] != '1' &&
			s->map[(int)((s->yr) / IMGWIDTH)][(int)((s->xr + 1) \
			/ IMGWIDTH)] == '1' &&
			(sin(ang) < 0 || sin(ang) >= 0) && (cos(ang) >= 0))
		ft_init_text(s, all, 0);
	else if (s->map[(int)((s->yr) / IMGWIDTH)][(int)((s->xr - 1) \
		/ IMGWIDTH)] == '1' &&
			s->map[(int)((s->yr) / IMGWIDTH)][(int)((s->xr + 1) \
			/ IMGWIDTH)] != '1' &&
			(sin(ang) < 0 || sin(ang) >= 0) && (cos(ang) < 0))
		ft_init_text(s, all, 1);
	else if (s->map[(int)((s->yr - 1) / IMGWIDTH)][(int)((s->xr) \
		/ IMGWIDTH)] != '1' &&
			s->map[(int)((s->yr + 1) / IMGWIDTH)][(int)((s->xr) \
			/ IMGWIDTH)] == '1' &&
			(cos(ang) < 0 || cos(ang) >= 0))
		ft_init_text(s, all, 2);
	else if (s->map[(int)((s->yr + 1) / IMGWIDTH)][(int)((s->xr) \
		/ IMGWIDTH)] != '1' &&
		s->map[(int)((s->yr - 1) / IMGWIDTH)][(int)((s->xr) \
		/ IMGWIDTH)] == '1' &&
			(cos(ang) < 0 || cos(ang) >= 0))
		ft_init_text(s, all, 3);
		s->all = all;
}

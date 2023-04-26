/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:52:15 by ebakchic          #+#    #+#             */
/*   Updated: 2023/04/14 16:21:22 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_check_wall(t_list *s, double x, double y, double ang)
{
	if (sin(ang) <= 0)
		y = y - 25;
	if (y < 0 || y > s->leny * IMGHEIGHT || x < 0
		|| x > ft_strlen(s->map[(int)(y / IMGHEIGHT)]) * IMGWIDTH)
		return (-1);
	if (s->map[(int)(y / IMGHEIGHT)][(int)(x / IMGWIDTH)] == '1')
		return (0);
	return (1);
}

int	ft_check_wall2(t_list *s, double x, double y, double ang)
{
	if (cos(ang) <= 0)
		x = x - 25;
	if (y < 0 || y > s->leny * IMGHEIGHT || x < 0
		|| x > ft_strlen(s->map[(int)(y / IMGHEIGHT)]) * IMGWIDTH)
		return (-1);
	if (s->map[(int)(y / IMGHEIGHT)][(int)(x / IMGWIDTH)] == '1')
		return (0);
	return (1);
}

void	ft_check_vertical(t_list *s, t_calcul *cal, double ang)
{
	int	x;

	x = floor(s->xp);
	if (cos(ang) >= 0)
		cal->xp = (x - (x % IMGWIDTH)) + IMGWIDTH;
	if (cos(ang) < 0)
		cal->xp = x - (x % IMGWIDTH);
	cal->dp = IMGWIDTH * tan(ang);
	if (sin(ang) < 0)
		cal->yp = s->yp - fabs((s->xp - cal->xp) * tan(ang));
	else
		cal->yp = s->yp + fabs((s->xp - cal->xp) * tan(ang));
	while (ft_check_wall2(s, cal->xp, cal->yp, ang) == 1)
	{
		if (cos(ang) <= 0)
			cal->yp -= cal->dp;
		else
			cal->yp += cal->dp;
		if (cos(ang) >= 0)
			cal->xp += IMGWIDTH;
		if (cos(ang) < 0)
			cal->xp -= IMGWIDTH;
	}
	ft_if_no_line2(s, cal, ang);
}

void	ft_check_horizontal(t_list *s, t_calcul *cal, double ang)
{
	int	y;

	y = floor(s->yp);
	if (sin(ang) < 0)
		cal->yp = y - (y % IMGHEIGHT);
	else
		cal->yp = (y - (y % IMGHEIGHT)) + IMGHEIGHT;
	cal->dp = fabs(IMGHEIGHT / tan(ang));
	if (cos(ang) > 0)
		cal->xp = s->xp + fabs((s->yp - cal->yp) / tan(ang));
	else
		cal->xp = s->xp - fabs((s->yp - cal->yp) / tan(ang));
	while (ft_check_wall(s, cal->xp, cal->yp, ang) == 1)
	{
		if (cos(ang) < 0)
			cal->xp -= cal->dp;
		else
			cal->xp += cal->dp;
		if (sin(ang) < 0)
			cal->yp -= IMGHEIGHT;
		if (sin(ang) >= 0)
			cal->yp += IMGHEIGHT;
	}
	ft_if_no_line(s, cal, ang);
}

double	ft_calcul_dis(t_list *s, double ang)
{
	double		ds;
	double		ds2;
	t_calcul	cal;

	ft_check_horizontal(s, &cal, ang);
	cal.tmpx = cal.xp;
	cal.tmpy = cal.yp;
	ds = sqrt(pow(s->xp - cal.xp, 2.0) + pow(s->yp - cal.yp, 2.0));
	ft_check_vertical(s, &cal, ang);
	ds2 = sqrt(pow(s->xp - cal.xp, 2.0) + pow(s->yp - cal.yp, 2.0));
	if (ds2 > ds)
	{
		cal.xp = cal.tmpx;
		cal.yp = cal.tmpy;
	}
	else
		ds = ds2;
	s->xr = cal.xp;
	s->yr = cal.yp;
	ds = ds * cos(s->ang - ang);
	return (ds);
}

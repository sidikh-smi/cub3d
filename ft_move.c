/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:13:04 by ebakchic          #+#    #+#             */
/*   Updated: 2023/04/15 10:04:09 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_rot_left_right(t_list *s)
{
	if (s->anim->rot_right == 1)
		s->ang += ROTESPEED;
	if (s->anim->rot_left == 1)
		s->ang -= ROTESPEED;
	if (s->anim->rot_right_m == 1)
		s->ang += ROTESPEED;
	if (s->anim->rot_left_m == 1)
		s->ang -= ROTESPEED;
	s->anim->rot_left_m = 0;
	s->anim->rot_right_m = 0;
}

void	ft_right_left(t_list *s)
{
	double	tmpx;
	double	tmpy;

	tmpx = s->xp;
	tmpy = s->yp;
	if (s->anim->right == 1)
	{
		s->xp -= MOVESPEED * sin(s->ang);
		s->yp += MOVESPEED * cos(s->ang);
	}
	if (s->anim->left == 1)
	{
		s->xp += MOVESPEED * sin(s->ang);
		s->yp -= MOVESPEED * cos(s->ang);
	}
	if (s->map[(int)((s->yp + 3) / IMGHEIGHT)] \
	[(int)((s->xp + 3) / IMGWIDTH)] == '1'
		|| s->map[(int)((s->yp - 3) / IMGHEIGHT)] \
		[(int)((s->xp - 3) / IMGWIDTH)] == '1')
	{
		s->xp = tmpx;
		s->yp = tmpy;
	}
}

void	ft_forward_back2(t_list *s, double tmpy, double tmpx)
{
	if (s->map[(int)((tmpy) / IMGHEIGHT)] \
	[(int)((s->xp + 5) / IMGWIDTH)] == '1'
	|| s->map[(int)((tmpy) / IMGHEIGHT)] \
	[(int)((s->xp - 5) / IMGWIDTH)] == '1')
	s->xp = tmpx;
	if (s->map[(int)((s->yp + 5) / IMGHEIGHT)] \
	[(int)((tmpx) / IMGWIDTH)] == '1'
	|| s->map[(int)((s->yp - 5) / IMGHEIGHT)] \
	[(int)((tmpx) / IMGWIDTH)] == '1')
	s->yp = tmpy;
}

void	ft_forward_back(t_list *s)
{
	double	tmpx;
	double	tmpy;

	tmpx = s->xp;
	tmpy = s->yp;
	if (s->anim->forward == 1)
	{
		s->xp += MOVESPEED * cos(s->ang);
		s->yp += MOVESPEED * sin(s->ang);
	}
	if (s->anim->back == 1)
	{
		s->xp -= MOVESPEED * cos(s->ang);
		s->yp -= MOVESPEED * sin(s->ang);
	}
	if (s->map[(int)((tmpy) / IMGHEIGHT)][(int)((s->xp) / IMGWIDTH)] == '0' &&
	s->map[(int)((s->yp) / IMGHEIGHT)][(int)((tmpx) / IMGWIDTH)] == '0' &&
	s->map[(int)((s->yp) / IMGHEIGHT)][(int)((s->xp) / IMGWIDTH)] == '1')
	{
		s->yp = tmpy;
		s->xp = tmpx;
	}
	else
		ft_forward_back2(s, tmpy, tmpx);
}

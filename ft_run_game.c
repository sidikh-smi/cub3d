/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:48:00 by ebakchic          #+#    #+#             */
/*   Updated: 2023/04/14 19:51:14 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_put_gun(t_list *s)
{
	int	i;

	i = 0;
	while (s->gun[i] != NULL)
		i++;
	if (s->l % 1000 == s->k && s->k < i)
		s->k++;
	mlx_put_image_to_window(s->mlx, s->win, s->gun[s->k - 1], 0, 0);
	s->anim->reload = 0;
	s->l++;
}

int	ft_start_game(t_list *s)
{
	mlx_clear_window(s->mlx, s->win);
	ft_rot_left_right(s);
	ft_right_left(s);
	ft_forward_back(s);
	ft_render(s);
	if (s->anim->reload == 1 && s->k == 84)
	{
		s->k = 0;
		s->l = 0;
	}
	ft_put_gun(s);
	return (0);
}

int	ft_check_mouse(int x, int y, void *p)
{
	t_list	*s;

	s = (t_list *)p;
	if (x > 0 && x <= WINWIDTH / 2 && y > 0 && y < WINHEIGHT)
		s->anim->rot_left_m = 1;
	else if (x > 0 && x < WINWIDTH && y > 0 && y < WINHEIGHT)
		s->anim->rot_right_m = 1;
	return (0);
}

void	ft_run_game(t_list *s, char **map)
{
	t_anim	an;
	t_so	so;
	t_no	no;
	t_we	we;
	t_ea	ea;

	s->so = &so;
	s->no = &no;
	s->we = &we;
	s->ea = &ea;
	ft_init(&an);
	ft_init2(s, map, &an);
	mlx_hook(s->win, KEYPRESS, 1L << 0, ft_active_key, &an);
	mlx_hook(s->win, 6, 0, ft_check_mouse, s);
	mlx_loop_hook(s->mlx, ft_start_game, s);
	mlx_hook(s->win, KEYRELEASE, 1L << 1, ft_disable_key, &an);
	mlx_loop(s->mlx);
}

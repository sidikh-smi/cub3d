/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:35:34 by ebakchic          #+#    #+#             */
/*   Updated: 2023/04/14 19:48:49 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_active_key(int keycode, t_anim *an)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == FORWARD)
		an->forward = 1;
	if (keycode == BACK)
		an->back = 1;
	if (keycode == RIGHT)
		an->right = 1;
	if (keycode == LEFT)
		an->left = 1;
	if (keycode == ROTATE_RIGHT)
		an->rot_right = 1;
	if (keycode == ROTATE_LEFT)
		an->rot_left = 1;
	if (keycode == RELOAD)
		an->reload = 1;
	return (0);
}

int	ft_disable_key(int keycode, t_anim *an)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == FORWARD)
		an->forward = 0;
	if (keycode == BACK)
		an->back = 0;
	if (keycode == RIGHT)
		an->right = 0;
	if (keycode == LEFT)
		an->left = 0;
	if (keycode == ROTATE_RIGHT)
		an->rot_right = 0;
	if (keycode == ROTATE_LEFT)
		an->rot_left = 0;
	return (0);
}

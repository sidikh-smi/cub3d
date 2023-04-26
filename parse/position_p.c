/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:23:18 by skhaliff          #+#    #+#             */
/*   Updated: 2023/04/12 21:28:19 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	p_north(t_vars *p, int x, int y)
{
	p->position = M_PI / 2;
	p->x = x;
	p->y = y;
}

void	p_south(t_vars *p, int x, int y)
{
	p->position = 3 * M_PI / 2;
	p->x = x;
	p->y = y;
}

void	p_east(t_vars *p, int x, int y)
{
	p->position = 0;
	p->x = x;
	p->y = y;
}

void	p_weast(t_vars *p, int x, int y)
{
	p->position = M_PI;
	p->x = x;
	p->y = y;
}

void	position_player(t_vars *p)
{
	int	x;
	int	y;

	x = 0;
	while (p->map[x])
	{
		y = 0;
		while (p->map[x][y])
		{
			if (p->map[x][y] == 'N')
				p_north(p, x, y);
			else if (p->map[x][y] == 'W')
				p_weast(p, x, y);
			else if (p->map[x][y] == 'E')
				p_east(p, x, y);
			else if (p->map[x][y] == 'S')
				p_south(p, x, y);
			y++;
		}
		x++;
	}
}

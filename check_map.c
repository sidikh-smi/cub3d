/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:14:57 by skhaliff          #+#    #+#             */
/*   Updated: 2023/04/11 13:26:25 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_char(char c)
{
	if (c == '1' || c == '0' || c == 'S'
		|| c == 'N' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

void	player_check(t_vars *s)
{
	int	i;
	int	q;

	i = s->j + 1;
	while (s->map[i])
	{
		q = 0;
		while (s->map[i][q])
		{
			if (s->map[i][q] == 'N' || s->map[i][q] == 'S'
				|| s->map[i][q] == 'W' || s->map[i][q] == 'E')
			{
				if (s->map[i][q - 1] == ' ' || s->map[i][q + 1] == ' '
					|| s->map[i + 1][q] == ' ' || s->map[i - 1][q] == ' ')
					error("Player\n");
			}
			q++;
		}
		i++;
	}
}

void	ft_check_map(t_vars *s)
{
	int		i;
	size_t	q;

	i = s->j + 1;
	while (s->map[i])
	{
		q = 0;
		while (s->map[i][q])
		{
			if (s->map[i][q] == '0')
			{
				if (!check_char(s->map[i][q - 1]))
					error("Wall\n");
				if (!check_char(s->map[i][q + 1]))
					error("Wall\n");
				if (q <= ft_strlen(s->map[i + 1])
					&& q <= ft_strlen(s->map[i - 1]))
				{
					if (!check_char(s->map[i + 1][q]))
						error("Wall\n");
					if (!check_char(s->map[i - 1][q]))
						error("Wall\n");
				}
				else
					error("map\n");
			}
			q++;
		}
		i++;
	}
}

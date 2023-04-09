/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components_cub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:41:56 by skhaliff          #+#    #+#             */
/*   Updated: 2023/04/09 13:50:45 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	components_cub(t_vars *h)
{
	int	s;
	int	i;

	s = h->j;
	if (!h->map[s])
		error("ERREUR\n");
	while (h->map[s])
	{
		i = 0;
		while (h->map[s][i])
		{
			if (h->map[s][i] != '0'
				&& h->map[s][i] != '1' && h->map[s][i] != 'N'
				&& h->map[s][i] != 'S'
				&& h->map[s][i] != 'E' && h->map[s][i] != 'W'
				&& h->map[s][i] != ' '
				&& h->map[s][i] != '\n' && h->map[s][i] != '\t')
				error("CONPONEMENT INV!!!!!");
			i++;
		}
		s++;
	}
}

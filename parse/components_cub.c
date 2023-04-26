/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components_cub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:41:56 by skhaliff          #+#    #+#             */
/*   Updated: 2023/04/12 21:27:44 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	lenght_line(t_vars *s)
{
	int	i;

	i = s->j;
	s->max_lenght = ft_strlen(s->map[i]);
	while (s->map[i])
	{
		if (s->max_lenght < ft_strlen(s->map[i]))
			s->max_lenght = ft_strlen(s->map[i]);
		i++;
	}
}

void	check_p(t_vars *s)
{
	int	a;
	int	p;
	int	c;

	a = s->j;
	c = 0;
	while (s->map[a])
	{
		p = 0;
		while (s->map[a][p])
		{
			if (s->map[a][p] == 'N' || s->map[a][p] == 'S'
				|| s->map[a][p] == 'W' || s->map[a][p] == 'E')
				c++;
			p++;
		}
		a++;
	}
	if (c != 1)
		error("More than one player or missing a player\n");
}

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

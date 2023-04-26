/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:11:55 by skhaliff          #+#    #+#             */
/*   Updated: 2023/04/15 09:38:52 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	skip_space(int j, char *c)
{
	while (c[j] && (c[j] == ' ' || c[j] == '\t'))
			j++;
	if (c[j] == '\0')
		error("Need a path\n");
	return (j);
}

void	ft_check_char(t_vars *s, int q, int i)
{
	if (s->map[q][i] != 'N' && s->map[q][i] != 'S'
		&& s->map[q][i] != 'W' && s->map[q][i] != 'E'
		&& s->map[q][i] != 'F' && s->map[q][i] != 'C')
		error("TExture\n");
	if (s->map[q][i] == 'N' || s->map[q][i] == 'S'
		|| s->map[q][i] == 'W' || s->map[q][i] == 'E')
		path_texture(s, s->map[q], s->map[q][i], i);
	if (s->map[q][i] == 'F' || s->map[q][i] == 'C')
		check_colors(s, s->map[q], s->map[q][i]);
}

void	textures(t_vars *s)
{
	int	q;
	int	i;

	s->t = ft_calloc(4, 4);
	q = 0;
	while (q < 6 && s->map[q])
	{
		i = 0;
		while (i != -1 && s->map[q][i])
		{
			if (s->map[q][i] == ' ' || s->map[q][i] == '\t' )
			{
				i++;
				continue ;
			}
			ft_check_char(s, q, i);
			i = -1;
		}
		q++;
	}
	free(s->t);
	s->j = q;
}

char	*ft(int fd, char *h)
{
	char	*e;
	int		start_map;

	e = NULL;
	start_map = 0;
	while (h)
	{
		if (!start_map)
		{
			if (new_line_map(h))
			{
				check_line(h);
				start_map = 1;
			}
			e = ft_strjoin(e, h);
		}
		else
		{
			check_line(h);
			e = ft_strjoin(e, h);
		}
		free (h);
		h = get_next_line(fd);
	}
	return (e);
}

void	check(t_vars *s, int fd)
{
	char	*h;
	char	*e;
	int		c;
	int		i;

	c = 0;
	h = get_next_line(fd);
	empty_map(h, s);
	e = ft(fd, h);
	i = ft_strlen(e);
	if (e[i - 1] == '\n')
		error("error map\n");
	s->map = ft_split(e, '\n');
	free(e);
	close(fd);
}

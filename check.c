/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:11:55 by skhaliff          #+#    #+#             */
/*   Updated: 2023/04/09 18:12:42 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	skip_space(int j, char *c)
{
	while (c[j] && (c[j] == ' ' || c[j] == '\t'))
			j++;
	return (j);
}

void	path_texture(t_vars *s, char *c, char a, int i, int *t)
{
	int	j;

	j = i + 2;
	if (a == 'N' && c[i + 1] == 'O' && (c[i + 2] == ' ' || c[i + 2] == '\t'))
	{
		if (t[0] == 0)
			t[0] = 1;
		else
			error("dupliquer\n");
		j = skip_space(j, c);
		s->path_no = ft_substr(c, j, 100);
	}
	else if (a == 'W' && c[i + 1] == 'E' && (c[i + 2] == ' ' || c[i + 2] == '\t'))
	{
		if (t[1] == 0)
			t[1] = 1;
		else
			error("dupliquer\n");
		j = skip_space(j, c);
		s->path_we = ft_substr(c, j, 100);
	}
	else if (a == 'S' && c[i + 1] == 'O' && (c[i + 2] == ' ' || c[i + 2] == '\t'))
	{
		if (t[2] == 0)
			t[2] = 1;
		else
			error("dupliquer\n");
		j = skip_space(j, c);
		s->path_so = ft_substr(c, j, 100);
	}
	else if (a == 'E' && c[i + 1] == 'A' && (c[i + 2] == ' ' || c[i + 2] == '\t'))
	{
		if (t[3] == 0)
			t[3] = 1;
		else
			error("dupliquer\n");
		j = skip_space(j, c);
		s->path_ea = ft_substr(c, j, 100);
	}
	else
		error("TExture\n");
}

void	ft_check_char(t_vars *s, int q, int i, int *t)
{
	if (s->map[q][i] != 'N' && s->map[q][i] != 'S'
		&& s->map[q][i] != 'W' && s->map[q][i] != 'E'
		&& s->map[q][i] != 'F' && s->map[q][i] != 'C')
		error("TExture\n");
	if (s->map[q][i] == 'N' || s->map[q][i] == 'S'
		|| s->map[q][i] == 'W' || s->map[q][i] == 'E')
		path_texture(s, s->map[q], s->map[q][i], i, t);
	if (s->map[q][i] == 'F' || s->map[q][i] == 'C')
		check_colors(s, s->map[q], s->map[q][i]);
}

void	textures(t_vars *s)
{
	int	q;
	int	i;
	int	*t;

	t = ft_calloc(4, 4);
	q = 0;
	while (q < 6)
	{	
		i = 0;
		while (i != -1 && s->map[q][i])
		{
			if (s->map[q][i] == ' ' || s->map[q][i] == '\t')
			{
				i++;
				continue ;
			}
			ft_check_char(s, q, i, t);
			i = -1;
		}
		q++;
	}
	s->j = q;
}

void	check(t_vars *s, int fd)
{
	char	*h;
	char	*e;
	int		i;
	int		l;

	l = 0;
	s->map = NULL;
	e = NULL;
	h = get_next_line(fd);
	empty_map(h, s);
	while (h)
	{
		e = ft_strjoin(e, h);
		free (h);
		h = get_next_line(fd);
	}
	i = ft_strlen(e);
	s->map = ft_split(e, '\n');
	while (s->map[l])
		l++;
	s->size = l;
	textures(s);
	components_cub(s);
	free(e);
	close(fd);
}

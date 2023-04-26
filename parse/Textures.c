/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:40:20 by skhaliff          #+#    #+#             */
/*   Updated: 2023/04/14 17:39:01 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	path_north(int *t, int j, char *c, t_vars *s)
{
	if (t[0] == 0)
			t[0] = 1;
	else
		error("dupliquer\n");
	j = skip_space(j, c);
	s->path_no = ft_substr(c, j, 100);
}

void	path_weast(int *t, int j, char *c, t_vars *s)
{
	if (t[1] == 0)
			t[1] = 1;
	else
		error("dupliquer\n");
	j = skip_space(j, c);
	s->path_no = ft_substr(c, j, 100);
}

void	path_south(int *t, int j, char *c, t_vars *s)
{
	if (t[2] == 0)
			t[2] = 1;
	else
		error("dupliquer\n");
	j = skip_space(j, c);
	s->path_no = ft_substr(c, j, 100);
}

void	path_east(int *t, int j, char *c, t_vars *s)
{
	if (t[3] == 0)
			t[3] = 1;
	else
		error("dupliquer\n");
	j = skip_space(j, c);
	s->path_no = ft_substr(c, j, 100);
}

void	check_texture(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd < 0)
		error("Path incorrect\n");
}

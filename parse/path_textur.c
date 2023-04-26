/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_textur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 09:53:39 by ebakchic          #+#    #+#             */
/*   Updated: 2023/04/15 09:54:03 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	path_texture3(t_vars *s, char *c, char a, int i)
{
	int	j;

	if (a == 'E' && c[i + 1] == 'A' \
	&& (c[i + 2] == ' ' || c[i + 2] == '\t'))
	{
		if (s->t[3] == 0)
			s->t[3] = 1;
		else
			error("dupliquer\n");
		j = skip_space(i + 2, c);
		s->path_ea = ft_substr(c, j, 100);
		check_texture(s->path_ea);
	}
	else
		error("TExture\n");
}

void	path_texture2(t_vars *s, char *c, char a, int i)
{
	int	j;

	if (a == 'S' && c[i + 1] == 'O' \
	&& (c[i + 2] == ' ' || c[i + 2] == '\t'))
	{
		if (s->t[2] == 0)
			s->t[2] = 1;
		else
			error("dupliquer\n");
		j = skip_space(i + 2, c);
		s->path_so = ft_substr(c, j, 100);
		check_texture(s->path_so);
	}
	else
		path_texture3(s, c, a, i);
}

void	path_texture(t_vars *s, char *c, char a, int i)
{
	int	j;

	if (a == 'N' && c[i + 1] == 'O' && (c[i + 2] == ' ' || c[i + 2] == '\t'))
	{
		if (s->t[0] == 0)
			s->t[0] = 1;
		else
			error("dupliquer\n");
		j = skip_space(i + 2, c);
		s->path_no = ft_substr(c, j, 100);
		check_texture(s->path_no);
	}
	else if (a == 'W' && c[i + 1] == 'E' \
	&& (c[i + 2] == ' ' || c[i + 2] == '\t'))
	{
		if (s->t[1] == 0)
			s->t[1] = 1;
		else
			error("dupliquer\n");
		j = skip_space(i + 2, c);
		s->path_we = ft_substr(c, j, 100);
		check_texture(s->path_we);
	}
	else
		path_texture2(s, c, a, i);
}

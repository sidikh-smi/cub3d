/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 12:35:52 by skhaliff          #+#    #+#             */
/*   Updated: 2023/04/09 13:32:09 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	colors_f(char **p, t_vars *s)
{
	s->f_r = ft_atoi(p[0]);
	s->f_g = ft_atoi(p[1]);
	s->f_b = ft_atoi(p[2]);
}

void	colors_c(char **p, t_vars *s)
{
	s->c_r = ft_atoi(p[0]);
	s->c_g = ft_atoi(p[1]);
	s->c_b = ft_atoi(p[2]);
}

char	**ft_syntax(char *value)
{
	char	**p;
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (value[i])
	{
		if (value[i] == ',')
			c++;
		i++;
	}
	if (c != 2)
		return (NULL);
	p = ft_split(value, ',');
	return (p);
}

void	check_colors(t_vars *s, char *a, char c)
{
	char	*value;
	char	**p;
	int		i;
	int		num;

	value = &a[2];
	p = ft_syntax(value);
	if (!p)
		error("coloor");
	i = 0;
	num = 0;
	while (p[i])
	{
		num = ft_atoi(p[i]);
		if (num == -1)
			error("ONLY A NUMBER\n");
		else if (num < 0 || num > 255)
			error("COLOR\n");
		i++;
	}
	if (c == 'F')
		colors_f(p, s);
	else if (c == 'C')
		colors_c(p, s);
	free_it(p);
}

void	trans_color(t_vars *p)
{
	p->color_f = (p->f_r << 16) + (p->f_g << 8) + p->f_b;
	p->color_c = (p->c_r << 16) + (p->c_g << 8) + p->c_b;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:11:32 by skhaliff          #+#    #+#             */
/*   Updated: 2023/04/12 11:59:22 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_walls(t_vars *d)
{
	int	i;
	int	s;
	int	size;

	s = d->j;
	size = 0;
	while (d->map[size])
		size++;
	i = 0;
	while (d->map[s])
	{
		i = 0;
		while (d->map[s][i] == ' ' || d->map[s][i] == '\t')
			i++;
		if (d->map[s][i] != '1' || (d->map[s][ft_strlen(d->map[s]) - 1] != '1'
			&& d->map[s][ft_strlen(d->map[s]) - 1] != ' '
			&& d->map[s][ft_strlen(d->map[s]) - 1] != '\t'))
			error("Suround WAALLLL!!!!");
		s++;
	}
	check_up_down(d->map[d->j], d->map[size - 1]);
}

void	check_up_down(char *a, char *b)
{
	int	j;

	j = 1;
	while (a[j])
	{
		if (a[j] != '1' && a[j] != ' ' && a[j] != '\t')
			break ;
		j++;
	}
	if (a[j] != '\0')
		error("Check the Walls!!");
	j = 1;
	while (b[j])
	{
		if (b[j] != '1' && b[j] != ' ' && b[j] != '\t')
			break ;
			j++;
	}
	if (b[j] != '\0')
		error("Check the Walls!!");
}

int	isber(char *s)
{
	int	i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == '.')
			return (i);
		i--;
	}
	return (0);
}

void	det_error(char *s, t_vars *d)
{
	int	fd;
	int	i;

	i = isber(s);
	if (ft_strcmp(s + i, ".cub") != 0)
		error("MAP INVALID");
	fd = open(s, O_RDONLY);
	if (fd < 0)
		error("fd invalid");
	check(d, fd);
	textures(d);
	components_cub(d);
	check_p(d);
	check_walls(d);
	ft_check_map(d);
	player_check(d);
}

int	main(int argc, char **argv)
{
	t_vars	*d;

	d = malloc(sizeof(t_vars));
	if (argc != 2)
		error("ERROR");
	else
	{
		init(d);
		det_error(argv[1], d);
		trans_color(d);
		position_player(d);
		lenght_line(d);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:31:25 by skhaliff          #+#    #+#             */
/*   Updated: 2023/04/09 13:40:57 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	empty_map(char *s, t_vars *d)
{
	if (s == NULL)
	{
		free(d->map);
		error("empty map!!");
	}
}

void	free_it(char **p)
{
	int	i;

	i = -1;
	while (p[++i])
		free(p[i]);
	free(p);
	p = NULL;
}

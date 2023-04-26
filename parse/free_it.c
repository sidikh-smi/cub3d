/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:31:25 by skhaliff          #+#    #+#             */
/*   Updated: 2023/04/12 21:27:54 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

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

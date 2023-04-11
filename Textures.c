/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:40:20 by skhaliff          #+#    #+#             */
/*   Updated: 2023/04/11 13:54:38 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_texture(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd < 0)
		error("Path incorrect\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:13:15 by skhaliff          #+#    #+#             */
/*   Updated: 2021/12/21 22:31:46 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

char	*new_line(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * ft_strlen(str) - i + 1);
	if (!s)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		s[j++] = str[i++];
	s[j] = '\0';
	free(str);
	return (s);
}

char	*read_file(int fd, char *str)
{
	char	*buffer;
	ssize_t	read_bt;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_bt = 1;
	while (!ft_strchr(str, '\n') && read_bt != 0)
	{
		read_bt = read(fd, buffer, BUFFER_SIZE);
		if (read_bt == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bt] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	if (read_bt == 0 && *str == '\0')
	{
		free(str);
		str = NULL;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*s;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_file(fd, str);
	if (!str)
		return (NULL);
	s = ft_line(str);
	str = new_line(str);
	return (s);
}

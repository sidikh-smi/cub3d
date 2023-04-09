/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 01:15:01 by skhaliff          #+#    #+#             */
/*   Updated: 2023/04/09 13:51:21 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	f(unsigned int i, char c)
{
	(void)i;
	c -= 32;
	return (c);
}

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*rtn;

	i = 0;
	if (!s || (!s && !f))
		return (ft_strdup(""));
	else if (!f)
		return (ft_strdup(s));
	rtn = ft_strdup(s);
	if (!rtn)
		return (rtn = NULL);
	while (s[i])
	{
		rtn[i] = (*f)(i, s[i]);
		i++;
	}
	return (rtn);
}

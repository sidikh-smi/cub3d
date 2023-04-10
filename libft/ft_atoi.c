/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:51:29 by skhaliff          #+#    #+#             */
/*   Updated: 2023/04/10 09:39:27 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	convert_num(const char *s, int isneg)
{
	int					i;
	unsigned long		nbr;

	i = 0;
	nbr = 0;
	while (s[i] != '\0' && ft_isdigit(s[i]))
	{
		nbr = (nbr * 10) + (s[i++] - '0');
		if (nbr > 9223372036854775807)
		{
			if (isneg == 0)
				return (-1);
			if (isneg == 1)
				return (0);
		}
	}
	if (s[i] != '\0' && (!ft_isdigit(s[i]) || (s[i] != ' ' || s[i] != '\t')))
		return (-1);
	return (nbr);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	nbr;
	int		isneg;

	i = 0;
	nbr = 0;
	isneg = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '-')
	{
		isneg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	nbr = convert_num(str + i, isneg);
	if (isneg == 1)
		return (-nbr);
	return (nbr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:18:28 by gfantoni          #+#    #+#             */
/*   Updated: 2024/01/29 11:27:29 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	is_neg;
	int	res;

	if (*str == '\0')
		return (0);
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || (str[i] == ' '))
		i++;
	is_neg = 1;
	if (str[i] == '-')
	{
		is_neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	res = 0;
	while (str[i] >= '0' && str [i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	return (res * is_neg);
}

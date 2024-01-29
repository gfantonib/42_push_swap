/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_sqrt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:07:22 by gfantoni          #+#    #+#             */
/*   Updated: 2024/01/29 09:58:19 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

long	ft_math_sqrt(long nb, long kick)
{
	long	result;
	long	iteration;

	iteration = 0;
	if (nb > 0)
	{
		while (1)
		{
			result = (kick + (nb / kick)) / 2;
			if (result == kick)
			{
				if (result * result == nb)
					return (result);
				else
					return (0);
			}
			kick = result;
		}
	}
	return (0);
}

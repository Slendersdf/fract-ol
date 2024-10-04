/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalldigits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:34:47 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/10/03 20:48:17 by fpaulas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Function to check if the string is composed only of digits
int	ft_isalldigits(const char *str)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] == '.' && dot == 0)
		{
			dot = 1;
			i++;
		}
		if ((str[i] < '0' || str[i] > '9') || (str[i] == '.' && dot == 1))
			return (0);
		i++;
	}
	return (1);
}

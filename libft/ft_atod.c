/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:35:44 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/10/03 20:46:23 by fpaulas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Function to get the sign
int	ft_sign(const char *str)
{
	int	sign;

	sign = 1;
	if (str[0] == '-')
		sign *= -1;
	return (sign);
}

// Function to convert a string to a double
double	ft_atod(const char *str)
{
	int		i;
	double	res;
	double	div;

	i = 0;
	res = 0;
	div = 10;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '.')
		return (res * ft_sign(str));
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res += (str[i] - '0') / div;
		div *= 10;
		i++;
	}
	return (res * ft_sign(str));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliott <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 11:48:44 by eliott            #+#    #+#             */
/*   Updated: 2020/11/08 11:49:48 by eliott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_basic3d.h"

int		ft_isnum(char c)
{
	return (c >= '0' && c <= '9');
}

int		ft_isalpha(char c)
{
	return (c >= 'a' && c <= 'z');
}

double	ft_atod(char *str, int *i)
{
	double	res;
	double	dec;
	double 	sign;

	sign = 1.0;
	dec = 10.0;
	res = 0.0;
	while (str[*i] == ' ' || ft_isalpha(str[*i]))
		(*i)++;
	if (str[*i] == '-')
	{
		(*i)++;
		sign = -1.0;
	}
	while (ft_isnum(str[*i]))
		res = (res * dec) + (double)(str[(*i)++] - '0');
	if (str[(*i)++] != '.')
		return (res);
	while (ft_isnum(str[*i]))
	{
		res += (str[(*i)++] - '0') / dec;
		dec *= 10;
	}
	return (res * sign);
}

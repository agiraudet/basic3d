/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:22:23 by agiraude          #+#    #+#             */
/*   Updated: 2020/11/08 01:00:18 by eliott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_basic3d.h"

void	ft_update_data(double *vert, double *modif)
{
	int i;
	
	i = 0;
	while (i < 4)
	{
		vert[i] = modif[i];
		i++;
	}
}

void	ft_process_modif(double *vert, double *modif)
{
	double	res[16];
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		res[i] = 0;
		j = 0;
		while (j < 4)
		{
			res[i] += vert[j] * modif[j * 4 + i];
			j++;
		}
		i++;
	}
	ft_update_data(vert, res);	
}

void	ft_modif_obj(t_obj *obj, double *modif)
{
	int i;

	i = 0;
	while (obj->vert[i])
		ft_process_modif(obj->vert[i++], modif);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliott <marvin@0.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 00:50:52 by eliott            #+#    #+#             */
/*   Updated: 2020/11/08 01:17:33 by eliott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double	*mx_scale(double scale)
{
	static double	data[] = {0, 0, 0, 1,
							  0, 0, 0, 1,
							  0, 0, 0, 1,
							  0, 0, 0, 1};

	data[0] = scale;
	data[5] = scale;
	data[10] = scale;
	return (data);
}

double	*mx_loc(double x, double y, double z)
{
	static double	data[] = {1, 0, 0, 0,
							  0, 1, 0, 0,
							  0, 0, 1, 0,
							  0, 0, 0, 1};
	
	data[3] = x;
	data[7] = y;
	data[11] = z;
	return (data);
}

double	*mx_rotX(double rot)
{	
	static double	data[] = {1, 0, 0, 0,
							  0, 1, 0, 0,
							  0, 0, 1, 0,
							  0, 0, 0, 1};

	data[5] = cos(rot);
	data[6] = -sin(rot);
	data[9] = sin(rot);
	data[10] = cos(rot);
	return (data);
}

double	*mx_rotY(double rot)
{	
	static double	data[] = {1, 0, 0, 0,
							  0, 1, 0, 0,
							  0, 0, 1, 0,
							  0, 0, 0, 1};

	data[0] = cos(rot);
	data[2] = sin(rot);
	data[8] = -sin(rot);
	data[10] = cos(rot);
	return (data);
}

double	*mx_rotZ(double rot)
{	
	static double	data[] = {1, 0, 0, 0,
							  0, 1, 0, 0,
							  0, 0, 1, 0,
							  0, 0, 0, 1};

	data[0] = cos(rot);
	data[1] = -sin(rot);
	data[4] = sin(rot);
	data[5] = cos(rot);
	return (data);
}

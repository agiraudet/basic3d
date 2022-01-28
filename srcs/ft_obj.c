/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:01:58 by agiraude          #+#    #+#             */
/*   Updated: 2020/11/12 16:03:22 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_basic3d.h"

double	*ft_make_vert(double x, double y, double z)
{
	double		*vert;

	vert = (double*)malloc(sizeof(double) * 4);
	if (!vert)
		return (vert);
	vert[0] = x;
	vert[1] = y;
	vert[2] = z;
	vert[3] = 1;
	return (vert);
}

int		*ft_make_edge(int a, int b)
{
	int		*edge;

	edge = (int*)malloc(sizeof(int) * 2);
	edge[0] = a;
	edge[1] = b;
	return (edge);
}

void		ft_project_vert(double *vert, double *x, double *y)
{
	if (!PERSP)
	{
		*x = vert[0] + WIN_WIDTH / 2;
		*y = vert[1] + WIN_HEIGHT / 2;
	}
	else
	{
		*x = vert[0] / vert[2] + WIN_WIDTH / 2;
		*y = vert[1] / vert[2] + WIN_HEIGHT / 2;
	}
}

void		ft_destroy_obj(t_obj *obj)
{
	int i;

	i = 0;
	while (obj->vert[i])
		free(obj->vert[i++]);
	free(obj->vert);
	i = 0;
	while (obj->edge[i])
		free(obj->edge[i++]);
	free(obj->edge);
	free(obj);
}

void	ft_count_data(char **file, int *vert, int *edge)
{
	while (*file)
	{
		if (**file == 'v')
			(*vert)++;
		if (**file == 'l')
			(*edge)++;
		file++;
	}
}

t_obj	*ft_load_obj(char *path)
{
	t_obj	*obj;
	char	**file;
	int		i;
	int		v;
	int		e;
	int		nb_vert;
	int		nb_edge;

	nb_vert = 0;
	nb_edge = 0;
	file = ft_get_file(path);
	ft_count_data(file, &nb_vert, &nb_edge);
	if (!nb_vert)
		return (0);
	obj = (t_obj*)malloc(sizeof(t_obj));
	if (!obj)
		return (0);
	obj->vert = (double**)malloc(sizeof(double*) * (nb_vert + 1));
	obj->edge = (int**)malloc(sizeof(int*) * (nb_edge + 1));
	e = 0;
	v = 0;
	while (*file)
	{
		i = 0;
		if (**file == 'v')
			obj->vert[v++] = ft_make_vert(ft_atod(*file, &i), ft_atod(*file, &i), ft_atod(*file, &i));
		i = 0;
		if (**file == 'l')
			obj->edge[e++] = ft_make_edge(ft_atod(*file, &i) - 1, ft_atod(*file, &i) - 1);
		file++;
	}
	ft_free_file(file);
	obj->vert[v] = 0;
	obj->edge[e] = 0;
	return (obj);
}

t_obj	*ft_make_cube(void)
{
	t_obj	*cube;

	cube = (t_obj*)malloc(sizeof(t_obj));
	if (!cube)
		return (0);
	cube->vert = (double**)malloc(sizeof(double*) * 9);
	cube->edge = (int**)malloc(sizeof(int*) * 13);
	
	cube->vert[0] = ft_make_vert(1.000000, -1.000000, -1.000000);
	cube->vert[1] = ft_make_vert(1.000000, -1.000000, 1.000000);
	cube->vert[2] = ft_make_vert(-1.000000, -1.000000, 1.000000);
	cube->vert[3] = ft_make_vert(-1.000000, -1.000000, -1.000000);
	cube->vert[4] = ft_make_vert(1.000000, 1.000000, -1.000000);
	cube->vert[5] = ft_make_vert(1.000000, 1.000000, 1.000000);
	cube->vert[6] = ft_make_vert(-1.000000, 1.000000, 1.000000);
	cube->vert[7] = ft_make_vert(-1.000000, 1.000000, -1.000000);
	cube->vert[8] = 0;

	cube->edge[0] = ft_make_edge(0, 1);
	cube->edge[1] = ft_make_edge(0, 3);
	cube->edge[2] = ft_make_edge(0, 4);
	cube->edge[3] = ft_make_edge(1, 2);
	cube->edge[4] = ft_make_edge(1, 5);
	cube->edge[5] = ft_make_edge(2, 3);
	cube->edge[6] = ft_make_edge(2, 6);
	cube->edge[7] = ft_make_edge(3, 7);
	cube->edge[8] = ft_make_edge(4, 5);
	cube->edge[9] = ft_make_edge(4, 7);
	cube->edge[10] = ft_make_edge(5, 6);
	cube->edge[11] = ft_make_edge(6, 7);
	cube->edge[12] = 0;
	return (cube);
}

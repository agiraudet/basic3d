/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic3d.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 19:40:02 by agiraude          #+#    #+#             */
/*   Updated: 2020/11/08 12:23:35 by eliott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BASIC3D_H
# define FT_BASIC3D_H

# define WIN_WIDTH 1080
# define WIN_HEIGHT 720
# define PERSP 0

# include <SDL2/SDL.h>

typedef struct		s_obj
{
	double	**vert;
	int		**edge;
}					t_obj;

double  *mx_scale(double scale);
double	*mx_loc(double x, double y, double z);
double	*mx_rotX(double rot);
double	*mx_rotY(double rot);
double	*mx_rotZ(double rot);

void	ft_project_vert(double *vert, double *x, double *y);
void	ft_destroy_obj(t_obj *obj);
t_obj	*ft_make_cube(void);
void	ft_modif_obj(t_obj *obj, double *modif);
void    ft_draw_obj(SDL_Renderer *ren, t_obj *obj);
char	**ft_get_file(char *path);
double	ft_atod(char *str, int *i);
t_obj	*ft_load_obj(char *path);
void    ft_free_file(char **file);

#endif

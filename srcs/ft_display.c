#include <SDL2/SDL.h>
#include "ft_basic3d.h"

void	ft_draw_edge(SDL_Renderer *ren, t_obj *obj, int i)
{
	double x1;
	double y1;
	double x2;
	double y2;

	ft_project_vert(obj->vert[obj->edge[i][0]], &x1, &y1);
	ft_project_vert(obj->vert[obj->edge[i][1]], &x2, &y2);
	SDL_RenderDrawLine(ren, x1, y1, x2, y2);
}

void	ft_draw_obj(SDL_Renderer *ren, t_obj *obj)
{
	int		i;
	double	x;
	double	y;
	
	i = 0;
	x = 0;
	y = 0;
	while (obj->vert[i])
	{
		ft_project_vert(obj->vert[i++], &x, &y);
		SDL_RenderDrawPoint(ren, x, y);
	}
	i = 0;
	while (obj->edge[i])
		ft_draw_edge(ren, obj, i++);
}


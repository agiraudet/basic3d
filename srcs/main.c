/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 23:12:48 by agiraude          #+#    #+#             */
/*   Updated: 2020/11/08 12:30:03 by eliott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>
#include "ft_basic3d.h"

int		main(int argc, char **argv)
{
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
		return (-1);
	SDL_Window *win = 0;
	SDL_Renderer *ren = 0;

	win = SDL_CreateWindow("obj", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH, WIN_HEIGHT, 0);
	ren = SDL_CreateRenderer(win, -1, 0);
	SDL_SetRenderDrawColor(ren, 0,0,0, 255);
	SDL_RenderClear(ren);

	t_obj	*obj;
	if (argc == 2)
	{
		obj = ft_load_obj(argv[1]);
		if (!obj)
			return (0);
	}
	else
	{
		obj = ft_make_cube();
		if (!obj)
			return (0);
	}
	ft_modif_obj(obj, mx_scale(100));	

	SDL_Event event;
	int loop = 1;
	while (loop)
	{
		while (SDL_PollEvent(&event))
			if (event.type == SDL_QUIT)
			{
				loop = 0;
				break ;
			}
		SDL_SetRenderDrawColor(ren, 0,0,0, 255);
		SDL_RenderClear(ren);
		SDL_SetRenderDrawColor(ren, 0,255,0, 255);
		ft_modif_obj(obj, mx_rotZ(0.00015));
		ft_modif_obj(obj, mx_rotY(0.00015));
		ft_draw_obj(ren, obj);
		SDL_RenderPresent(ren);
	}

	ft_destroy_obj(obj);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return (0);
}

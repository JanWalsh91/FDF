/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:03:18 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/06 16:57:15 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_env
{
	void *mlx;
	void *win;
}				t_env;

void	draw(void *mlx, void *win)
{
	int	y;
	int	x;


	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF); //weight/transparency, RGB
			x++;
			mlx_expose_hook(win, NULL, NULL);
		}
		y++;
	}
}

int	my_key_funct(int keycode, void *param) //how to transfer more info through this function
{
	printf("key event %i\n", keycode);
	//mlx_pixel_put(mlx, win, 300, 300, 0xFF00FF); //?
	return (0);
}

int	key_hook(int keycode, t_env *e)
{
	printf("keycode: %i\n", keycode);
	if (keycode == 53)
		exit(0);
	return (keycode);
}

int	mouse_hook(int button, int x, int y, t_env *e)
{
	printf("mouse: %i (%i;%i)\n", button, x, y);
	if (button == 53)
		exit(0);
	return (0);
}

int	expose_hook(t_env *e)
{
	draw(e->mlx, e->win);
	return (1);
}

int	main(void)
{
	t_env	e;

	e.mlx = mlx_init(); // returns a void * which is a pointer used to identify 
					//the connection with the graphic server. Used for each
					//minilix function
	e.win = mlx_new_window(e.mlx, 2400, 1300, "mlx 42"); // returns an identifier to
													// that window
	draw(e.mlx, e.win);
	mlx_key_hook(e.win, key_hook, 0);
	mlx_expose_hook(e.win, &expose_hook, &e);
	mlx_mouse_hook(e.win, &mouse_hook, &e);
	mlx_loop(e.mlx);
					//does not end the program.
	

	
	return (0);
}

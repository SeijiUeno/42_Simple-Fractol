/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <rflseijiueno@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:28:45 by sueno-te          #+#    #+#             */
/*   Updated: 2024/05/22 17:29:37 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_fractol *f, int argc, char **argv)
{
	f->mlx = NULL;
	f->img = NULL;
	if (argc <= 1)
		return (errors(f, too_few_args));
	which_fractal(f, argc, argv);
	f->mlx = mlx_init(WIDTH, HEIGHT, "fractol", false);
	if (!f->mlx)
		return (errors(f, mlx_failure));
	f->img = mlx_new_image(f->mlx, f->mlx->width, f->mlx->height);
	if (!f->img || mlx_image_to_window(f->mlx, f->img, 0, 0) < 0)
		errors (f, mlx_image_failure);
	f->iters = ITERS;
}

void	quit(t_fractol *f, int exit_type)
{
	if (f->img)
		mlx_delete_image(f->mlx, f->img);
	if (f->mlx)
	{
		mlx_close_window(f->mlx);
		mlx_terminate(f->mlx);
	}
	exit (exit_type);
}

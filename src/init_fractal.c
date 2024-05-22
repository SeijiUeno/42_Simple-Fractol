/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <rflseijiueno@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 05:19:27 by sueno-te          #+#    #+#             */
/*   Updated: 2024/05/22 17:29:29 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_mandelbrot(t_fractol *f, int argc)
{
	if (argc > 2)
		errors(f, extra_args);
	f->fractal_function = mandelbrot;
	f->x_spam = 3;
	f->y_spam = 3;
	f->x_offset = 2.3;
	f->y_offset = 1.5;
	f->zoom_of_interest_x = 1.5;
	f->zoom_of_interest_y = 0.0;
}

static void	init_julia(t_fractol *f, int argc, char **argv)
{
	if (argc != 2 && argc != 4)
		errors(f, too_few_args_julia);
	f->fractal_function = julia;
	f->x_spam = 3.2;
	f->y_spam = 3.2;
	f->x_offset = 1.6;
	f->y_offset = 1.6;
	if (argc == 2)
	{
		f->x_seed = 0.285;
		f->y_seed = 0.01;
	}
	else
	{
		f->x_seed = ft_atof(argv[2]);
		f->y_seed = ft_atof(argv[3]);
	}
	f->zoom_of_interest_x = 0.560;
	f->zoom_of_interest_y = 0.316;
}


void	which_fractal(t_fractol *f, int argc, char **argv)
{
	if (!ft_strncmp("mandelbrot", argv[1], ft_strlen("mandelbrot")))
		init_mandelbrot(f, argc);
	else if (!ft_strncmp("julia", argv[1], ft_strlen("julia")))
		init_julia(f, argc, argv);
	else
		errors(f, invalid_args);
}

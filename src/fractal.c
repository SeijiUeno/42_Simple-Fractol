/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <rflseijiueno@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:28:20 by sueno-te          #+#    #+#             */
/*   Updated: 2024/05/22 14:49:11 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	julia(double real_c, double imaginary_c, void *vars)
{
	int			n_interations;
	double		tmp;
	t_fractol	*f;

	f = vars;
	n_interations = 0;
	while (n_interations < f->iters)
	{
		if ((imaginary_c * imaginary_c + real_c * real_c) > 4.0)
			break ;
		tmp = 2 * real_c * imaginary_c + f->y_seed;
		real_c = real_c * real_c - imaginary_c * imaginary_c + f->x_seed;
		imaginary_c = tmp;
		n_interations++;
	}
	return (n_interations);
}

unsigned int	mandelbrot(double real_c, double imaginary_c, void *vars)
{
	unsigned int	n_interations;
	double			real;
	double			img;
	double			tmp;
	t_fractol		*f;

	f = vars;
	real = 0;
	img = 0;
	n_interations = 0;
	while (n_interations < f->iters)
	{
		if ((real * real + img * img) > 4.0)
			break ;
		tmp = 2 * real * img + imaginary_c;
		real = real * real - img * img + real_c;
		img = tmp;
		n_interations++;
	}
	return (n_interations);
}

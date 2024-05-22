/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgba.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <rflseijiueno@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 00:05:13 by sueno-te          #+#    #+#             */
/*   Updated: 2024/05/22 17:29:44 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	color_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

double	color_factor(t_fractol *f)
{
	return (1 / (f->iters));
}

double	psico_scheme(double nb)
{
	int	r;
	int	g;
	int	b;

	nb = pow(nb + 10, 3) + pow(nb + 2, 2) + nb * 0.001;
	r = (cos(nb * 0.1) + 1) * 127;
	g = (cos(nb * 0.2) + 1) * 127;
	b = (sin(nb * 0.3) + cos(nb * 0.2) + 2) * 63;
	return (color_rgba(r, g, b, 255));
}
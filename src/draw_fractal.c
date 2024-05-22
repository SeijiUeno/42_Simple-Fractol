/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <rflseijiueno@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 00:06:00 by sueno-te          #+#    #+#             */
/*   Updated: 2024/05/22 17:29:11 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double get_scaled_value(double coord, double span, double offset, int size)
{
    double relative_coord;
	
	relative_coord = (double)(coord / size);
    return (relative_coord * span - offset);
}

static double ft_x_value(const t_fractol *f, int x_coord)
{
    return (get_scaled_value(x_coord, f->x_spam, f->x_offset, f->img->width));
}

static double ft_y_value(const t_fractol *f, int y_coord)
{
    return (get_scaled_value(y_coord, f->y_spam, f->y_offset, f->img->height));
}

void draw_fractal(t_fractol *f)
{
	double		x;
	double		y;
	double		z;
	uint32_t	i;
	uint32_t	j;
	
    for (i = 0; i < f->img->width; i++)
    {
        for (j = 0; j < f->img->height; j++)
        {
			x = ft_x_value(f, i);
			y = ft_y_value(f, j);
			z = f->fractal_function(x, y, f) * color_factor(f);
			mlx_put_pixel(f->img, i, j, psico_scheme(z));
        }
    }
}

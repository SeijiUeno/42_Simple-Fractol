/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <rflseijiueno@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 00:05:01 by sueno-te          #+#    #+#             */
/*   Updated: 2024/05/22 17:29:47 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void adjust_offset(double *offset, double span, double new_span, double point_of_interest)
{
    *offset = point_of_interest - (point_of_interest - *offset) * (new_span / span);
}

void zoom_in(t_fractol *f)
{
    double	prev_span;

    prev_span = f->x_spam;
    f->x_spam *= 0.99;
    adjust_offset(&f->x_offset, prev_span, f->x_spam, f->zoom_of_interest_x);

    prev_span = f->y_spam;
    f->y_spam *= 0.99;
    adjust_offset(&f->y_offset, prev_span, f->y_spam, f->zoom_of_interest_y);
}

void	zoom_out(t_fractol *f)
{
	double	prev_span;

	prev_span = f->x_spam;
	f->x_spam *= 1.01;
	f->x_offset -= (prev_span - f->x_spam) / 2;
	prev_span = f->y_spam;
	f->y_spam *= 1.01;
	f->y_offset -= (prev_span - f->y_spam) / 2;
}

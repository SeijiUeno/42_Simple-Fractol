/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <rflseijiueno@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 00:05:01 by sueno-te          #+#    #+#             */
/*   Updated: 2024/05/22 15:34:24 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	zoom_in(t_fractol *f)
{
	double	prev_span;

	prev_span = f->x_spam;
	f->x_spam *= 0.99;
	f->x_offset -= (prev_span - f->x_spam) / 2;
	prev_span = f->y_spam;
	f->y_spam *= 0.99;
	f->y_offset -= (prev_span - f->y_spam) / 2;
	f->zoom /= 0.99;
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
	f->zoom /= 1.01;
}
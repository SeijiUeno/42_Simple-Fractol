/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <rflseijiueno@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:28:03 by sueno-te          #+#    #+#             */
/*   Updated: 2024/05/22 17:29:24 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	close_hook(void *param)
{
	quit ((t_fractol *)param, EXIT_SUCCESS);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_fractol	*f;

	f = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		quit(f, EXIT_SUCCESS);
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_fractol	*f;
	
	(void)xdelta;
	f = param;
	if (ydelta > 0)
	{
		zoom_in(f);
	}
	else if (ydelta < 0)
	{
		zoom_out(f);
	}
}

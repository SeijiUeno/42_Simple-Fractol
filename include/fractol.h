/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <rflseijiueno@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:27:43 by sueno-te          #+#    #+#             */
/*   Updated: 2024/05/22 16:05:43 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>
# include "MLX42/MLX42.h"
# include "libft.h"

# define WIDTH 500
# define HEIGHT 500
# define ITERS 80

enum				e_error
{
	too_few_args,
	too_many_args,
	invalid_args,
	extra_args,
	too_few_args_julia,
	mlx_failure,
	mlx_image_failure
};

enum				e_color
{
	psico,
};

typedef struct s_fractol_setup
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	double			x_spam;
	double			y_spam;
	double			x_offset;
	double			y_offset;
	double			x_seed;
	double			y_seed;
	double			iters;
	double			color_factor;
	unsigned int	(*fractal_function)(double, double, void *);
}					t_fractol;

uint32_t			color_rgba(int r, int g, int b, int a);
double				color_factor(t_fractol *f);
double				psico_scheme(double nb);

void				which_fractal(t_fractol *f, int argc, char **argv);
unsigned int		julia(double real_c, double imaginary_c, void *vars);
unsigned int		mandelbrot(double real_c, double imaginary_c, void *vars);

void				close_hook(void *param);
void				key_hook(mlx_key_data_t keydata, void *param);
void				scroll_hook(double xdelta, double ydelta, void *param);

void				draw_fractal(t_fractol *f);
void				quit(t_fractol *f, int exit_type);
void				errors(t_fractol *f, int error);
void				init(t_fractol *f, int argc, char **argv);
void				zoom_in(t_fractol *f);
void				zoom_out(t_fractol *f);

#endif

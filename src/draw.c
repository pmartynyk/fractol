/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 10:52:24 by pmartyny          #+#    #+#             */
/*   Updated: 2019/09/24 10:52:26 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_menu(t_fractol *fractol)
{
	mlx_string_put(fractol->mlx, fractol->win, 1000, 0, 16777215, "Usage:");
	mlx_string_put(fractol->mlx, fractol->win, 1000, 40,
	16777215, "ESC to exit");
	mlx_string_put(fractol->mlx, fractol->win, 1000, 60, 16777215,
	"Scroll to zoom");
	mlx_string_put(fractol->mlx, fractol->win, 1000, 80, 16777215,
	"TAB to change color");
	mlx_string_put(fractol->mlx, fractol->win, 1000, 100, 16777215,
	"R to restart");
	mlx_string_put(fractol->mlx, fractol->win, 1000, 120, 16777215,
	"Fractol's:");
	mlx_string_put(fractol->mlx, fractol->win, 1000, 140, 16777215,
	"1. Mandelbrot");
	mlx_string_put(fractol->mlx, fractol->win, 1000, 160, 16777215, "2. Julia");
	mlx_string_put(fractol->mlx, fractol->win, 1000, 180, 16777215,
	"3. Tricorn");
	mlx_string_put(fractol->mlx, fractol->win, 1000, 200, 16777215,
	"4. Burningship");
}

static void	ft_calc_coef(t_fractol *fractol)
{
	if (!ft_strcmp(fractol->name, "Julia"))
	{
		fractol->calc.x_coeff = fractol->calc.re_max - fractol->calc.re_min;
		fractol->calc.y_coeff = fractol->calc.im_min - fractol->calc.im_max;
	}
	else
	{
		fractol->calc.x_coeff = (fractol->calc.re_max - fractol->calc.re_min)
		/ WIDTH;
		fractol->calc.y_coeff = (fractol->calc.im_min - fractol->calc.im_max)
		/ HEIGHT;
	}
}

void		ft_draw(t_fractol *fractol)
{
	int x;
	int i;

	INT1(y, 0);
	ft_calc_coef(fractol);
	while (y < HEIGHT)
	{
		x = fractol->start;
		fractol->calc.c_im = (y * fractol->calc.y_coeff) +
		fractol->calc.im_max + fractol->calc.move_y;
		while (x < fractol->end)
		{
			fractol->calc.c_re = (x * fractol->calc.x_coeff) +
			fractol->calc.re_min + fractol->calc.move_x;
			fractol->calc.z_re = 0;
			fractol->calc.z_im = 0;
			i = -1;
			while (++i < ITERATIONS)
				if (ft_take_fractal(fractol) == 0)
					break ;
			pixel_put(fractol, x, y, get_color(i, fractol));
			x++;
		}
		y++;
	}
}

void		ft_draw_julia(t_fractol *fractol)
{
	int x;
	int y;
	int i;

	y = -1;
	ft_calc_coef(fractol);
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			fractol->calc.z_re = 1.5 * (x - WIDTH / 2.0) /
			(0.5 * fractol->calc.x_coeff * WIDTH) + fractol->calc.move_x;
			fractol->calc.z_im = (y - HEIGHT / 2.0) /
			(0.5 * fractol->calc.y_coeff * HEIGHT) + fractol->calc.move_y;
			i = -1;
			while (++i < ITERATIONS)
				if (ft_julia(fractol) == 0)
					break ;
			pixel_put(fractol, x, y, get_color(i, fractol));
		}
	}
}

void		ft_threads(t_fractol *fractol)
{
	pthread_t threads[THREADS];
	t_fractol tmp_fractol[THREADS];

	INT2(x, 0, i, 0);
	mlx_clear_window(fractol->mlx, fractol->win);
	while (i < THREADS)
	{
		tmp_fractol[i] = *fractol;
		tmp_fractol[i].start = x;
		x += WIDTH / THREADS;
		tmp_fractol[i].end = x;
		if (!ft_strcmp(fractol->name, "Julia"))
			pthread_create(&threads[i], NULL, (void *)ft_draw_julia,
			(void *)&tmp_fractol[i]);
		else
			pthread_create(&threads[i], NULL, (void *)ft_draw,
			(void *)&tmp_fractol[i]);
		i++;
	}
	i = -1;
	while (++i < THREADS)
		pthread_join(threads[i], NULL);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->image, 0, 0);
	ft_menu(fractol);
}

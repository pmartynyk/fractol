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

void ft_menu(t_fractol *fractol)
{
	// mlx_string_put(fractol->mlx, fractol->win, 1000, 0, 16777215, "Usage:");
	// mlx_string_put(fractol->mlx, fractol->win, 1000, 40, 16777215, "ESC to exit");
	// mlx_string_put(fractol->mlx, fractol->win, 1000, 60, 16777215, "ARROWS to move");
	// mlx_string_put(fractol->mlx, fractol->win, 1000, 80, 16777215,
	// 	"+ / - for change iterations");
	// mlx_string_put(fractol->mlx, fractol->win, 1000, 100, 16777215,
	// 	"Press 1-8 for change fractol");
	// mlx_string_put(fractol->mlx, fractol->win, 1000, 120, 16777215,
	// 	"Press PAGE_UP or PAGE_DOWN for change color");
	// mlx_string_put(fractol->mlx, fractol->win, 500, 0, 16777215,
	// 	fractol->name);
	// mlx_string_put(fractol->mlx, fractol->win, 1000, 150, 16777215, "Fractol's:");
	// mlx_string_put(fractol->mlx, fractol->win, 1100, 170, 16777215, "1. Mandelbrot");
	// mlx_string_put(fractol->mlx, fractol->win, 1100, 190, 16777215, "2. Julia");
	// mlx_string_put(fractol->mlx, fractol->win, 1100, 210, 16777215, "3. Tricorn");
	// mlx_string_put(fractol->mlx, fractol->win, 1100, 230, 16777215, "4. Burningship");
	// mlx_string_put(fractol->mlx, fractol->win, 1100, 250, 16777215, "5. Celtic");
	// mlx_string_put(fractol->mlx, fractol->win, 1100, 270, 16777215, "6. Buffalo");
	// mlx_string_put(fractol->mlx, fractol->win, 1100, 290, 16777215, "7. Heart");
	// mlx_string_put(fractol->mlx, fractol->win, 1100, 310, 16777215, "8. Mandelbar");
}

void ft_draw(t_fractol *fractol)
{
	INT1(y, 0);
	int x;
	int i;

	fractol->calc.x_coeff = (fractol->calc.re_max - fractol->calc.re_min) / WIDTH;
	fractol->calc.y_coeff = (fractol->calc.im_min - fractol->calc.im_max) / HEIGHT;
	while (y < HEIGHT)
	{
		x = fractol->start;
		fractol->calc.c_im = (y * fractol->calc.y_coeff) + fractol->calc.im_max + fractol->calc.move_y;
		while (x < fractol->end)
		{
			fractol->calc.c_re = (x * fractol->calc.x_coeff) + fractol->calc.re_min + fractol->calc.move_x;
			fractol->calc.z_re = 0;
			fractol->calc.z_im = 0;
			i = -1;
			while (++i < ITERATIONS)
				if (ft_take_fractal(fractol) == 0)
					break;
			pixel_put(fractol, x, y, get_color(i, fractol));
			x++;
		}
		y++;
	}
}

void ft_draw_julia(t_fractol *fractol)
{
	int x;
	int y;
	int i;

	fractol->calc.x_coeff = fractol->calc.re_max - fractol->calc.re_min;
	fractol->calc.y_coeff = fractol->calc.im_min - fractol->calc.im_max;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			fractol->calc.z_re = 1.5 * (x - WIDTH / 2.0) / (0.5 * fractol->calc.x_coeff * WIDTH) + fractol->calc.move_x;
			fractol->calc.z_im = (y - HEIGHT / 2.0) / (0.5 * fractol->calc.y_coeff * HEIGHT) + fractol->calc.move_y;
			i = -1;
			while (++i < ITERATIONS)
				if (ft_julia(fractol) == 0)
					break;
			pixel_put(fractol, x, y, get_color(i, fractol));
		}
	}
}

void ft_threads(t_fractol *fractol)
{
	pthread_t threads[THREADS];
	t_fractol tmp_fractol[THREADS];
	INT2(x, 0, i, 0);
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
	mlx_clear_window(fractol->mlx, fractol->win);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->image, 0, 0);
	ft_menu(fractol);
}
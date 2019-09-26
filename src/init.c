/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:56:29 by pmartyny          #+#    #+#             */
/*   Updated: 2019/09/25 14:56:31 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_mlx_init(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	fractol->image = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->image_buf = (int *)mlx_get_data_addr(fractol->image,
	&fractol->bits_per_pixel, &fractol->size_line, &fractol->endian);
	fractol->win = mlx_new_window(fractol->mlx, WIDTH + MENU,
	HEIGHT, "FRACTOL");
}

void	ft_init(t_fractol *fractol)
{
	fractol->calc.move_x = 0.0;
	fractol->calc.move_y = 0.0;
	fractol->calc.re_max = 1.1;
	fractol->calc.re_min = -2.5;
	fractol->calc.im_max = 1.2;
	fractol->calc.im_min = -1.2;
	fractol->color_iterator = 1;
}

void	ft_init_julia(t_fractol *fractol)
{
	fractol->calc.c_re = -0.7;
	fractol->calc.c_im = 0.27015;
	fractol->calc.move_x = 0;
	fractol->calc.move_y = 0;
	fractol->calc.re_min = 0.0;
	fractol->calc.im_min = 0.0;
	fractol->calc.im_max = 1.0;
	fractol->calc.re_max = 1.0;
	fractol->color_iterator = 1;
}

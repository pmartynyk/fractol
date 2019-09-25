/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 10:54:02 by pmartyny          #+#    #+#             */
/*   Updated: 2019/09/24 10:54:03 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_usage(t_fractol *fractol)
{
	free(fractol);
	ft_printf("Usage:	./fractol (fractol name)\n");
	ft_printf("Fractal's: Mandelbrot; Julia\n");
	exit(0);
}

void pixel_put(t_fractol *fractol, int x, int y, int color)
{
	if (x < WIDTH && x >= 0 && y < HEIGHT && y >= 0)
		fractol->imageBuf[y * WIDTH + x] = color;
}

int get_color(int color, t_fractol *fractol)
{
	unsigned int rgb;
	unsigned char r;
	unsigned char g;
	unsigned char b;

	if (color == ITERATIONS)
		return (0);
	r = color * 1 * fractol->color_iterator;
	g = color * 2 * fractol->color_iterator;
	b = color * 5 * fractol->color_iterator;
	rgb = (r << 16) + (g << 8) + b;
	return (rgb);
}

int ft_take_fractal(t_fractol *fractol)
{
	if (!ft_strcmp(fractol->name, "Mandelbrot"))
		return (ft_mandelbrot(fractol));
	else if (!ft_strcmp(fractol->name, "Julia"))
		return (ft_julia(fractol));
	return (0);
}
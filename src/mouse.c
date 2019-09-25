/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:50:54 by pmartyny          #+#    #+#             */
/*   Updated: 2019/09/25 17:50:57 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static double		interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

static void		ft_interpol(t_fractol *fractol, double mr, double mi, double inter)
{
	fractol->calc.re_min = interpolate(mr, fractol->calc.re_min, inter);
	fractol->calc.im_min = interpolate(mi, fractol->calc.im_min, inter);
	fractol->calc.re_max = interpolate(mr, fractol->calc.re_max, inter);
	fractol->calc.im_max = interpolate(mi, fractol->calc.im_max, inter);
}

int			ft_mouse_scroll(int key, int x, int y, t_fractol *fractol)
{
	double	mousere;
	double	mouseim;
	double	inter;

	y = HEIGHT - y;
	if (key == 4)
	{
		inter = 1.0 / 1.1;
		mousere = (double)x / (WIDTH / (fractol->calc.re_max - fractol->calc.re_min))
		+ fractol->calc.re_min;
		mouseim = (double)y / (HEIGHT / (fractol->calc.im_max - fractol->calc.im_min))
		+ fractol->calc.im_min;
		ft_interpol(fractol, mousere, mouseim, inter);
	}
	else if (key == 5)
	{
		inter = 1.0 * 1.1;
		mousere = (double)x / (WIDTH / (fractol->calc.re_max - fractol->calc.re_min))
		+ fractol->calc.re_min;
		mouseim = (double)y / (HEIGHT / (fractol->calc.im_max - fractol->calc.im_min))
		+ fractol->calc.im_min;
		ft_interpol(fractol, mousere, mouseim, inter);
	}
	ft_threads(fractol);
	return (0);
}
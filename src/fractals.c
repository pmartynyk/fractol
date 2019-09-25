/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 11:03:14 by pmartyny          #+#    #+#             */
/*   Updated: 2019/09/24 11:03:18 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int ft_mandelbrot(t_fractol *fractol)
{
    double z_re_sq;
    double z_im_sq;

    z_re_sq = fractol->calc.z_re * fractol->calc.z_re;
    z_im_sq = fractol->calc.z_im * fractol->calc.z_im;
    fractol->calc.z_im = (2.0 * fractol->calc.z_re * fractol->calc.z_im) + fractol->calc.c_im;
    fractol->calc.z_re = z_re_sq - z_im_sq + fractol->calc.c_re;
    if (z_im_sq + z_re_sq > 4)
        return (0);
    return (1);
}

int		ft_julia(t_fractol *fractol)
{
	double	z_re_sq;
	double	z_im_sq;

	z_re_sq = fractol->calc.z_re * fractol->calc.z_re;
	z_im_sq = fractol->calc.z_im * fractol->calc.z_im;
	fractol->calc.z_im = (2.0 * fractol->calc.z_re * fractol->calc.z_im) + fractol->calc.c_im;
	fractol->calc.z_re = z_re_sq - z_im_sq + fractol->calc.c_re;
	if (z_im_sq + z_re_sq > 4)
		return (0);
	return (1);
}

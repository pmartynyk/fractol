/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 10:31:43 by pmartyny          #+#    #+#             */
/*   Updated: 2019/09/24 10:31:45 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int ft_check_button(int button, t_fractol *fractol)
{
	// ft_printf("%d\n", button);
	(void)fractol;
	if (button == 53)
		exit(0);
	if (button == 17)
		exit(0);
	if (button == 48)
		fractol->color_iterator++;
	else if (button == 15)
	{
		if (!ft_strcmp(fractol->name, "Julia"))
			ft_init_julia(fractol);
		else
			ft_init(fractol);
	}
	ft_threads(fractol);
	return (0);
}

static int ft_close(t_fractol *fractol)
{
	(void)fractol;
	exit(0);
}
static void ft_check_name(t_fractol *fractol, char *name)
{
	if (!ft_strcmp(name, "Mandelbrot"))
		fractol->name = name;
	else if (!ft_strcmp(name, "Julia"))
		fractol->name = name;
	else if (!ft_strcmp(name, "Tricorn"))
		fractol->name = name;
	else if (!ft_strcmp(name, "Burningship"))
		fractol->name = name;
	else
		ft_usage(fractol);

	if (!ft_strcmp(fractol->name, "Julia"))
		ft_init_julia(fractol);
	else
		ft_init(fractol);
	ft_threads(fractol);
}

int main(int argc, char **argv)
{
	t_fractol *fractol;

	if (argc == 2)
	{
		if (!(fractol = (t_fractol *)malloc(sizeof(t_fractol))))
			exit(0);
		ft_mlx_init(fractol);
		ft_check_name(fractol, argv[1]);
		mlx_hook(fractol->win, 2, 0, ft_check_button, fractol);
		mlx_hook(fractol->win, 17, 0, ft_close, fractol);
		mlx_hook(fractol->win, 4, 0, ft_mouse_scroll, fractol);
		mlx_loop(fractol->mlx);
	}
	else
		ft_printf("Usage: ./fractol [fractol name]\n");
}

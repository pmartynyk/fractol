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

static int	ft_check_button(int button, t_fractol *fractol)
{
	(void)fractol;
	if (button == 53)
		exit(0);
	if (button == 17)
		exit(0);
	// if (button == NUM_PLUS)
	// 	fdf->cam->step += 2;
	// else if (button == NUM_MINUS)
	// {
	// 	fdf->cam->step -= 2;
	// 	fdf->cam->step = (fdf->cam->step <= 0 ? 1 : fdf->cam->step);
	// }
	// else if (button == KEYDOWN)
	// 	fdf->cam->setx += 5;
	// else if (button == KEYLEFT)
	// 	fdf->cam->sety -= 5;
	// else if (button == KEYUP)
	// 	fdf->cam->setx -= 5;
	// else if (button == KEYRIGHT)
	// 	fdf->cam->sety += 5;
	// else
	// 	ft_check_button2(button, fdf);
	// ft_draw(fdf);
	return (0);
}

static int	ft_close(t_fractol *fractol)
{
	(void)fractol;
	exit(0);
}

static void ft_mlx_init(t_fractol *fractol)
{

	fractol->mlx = mlx_init();
	fractol->image = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->imageBuf = (int *)mlx_get_data_addr(fractol->image, &fractol->bits_per_pixel,
								  &fractol->size_line, &fractol->endian);
	fractol->win = mlx_new_window(fractol->mlx, WIDTH + MENU, HEIGHT, "FRACTOL");
}

int main(int argc, char **argv)
{
	(void)argv;
	t_fractol *fractol;

	if (argc == 2)
	{
		if (!(fractol = (t_fractol *)malloc(sizeof(t_fractol))))
			exit(0);
		ft_mlx_init(fractol);
		mlx_hook(fractol->win, 2, 0, ft_check_button, fractol);
		mlx_hook(fractol->win, 17, 0, ft_close, fractol);
		// mlx_hook(fractol->win, 4, 0, ft_mouse_move, fractol);
		mlx_loop(fractol->mlx);
	}
	else
		ft_printf("Usage: ./fractol [fractol name]\n");
}

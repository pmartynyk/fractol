/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 10:32:19 by pmartyny          #+#    #+#             */
/*   Updated: 2019/09/24 10:32:22 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft_printf/includes/ft_printf.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <pthread.h>

# define KEYUP 126
# define KEYDOWN 125
# define KEYLEFT 123
# define KEYRIGHT 124
# define O_BUTTON 31
# define NUM_PLUS 69
# define NUM_MINUS 78
# define PROJECTION1 18
# define PROJECTION2 19
# define MOVEUP 13
# define MOVEDOOWN 1
# define MOVELEFT 0
# define MOVERIGHT 2
# define WIDTH 1000
# define HEIGHT 600
# define MENU 250
# define THREADS 8
# define ITERATIONS 50
# define ERROR(x) { ft_printf(x); exit(0); }
# define INT1(a,av) int a=av
# define INT2(a,av,b,bv) int a=av,b=bv

typedef struct	s_calc
{
	double		move_x;
	double		move_y;
	double		re_min;
	double		re_max;
	double		im_min;
	double		im_max;
	double		c_re;
	double		c_im;
	double		z_im;
	double		z_re;
	double		x_coeff;
	double		y_coeff;
}				t_calc;

typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	void		*image;
	int			*image_buf;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	char		*name;
	int			start;
	int			end;
	int			color_iterator;
	t_calc		calc;

}				t_fractol;

void			ft_draw(t_fractol *fractol);
void			ft_draw_julia(t_fractol *fractol);
void			ft_threads(t_fractol *fractol);
void			ft_usage(t_fractol *fractol);
void			pixel_put(t_fractol *fractol, int x, int y, int color);
int				get_color(int color, t_fractol *fractol);
int				ft_take_fractal(t_fractol *fractol);
int				ft_mandelbrot(t_fractol *fractol);
int				ft_julia(t_fractol *fractol);
int				ft_tricorn(t_fractol *fractol);
int				ft_burningship(t_fractol *fractol);
void			ft_mlx_init(t_fractol *fractol);
void			ft_init(t_fractol *fractol);
void			ft_init_julia(t_fractol *fractol);
int				ft_mouse_scroll(int key, int x, int y, t_fractol *fractol);

#endif

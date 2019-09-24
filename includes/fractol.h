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
# define HEIGHT 1000
# define MENU 500

# define ERROR(x) { ft_printf(x); exit(0); }

typedef struct	s_fractol
{
	void	*mlx;
	void	*win;
	void	*image;
	int		*imageBuf;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_fractol;


#endif

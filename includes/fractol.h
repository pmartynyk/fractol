/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:23:58 by pmartyny          #+#    #+#             */
/*   Updated: 2019/03/28 14:24:00 by pmartyny         ###   ########.fr       */
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

# define ERROR(x) { ft_printf(x); exit(0); }




#endif

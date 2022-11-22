/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 09:05:09 by donpark           #+#    #+#             */
/*   Updated: 2021/09/01 09:05:09 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <math.h>
# include <errno.h>

# define PI		3.141592

# define RED	0x00FF0000
# define ORANGE	0x00FF8C00
# define YELLOW	0x00FFFF00
# define GREEN	0x00008000
# define BLUE	0x000000FF
# define INDIGO	0x004B0082
# define PURPLE	0x00800080

# define KEY_PRESS		2
# define KEY_RELEASE	3
# define BTN_PRESS		4
# define BTN_RELEASE	5

# if defined(__linux__)
#  define UP			65362
#  define DOWN			65364
#  define LEFT			65361
#  define RIGHT			65363
#  define ESC			65307
#  define PLUS			61
#  define MINUS			45
#  define NUMPAD_PLUS	65451
#  define NUMPAD_MINUS	65453
#  define NUM_1			49
#  define NUM_2			50
#  define NUM_3			51
#  define NUM_4			52
#  define NUM_5			53
#  define NUM_6			54
#  define LEFT_SQUARE	91
#  define RIGHT_SQUARE	93
#  define LEFT_ANGLE	44
#  define RIGHT_ANGLE	46

#  define MOUSE_LEFT		1
#  define MOUSE_WHEEL_CLICK	2
#  define MOUSE_RIGHT		3
#  define MOUSE_WHEEL_UP	4
#  define MOUSE_WHEEL_DOWN	5
# else
#  define UP			126
#  define DOWN			125
#  define LEFT			123
#  define RIGHT			124
#  define ESC			53

#  define PLUS			24
#  define MINUS			27
#  define NUMPAD_PLUS	69
#  define NUMPAD_MINUS	78
#  define NUM_1			18
#  define NUM_2			19
#  define NUM_3			20
#  define NUM_4			21
#  define NUM_5			23
#  define NUM_6			22
#  define LEFT_SQUARE	33
#  define RIGHT_SQUARE	30
#  define LEFT_ANGLE	43
#  define RIGHT_ANGLE	47

#  define MOUSE_LEFT		1
#  define MOUSE_WHEEL_CLICK	3
#  define MOUSE_RIGHT		2
#  define MOUSE_WHEEL_UP	4
#  define MOUSE_WHEEL_DOWN	5
# endif

typedef struct s_fdf
{
	void				*mlx;
	void				*win;
	int					width;
	int					height;
	char				*title;

	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;

	int					color;

	int					row;
	int					column;
	int					**z_matrix;
	struct s_control	*control;
}	t_fdf;

typedef struct s_bresenham
{
	int		x;
	int		y;
	int		x1;
	int		y1;
	int		z;
	int		z1;
	int		x_step;
	int		y_step;
	int		w;
	int		h;
	double	l;
	int		det;

}	t_bresenham;

typedef struct s_point
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
}	t_point;

typedef struct s_control
{
	int	zoom_in;
	int	zoom_out;
	int	zoom;

	int	left;
	int	right;
	int	up;
	int	down;
	int	shift_x;
	int	shift_y;

	int	rotate_x1;
	int	rotate_x2;
	int	rotate_y1;
	int	rotate_y2;
	int	rotate_z1;
	int	rotate_z2;
	int	alpha;
	int	beta;
	int	gamma;

	int	is_iso;
	int	iso_degree;

	int	z_value_up;
	int	z_value_down;
}	t_control;

void	get_row(char *file_name, t_fdf *data);
void	get_column(char *file_name, t_fdf *data);
void	read_file(char *file_name, t_fdf *data);

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
void	init_win(t_fdf *data);

void	fdf_memory_allocate(t_fdf **data);
void	final_free(t_fdf *data);

void	draw(t_fdf *data);
void	bresenham(t_point point, t_fdf *data);

void	zoom(t_bresenham *b, t_control *control);

void	rotate_x(t_bresenham *b, double alpha);
void	rotate_y(t_bresenham *b, double beta);
void	rotate_z(t_bresenham *b, double gamma);
void	iso(t_bresenham *b, t_control *control);

void	shift(t_bresenham *b, t_control *control);

void	set_color(t_bresenham *b, t_fdf *data);

int		key_press(int keycode, t_fdf *data);
int		key_release(int keycode, t_fdf *data);
void	direction_key(int keycode, t_fdf *data, int press_release);
void	zoom_key(int keycode, t_fdf *data, int press_release);
void	rotate_key(int keycode, t_fdf *data, int press_release);
void	z_value_key(int keycode, t_fdf *data, int press_release);
void	iso_plane_key(int keycode, t_fdf *data);

void	move_control(t_fdf *data);
void	zoom_control(t_fdf *data);
void	rotate_control(t_fdf *data);
void	z_matrix_control(t_fdf *data);

void	print_error(char *error);

void	z_matrix_print(t_fdf *data);
#endif

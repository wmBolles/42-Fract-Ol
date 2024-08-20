/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 09:59:52 by wabolles          #+#    #+#             */
/*   Updated: 2024/07/19 15:26:01 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static void	put_pixels_julia(int x, int y, t_xdata *fract)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	c.x = fract->julia_x;
	c.y = fract->julia_y;
	z.x = scaling(x, -2, 2) * fract->zoom;
	z.y = scaling(y, 2, -2) * fract->zoom;
	i = 0;
	while (i < MAX_ITER)
	{
		z = add_complex(square_complex(z), c);
		if (isinf(z.x) || isinf(z.y))
		{
			color = _rgb(i, 42, i * 42, i * i);
			pixel_img_put(fract, x, y, color);
			return ;
		}
		i++;
	}
	pixel_img_put(fract, x, y, 100);
}

void	rendering_julia(t_xdata *fract)
{
	int		x;
	int		y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			put_pixels_julia(x, y, fract);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fract->connect, fract->win, fract->img_ptr, 0, 0);
}

int	julia(char *name, double x, double y)
{
	t_xdata		data;

	data.julia_x = x;
	data.julia_y = y;
	data.connect = mlx_init();
	if (!data.connect)
		return (FAILURE);
	data.win = mlx_new_window(data.connect, WIDTH, HEIGHT, name);
	if (!data.win)
		return (mlx_destroy_window(data.connect, NULL), FAILURE);
	data.img_ptr = mlx_new_image(data.connect, WIDTH, HEIGHT);
	if (!data.img_ptr)
		return (mlx_destroy_window(data.connect, data.win), FAILURE);
	data.data_addr = mlx_get_data_addr(data.img_ptr,
			&data.bits_per_pixel,
			&data.size_len,
			&data.endian);
	data.zoom = 1.0;
	rendering_julia(&data);
	events_listiner_julia(&data);
	mlx_loop(data.connect);
	return (SUCCESS);
	return (0);
}

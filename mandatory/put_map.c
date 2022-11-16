/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:06:44 by mmardi            #+#    #+#             */
/*   Updated: 2022/03/20 14:13:58 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_moves(t_data *data)
{
	data->moves++;
	mlx_string_put(data->ptr, data->win, 10, 10, 0xffffff, "Moves");
	ft_putnbr(data->moves);
	ft_putchar('\n');
}

void	xpm_to_image(t_data *data)
{
	data->p1 = mlx_xpm_file_to_image(data->ptr, \
	"./img/b1.xpm", &data->a, &data->b);
	data->p2 = mlx_xpm_file_to_image(data->ptr, \
	"./img/b2.xpm", &data->a, &data->b);
	data->ground = mlx_xpm_file_to_image(data->ptr, \
	"./img/ground.xpm", &data->a, &data->b);
	data->wall = mlx_xpm_file_to_image(data->ptr, \
	"./img/wall.xpm", &data->a, &data->b);
	data->c = mlx_xpm_file_to_image(data->ptr, \
	"./img/collect.xpm", &data->a, &data->b);
	data->odoor = mlx_xpm_file_to_image(data->ptr, \
	"./img/door.xpm", &data->a, &data->b);
	data->cdoor = mlx_xpm_file_to_image(data->ptr, \
	"./img/bab.xpm", &data->a, &data->b);
}

void	put_image(t_data data, int x, int y)
{
	static int	c = 1;

	mlx_put_image_to_window(data.ptr, data.win, data.ground, x * 32, y * 32);
	if (data.map[y][x] == 'P' && c >= 50)
		mlx_put_image_to_window(data.ptr, data.win, data.p1, x * 32, y * 32);
	else if (data.map[y][x] == 'P' && c < 50)
		mlx_put_image_to_window(data.ptr, data.win, data.p2, x * 32, y * 32);
	else if (data.map[y][x] == '1')
		mlx_put_image_to_window(data.ptr, data.win, data.wall, x * 32, y * 32);
	else if (data.map[y][x] == 'C')
		mlx_put_image_to_window(data.ptr, data.win, data.c, x * 32, y * 32);
	else if (data.map[y][x] == 'E' && count_collects(data))
		mlx_put_image_to_window(data.ptr, data.win, data.cdoor, x * 32, y * 32);
	else if (data.map[y][x] == 'E' && count_collects(data) == 0)
		mlx_put_image_to_window(data.ptr, data.win, data.odoor, x * 32, y * 32);
	c++;
	if (c == 100)
		c = 0;
}

int	put_images(t_data *data)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			put_image(*data, i, j);
			i++;
		}
		j++;
	}
	return (0);
}

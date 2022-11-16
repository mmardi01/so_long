/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:44:36 by mmardi            #+#    #+#             */
/*   Updated: 2022/03/19 17:55:45 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_index(int *x, int *y, t_data *data)
{
	while (data->map[*y])
	{
		*x = 0;
		while (data->map[*y][*x])
		{
			if (data->map[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

void	move_right(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	check_index(&x, &y, data);
	if (data->map[y][x + 1] == '0')
	{
		data->map[y][x + 1] = 'P';
		data->map[y][x] = '0';
		put_moves(data);
	}
	if (data->map[y][x + 1] == 'C')
	{
		data->map[y][x + 1] = 'P';
		data->map[y][x] = '0';
		put_moves(data);
	}
	if (data->map[y][x + 1] == 'E' && count_collects(*data) == 0)
	{
		put_moves(data);
		write(1, "You Win!\n", 9);
		ft_exit(data);
	}
}

void	move_left(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	check_index(&x, &y, data);
	if (data->map[y][x - 1] == '0')
	{
		data->map[y][x - 1] = 'P';
		data->map[y][x] = '0';
		put_moves(data);
	}
	if (data->map[y][x - 1] == 'C')
	{
		data->map[y][x - 1] = 'P';
		data->map[y][x] = '0';
		put_moves(data);
	}
	if (data->map[y][x - 1] == 'E' && count_collects(*data) == 0)
	{
		put_moves(data);
		write(1, "You Win!\n", 9);
		ft_exit(data);
	}
}

void	move_up(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	check_index(&x, &y, data);
	if (data->map[y - 1][x] == '0')
	{
		data->map[y - 1][x] = 'P';
		data->map[y][x] = '0';
		put_moves(data);
	}
	if (data->map[y - 1][x] == 'C')
	{
		data->map[y - 1][x] = 'P';
		data->map[y][x] = '0';
		put_moves(data);
	}
	if (data->map[y - 1][x] == 'E' && count_collects(*data) == 0)
	{
		put_moves(data);
		write(1, "You Win!\n", 9);
		ft_exit(data);
	}
}

void	move_down(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	check_index(&x, &y, data);
	if (data->map[y + 1][x] == '0')
	{
		data->map[y + 1][x] = 'P';
		data->map[y][x] = '0';
		put_moves(data);
	}
	if (data->map[y + 1][x] == 'C')
	{
		data->map[y + 1][x] = 'P';
		data->map[y][x] = '0';
		put_moves(data);
	}
	if (data->map[y + 1][x] == 'E' && count_collects(*data) == 0)
	{
		put_moves(data);
		write(1, "You Win!\n", 9);
		ft_exit(data);
	}
}

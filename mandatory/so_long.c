/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:13:29 by mmardi            #+#    #+#             */
/*   Updated: 2022/03/22 13:03:56 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_data *data)
{
	ft_free(data);
	exit (0);
	return (0);
}

int	ft_keys(int key, t_data *data)
{
	if (key == 2)
		move_right(data);
	if (key == 0)
		move_left(data);
	if (key == 13)
		move_up(data);
	if (key == 1)
		move_down(data);
	if (key == 53)
		ft_exit(data);
	put_images(data);
	return (0);
}

void	put_error(void)
{
	write (2, "Error\n", 6);
	exit (1);
}

int	check_arg(int ac, char **av)
{
	int		fd;
	char	*str;

	fd = open(av[1], O_RDONLY);
	if (ac != 2)
		return (1);
	if (ft_strchr(av[1], '.') == 0)
		return (1);
	str = ft_strrchr(av[1], '.');
	if (ft_strcmp(".ber", str) != 0)
		return (1);
	if (fd == -1)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		width;
	int		height;

	if (check_arg(ac, av))
	{
		put_error();
	}
	read_map(av[1], &data);
	ft_check_length(data);
	ft_check_walls(&data);
	data.moves = 0;
	width = data.width * 32;
	height = data.height * 32;
	data.ptr = mlx_init();
	data.win = mlx_new_window(data.ptr, width, height, "so_long");
	xpm_to_image(&data);
	put_images(&data);
	mlx_hook(data.win, 2, 0, ft_keys, &data);
	mlx_hook(data.win, 17, 0, ft_exit, &data);
	mlx_loop_hook(data.ptr, put_images, &data);
	mlx_loop(data.ptr);
}

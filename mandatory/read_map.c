/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:24:18 by mmardi            #+#    #+#             */
/*   Updated: 2022/03/22 12:54:29 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_data *data)
{
	mlx_destroy_image(data->ptr, data->p1);
	mlx_destroy_image(data->ptr, data->p2);
	mlx_destroy_image(data->ptr, data->odoor);
	mlx_destroy_image(data->ptr, data->cdoor);
	mlx_destroy_image(data->ptr, data->c);
	mlx_destroy_image(data->ptr, data->ground);
	mlx_destroy_image(data->ptr, data->wall);
	mlx_destroy_window(data->ptr, data->win);
	free(data->map);
}

void	check_newlines(t_data *data, char *str)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	n = 0;
	while (data->map[i])
		i++;
	i--;
	while (str[j])
	{
		if (str[j] == '\n')
			n++;
		j++;
	}
	if (n != i)
		put_error();
}

char	*ft_read(int fd)
{
	char		*buff;
	int			n;
	static char	*res;

	buff = (char *)malloc(sizeof(char) * (2));
	if (!buff)
		return (NULL);
	n = 1;
	while (n)
	{
		n = read(fd, buff, 1);
		if (n == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[n] = '\0';
		res = ft_strjoin(res, buff);
	}
	free (buff);
	return (res);
}

void	read_map(char *filename, t_data *data)
{
	int		fd;		
	char	*str;

	fd = open(filename, O_RDONLY);
	str = ft_read(fd);
	ft_check_content(str);
	data->map = ft_split(str, '\n');
	check_newlines(data, str);
	free (str);
}

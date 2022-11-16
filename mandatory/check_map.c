/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:23:07 by mmardi            #+#    #+#             */
/*   Updated: 2022/03/17 14:31:50 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_walls(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < ft_strlen(data->map[0]))
		if (data->map[0][i++] != '1')
			put_error();
	data->width = i;
	while (data->map[j])
		if (data->map[j++][i - 1] != '1')
			put_error();
	i = 0;
	while (i < ft_strlen(data->map[0]))
		if (data->map[j - 1][i++] != '1')
			put_error();
	j = 0;
	while (data->map[j])
		if (data->map[j++][0] != '1')
			put_error();
	data->height = j;
}

void	ft_check_length(t_data data)
{
	int	i;
	int	j;

	i = ft_strlen(data.map[0]);
	j = 1;
	while (data.map[j])
	{
		if (ft_strlen(data.map[j]) != i)
			put_error();
		j++;
	}
}

void	ft_check_content(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[0] == '\n')
		put_error();
	if (ft_strchr(str, '0') == NULL)
		put_error();
	if (ft_strchr(str, 'C') == NULL)
		put_error();
	if (ft_strchr(str, 'E') == NULL)
		put_error();
	while (str[i])
	{
		if (str[i] == 'P')
			j++;
		if (str[i] != 'C' && str[i] != 'P' && str[i] != '1' && str[i] != '0' \
		&& str[i] != '\n' && str[i] != 'E')
			put_error();
		i++;
	}
	if (j != 1)
		put_error();
}

int	count_collects(t_data data)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (data.map[j])
	{
		i = 0;
		while (data.map[j][i])
		{
			if (data.map[j][i] == 'C')
				c++;
			i++;
		}
		j++;
	}
	return (c);
}

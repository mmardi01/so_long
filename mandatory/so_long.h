/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:16:31 by mmardi            #+#    #+#             */
/*   Updated: 2022/03/21 14:04:39 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include<fcntl.h>
# include<stdio.h>
# include<stdlib.h>
# include<mlx.h>
# include<math.h>
# include <unistd.h>

typedef struct t_data
{
	char	**map;
	int		width;
	int		height;
	void	*ptr;
	void	*win;
	void	*p1;
	void	*p2;
	void	*odoor;
	void	*cdoor;
	void	*c;
	void	*ground;
	void	*wall;
	int		x;
	int		y;
	int		a;
	int		b;
	int		moves;
}	t_data;

void	read_map(char *filename, t_data *data);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(char *s, char *p);
void	ft_check_walls(t_data *data);
void	put_error(void);
int		put_images(t_data *data);
void	ft_check_length(t_data data);
char	**ft_split(const char *s, char c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, char c);
int		ft_strlen(const char	*str);
void	ft_check_content(char *str);
void	xpm_to_image(t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);
int		count_collects(t_data data);
void	ft_putnbr(unsigned int n);
void	put_moves(t_data *data);
void	ft_putchar(char c);
char	*ft_itoa(int nbr);
int		ft_exit(t_data *data);
void	ft_free(t_data *data);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiban <kchiban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:43:58 by kchiban           #+#    #+#             */
/*   Updated: 2023/06/08 01:02:17 by kchiban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include "getline/get_next_line.h"
# include "f_printf/ft_printf.h"

typedef struct t_drawing{
	void	*mlx;
	void	*img;
	void	*mlx_win;
	int		map_len;
	int		map_char;
	char	**check_path;
	char	**check_pat;
	int		player_i;
	int		player_j;
	int		collection;
	int		player;
	int		exit;
	int		img_height;
	int		img_width;
	char	**str;
	int		move;
	int		len;
	int		fd;
}				t_draw;

void	check_map_items(char *str);
void	*ft_calloc(size_t count, size_t size);
void	ft_putnbr_fd(int n, int fd);
void	images(t_draw *data);
void	wall_a(char **str, t_draw *data);
void	wall_b(char **str, t_draw *data);
void	wall_c(char **str, t_draw *data);
void	wall_d(char **str, t_draw *data);
void	wall_e(char **str, t_draw *data);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
void	parsing(t_draw *data);
void	check_map(t_draw *data);
void	print_error(char *str);
void	check_path1(int i, int j, t_draw *data);
void	check_path(int i, int j, t_draw *data);
void	check_path_valid(t_draw *data);
void	ft_images(char *str, t_draw *data, int i, int j);
int		render(int nbr, t_draw *data);
void	change_player_map(t_draw *data);
void	change_player_map1(t_draw *data);
void	change_player_map2(t_draw *data);
void	change_player_map3(t_draw *data);
void	print_error(char *str);
void	check_new_line(char *str);
int		mouse(void);
#endif 

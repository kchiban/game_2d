/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiban <kchiban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:36:08 by kchiban           #+#    #+#             */
/*   Updated: 2023/06/08 00:30:05 by kchiban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_a(char **str, t_draw *data)
{
	int	i;
	int	s;

	s = 0;
	i = 0;
	while (str[s++])
		data->map_len = s - 1;
	s = 0;
	while (str[0][s++])
		data->map_char = s - 1;
	while (str[i][0])
	{
		if (str[i][0] != '1')
		{
			print_error("check your walls !");
			exit(1);
		}
		if (i == data->map_len)
			break ;
		i++;
	}
}

void	wall_b(char **str, t_draw *data)
{
	int	i;
	int	s;

	s = 0;
	i = 0;
	while (str[s++])
		data->map_len = s - 1;
	s = 0;
	while (str[0][s++])
		data->map_char = s - 1;
	while (str[0][i])
	{
		if (str[0][i] != '1')
		{
			print_error("check your walls !");
			exit(1);
		}
		if (i == data->map_char)
			break ;
		i++;
	}
}

void	wall_c(char **str, t_draw *data)
{
	int	i;

	i = 0;
	while (str[i][data->map_char])
	{
		if (str[i][data->map_char] != '1')
		{
			print_error("check your walls !");
			exit(1);
		}
		if (i == data->map_len)
			break ;
		i++;
	}
}

void	wall_d(char **str, t_draw *data)
{
	int	i;

	i = 0;
	while (str[data->map_len][i])
	{
		if (str[data->map_len][i] != '1')
		{
			print_error("check your walls !");
			exit(1);
		}
		if (i == data->map_char)
			break ;
		i++;
	}
}

void	wall_e(char **str, t_draw *data)
{
	int	i;
	int	s;
	int	d;

	i = 0;
	s = 0;
	d = 0;
	while (str[data->map_len])
		data->map_len++;
	while (str[i])
	{
		s = 0;
		while (str[i][s] != '\0')
			s++;
		if (i > 0)
		{
			if (d != s)
				print_error("check the len of your map !");
		}
		d = s;
		if (i == data->map_len)
			break ;
		i++;
	}
}

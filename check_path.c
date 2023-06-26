/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiban <kchiban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:20:08 by kchiban           #+#    #+#             */
/*   Updated: 2023/06/08 00:29:28 by kchiban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_path_valid(t_draw *data)
{
	int	i;
	int	s;

	i = 0;
	while (data->check_path[i])
	{
		s = 0;
		while (data->check_path[i][s])
		{
			if (data->check_path[i][s] == 'C' || data->check_path[i][s] == 'P'
				|| data->check_pat[i][s] == 'E')
				print_error("this map is not valid !");
			s++;
		}
		i++;
	}
}

void	check_path1(int i, int j, t_draw *data)
{
	if (i < 0 || j < 0 || i >= data->map_len || j >= data->map_char
		||data->check_path[i][j] == '1' || data->check_path[i][j] == 'E')
		return ;
	data->check_path[i][j] = '1';
	check_path1(i + 1, j, data);
	check_path1(i - 1, j, data);
	check_path1(i, j + 1, data);
	check_path1(i, j - 1, data);
}

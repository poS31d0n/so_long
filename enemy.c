/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscot <sscot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:56:23 by hjanis            #+#    #+#             */
/*   Updated: 2022/03/13 14:54:01 by sscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	enemy_grass(t_data *data, t_tilestruct	*tile, int i)
{
	data->enemy[i].tile->type = EMPTY;
	tile->type = ENEMY;
	if (data->enemy[i].tile->type != EXIT)
		data->enemy[i].tile->type = EMPTY;
	data->enemy[i].tile = tile;
}

void	enemy_player(t_data *data, t_tilestruct	*tile, int i)
{
	tile->type = ENEMY;
	data->enemy[i].tile = tile;
	exit(1);
}

void	enemy_move_up(t_data *data, t_tilestruct *tile, int frame, int i)
{
	if (tile->type == EMPTY)
		enemy_grass(data, tile, i);
	if (tile->type == PLAYER)
	{
		enemy_player(data, tile, i);
	}
	if (tile->type == WALL)
		frame = 0;
	else
		return ;
}

void	enemy_move_down(t_data *data, t_tilestruct *tile, int frame, int i)
{
	if (tile->type == EMPTY)
		enemy_grass(data, tile, i);
	if (tile->type == PLAYER)
	{
		enemy_player(data, tile, i);
	}
	if (tile->type == WALL)
		frame = 300;
	else
		return ;
}

int	enemy(t_data *data)
{
	static int		frame;
	int				i;

	i = -1;
	while (++i < data->enemy_count)
	{
		if (!frame)
			frame = 0;
		if (frame < 800)
		{
			if (frame % 80 == 0)
				enemy_move_down(data, data->enemy[i].tile->down, frame, i);
			frame++;
		}
		if (frame >= 800 && frame < 1600)
		{
			if (frame % 80 == 0)
				enemy_move_up(data, data->enemy[i].tile->up, frame, i);
			frame++;
		}
		if (frame == 1600)
			frame = 0;
	}
	return (1);
}

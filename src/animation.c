/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmago <mmago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 00:06:25 by mmago             #+#    #+#             */
/*   Updated: 2022/04/11 21:08:41 by mmago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_stop_check(t_game *game)
{
	if (game->game == 1)
	{
		game->img[4] = NULL;
		game->img[4] = mlx_xpm_file_to_image(game->mlx, PLAYER7,
				&game->img_width, &game->img_height);
	}
	if (game->game == 2)
	{
		game->img[4] = NULL;
		game->img[4] = mlx_xpm_file_to_image(game->mlx, WINN,
				&game->img_width, &game->img_height);
	}
}

void	anim_render(t_game *game, char *coin, char *player, int anim)
{
	if (anim % 100 > 100)
		anim = 0;
	if (anim % 100 > 10)
	{
		game->img[5] = NULL;
		game->img[5] = mlx_xpm_file_to_image(game->mlx, ENEMY1,
				&game->img_width, &game->img_height);
	}
	if (anim % 100 > 50)
	{
		game->img[5] = NULL;
		game->img[5] = mlx_xpm_file_to_image(game->mlx, ENEMY,
				&game->img_width, &game->img_height);
	}
	if (game->count_c == 0)
		game->img[2] = mlx_xpm_file_to_image(game->mlx, EXIT0,
				&game->img_width, &game->img_height);
	game->img[3] = NULL;
	game->img[3] = mlx_xpm_file_to_image(game->mlx, coin,
			&game->img_width, &game->img_height);
	game->img[4] = NULL;
	game->img[4] = mlx_xpm_file_to_image(game->mlx, player,
			&game->img_width, &game->img_height);
	ft_stop_check(game);
}

int	t_anim(t_game *game)
{
	static int	anim;

	anim += 2;
	if (anim % 100 > 10)
		anim_render(game, COIN, PLAYER, anim);
	if (anim % 100 > 20)
		anim_render(game, COIN1, PLAYER1, anim);
	if (anim % 100 > 30)
		anim_render(game, COIN2, PLAYER2, anim);
	if (anim % 100 > 40)
		anim_render(game, COIN3, PLAYER3, anim);
	if (anim % 100 > 50)
		anim_render(game, COIN4, PLAYER4, anim);
	if (anim % 100 > 60)
		anim_render(game, COIN5, PLAYER5, anim);
	if (anim % 100 > 70)
		anim_render(game, COIN6, PLAYER6, anim);
	if (anim % 100 > 80)
		anim_render(game, COIN7, PLAYER3, anim);
	if (anim % 100 > 90)
		anim_render(game, COIN8, PLAYER2, anim);
	if (anim % 100 > 100)
		anim_render(game, COIN9, PLAYER1, anim);
	ft_render(game);
	return (1);
}

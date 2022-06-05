/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmago <mmago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 22:45:08 by mmago             #+#    #+#             */
/*   Updated: 2022/04/11 21:08:44 by mmago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_img_init(t_game *game)
{
	game->img[0] = mlx_xpm_file_to_image(game->mlx, WALL0,
			&game->img_width, &game->img_height);
	game->img[1] = mlx_xpm_file_to_image(game->mlx, WALL1,
			&game->img_width, &game->img_height);
	game->img[2] = mlx_xpm_file_to_image(game->mlx, EXIT1,
			&game->img_width, &game->img_height);
	game->img[3] = mlx_xpm_file_to_image(game->mlx, COIN,
			&game->img_width, &game->img_height);
	game->img[4] = mlx_xpm_file_to_image(game->mlx, PLAYER,
			&game->img_width, &game->img_height);
	game->img[5] = mlx_xpm_file_to_image(game->mlx, ENEMY,
			&game->img_width, &game->img_height);
}

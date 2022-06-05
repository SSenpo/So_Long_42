/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmago <mmago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 22:45:42 by mmago             #+#    #+#             */
/*   Updated: 2022/04/11 21:08:46 by mmago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keysum, t_game *game)
{
	if ((keysum == 0 || keysum == 1 || keysum == 2 || keysum == 3
			|| keysum == 13) && game->game == 0)
	{
		ft_p_move(keysum, game);
	}
	if (keysum == 53)
	{
		ft_printf("EXIT GAME\n");
		mlx_destroy_window(game->mlx, game->win);
		ft_free(game);
		exit(0);
	}
	return (1);
}

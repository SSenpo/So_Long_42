/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmago <mmago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 22:45:56 by mmago             #+#    #+#             */
/*   Updated: 2022/04/11 21:08:11 by mmago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define EXIT0 "img/exit/exit.xpm"
# define EXIT1 "img/exit/no_exit.xpm"
# define WINN "img/exit/winn.xpm"
# define WALL0 "img/place/place100.xpm"
# define WALL1 "img/walls/5.xpm"
# define COIN "img/coin1/01.xpm"
# define COIN1 "img/coin1/02.xpm"
# define COIN2 "img/coin1/03.xpm"
# define COIN3 "img/coin1/04.xpm"
# define COIN4 "img/coin1/05.xpm"
# define COIN5 "img/coin1/06.xpm"
# define COIN6 "img/coin1/07.xpm"
# define COIN7 "img/coin1/08.xpm"
# define COIN8 "img/coin1/09.xpm"
# define COIN9 "img/coin1/010.xpm"
# define PLAYER "img/player/1.xpm"
# define PLAYER1 "img/player/2.xpm"
# define PLAYER2 "img/player/3.xpm"
# define PLAYER3 "img/player/4.xpm"
# define PLAYER4 "img/player/5.xpm"
# define PLAYER5 "img/player/6.xpm"
# define PLAYER6 "img/player/7.xpm"
# define PLAYER7 "img/player/8.xpm"
# define ENEMY "img/enemy/1.xpm"
# define ENEMY1 "img/enemy/2.xpm"

typedef struct s_game
{
	void				*mlx;
	void				*win;
	void				*img[6];
	int					img_width;
	int					img_height;					
	int					fd;
	int					move;
	int					h_map;
	int					w_map;
	int					p_x;
	int					p_y;
	int					count_p;
	int					count_c;
	int					count_e;
	int					count_enemy;
	char				**map;
	int					a;
	int					s;
	int					d;
	int					f;
	int					game;
}				t_game;

// ERROR FUNCTION
void	ft_error(int i, t_game *game);
void	ft_free(t_game *game);
int		ft_close(t_game *game);
int		ft_end(int i, t_game *game);

// MAP VALIDATION
void	ft_null(t_game *game);
void	h_w_map(t_game *game);
void	map_walls(t_game *game);
void	map_valid(t_game *game);
void	map_characters(t_game *game);
void	ft_read_map(t_game *game, char **av);

// IMG
void	ft_img_init(t_game *game);

// ANIMATION
int		t_anim(t_game *game);
void	anim_render(t_game *game, char *coin, char *player, int anim);

// RENDER
void	ft_render(t_game *game);
void	ft_render_map(t_game *game);

// SO_LONG function's
int		main(int ac, char **av);

// PLAYER
int		key_hook(int keysum, t_game *game);
void	ft_p_move(int keysum, t_game *game);
void	p_move_down(t_game *game);
void	p_move_up(t_game *game);
void	p_move_right(t_game *game);
void	p_move_left(t_game *game);

#endif
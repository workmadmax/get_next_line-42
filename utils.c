/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:17:15 by mdouglas          #+#    #+#             */
/*   Updated: 2022/09/23 20:46:19 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verify_obj(t_game *game)
{
	if (game->map[game->player.y][game->player.x] == 'C')
		game->player.collect++;
	if (game->map[game->player.y][game->player.x] == 'E'
		&& game->player.collect == game->gems)
		exit_game(game);
}

int	count_line(char *arg)
{
	char	*temps;
	int		fd;
	int		i;

	fd = 0;
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (printf("Error\n"), 1);
	temps = get_next_line(fd);
	i = 1;
	while (temps)
	{
		free(temps);
		temps = get_next_line(fd);
		++i;
	}
	free(temps);
	close(fd);
	return (i);
}


void	set_map(t_game *game)
{
	game->info_map.mapLen = ft_strlen(game->map[0]);
	game->info_map.mapHei = count_line(game->argv);
	game->info_map.wall = "./imgs/sand.xpm";
	game->info_map.coll = "./imgs/coll.xpm";
	game->info_map.player = "./imgs/play1.xpm";
	game->info_map.exit = "./imgs/exit.xpm";
	game->info_map.grass = "./imgs/grass.xpm";
}

void	set_game(t_game *game)
{
	game->steps = 1;
	game->gems = 0;
	game->player.collect = 0;
	game->player.total = 0;
}

void	check_ext(char *file, int argc)
{
	char *ext;

	if (argc < 2)
		printf("Error nos argumentos passados\n");
	ext = ft_strrchr(file, '.');
	if (!ext || ft_strncmp(ext, ".ber", 4) != 0)
		printf("Mapa precisa ser .ber\n");
}

void	set_hero(t_game *game, int x, int y, char elem)
{
	if (elem == 'P')
	{
		game->player.total += 1;
		game->player.x = x;
		game->player.y = y;
	}
}

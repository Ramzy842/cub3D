/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:10:22 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/24 08:03:24 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	fill_scene(char *scene_path, char **scene)
{
	int		fd;
	char	*line;
	int		x;

	fd = open(scene_path, O_RDONLY);
	line = get_next_line(fd);
	x = 0;
	while (line)
	{
		scene[x] = line;
		x++;
		line = get_next_line(fd);
	}
}

char	**read_scene(char *scene_path)
{
	char	*line;
	char	**scene;
	int		row_count;
	int		fd;

	fd = open(scene_path, O_RDONLY);
	row_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		row_count++;
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	free(line);
	scene = malloc((row_count + 1) * (sizeof(char *)));
	scene[row_count] = NULL;
	close(fd);
	fill_scene(scene_path, scene);
	return (scene);
}

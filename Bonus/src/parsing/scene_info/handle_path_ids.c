/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_path_ids.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 03:50:19 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/26 12:46:03 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	handle_texture_path_absence(char *path, char **str, char *id)
{
	printf("\x1b[31mError\nCannot open file %s\x1b[0m\n", path);
	free(id);
	free(path);
	free_2d_arr(str);
	return (0);
}

int	handle_valid_id(t_element *list, char *path, char *id, char **str)
{
	int	pfd;

	pfd = open(path, O_RDONLY | O_EXCL);
	if (pfd == -1)
		return (handle_texture_path_absence(path, str, id));
	edit_node(&list, id, path, NULL);
	free(id);
	free(path);
	free_2d_arr(str);
	return (1);
}

int	handle_invalid_id(char *id, char *path)
{
	printf("\x1b[31mError\nInvalid path identifier!\x1b[0m\n");
	if (id)
		free(id);
	if (path)
		free(path);
	return (0);
}

int	handle_already_found_id(char *id, char **str)
{
	free(id);
	free_2d_arr(str);
	return (0);
}

int	handle_path_ids(t_element *list, char *id, char **str)
{
	char	*path; 
	int		len;
	int		res;

	path = NULL;
	len = 0;
	res = 0;
	if (is_already_found(list, id, NULL))
		return (handle_already_found_id(id, str));
	len = ft_2d_len(str);
	if (str[1])
		path = ft_strdup(str[1]);
	if (len == 2)
	{
		res = handle_valid_id(list, path, id, str);
		if (!res)
			return (res);
	}
	else
		return (handle_invalid_id(id, path));
	return (1);
}

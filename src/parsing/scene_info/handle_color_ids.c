/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_color_ids.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 08:40:09 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/26 12:33:50 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	handle_already_found_id_or_comma(char *id, char **spl,
		char *temp, char **str)
{
	free(id);
	if (temp)
		free(temp);
	if (spl)
		free_2d_arr(spl);
	free_2d_arr(str);
	return (0);
}

void	handle_valid_color_id(t_element *list, char **spl,
	char *id, char **colors)
{
	edit_node(&list, id, NULL, colors);
	free_2d_arr(spl);
	free(id);
}

int	handle_invalid_color_id(char *id, char **colors, char **spl, char **str)
{
	printf("\x1b[31mError\nInvalid color identifier!\x1b[0m\n");
	if (id)
		free(id);
	if (colors)
		free_2d_arr(colors);
	if (spl)
		free_2d_arr(spl);
	if (str)
		free_2d_arr(str);
	return (0);
}

int	handle_invalid_identifier(char *id, char **str)
{
	printf("\x1b[31mError\n%s is not a valid identifier!\x1b[0m\n", id);
	if (id)
		free(id);
	if (str)
		free_2d_arr(str);
	return (0);
}

int	handle_color_ids(char **str, char *id, t_element *list, char *line)
{
	int		len;
	char	*tmp_str;
	char	*temp;
	char	**spl;
	char	**colors;

	spl = ft_split(line, ' ');
	temp = join_2d_arr(spl);
	tmp_str = NULL;
	if (temp)
		tmp_str = ft_strdup(&temp[1]);
	if (is_already_found(list, id, tmp_str) || fails_by_commas(tmp_str))
		return (handle_already_found_id_or_comma(id, spl, temp, str));
	free(tmp_str);
	if (temp)
		free(temp);
	colors = NULL;
	colors = run_operations(&len, str);
	if (is_valid_color_id(len, colors))
		handle_valid_color_id(list, spl, id, colors);
	else
		return (handle_invalid_color_id(id, colors, spl, str));
	free_2d_arr(str);
	return (1);
}

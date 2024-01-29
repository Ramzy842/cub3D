/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_color_ids_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:33:33 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/29 19:04:55 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

char	**trim_arr(char **colors)
{
	int		x;
	char	*str;
	char	**new_colors;

	x = 0;
	str = NULL;
	new_colors = malloc((sizeof(char *) + 1) * ft_2d_len(colors));
	if (!new_colors)
		return (NULL);
	while (colors[x])
	{
		str = ft_strtrim(colors[x], " \t\n\r");
		new_colors[x] = str;
		x++;
	}
	new_colors[x] = NULL;
	free_2d_arr(colors);
	return (new_colors);
}

char	**run_operations(char *str)
{
	char	**tmp_colors;
	char	**colors;

	tmp_colors = ft_split(&str[1], ',');
	colors = trim_arr(tmp_colors);
	return (colors);
}

int	is_valid_color_id(char **colors)
{
	if (ft_2d_len(colors) == 3 && are_numeric_values(colors)
		&& are_rgb_numbers(colors))
		return (1);
	return (0);
}

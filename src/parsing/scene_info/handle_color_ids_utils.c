/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_color_ids_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:33:33 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/26 12:35:29 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

char	**run_operations(int *len, char **str)
{
	char	**colors;
	char	*temp_str_2;

	*len = ft_2d_len(str);
	colors = strdup_2d_arr(&str[1]);
	temp_str_2 = join_2d_arr(colors);
	free_2d_arr(colors);
	colors = custom_split2(temp_str_2);
	free(temp_str_2);
	return (colors);
}

int	is_valid_color_id(int len, char **colors)
{
	if (len == 2 && are_numeric_values(colors)
		&& are_rgb_numbers(colors))
		return (1);
	return (0);
}

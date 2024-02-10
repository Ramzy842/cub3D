/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:24:19 by rchahban          #+#    #+#             */
/*   Updated: 2024/02/10 15:10:25 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void init_map_props(t_scene *scene)
{
    scene->map_cols = ft_strlen(scene->map[0]);
    scene->map_rows = ft_2d_len(scene->map);
}

int process_scene_config(t_scene *scene, char **scene_config, t_element **list)
{
    int count;
    int map_lines;
    int map_start_pos;

    init_elements(list);
    map_start_pos = 0;
    count = get_scene_info_count(scene_config, &map_start_pos);
    scene->scene_info = get_scene_info(scene_config, &count);
    if (ft_2d_len(scene->scene_info) < 6)
        return (1);
    map_lines = get_map_count(scene_config, &map_start_pos);
    scene->map = NULL;
    scene->temp_map = get_scene_map(scene_config, map_lines, &map_start_pos);
    if (!scene->temp_map)
    {
        printf("\x1b[31mError\nMissing or invalid map!\x1b[0m\n");
        return (0);
    }
    scene->biggest_len = extract_biggest_line_len(scene->temp_map);
    scene->map = rebuild_map(scene->temp_map, scene->biggest_len);
    get_player_props(scene);
    init_map_props(scene);
    return (1);
}

void drawCircle(t_mymlx *mymlx)
{
    int radiuserr;   
    int cy;
    int radius = 10;
    cy = 0;
    radiuserr = 1 - radius;
    while (radius >= cy)
    {
        mlx_put_pixel(mymlx->img, (mymlx->x + radius)*0.4, (mymlx->y - cy)*0.4, mymlx->circleColor);
        mlx_put_pixel(mymlx->img, (mymlx->x - radius)*0.4, (mymlx->y - cy)*0.4, mymlx->circleColor);
        mlx_put_pixel(mymlx->img, (mymlx->x + cy)*0.4, (mymlx->y - radius)*0.4, mymlx->circleColor);
        mlx_put_pixel(mymlx->img, (mymlx->x - cy)*0.4, (mymlx->y - radius)*0.4, mymlx->circleColor);
        mlx_put_pixel(mymlx->img, (mymlx->x + radius)*0.4, (mymlx->y + cy)*0.4, mymlx->circleColor);
        mlx_put_pixel(mymlx->img, (mymlx->x - radius)*0.4, (mymlx->y + cy)*0.4, mymlx->circleColor);
        mlx_put_pixel(mymlx->img, (mymlx->x + cy)*0.4, (mymlx->y+ radius)*0.4, mymlx->circleColor);
        mlx_put_pixel(mymlx->img, (mymlx->x - cy)*0.4, (mymlx->y + radius)*0.4, mymlx->circleColor);
        cy++;
        if (radiuserr  < 0)
            radiuserr  += 2 * cy + 1;
        else
        {
            radius--;
            radiuserr  += 2 * (cy - radius + 1);
        }
    }
}



void get_scene_info_values(t_scene *scene)
{
    t_element *current;

    current = scene->info_list;
    while (current)
    {
        if (!ft_strcmp(current->id, "EA"))
            scene->ea_texture = current->path;
        else if (!ft_strcmp(current->id, "WE"))
            scene->we_texture = current->path;
        else if (!ft_strcmp(current->id, "SO"))
            scene->so_texture = current->path;
        else if (!ft_strcmp(current->id, "NO"))
            scene->no_texture = current->path;
        else if (!ft_strcmp(current->id, "F"))
            scene->floor_colors = current->colors;
        else if (!ft_strcmp(current->id, "C"))
            scene->ceiling_colors = current->colors;
        current = current->next;
    }
}

void init_var(t_scene *scene)
{
    scene->mymlx->fov_angle = 60 * (M_PI / 180);
    scene->mymlx->movespeed = 15.0;
    scene->mymlx->rotation_speed = scene->mymlx->movespeed * (M_PI / 180);
    scene->mymlx->num_rays = WIDTH;
    playertype(scene);
    get_text(scene);
}
void mlx_initiate(t_scene *scene)
{
    scene->mymlx->mlx = mlx_init(WIDTH, HEIGHT, "kalkabut", true);
    scene->mymlx->img = mlx_new_image(scene->mymlx->mlx,
                                      scene->map_cols * BLOCK, scene->map_rows * BLOCK);
    scene->mymlx->img2 = mlx_new_image(scene->mymlx->mlx, WIDTH, HEIGHT);
    mlx_image_to_window(scene->mymlx->mlx, scene->mymlx->img2, 0, 0);
    mlx_image_to_window(scene->mymlx->mlx, scene->mymlx->img, 0, 0);
    scene->mymlx->x = scene->x;
    scene->mymlx->y = scene->y;
}

int initiate_gfx(t_scene *scene)
{
    if (scene->map)
    {
        scene->mymlx = (t_mymlx *)malloc(sizeof(t_mymlx));
        ft_memset(scene->mymlx, 0, sizeof(t_mymlx));
        get_scene_info_values(scene);
        init_var(scene);
        getcolors(scene);
        mlx_initiate(scene);
        mlx_loop_hook(scene->mymlx->mlx, ft_hook, scene);
        mlx_loop(scene->mymlx->mlx);
        mlx_terminate(scene->mymlx->mlx);
    }
    if (scene->scene_info)
        free_2d_arr(scene->scene_info);
    free_list(scene->info_list);
    return (0);
}

int scene_config_is_empty(char **scene_config)
{
    char *str;
    int x;

    x = 0;
    str = NULL;
    while (scene_config[x])
    {
        str = ft_strtrim(scene_config[x], " \t\n\r");
        if (ft_strlen(str))
        {
            free(str);
            str = NULL;
            return (0);
        }
        free(str);
        str = NULL;
        x++;
    }
    printf("\x1b[31mError\nThe file you used is empty!\x1b[0m\n");
    free_2d_arr(scene_config);
    return (1);
}

int main(int argc, char **argv)
{
    t_scene scene;
    char **scene_config;
    int is_valid_scene_info;
    int is_valid_map;

    if (argc != 2 || argv[2])
        return (1);
    if (!valid_extension(argv[1]))
        return (1);
    scene_config = read_scene(argv[1]);
    if (scene_config_is_empty(scene_config))
        return (1);
    if (!process_scene_config(&scene, scene_config, &(scene.info_list)))
        return (1);
    is_valid_scene_info = valid_scene_info(scene.scene_info, scene.info_list);
    is_valid_map = valid_map(scene.temp_map, &scene);
    if (is_valid_scene_info && is_valid_map)
        initiate_gfx(&scene);
    else
    {
        free_list(scene.info_list);
        return (1);
    }
    return (0);
}

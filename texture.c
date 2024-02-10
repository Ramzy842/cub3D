/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:52:38 by mbouderr          #+#    #+#             */
/*   Updated: 2024/02/10 13:03:57 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void text_checker( mlx_texture_t *texture)
{
    if (!texture || texture->height != 32 || texture->width != 32){
        printf("texture size is incorrect\n");
        exit(1);
        }
}

mlx_texture_t    *text_so(t_scene *scene)
{
    scene->mymlx->so = mlx_load_png(scene->so_texture);
    printf("this is SO texture %s\n", scene->so_texture);
    if (scene->mymlx->so == NULL){
            puts("No so texture\n");
           free(scene->mymlx);
         exit(0);
    }
    text_checker(scene->mymlx->so);
    return scene->mymlx->so;
}
 mlx_texture_t*   text_no(t_scene *scene)
{
    scene->mymlx->no = mlx_load_png(scene->no_texture);
    if (scene->mymlx->no == NULL){
                    puts("No no texture\n");
        free(scene->mymlx);
                    // mlx_delete_texture(scene->mymlx->no);
        exit(0);
    }
       text_checker(scene->mymlx->no);

    return scene->mymlx->no;
}
  mlx_texture_t*    text_ea(t_scene *scene)
{
    scene->mymlx->ea = mlx_load_png(scene->ea_texture);
    if (scene->mymlx->ea == NULL){
                    puts("No  ea texture\n");
                    free(scene->mymlx);
                            exit(0);
    }
        text_checker(scene->mymlx->ea);

    return  scene->mymlx->ea;
}
 mlx_texture_t*    text_we(t_scene *scene)
{
    scene->mymlx->we = mlx_load_png(scene->we_texture);
    if (scene->mymlx->we == NULL){
        free(scene->mymlx);
            exit(0);
    }
        text_checker(scene->mymlx->we);

    return scene->mymlx->we; 

}

void get_text(t_scene *scene)
{
    scene->mymlx->ea =  text_ea(scene); 
    scene->mymlx->no  = text_no(scene);
    scene->mymlx->so =  text_so(scene);
    scene->mymlx->we =  text_we(scene);
}

 


int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}



int	get_texture(t_mymlx *mymlx, mlx_texture_t *texture, int offset_x , int y)
{
	int	offset_y;
	int	index;



	offset_y = (y-1 -(HEIGHT / 2) + (mymlx->s_3d.wallStripHeight / 2))* ((double)32/ mymlx->s_3d.wallStripHeight);
 	index = (offset_y * 32 + offset_x) * 4;
    // if(offset_x >0 && (uint32_t)offset_y >0&& (uint32_t)offset_x<=texture->width && (uint32_t)offset_y <= texture->height)
         return (get_rgba(texture->pixels[index], texture->pixels[index + 1], texture->pixels[index + 2], texture->pixels[index + 3]));

}















 


// void    dir_tex(t_scene *scene)
// {
 

//     if (scene->mymlx->horzHitDistance > scene->mymlx->vertHitDistance) 
//     {
//         if (scene->mymlx->RayFaceRight)
//             scene->mymlx->ea;
//         else   // Ray facing left 
//            scene->mymlx->we;
//     }
//     else
//     {
//         if (scene->mymlx->RayFaceUp)
//             scene->mymlx->no;
//         else  
//             mlx_put_pixel(mymlx->mlx,) scene->mymlx->so;
//     }
// }
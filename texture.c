#include "./includes/cub3d.h"

mlx_texture_t    *text_so(t_scene *scene)
{
    scene->mymlx->so = mlx_load_png("/Users/mbouderr/Desktop/9lawi/lava.png");
    if (scene->mymlx->so == NULL){
            puts("No so texture\n");
        exit(0);
    }
    return scene->mymlx->so;
}
 mlx_texture_t*   text_no(t_scene *scene)
{
    scene->mymlx->no = mlx_load_png("/Users/mbouderr/Desktop/9lawi/dali3.png");
    if (scene->mymlx->no == NULL){
                    puts("No no texture\n");

        exit(0);
    }
    return scene->mymlx->no;
}
  mlx_texture_t*    text_ea(t_scene *scene)
{
    scene->mymlx->ea = mlx_load_png("/Users/mbouderr/Desktop/9lawi/East.png");
    if (scene->mymlx->ea == NULL){
                    puts("No  ea texture\n");

        exit(0);
    }
    return  scene->mymlx->ea;
}
 mlx_texture_t*    text_we(t_scene *scene)
{
    scene->mymlx->we = mlx_load_png("/Users/mbouderr/Desktop/9lawi/rbi3.png");
    if (scene->mymlx->we == NULL){
                    puts("No we texture\n");
        exit(0);
    }
    return scene->mymlx->we; 
}



void get_text(t_scene *scene)
{
    scene->mymlx->ea = text_ea(scene); 
    scene->mymlx->no  = text_no(scene);
    scene->mymlx->so =  text_so(scene);
    scene->mymlx->we =  text_we(scene);
}

 


int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}


int	get_texture(t_scene *scene,t_mymlx *mymlx, mlx_texture_t *texture, int offset_x , int y)
{
	int	offset_y;
	int	index;


    if (!texture || texture->height != 32 || texture->width != 32){
        printf("no texture found\n");
        return 0;
        }
	offset_y = (y - (HEIGHT / 2) + (mymlx->s_3d.wallStripHeight / 2))* ((float )32/ mymlx->s_3d.wallStripHeight);
    // printf("Offset Y: %d\n", offset_y);  
	index = (offset_y * 32 + offset_x) * 4;
    // if(offset_x > 0 && offset_y > 0 && offset_x <= texture->width && offset_y <= texture->height)
        return (get_rgba(texture->pixels[index], texture->pixels[index + 1], texture->pixels[index + 2], texture->pixels[index + 3]));
    // else
    //     return(get_rgba(0,0,0,0));
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
#include "./includes/cub3d.h"

   void    text_So(t_scene *scene, int i)
{
    scene->mymlx->so = mlx_load_png(scene->so_texture);
    if (scene->mymlx->so == NULL){
        exit(0);
    }
}
   void    text_no(t_scene *scene, int i)
{
    scene->mymlx->no = mlx_load_png(scene->no_texture);
    if (scene->mymlx->no == NULL){
        exit(0);
    }
}
   void    text_ea(t_scene *scene, int i)
{
    scene->mymlx->ea = mlx_load_png(scene->ea_texture);
    if (scene->mymlx->ea == NULL){
        exit(0);
    }
}
   void    text_we(t_scene *scene, int i)
{
    scene->mymlx->we = mlx_load_png(scene->we_texture);
    if (scene->mymlx->we == NULL){
        exit(0);
    }
}

void    dir_tex(t_scene *scene)
{
 

    if (scene->mymlx->horzHitDistance > scene->mymlx->vertHitDistance) 
    {
        if (scene->mymlx->RayFaceRight)
            scene->mymlx->ea;
        else   // Ray facing left 
           scene->mymlx->we;
    }
    else
    {
        if (scene->mymlx->RayFaceUp)
            scene->mymlx->no;
        else    // Rayfacing down
            scene->mymlx->so;
    }
}


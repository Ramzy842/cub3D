/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:24:19 by rchahban          #+#    #+#             */
/*   Updated: 2024/02/03 00:10:48 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

double distanceBetweenPoints(double x1, double y1, double x2, double y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void drawLine(t_mymlx *mymlx, int x1, int y1, int x2, int y2, int color)
{
    int dx = (int)abs(x2 - x1);
    int dy = (int)abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        mlx_put_pixel(mymlx->img, x1, y1, color);
        if (x1 == x2 && y1 == y2)
            break;
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

int check_wall(t_scene *scene)
{
    int tile_x = scene->mymlx->newplayer_x / 32;
    int tile_y = scene->mymlx->newplayer_y / 32;

    if (tile_x < 0 || tile_x >= scene->map_cols || tile_y < 0 || tile_y >= scene->map_rows)
    {
        // printf("out of the map\n");
        exit(0);
    }

    if (scene->map[tile_y][tile_x] == '1' || scene->map[tile_y][tile_x] == 'V')
    {
        // printf("Wall\n");
        return 1;
    }
    else
    {
        // printf("Not a Wall\n");
        return 0;
    }
}

int map_has_wall(t_mymlx *mymlx, double x, double y)

{

    if (x < 0 || x > WIDTH || y < 0 || y >= HEIGHT)
        return true;

    int mapgridindexX = (int)floor(x / 32);
    int mapgridindexY = (int)floor(y / 32);
    char mapcontent;

    if (mapgridindexX >= mymlx->num_col)
        return true;

    if (mapgridindexY >= mymlx->num_rows)
        return true;
    mapcontent = mymlx->splited[mapgridindexY][mapgridindexX];
    return mapcontent == '1';
}

double normalize_angle(double angle)
{
    if (angle > 2 * M_PI)
        angle -= 2 * M_PI;
    if (angle < 0)
        angle += 2 * M_PI;
    return angle;
}

void isHorizontal(t_mymlx *mymlx)
{

    mymlx->ray_angle = normalize_angle(mymlx->ray_angle);
    //   normalize_angle(mymlx->ray_angle);

    mymlx->RayFaceDown = mymlx->ray_angle > 0 && mymlx->ray_angle < M_PI;
    mymlx->RayFaceUp = !mymlx->RayFaceDown;
    mymlx->RayFaceRight = mymlx->ray_angle < 0.5 * M_PI || mymlx->ray_angle > 1.5 * M_PI;
    mymlx->RayFaceLeft = !mymlx->RayFaceRight;

    // horizontal
    mymlx->foundHorizWall = false;
    mymlx->horiwallhitX = mymlx->x;
    mymlx->horiwallhitY = mymlx->y;
    // mymlx->horzwallcontent = 0;

    mymlx->Hyintercept = (int)(mymlx->y / 32) * 32;
    if (mymlx->RayFaceDown)
        mymlx->Hyintercept += 32;
    // else
        // mymlx->Hyintercept -= 0.1;
    mymlx->Hxintercept = mymlx->x + (mymlx->Hyintercept - mymlx->y) / tan(mymlx->ray_angle);
    mymlx->ystep = 32;
    if (mymlx->RayFaceUp)
        mymlx->ystep = -mymlx->ystep;
    mymlx->xstep = mymlx->ystep / tan(mymlx->ray_angle); // ki7ma9 ila derti 32/tan(rayangle);
    // mymlx->xstep *=(mymlx->RayFaceLeft && mymlx->xstep >0) ?-1 :1;
    // mymlx->xstep *=(mymlx->RayFaceRight && mymlx->xstep <0) ?-1 :1;
    mymlx->nexthorztouchX = mymlx->Hxintercept;
    mymlx->nexthorztouchY = mymlx->Hyintercept;

    while (mymlx->nexthorztouchX >= 0 && mymlx->nexthorztouchX <=WIDTH && mymlx->nexthorztouchY >= 0 && mymlx->nexthorztouchY <=HEIGHT)
    {
        mymlx->xtocheck = mymlx->nexthorztouchX;
        mymlx->ytocheck = mymlx->nexthorztouchY;
        if (mymlx->RayFaceUp)
            mymlx->ytocheck -= 1;

        if (map_has_wall(mymlx, mymlx->xtocheck, mymlx->ytocheck))
        {
            mymlx->horiwallhitX = mymlx->nexthorztouchX;
            mymlx->horiwallhitY = mymlx->nexthorztouchY;
            mymlx->foundHorizWall = true;
            break;
        }
        else
        {
            mymlx->nexthorztouchX += mymlx->xstep;
            mymlx->nexthorztouchY += mymlx->ystep;
        }
    }
}



void isVertical(t_mymlx *mymlx)
{

    mymlx->ray_angle = normalize_angle(mymlx->ray_angle);
    mymlx->foundVertWall = false;
    mymlx->VertwallhitX = mymlx->x;
    mymlx->VertwallhitY = mymlx->y;
    // mymlx->Vertwallcontent = 0;
    // find x coordinate of the closed vertical grid intersection
    mymlx->Vxintercept = (int)(mymlx->x / 32) * 32;
    //  mymlx->Vxintercept += mymlx->RayFaceRight ? 32 : -0.001; //0.0001 for wall yban mzn
    if (mymlx->RayFaceRight)
        mymlx->Vxintercept += 32;
    // else
        // mymlx->Vxintercept -= 0.1;
    // find the y ccordinate of the closed vertical gerid intersection
    mymlx->Vyintercept = mymlx->y + (mymlx->Vxintercept - mymlx->x) * tan(mymlx->ray_angle);
    mymlx->xstep = 32;
    // mymlx->xstep *=mymlx->RayFaceLeft ?-1 :1;
    if (mymlx->RayFaceLeft)
        mymlx->xstep = -mymlx->xstep;
    mymlx->ystep = 32 * tan(mymlx->ray_angle);
    // mymlx->ystep *=(mymlx->RayFaceUp && mymlx->ystep >0) ?-1 :1;
    if (mymlx->RayFaceUp && mymlx->ystep > 0)
        mymlx->ystep = -mymlx->ystep;
    else if (mymlx->RayFaceDown && mymlx->ystep < 0)
    {
        mymlx->ystep = -mymlx->ystep;
    }

    double nextVerttouchX = mymlx->Vxintercept;
    double nextVerttouchY = mymlx->Vyintercept;

    while (nextVerttouchX >= 0 && nextVerttouchX <= WIDTH && nextVerttouchY >= 0 && nextVerttouchY <=HEIGHT)
    {
        double xtocheck = nextVerttouchX;
        double ytocheck = nextVerttouchY;
                if (mymlx->RayFaceLeft)
                  xtocheck-= 1;
        if (map_has_wall(mymlx, xtocheck, ytocheck))
        {
            mymlx->VertwallhitX = nextVerttouchX;
            mymlx->VertwallhitY = nextVerttouchY;
            mymlx->foundVertWall = true;
            break;
        }
        else
        {
            nextVerttouchX += mymlx->xstep;
            nextVerttouchY += mymlx->ystep;
        }
    }
}



void calculateDistance(t_mymlx *mymlx)
{
    if (mymlx->vertHitDistance > mymlx->horzHitDistance)
    {
        mymlx->distance = mymlx->horzHitDistance;
        mymlx->wallHitX = mymlx->horiwallhitX;
        mymlx->wallHitY = mymlx->horiwallhitY;
        // mymlx->wallHitContent = mymlx->horzwallcontent;
        mymlx->wasHitVertical = false;
    }
    else
    {
        mymlx->distance = mymlx->vertHitDistance;
        mymlx->wallHitX = mymlx->VertwallhitX;
        mymlx->wallHitY = mymlx->VertwallhitY;
        // mymlx->wallHitContent = mymlx->Vertwallcontent;
        mymlx->wasHitVertical = true;
    }
    drawLine(mymlx, mymlx->x, mymlx->y, mymlx->wallHitX, mymlx->wallHitY, 0xFF0000FF);
}

void	init_map_props(t_scene *scene)
{
	scene->map_cols = ft_strlen(scene->map[0]);
	scene->map_rows = ft_2d_len(scene->map);
}

int	process_scene_config(t_scene *scene, char **scene_config, t_element **list)
{
	int	count;
	int	map_lines;
	int	map_start_pos;

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

void cloear(mlx_image_t *img, t_mymlx *mymlx)
{
    int i = 0;
    int j = 0;
    while (j < mymlx->num_col * 32)
    {
        i = 0;
        while (i < mymlx->num_rows * 32)
        {
            mlx_put_pixel(img, j, i, 0x000000FF);
            i++;
        }
        j++;
    }
}

double get_short_distance(t_mymlx *mymlx)
{
    if (mymlx->horzHitDistance < mymlx->vertHitDistance)
        return (mymlx->horzHitDistance);
    else
        return (mymlx->vertHitDistance);
}

void	threeDrendring(t_mymlx *mymlx, int  i)
{
 
	// t_mydda	mydda;
    // mymlx->text = init_tex(mymlx);
	mymlx->s_3d.index = 0;
	mymlx->s_3d.distance = get_short_distance(mymlx); //
	mymlx->s_3d.perpDistance = mymlx->s_3d.distance * cos(mymlx->ray_angle - mymlx->rotation_angle);

	mymlx->s_3d.projectedWallHeight = (32/ mymlx->s_3d.perpDistance) * ((WIDTH / 2) / tan(mymlx->fov_angle / 2)); // chhab b3id player to calculate project wall height

	mymlx->s_3d.wallStripHeight = (int)mymlx->s_3d.projectedWallHeight; // how tall the wall is 

	mymlx->heightwall = mymlx->s_3d.wallStripHeight; 

	mymlx->s_3d.walltoppixel = (HEIGHT / 2) - (mymlx->s_3d.wallStripHeight / 2);

        mymlx->s_3d.walltoppixel  = mymlx->s_3d.walltoppixel< 0 ? 0 : mymlx->s_3d.walltoppixel;

	mymlx->s_3d.wallbottompixel = (HEIGHT / 2) + (mymlx->s_3d.wallStripHeight / 2);
	
	if (mymlx->s_3d.wallbottompixel > HEIGHT)
		mymlx->s_3d.wallbottompixel = HEIGHT;

    for (int k= 0;k < HEIGHT; k++)
    {
        if (k < mymlx->s_3d.walltoppixel)
            mlx_put_pixel(mymlx->img2, (int)i, (int)k, 0x00FFFF); //ceiling
        else if (k > mymlx->s_3d.wallbottompixel)
            mlx_put_pixel(mymlx->img2, (int)i, (int)k, 0x000FFF); // floore
        else    
        {
            if (mymlx->horzHitDistance > mymlx->vertHitDistance)
                mlx_put_pixel(mymlx->img2, (int)i, (int)k, 0xf2b31ccc);  //verical
            else
                mlx_put_pixel(mymlx->img2, (int)i, (int)k, 0x8Fc02c); // horizontal
        }
    }

    // mydda.ystart = mymlx->s_3d.wallbottompixel;
    // mydda.endx = i;
    // mydda.endy = mydda.ystart;
    // drawLineDDA(mymlx, mydda.xstart, mydda.ystart, mydda.endx, mydda.endy, 0xFF777777);


	// L_ard(mymlx, i);
	mymlx->s_3d.index = mymlx->s_3d.wallbottompixel;
	// ceiling(mymlx, i);
}

void cast_all_rays(t_mymlx *mymlx)
{
    int colum_id = 0;
    mymlx->ray_angle = mymlx->rotation_angle - (mymlx->fov_angle / 2);
    while (colum_id < mymlx->num_rays)
    {

        isHorizontal(mymlx);
        isVertical(mymlx);
        mymlx->ray_angle += mymlx->fov_angle / mymlx->num_rays;
        if (mymlx->foundHorizWall)
            mymlx->horzHitDistance = distanceBetweenPoints(mymlx->x, mymlx->y, mymlx->horiwallhitX, mymlx->horiwallhitY);
        else
            mymlx->horzHitDistance = 90000000000;
        if (mymlx->foundVertWall)
            mymlx->vertHitDistance = distanceBetweenPoints(mymlx->x, mymlx->y, mymlx->VertwallhitX, mymlx->VertwallhitY);
        else
            mymlx->vertHitDistance = 90000000000;
        calculateDistance(mymlx);
        threeDrendring(mymlx, colum_id);
        colum_id++;
    }
}

// double get_short_distance(t_mymlx *mymlx)
// {
//     if (mymlx->horzHitDistance < mymlx->vertHitDistance)
//         return (mymlx->horzHitDistance);
//     else
//         return (mymlx->vertHitDistance);
// }

void rect(int tile_x, int tile_y, t_scene *scene, int value)
{

    int end_x = tile_x + 32;
    int end_y = tile_y + 32;

    while (tile_x < end_x)
    {
        int current_y = tile_y;
        while (current_y < end_y)
        {

            if (value == 1)
            {
                mlx_put_pixel(scene->mymlx->img, tile_x, current_y, 0x0099FFFF); // Red color
            }
            else
            {

                mlx_put_pixel(scene->mymlx->img, tile_x, current_y, 0x00FF00FF); // Red color
            }
            current_y++;
        }
        tile_x++;
    }
}

double rad(float degree) 
{
    return (degree * M_PI / 180);
}

void checkDir(t_mymlx *mymlx, double rotation_angle)
{
     double tempY = mymlx->y + sin(rotation_angle) * mymlx->movespeed;
    double tempX = mymlx->x + cos(rotation_angle) * mymlx->movespeed;

     mymlx->YisAllowed = tempY;
    mymlx->XisAllowed = tempX;
}

int is_move_allowed(t_scene *scene)
{
    return (scene->map[(int)scene->mymlx->YisAllowed / 32][(int)scene->mymlx->XisAllowed / 32] != '1');
}

void drawCircle(t_mymlx *mymlx, int radius, int color)
{

    int cx = radius;
    int cy = 0;
    int radiusError = 1 - cx;
    color = mymlx->circleColor;

    while (cx >= cy)
    {
        mlx_put_pixel(mymlx->img, mymlx->x + cx, mymlx->y - cy, mymlx->circleColor);
        mlx_put_pixel(mymlx->img, mymlx->x - cx, mymlx->y - cy, mymlx->circleColor);
        mlx_put_pixel(mymlx->img, mymlx->x + cy, mymlx->y - cx, mymlx->circleColor);
        mlx_put_pixel(mymlx->img, mymlx->x - cy, mymlx->y - cx, mymlx->circleColor);
        mlx_put_pixel(mymlx->img, mymlx->x + cx, mymlx->y + cy, mymlx->circleColor);
        mlx_put_pixel(mymlx->img, mymlx->x - cx, mymlx->y + cy, mymlx->circleColor);
        mlx_put_pixel(mymlx->img, mymlx->x + cy, mymlx->y + cx, mymlx->circleColor);
        mlx_put_pixel(mymlx->img, mymlx->x - cy, mymlx->y + cx, mymlx->circleColor);
        cy++;
        if (radiusError < 0)
        {
            radiusError += 2 * cy + 1;
        }
        else
        {
            cx--;
            radiusError += 2 * (cy - cx + 1);
        }
    }
}

void print_grid(t_scene *scene)
{
    cloear(scene->mymlx->img, scene->mymlx);

    for (int i = 0; i < scene->map_rows; i++)
    {
        for (int j = 0; j < scene->map_cols; j++)
        {
            double tile_x = j * 32;
            double tile_y = i * 32;
            if (scene->map[i][j] == '1')
            {
                rect(tile_x, tile_y, scene, 1);
            }
           if (scene->map[i][j] == '0' ||  scene->map[i][j] == 'N' || scene->map[i][j] == 'S' || scene->map[i][j] == 'W' || scene->map[i][j] == 'E' )
            {
             
                rect(tile_x, tile_y, scene, 0);
            }
        }
    }
}

void draw_player_view(t_mymlx *mymlx)
{
    int lineEndX = mymlx->x + cos(mymlx->rotation_angle) * 30;
    int lineEndY = mymlx->y + sin(mymlx->rotation_angle) * 30;
    drawLine(mymlx, mymlx->x, mymlx->y, lineEndX, lineEndY, 0x0000FFFF);
}



void ft_hook(void *param)
{
    t_scene *scene = (t_scene*)param;
	scene->mymlx->x = scene->x;
	scene->mymlx->y = scene->y;;
    scene->mymlx->dirY = scene->mymlx->y;
    scene->mymlx->dirX = scene->mymlx->x;
    scene->mymlx->YisAllowed = scene->mymlx->y;
    scene->mymlx->XisAllowed = scene->mymlx->x;
    if (mlx_is_key_down(scene->mymlx->mlx, MLX_KEY_ESCAPE)) // done
    {
        mlx_close_window(scene->mymlx->mlx);
    }
     if (mlx_is_key_down(scene->mymlx->mlx, MLX_KEY_UP)) // W
    {
        checkDir(scene->mymlx, scene->mymlx->rotation_angle);
    }
     if (mlx_is_key_down(scene->mymlx->mlx, MLX_KEY_A)) // A
    {
        checkDir(scene->mymlx, scene->mymlx->rotation_angle + rad(270));
    }
    if (mlx_is_key_down(scene->mymlx->mlx, MLX_KEY_D)) // D
    {
        checkDir(scene->mymlx, scene->mymlx->rotation_angle + rad(90));
    }
     if (mlx_is_key_down(scene->mymlx->mlx, MLX_KEY_DOWN)) // S
    {
        checkDir(scene->mymlx, scene->mymlx->rotation_angle + rad(180));
    }

     if (mlx_is_key_down(scene->mymlx->mlx, MLX_KEY_LEFT)) // left  //DONE
    {
        scene->mymlx->rotation_angle -= 0.05;
        scene->mymlx->rotation_angle = normalize_angle(scene->mymlx->rotation_angle);
    }

     if (mlx_is_key_down(scene->mymlx->mlx, MLX_KEY_RIGHT)) // right //DONE
    {
        scene->mymlx->rotation_angle += 0.05 ;
        scene->mymlx->rotation_angle = normalize_angle(scene->mymlx->rotation_angle);
    }
  
  if (is_move_allowed(scene))
    {
        scene->mymlx->x = scene->mymlx->XisAllowed;
        scene->mymlx->y = scene->mymlx->YisAllowed;
    }   
    print_grid(scene);
    cast_all_rays(scene->mymlx);
    draw_player_view(scene->mymlx);
      drawCircle(scene->mymlx, scene->mymlx->radius, scene->mymlx->circleColor);
}





void drawLineDDA(t_mymlx *mymlx, int x1, int y1, int x2, int y2, int color)
{
	(void) color;
    int dx = x2 - x1;
    int dy = y2 - y1;
   int steps;
   steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    double xIncrement = dx / (double)steps;
    double yIncrement = dy / (double)steps;
    double x = x1;
    double y = y1;
 

    for (int i = 0; i <= steps; ++i)
    {
        if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
            break;

        if (mymlx->horzHitDistance > mymlx->vertHitDistance)
            mlx_put_pixel(mymlx->img2, (int)x, (int)y, 0x0000FF);
        else
            mlx_put_pixel(mymlx->img2, (int)x, (int)y, 0x00FFFF);
        
        // mlx_put_pixel(mymlx->img2, (int)x, (int)y, color);

        x += xIncrement;
        y += yIncrement;
    }
}



void playertype(t_scene *scene)
{
	printf("mymlx->playertype == %c\n",scene->player_type);
    if (scene->player_type == 'N')
        scene->mymlx->rotation_angle =  M_PI;
    else if (scene->player_type == 'S')
        scene->mymlx->rotation_angle = 0;
    else if (scene->player_type == 'E')
        scene->mymlx->rotation_angle = M_PI / 2;
    else if (scene->player_type == 'W')
       scene->mymlx->rotation_angle =  3*M_PI / 2;
}

int	initiate_gfx(t_scene *scene)
{
	printf("Launching the scene...\n");
	if (scene->map)
	{
    // int fd;
    scene->mymlx = (t_mymlx *)malloc(sizeof(t_mymlx));
    if (!scene->mymlx)
        return 1;
    ft_memset(scene->mymlx, 0, sizeof(t_mymlx));
    scene->mymlx->rotation_angle = 0; // PLayer face angle up down right left  fix it later !!!
    scene->mymlx->fov_angle = 60 * (M_PI / 180);

    scene->mymlx->radius = 4; // circle player radius
   	scene->mymlx->circleColor = 0x00FF000;
    scene->mymlx->movespeed = 2.0;//  4 pixel /fram
    //(M_PI/180) == convert to radian
    scene->mymlx->rotation_speed = scene->mymlx->movespeed * (M_PI / 180); // amounth by which the player rotation angle will change per frame
    printf("player type == %c\n",scene->player_type);
    //  scene->mymlx->fov_angle = 60 * (scene->mymlx->mypi/ 180);
    printf("fovvv ==%f \n", scene->mymlx->fov_angle);
    scene->mymlx->width = scene->map_cols * 32;
    scene->mymlx->hight = scene->map_rows * 32;
    scene->mymlx->num_rays = WIDTH  ; // update the value; //NUM_RAYS
    scene->mymlx->mlx = mlx_init(WIDTH, HEIGHT, "kalkabut", true);
    scene->mymlx->img = mlx_new_image(scene->mymlx->mlx,
							scene->map_cols*32 ,scene->map_rows*32);
    scene->mymlx->img2 = mlx_new_image(scene->mymlx->mlx, WIDTH, HEIGHT);
    // mlx_new_image(scene->mymlx->mlx, scene->mymlx->num_col * 32, scene->mymlx->num_rows * 32);
    mlx_image_to_window(scene->mymlx->mlx, scene->mymlx->img2, 0, 0);
	mlx_image_to_window(scene->mymlx->mlx, scene->mymlx->img,  0,  0);
    // mlx_loop_hook(scene->mymlx->mlx, ft_hook, mymlx);
    // print_grid(mymlx);
    // printf("scene->mymlx->x  == %f || scene->mymlx->y %f\n",scene->mymlx->x , scene->mymlx->y);
    playertype( scene);
    mlx_loop_hook(scene->mymlx->mlx, ft_hook, scene);
    mlx_loop(scene->mymlx->mlx);
    // mlx_terminate(scene->mymlx->mlx);
	// print_map(scene->map);
	// free_2d_arr(scene->map);
	}
	if (scene->scene_info)
		free_2d_arr(scene->scene_info);
	free_list(scene->info_list);
	return (0);
}

int	scene_config_is_empty(char **scene_config)
{
	char	*str;
	int		x;

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

int	main(int argc, char **argv)
{
	t_scene		scene;
	char		**scene_config;
	int			is_valid_scene_info;
	int			is_valid_map;

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

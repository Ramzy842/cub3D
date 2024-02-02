#include "cub.h"

void rect(int tile_x, int tile_y, t_mymlx *mymlx, int value)
{

    int end_x = tile_x + Tilesize;
    int end_y = tile_y + Tilesize;

    while (tile_x < end_x)
    {
        int current_y = tile_y;
        while (current_y < end_y)
        {

            if (value == 1)
            {
                mlx_put_pixel(mymlx->img, tile_x, current_y, 0x0099FFFF); // Red color
            }
            else
            {

                mlx_put_pixel(mymlx->img, tile_x, current_y, 0x00FF00FF); // Red color
            }
            current_y++;
        }
        tile_x++;
    }
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

int is_move_allowed(t_mymlx *mymlx)
{
     return (mymlx->splited[(int)mymlx->YisAllowed / 32][(int)mymlx->XisAllowed / 32] != '1');
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

void ft_hook(void *param)
{
    t_mymlx *mymlx = (t_mymlx *)param;
    mymlx->dirY = mymlx->y;
    mymlx->dirX = mymlx->x;
    mymlx->YisAllowed = mymlx->y;
    mymlx->XisAllowed = mymlx->x;
    if (mlx_is_key_down(mymlx->mlx, MLX_KEY_ESCAPE)) // done
    {
        mlx_close_window(mymlx->mlx);
    }
     if (mlx_is_key_down(mymlx->mlx, MLX_KEY_UP)) // W
    {
        checkDir(mymlx, mymlx->rotation_angle);
    }
     if (mlx_is_key_down(mymlx->mlx, MLX_KEY_A)) // A
    {
        checkDir(mymlx, mymlx->rotation_angle + rad(270));
    }
    if (mlx_is_key_down(mymlx->mlx, MLX_KEY_D)) // D
    {
        checkDir(mymlx, mymlx->rotation_angle + rad(90));
    }
     if (mlx_is_key_down(mymlx->mlx, MLX_KEY_DOWN)) // S
    {
        checkDir(mymlx, mymlx->rotation_angle + rad(180));
    }

     if (mlx_is_key_down(mymlx->mlx, MLX_KEY_LEFT)) // left  //DONE
    {
        mymlx->rotation_angle -= 0.05;
        mymlx->rotation_angle = normalize_angle(mymlx->rotation_angle);
    }

     if (mlx_is_key_down(mymlx->mlx, MLX_KEY_RIGHT)) // right //DONE
    {
        mymlx->rotation_angle += 0.05 ;
        mymlx->rotation_angle = normalize_angle(mymlx->rotation_angle);
    }
  
  if (is_move_allowed(mymlx))
    {
        mymlx->x = mymlx->XisAllowed;
        mymlx->y = mymlx->YisAllowed;
    }   
    print_grid(mymlx);
    cast_all_rays(mymlx);
    draw_player_view(mymlx);
      drawCircle(mymlx, mymlx->radius, mymlx->circleColor);
}


void draw_player_view(t_mymlx *mymlx)
{
    int lineEndX = mymlx->x + cos(mymlx->rotation_angle) * 30;
    int lineEndY = mymlx->y + sin(mymlx->rotation_angle) * 30;
    drawLine(mymlx, mymlx->x, mymlx->y, lineEndX, lineEndY, 0x0000FFFF);
}

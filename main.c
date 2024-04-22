#include <mlx.h>
#include <stdlib.h>
#include<stdio.h>
#define MLX_ERROR 1
#define XK_ESPACE 53
#define XK_CLOSE  65307
#define RED_PIXEL  0xFF0000
# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

typedef struct s_mlx
{
    void *mlx;
    void *ptr;
} t_mlx;
// handle the keypress 
int handle_keypress(int keysym, t_mlx *data)
{
    printf("%d", keysym);
    exit (0);
    // if (keysym == XK_ESPACE ||keysym == XK_CLOSE) 
    // {
    //     mlx_destroy_window(data->mlx, data->ptr);
    //     data->ptr = NULL;
    // }
    return (0);
}
// if window is destroyed we dont want to put pixels
int render(t_mlx *data)
{
    if (data->ptr != NULL)
        mlx_pixel_put(data->mlx, data->ptr, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, RED_PIXEL);
    return (0);
}

int main()
{
    t_mlx *data;
    data = malloc(sizeof(t_mlx));
    data->mlx = mlx_init();
    if (data->mlx == NULL)
        return (MLX_ERROR);
    data->ptr = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "window");
    //mlx_loop(data->mlx);
    if (data->ptr == NULL)
    {
        free(data->ptr);
        return (MLX_ERROR);
    }
    // setup hooks
    int i = render(data);
    printf("keycode -- %d",i);
    mlx_loop_hook(data->mlx, &render, data);
    mlx_key_hook(data->ptr, &handle_keypress, data);
    mlx_loop(data->mlx);
    //mlx_destroy_display(mlx);
}

#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

int handle_input(int keycode, void *param)
{
    printf("Key %d pressed\n", keycode);
    if (keycode == 53) // Escape key on macOS
    {
        exit(0); // Exit program
    }
    return (0);
}

int main(void)
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 640, 480, "Key Event Test");

    // Hook keypress events
    mlx_hook(win, 2, 1L << 0, handle_input, NULL);

    mlx_loop(mlx);
    return (0);
}

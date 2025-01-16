#include "mlx/mlx.h"
#include <stdlib.h>

#define TILE_SIZE 32
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main()
{
    void *mlx;
    void *window;
    void *tileset;
    int img_width, img_height;

    mlx = mlx_init();
    window = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Tileset Example");

    // Load the tileset image
    tileset = mlx_xpm_file_to_image(mlx, "assets/Cliff_Tile.xpm", &img_width, &img_height);
    if (!tileset)
        return 1; // Exit if the tileset fails to load

    // Draw tiles to form a simple grid
    for (int y = 0; y < 80; y++) { // 10 rows
        for (int x = 0; x < 60; x++) { // 10 columns
            mlx_put_image_to_window(mlx, window, tileset, x * TILE_SIZE, y * TILE_SIZE);
        }
    }

    mlx_loop(mlx);
    return 0;
}

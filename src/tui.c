#include <MLX42/MLX42.h>
#include <stdlib.h>

typedef struct s_game
{
    mlx_t        *mlx;
    mlx_image_t  *board;
    mlx_image_t  *piece;
} t_game;

void mouse_hook(mouse_key_t button, action_t action,
                modifier_key_t mods, void *param)
{
    t_game *game;
    int x, y;
    int32_t id;

    (void)mods;
    game = param;

    if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
    {
        mlx_get_mouse_pos(game->mlx, &x, &y);

        id = mlx_image_to_window(game->mlx, game->piece, x - 27, y - 30);
        if (id >= 0)
        {
            game->piece->instances[id].z = 1;
            game->piece->instances[id].enabled = true;
        }
    }
}

int main(void)
{
    t_game game;
    mlx_texture_t *tex;

    game.mlx = mlx_init(800, 600, "PNG Test", true);
    if (!game.mlx)
        return (EXIT_FAILURE);

    // Board
    tex = mlx_load_png("../assets/board8h6h.png");
    game.board = mlx_texture_to_image(game.mlx, tex);
    mlx_delete_texture(tex);
    mlx_image_to_window(game.mlx, game.board, 0, 0);

    // Piece (carregada UMA VEZ)
    tex = mlx_load_png("../assets/black.png");
    game.piece = mlx_texture_to_image(game.mlx, tex);
    mlx_delete_texture(tex);

    // Hook ANTES do loop
    mlx_mouse_hook(game.mlx, mouse_hook, &game);

    mlx_loop(game.mlx);
    mlx_terminate(game.mlx);
    return (EXIT_SUCCESS);
}


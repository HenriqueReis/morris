#include <MLX42/MLX42.h>
#include <stdlib.h>

int main(void)
{
    mlx_t          *mlx;
    mlx_texture_t  *texture;
    mlx_image_t    *image;

    // 1. Inicializa MLX / cria janela
    mlx = mlx_init(800, 600, "PNG Test", true);
    if (!mlx)
        return (EXIT_FAILURE);

    // 2. Carrega o PNG para uma textura
    texture = mlx_load_png("../assets/board8h6h.png");
    if (!texture)
    {
        mlx_terminate(mlx);
        return (EXIT_FAILURE);
    }

    // 3. Converte a textura em imagem renderizável
    image = mlx_texture_to_image(mlx, texture);
    mlx_delete_texture(texture);
    if (!image)
    {
        mlx_terminate(mlx);
        return (EXIT_FAILURE);
    }

    // 4. Coloca a imagem na janela (0,0)
    mlx_image_to_window(mlx, image, 0, 0);

    // 5. Loop de eventos
    mlx_loop(mlx);

    // 6. Finalização
    mlx_terminate(mlx);
    return (EXIT_SUCCESS);
}

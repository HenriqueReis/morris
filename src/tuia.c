//#include "ninemens.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_data
{
        void    *mlx;
        void    *win;
        void    *img;
        char    *addr;
        int     bpp;// bytes per pixel 
        int     line_length;
        int     endian;
        int     width;
        int     height;
}    t_data;

int     main(void)
{
        t_data  data;

        data.mlx = mlx_init();
        data.width = 800;
        data.height = 600;
        data.win = mlx_new_window(data.mlx, 800, 600, "MLX");
        data.img = mlx_xpm_file_to_image(data.mlx,"../assets/board.xpm", &data.width, &data.height);
//        data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_length, &data.endian);
//        mlx_loop_hook(data.mlx, render, &data);
        mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
        mlx_loop(data.mlx);
}

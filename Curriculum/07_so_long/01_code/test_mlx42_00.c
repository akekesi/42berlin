#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "so_long.h"
#define WIDTH 256
#define HEIGHT 256

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int32_t	test_mlx42_00(void)
{

	// MLX allows you to define its core behaviour before startup.
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "test", true);
	if (!mlx)
		ft_error();

	/* Do stuff */
	mlx_texture_t* texture = mlx_load_png("enemy.png");
	if (!texture)
        ft_error();
	
	// Convert texture to a displayable image
	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
	if (!img)
        ft_error();
	// // Create and display the image.
	// mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	// // if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
	// // 	ft_error();
	// if (!img)
	// 	ft_error();
	// // Set every pixel to white
	// #include <memory.h>
	// memset(img->pixels, 155, img->width * img->height * sizeof(int32_t));

	// Display an instance of the image
	if (mlx_image_to_window(mlx, img, 390, 130) < 0)
        ft_error();

	// Even after the image is being displayed, we can still modify the buffer.
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	mlx_put_pixel(img, 0, 70, 0xFF0000FF);
	mlx_put_pixel(img, 70, 0, 0xFF0000FF);
	mlx_put_pixel(img, 70, 70, 0xFF0000FF);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
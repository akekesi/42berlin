/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:19:05 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/12 18:34:37 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "test.h"

void	test_gnl_loop(int close_fd)
{
	int		i;
	int		fd;
	char	*str;
	char	*path;

	path = "99_text/test_gnl_00.txt";
	fd = open(path, O_RDONLY);
	printf("fd: %d\n", fd);
	i = 0;
	while (i < 3) // <-- number of loop
	{
		i++;
		str = get_next_line(fd);
		printf("%d. -->%s<--\n", i, str);
		free(str);
	}
	if (close_fd)
	{
		close(fd);
		str = get_next_line(-1);
		printf("%d. -->%s<--\n", i, str);
	}
}

void	test_gnl_new_start(int close_fd)
{
	int		i;
	int		fd;
	char	*str;
	char	*path;

	path = "99_text/read_error.txt";
	i = 0;
	fd = open(path, O_RDONLY);
	printf("fd: %d\n", fd);
	str = get_next_line(fd);
	printf("%d. -->%s<--\n", ++i, str);
	free(str);

	close(fd);
	str = get_next_line(-1);
	printf("after close(fd):\n");
	printf("%d. -->%s<--\n", ++i, str);

	fd = open(path, O_RDONLY);
	printf("after open() again:\n");
	printf("fd: %d\n", fd);
	str = get_next_line(fd);
	printf("%d. -->%s<--\n", i++, str);
	free(str);

	if (close_fd)
	{
		close(fd);
		str = get_next_line(-1);
		printf("%d. -->%s<--\n", i, str);
	}
}

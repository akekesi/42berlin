/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:19:05 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/20 21:57:43 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_bonus.h"
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
	while (i < 3) // <-- number of loops
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
		printf("free: -->%s<--\n", str);
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
		printf("free: -->%s<--\n", str);
	}
}

void	test_gnl_bonus(int close_fd)
{
	int		i;
	int		fd1;
	int		fd2;
	char	*str1;
	char	*str2;
	char	*path1;
	char	*path2;

	path1 = "99_text/test_gnl_00.txt";
	path2 = "99_text/read_error.txt";
	fd1 = open(path1, O_RDONLY);
	fd2 = open(path2, O_RDONLY);
	i = 0;
	while (i < 3) // <-- number of loops
	{
		i++;
		str1 = get_next_line(fd1); // <-- _bonus ???
		str2 = get_next_line(fd2); // <-- _bonus ???
		printf("%d. fd: %d-->%s\n<--\n", i, fd1, str1);
		printf("%d. fd: %d-->%s\n<--\n", i, fd2, str2);
		free (str1);
		free (str2);
	}
	if (close_fd)
	{
		close(fd1);
		close(fd2);
		str1 = get_next_line(-1);
		str2 = get_next_line(-1);
		printf("free -->%s<--\n", str1);
		printf("free -->%s<--\n", str2);
	}
}

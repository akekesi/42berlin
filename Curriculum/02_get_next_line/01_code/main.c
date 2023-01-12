/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:17:59 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/12 18:06:09 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "test.h"

int	main(void)
{
	printf("|-- TEST -->\n");
	printf("|-- get_next_line -->\n");
	int		i;
	int		i_max;
	int		fd;
	char	*str;
	char	*path;

	path = "99_text/test_gnl_00.txt";
	// path = "99_text/no_txt_file.txt";
	fd = open(path, O_RDONLY);
	if (fd == -1)
		printf("fd = -1\n");
	i = 1;
	i_max = 3;
	while (i < i_max + 1)
	{
		str = get_next_line(fd);
		printf("%d. -->%s<--\n", i, str);
		free(str);
		i++;
	}
	str = get_next_line(-1);
	free(str);

	path = "99_text/read_error.txt";
	fd = open(path, O_RDONLY);
	printf("fd: %d\n", fd);
	str = get_next_line(fd);
	i = 1;
	printf("%d. -->%s<--\n", i++, str);
	free(str);

	close(fd);
	str = get_next_line(-1);
	printf("%d. -->%s<--\n", i++, str);

	fd = open(path, O_RDONLY);
	printf("fd: %d\n", fd);
	str = get_next_line(fd);
	printf("%d. -->%s<--\n", i++, str);
	free(str);

	printf("<-- get_next_line --|\n");
	printf("<-- TEST --|\n");
	return (1);
}

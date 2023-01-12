/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:17:59 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/13 00:18:06 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "test.h"

int	main(void)
{
	printf("|-- TEST -->\n");

	printf("|-- get_next_line -->\n");
	int		i;
	int		fd;
	char	*str;
	char	*path;

	path = "99_text/1char.txt";
	fd = open(path, O_RDONLY);
	i = 0;
	while (i < 2) // <-- number of loops
	{
		i++;
		str = get_next_line(fd);
		printf("%d. -->%s<--\n", i, str);
		free(str);
	}
	printf("<-- get_next_line --|\n");

	// printf("|-- get_next_line loop -->\n");
	// test_gnl_loop(1);
	// test_gnl_loop(0);
	// test_gnl_loop(1);
	// printf("<-- get_next_line loop --|\n");

	// printf("|-- get_next_line new start -->\n");
	// test_gnl_new_start(1);
	// test_gnl_new_start(0);
	// test_gnl_new_start(1);
	// printf("<-- get_next_line new start --|\n");

	// printf("|-- get_next_line bonus -->\n");
	// test_gnl_bonus(1);
	// printf("<-- get_next_line bonus --|\n");
	printf("<-- TEST --|\n");
	return (1);
}

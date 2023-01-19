/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:17:59 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/19 16:01:39 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "test.h"

int	main(void)
{
	// https://www.gnu.org/software/libc/manual/html_node/Limits-on-Resources.html
	// https://docs.oracle.com/cd/E19476-01/821-0505/file-descriptor-requirements.html
	// ulimit -aH
	// ulimit -H -n

	printf("|-- TEST -->\n");
	// printf("|-- get_next_line -->\n");
	// // gcc main.c -Wall -Wextra -Werror test.c get_next_line.c get_next_line_utils.c&& valgrind ./a.out
	// int		i;
	// int		fd;
	// char	*str;
	// char	*path;

	// path = "99_text/multiple_nl.txt";
	// fd = open(path, O_RDONLY);
	// i = 0;
	// while (i < 6) // <-- number of loops
	// {
	// 	i++;
	// 	str = get_next_line(fd);
	// 	printf("%d. -->%s<--\n", i, str);
	// 	free(str);
	// }
	// printf("<-- get_next_line --|\n");

	// printf("|-- get_next_line loop -->\n");
	// // gcc main.c -Wall -Wextra -Werror test.c get_next_line.c get_next_line_utils.c&& valgrind ./a.out
	// test_gnl_loop(1);
	// printf("-------------\n");
	// test_gnl_loop(0);
	// printf("-------------\n");
	// test_gnl_loop(1);
	// printf("<-- get_next_line loop --|\n");

	// printf("|-- get_next_line new start -->\n");
	// // gcc main.c -Wall -Wextra -Werror test.c get_next_line.c get_next_line_utils.c&& valgrind ./a.out
	// test_gnl_new_start(1);
	// printf("-------------\n");
	// test_gnl_new_start(0);
	// printf("-------------\n");
	// test_gnl_new_start(1);
	// printf("<-- get_next_line new start --|\n");

	// printf("|-- get_next_line bonus -->\n");
	// // gcc main.c -Wall -Wextra -Werror test.c *bonus.c && valgrind ./a.out
	// test_gnl_bonus(1);
	// printf("<-- get_next_line bonus --|\n");
	printf("<-- TEST --|\n");
	return (1);
}

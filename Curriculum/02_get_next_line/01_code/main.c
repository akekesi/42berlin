/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:17:59 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/08 22:28:05 by akekesi          ###   ########.fr       */
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
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("fd = -1\n");
		return (0);
	}
	i = 0;
	i_max = 9;
	while (i < i_max)
	{
		str = get_next_line(fd);
		printf("%d. -->%s<--\n", i, str);
		i++;
	}
	free(str);
	printf("<-- get_next_line --|\n");
	printf("<-- TEST --|\n");
	return (1);
}

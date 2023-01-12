/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:17:59 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/12 18:34:45 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "test.h"

int	main(void)
{
	printf("|-- TEST -->\n");
	printf("|-- get_next_line loop -->\n");
	test_gnl_loop(1);
	test_gnl_loop(0);
	test_gnl_loop(1);
	printf("<-- get_next_line loop --|\n");

	printf("|-- get_next_line new start -->\n");
	test_gnl_new_start(1);
	test_gnl_new_start(0);
	test_gnl_new_start(1);
	printf("<-- get_next_line new start --|\n");
	printf("<-- TEST --|\n");
	return (1);
}

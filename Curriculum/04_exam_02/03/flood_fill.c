/*
Assignment name  : flood_fill
Expected files   : flood_fill.c
Allowed functions: -
--------------------------------------------------------------------------------

Write a function that takes a char ** as a 2-dimensional array of char, a 
t_point as the dimensions of this array and a t_point as the starting point.

Starting from the given 'begin' t_point, this function fills an entire zone 
by replacing characters inside with the character 'F'. A zone is an group of 
the same character delimitated horizontally and vertically by other characters
or the array boundry.

The flood_fill function won't fill diagonally.

The flood_fill function will be prototyped like this:
  void  flood_fill(char **tab, t_point size, t_point begin);

The t_point structure is prototyped like this: (put it in flood_fill.c)

  typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;

Example:

$> cat test.c
#include <stdlib.h>
#include <stdio.h>

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}

$> gcc flood_fill.c test.c -o test; ./test
11111111
10001001
10010001
10110001
11100001

FFFFFFFF
F000F00F
F00F000F
F0FF000F
FFF0000F
$> 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

void	ft_print_area(char **area, t_point size)
{
	int	i;

	i = 0;
	while (i < size.y)
	{
		printf("%s\n", area[i]);
		i++;
	}
}

char	**make_area(char **zone, t_point size)
{
	int		i;
	int		j;
	char	**new;

	new = (char **)malloc(sizeof(char *) * size.y);
	if (!new)
		return (NULL);
	i = 0;
	while (i < size.y)
	{
		new[i] = (char *)malloc(sizeof(char) * (size.x + 1));
		j = 0;
		while (j < size.x)
		{
			new[i][j] = zone[i][j];
			j++;
		}
		new[i][size.x] = '\0';
		i++;
	}
	return (new);
}

void	flood_fill(char **area, t_point size, t_point begin)
{
	t_point	tmp_begin = {1, 1};

	printf("%d-%d\n", begin.x, begin.y);
	ft_print_area(area, size);
	printf("\n");
	if (area[begin.y][begin.x] == 'F')
		return ;
	if (area[begin.y][begin.x] == '0')
		return ;
	area[begin.y][begin.x] = 'F';
	if (begin.x > 0)
	{
		tmp_begin.x = begin.x - 1;
		tmp_begin.y = begin.y;
		flood_fill(area, size, tmp_begin);
	}
	if (begin.x + 1 < size.x)
	{
		tmp_begin.x = begin.x + 1;
		tmp_begin.y = begin.y;
		flood_fill(area, size, tmp_begin);
	}
	if (begin.y > 0)
	{
		tmp_begin.x = begin.x;
		tmp_begin.y = begin.y - 1;
		flood_fill(area, size, tmp_begin);
	}
	if (begin.y + 1 < size.y)
	{
		tmp_begin.x = begin.x;
		tmp_begin.y = begin.y + 1;
		flood_fill(area, size, tmp_begin);
	}
}

int	main(void)
{
	int		i;
	t_point	size = {8, 5};
	t_point	begin = {7, 4};
	char	*zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};
	char	**area = make_area(zone, size);

	i = 0;
	ft_print_area(area, size);
	printf("\n");
	flood_fill(area, size, begin);
	ft_print_area(area, size);
	printf("\n");
}

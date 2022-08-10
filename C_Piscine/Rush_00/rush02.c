void	ft_putchar(char c);
void	rush(int x, int y);
char	rush_if(int x, int y, int xi, int yi);

void	rush(int x, int y)
{
	int		xi;
	int		yi;
	char	c;

	if (x < 1 || y < 1)
	{
		return ;
	}
	yi = 0;
	while (yi < y)
	{
		xi = 0;
		while (xi < x)
		{
			c = rush_if(x, y, xi, yi);
			ft_putchar(c);
			xi++;
		}
		ft_putchar('\n');
		yi++;
	}
}

char	rush_if(int x, int y, int xi, int yi)
{
	if (yi == 0 && xi == 0)
		return ('A');
	else if (yi == 0 && xi == x - 1)
		return ('A');
	else if (yi == y - 1 && xi == 0)
		return ('C');
	else if (yi == y - 1 && xi == x - 1)
		return ('C');
	else if (yi == 0 || yi == y - 1)
		return ('B');
	else if (xi == 0 || xi == x - 1)
		return ('B');
	else
		return (' ');
}

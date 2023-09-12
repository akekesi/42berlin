# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

long long	get_time_current(void);
long long	get_time_elapsed(long long time_0);
char		*ft_itoa(int n);
int			hf_calc_digits(int n);
int			ft_strlen(const char *str);
void		do_write(int number);
void		do_printf(int number);

long long	get_time_current(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

long long	get_time_elapsed(long long time_0)
{
	return (get_time_current() - time_0);
}

char	*ft_itoa(int n)
{
	int		i;
	long	n_;
	char	*str;

	i = hf_calc_digits(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (!n)
	{
		str[i--] = '0';
		return (str);
	}
	n_ = n;
	if (n_ < 0)
		n_ *= -1;
	while (n_)
	{
		str[i--] = '0' + (n_ % 10);
		n_ /= 10;
	}
	if (!i)
		str[i] = '-';
	return (str);
}

int	hf_calc_digits(int n)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_strlen(const char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

void	do_write(int number)
{
	char	*str;

	str = ft_itoa(number);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	free(str);
}

void	do_printf(int number)
{
	printf("%d\n", number);
}

int	main(void)
{
	int	i;
	int	iter;
	int	number;
	long long	time;
	long long	time_write;
	long long	time_printf;

	iter = 10 * 1000 * 1000;
	number = 1234567;

	// write
	i = 0;
	time = get_time_current();
	while (i++ < iter)
		do_write(number);
	time_write = get_time_elapsed(time);

	// printf
	i = 0;
	time = get_time_current();
	while (i++ < iter)
		do_printf(number);
	time_printf = get_time_elapsed(time);

	printf("t-write:  %lli\n", time_write);
	printf("t-printf: %lli\n", time_printf);
}

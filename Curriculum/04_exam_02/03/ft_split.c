/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/

#include <stdlib.h>
#include <stdio.h>

char	**ft_split(char *str);
char	*ft_split_sub(char *str, int n);
int		ft_isspace(char c);
int		ft_strlen_space(char *str);
int		ft_words_n_p(char *str, int n);

char	**ft_split(char *str)
{
	int		i;
	int		n;
	char	**words;

	n = ft_words_n_p(str, -1);
	words = (char **)malloc(sizeof(char *) * (n + 1));
	if (!words)
		return (NULL);
	words[n] = NULL;
	i = 0;
	while (i < n)
	{
		words[i] = ft_split_sub(str, i);
		i++;
	}
	return (words);
}

char	*ft_split_sub(char *str, int n)
{
	int		i;
	int		pos;
	int		len;
	char	*word;

	pos = ft_words_n_p(str, n);
	len = ft_strlen_space(str + pos);
	word = (char *)malloc(sizeof(char) * (len + 1));
	word[len] = '\0';
	i = 0;
	while (str[pos + i] && !ft_isspace(str[pos + i]))
	{
		word[i] = str[pos + i];
		i++;
	}
	return (word);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int	ft_strlen_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	return (i);
}

int	ft_words_n_p(char *str, int n)
{
	int	i;
	int	n_;
	int	new;

	i = 0;
	n_ = 0;
	new = 1;
	while (str[i])
	{
		if (!ft_isspace(str[i]) && new)
		{
			new = 0;
			if (n == n_)
				return (i);
			n_++;
		}
		if (ft_isspace(str[i]))
			new = 1;
		i++;
	}
	return (n_);
}

int	main(int argc, char **argv)
{
	int		i;
	char	**words;

	if (argc == 2)
	{
		words = ft_split(argv[1]);
		i = 0;
		while (words[i])
		{
			printf("%s\n", words[i]);
			i++;
		}
	}
}

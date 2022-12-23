#include <stdlib.h>

void	hf_free_2d(void **array)
{
	while (*array)
	{
		free(*array);
		array++;
	}
	free(array);
}

size_t	**hf_add_row(size_t **matrix_old, size_t *row_new, size_t n)
{
	size_t	i;
	size_t	**matrix_new;

	matrix_new = (size_t **)malloc(sizeof(size_t *) * (n + 1));
	if (!matrix_new)
		return (NULL);
	i = 0;
	while (i < n)
	{
		matrix_new[i] = matrix_old[i];
		i++;
	}
	matrix_new[i] = row_new;
	matrix_new[n + 1] = NULL;
	hf_free_2d(matrix_old);
	return (matrix_new);
}

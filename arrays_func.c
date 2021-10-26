#include "matrix.h"

void	parse_args(int ac, char **av, t_matrix matrix)
{
	while (ac != 0)
	{
		if (ac == 3)
			matrix.columns =  atoi(av[ac - 1]);
		if (ac == 2)
			matrix.strings = atoi(av[ac - 1]);
		ac--;
	}
}

void	fill_matrix(t_matrix matrix, int **matrix1, int **matrix2)
{
	int i;
	int j;
	int number;

	number = 1;
	j = 0;
	i = 0;
	while (i < matrix.strings)
	{
		while(j < matrix.columns)
		{
			matrix1[i][j] = number;
			matrix2[i][j] = number;
			number++;
			j++;
		}
		j = 0;
		i++;
	}
}

void	smart_malloc(t_matrix matrix, int **matrix1, int **matrix2,int **Res_matrix)
{
	int i;

	i = 0;
	matrix1 = (int **)malloc(sizeof (int *) * matrix.strings);
	matrix2 = (int **)malloc(sizeof (int *) * matrix.strings);
	Res_matrix = (int **)malloc(sizeof (int *) * matrix.strings);
	// Выделение памяти под колонки в каждой строке
	while (i < matrix.columns)
	{
		matrix1[i] = (int *)malloc(sizeof (int ) * matrix.columns);
		matrix2[i] = (int *)malloc(sizeof (int ) * matrix.columns);
		Res_matrix[i] = (int *)malloc(sizeof (int ) * matrix.columns);
		i++;
	}
}
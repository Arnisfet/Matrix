/* Алгоритм решения задачи:
 * 1) Парсинг параметров пришедших из ав;
 * 2) Выделение памяти под 2 матрицы, в которых будут храниться данные*/

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

void	smart_malloc(t_matrix matrix, int **matrix1, int **matrix2,
		 int **Res_matrix)
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
int main(int ac, char **av)
{
	t_matrix matrix;
	int **matrix1; //Первая матрица
	int **matrix2; //Вторая матрица
	int **Res_matrix; // Результирующая матрица
	int i;

	i = 0;
	parse_args(ac, av, matrix);
	//Выделение памяти под таблицу из строк и столюцов
	smart_malloc(matrix, matrix1, matrix2, Res_matrix);





}

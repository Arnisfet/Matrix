/* Алгоритм решения задачи:
 * 1) Парсинг параметров пришедших из ав;
 * 2) Выделение памяти под 2 матрицы, в которых будут храниться данные*/

#include "matrix.h"

void	*thread_func(void *thread_data)
{
	t_matrix *data;
	int i;

	i = 0;
	data = (t_matrix *)thread_data;
	while (i < data->strings)
	{
		data->mtrx_res[data->elem_num][i] = data->mtrx1[data->elem_num][i] +
				data->mtrx2[data->elem_num][i];
		i++;
	}
	return (NULL);
}

int main(int ac, char **av)
{
	t_matrix matrix;
	int **matrix1; //Первая матрица
	int **matrix2; //Вторая матрица
	int **Res_matrix; // Результирующая матрица
	pthread_t *thread;
	t_matrix *data;
	int i;

	i = 0;
	parse_args(ac, av, matrix);
	//Выделение памяти под таблицу из строк и столюцов
	smart_malloc(matrix, matrix1, matrix2, Res_matrix);
	fill_matrix(matrix, matrix1, matrix2);
	thread = (pthread_t *)malloc(sizeof (pthread_t) * matrix.strings);
	data = (t_matrix *)malloc(sizeof (t_matrix *));
	while (i != matrix.strings)
	{
		data[i].elem_num = i;
		data[i].mtrx1 = matrix1;
		data[i].mtrx2 = matrix2;
		data[i].mtrx_res = Res_matrix;
		pthread_create(&thread[i], NULL, thread_func, &data[i]);
		i++;
	}
	i = 0;
	while (i < matrix.strings)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
}

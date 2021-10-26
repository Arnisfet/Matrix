
#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_matrix
{
	int columns;
	int strings;
	int elem_num;
	int **mtrx1;
	int **mtrx2;
	int **mtrx_res;
}				t_matrix;

void	parse_args(int ac, char **av, t_matrix matrix);
void	fill_matrix(t_matrix matrix, int **matrix1, int **matrix2);
void	smart_malloc(t_matrix matrix, int **matrix1, int **matrix2,int
**Res_matrix);


#endif //MATRIX_MATRIX_H

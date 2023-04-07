#include <stdio.h>
#include <stdlib.h>

void square_matrix_maker(int **matrix, int dimension);
void square_matrix_printer(int **matrix, int dimension);
void matrix_multiplication(int **matrix1, int **matrix2, int dimension);
void square_matrix_printer_mx(int **matrix, int dimension);

int main()
{
    int dimension;
    printf("\nPlease enter the dimension of the square matrix: ");
    scanf("%d", &dimension);

    int **matrix1 = (int **)malloc(dimension * sizeof(int *));
    for (int i = 0; i < dimension; i++)
    {
        matrix1[i] = (int *)malloc(dimension * sizeof(int));
    }

    int **matrix2 = (int **)malloc(dimension * sizeof(int *));
    for (int i = 0; i < dimension; i++)
    {
        matrix2[i] = (int *)malloc(dimension * sizeof(int));
    }

    printf("\nPlease enter the elements of the first matrix: \n");
    square_matrix_maker(matrix1, dimension);
    square_matrix_printer(matrix1, dimension);

    printf("\nPlease enter the elements of the second matrix: \n");
    square_matrix_maker(matrix2, dimension);
    square_matrix_printer(matrix2, dimension);

    matrix_multiplication(matrix1, matrix2, dimension);

    free(matrix1);
    free(matrix2);

    return 0;
}

void square_matrix_maker(int **matrix, int dimension)
{
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            printf("\nPlease enter the element in position [%d][%d] of the matrix: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\n\n");
}

void square_matrix_printer(int **matrix, int dimension)
{
    printf("\nThe matrix you entered is: \n");

    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            printf("\t%d", matrix[i][j]);
        }
        printf("\n");
    }
}

void matrix_multiplication(int **matrix1, int **matrix2, int dimension)
{
    int **matrix3 = (int **)malloc(dimension * sizeof(int *));
    for (int i = 0; i < dimension; i++)
    {
        matrix3[i] = (int *)malloc(dimension * sizeof(int));
    }

    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            matrix3[i][j] = 0;
            for (int k = 0; k < dimension; k++)
            {
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    printf("\nThe product of the two matrices is: \n");
    square_matrix_printer_mx(matrix3, dimension);
    free(matrix3);
}

void square_matrix_printer_mx(int **matrix, int dimension)
{
    printf("\n");

    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            printf("\t%d", matrix[i][j]);
        }
        printf("\n");
    }
}

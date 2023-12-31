
#include <stdio.h>
#include<conio.h>
int matrixInput(int mat[][3]);
int matrixPrint(int mat[][3]);
int matrixMultiply(int mat1[][3], int mat2[][3], int res[][3]);



int main()
{
    int mat1[3][3],mat2[3][3], product[3][3],ROW,COL;
    printf("Enter the number of rows and columns:");
    scanf("%d%d",&ROW,&COL);
    printf("Enter elements in first matrix of size %dx%d\n", ROW, COL);
    matrixInput(mat1);

    printf("Enter elements in second matrix of size %dx%d\n", ROW, COL);
    matrixInput(mat2);

    matrixMultiply(mat1, mat2, product);
    printf("Product of both matrices is : \n");
    matrixPrint(product);
    return 0;
}
int matrixInput(int mat[][3])
{
    int row, col;

    for (row = 0; row < 2; row++)
    {
        for (col = 0; col < 2; col++)
        {
            scanf("%d", (*(mat + row) + col));
        }
    }
}
int matrixPrint(int mat[][3])
{
    int row, col;

    for (row = 0; row < 2; row++)
    {
        for (col = 0; col < 2; col++)
        {
            printf("%d ", *(*(mat + row) + col));
        }

        printf("\n");
    }
}
int matrixMultiply(int mat1[][3], int mat2[][3], int res[][3])
{
    int row, col, i, sum=0;


    for (row = 0; row < 2; row++)
    {
        for (col = 0; col < 2; col++)
        {
            for (i = 0; i < 2; i++)
            {
                sum += (*(*(mat1 + row) + i)) * (*(*(mat2 + i) + col));
            }
             *(*(res + row) + col) = sum;
        }
    }
}
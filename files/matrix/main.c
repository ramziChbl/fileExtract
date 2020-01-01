#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void* cmat();

int main()
{
    int *mat = malloc(sizeof(int)*3*3);
    mat = cmat();
    afficherMat(mat);
    return 0;
}


void afficherMat(int mat[][3])
{
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            printf(" %d ", mat[i][j]);
        }
        printf("\n");
    }
}

void* cmat()
{
    int *mat = malloc(sizeof(int)*3*3);
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            mat[i*SIZE +j] = i + j;
        }
    }
    return mat;
}

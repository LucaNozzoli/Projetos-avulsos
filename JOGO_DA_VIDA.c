#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10


int numeroVizinhas(int **m, int i, int j)
{

    int cont=0, ii, jj;
    for(ii=i-1; ii<=i+1; ii++)
    {
        for(jj=j-1; jj<=j+1; jj++)
        {
            if(ii!=i || jj!=j)
            {
                if(m[ii][jj]==1)
                    cont++;
            }
        }
    }
    return cont;

}

int ** alocaMatriz(int l, int c)
{

    int **m, i;
    m = (int**)malloc(l * sizeof(int*));
    for(i=0; i<l; i++)
        m[i] = (int*)malloc(c * sizeof(int));
    return m;

}

void imprimeMatriz(int **m, int l, int c)
{

    int i, j;
    for(i=0; i<l; i++)
    {
        for(j=0; j<c; j++)
            printf("%3d", m[i][j]);
        printf("\n");
    }

}

void preencheMatrizBlinker(int **m, int l, int c)
{

    int i, j;
    srand(time(NULL));
    for(i=0; i<l; i++)
    {
        for(j=0; j<c; j++)
            m[i][j] = 0;
        printf("\n");
    }

    m[l/2][c/2-1] = 1;
    m[l/2][c/2+1] = 1;
    m[l/2][c/2] = 1;

}

void copiaMatriz(int **fonte, int **dest, int l, int c)
{

    int i, j;
    for(i=0; i<l; i++)
    {
        for(j=0; j<c; j++)
            dest[i][j] = fonte[i][j];
        printf("\n");
    }

}

int main()
{
    int **matriz, **aux, l, c, i, j, k, iter, vizinhas;

    printf("Quantidade de linhas, colunas: ");
    scanf("%d %d", &l, &c);
    printf("Quantas iteracoes? ");
    scanf("%d", &iter);

    matriz = alocaMatriz(l,c);

    aux = alocaMatriz(l,c);

    preencheMatrizBlinker(matriz, l, c);
    printf("\n");
    imprimeMatriz(matriz, l, c);

    copiaMatriz(matriz, aux, l, c);

    for(k=0; k<iter; k++)
    {
        for(i=1; i<l-1; i++)
            for(j=1; j<c-1; j++)
            {
                vizinhas = numeroVizinhas(matriz,i,j);
                if(matriz[i][j]==1)
                {
                    if(vizinhas<2 || vizinhas>3)
                        aux[i][j] = 0;
                }
                else if(vizinhas == 3)
                    aux[i][j] = 1;

            }

        copiaMatriz(aux, matriz, l, c);

        printf("\n");
        imprimeMatriz(matriz, l, c);
    }
}

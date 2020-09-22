#include <stdio.h>
#define N 11

int verificarcpf(int v[]);



int main()
{

    int v[N]= {0,8,1,3,3,0,7,3,9,2,8};
    if(verificarcpf(v)==1)
    {
        printf("valido");
    }
    else
    {
        printf("invalido");
    }

}
int verificarcpf(int v[])
{

    int i, j, soma1=0, soma2=0;
    for(i=0; i<=8; i++)
    {
        soma1 = soma1 + (i+1)*v[i];
    }
    for(j=1; j<=9; j++)
    {
        soma2 = soma2 + j*v[j];

    }
    if(v[9]==(soma1%11%10)&&v[10]==(soma2%11%10))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

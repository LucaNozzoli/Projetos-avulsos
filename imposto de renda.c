#include <stdio.h>

int main()
{

    int mes;
    float salario, imposto;

    imposto = 0;

    printf("digite o valor correspondente ao mes:\n");
    scanf("%d", &mes);
    printf("digite o valor do salario:\n");
    scanf("%f", &salario);
    if(salario>3743.19)
    {
        imposto = ((747.60) * 0.075) + ((748.95)*0.15) + ((750.49)*0.225) + ((salario-3743.19)*0.275);
    }
    else if(salario>=2995.71 && salario<=3743.19)
    {
        imposto = ((747.60) * 0.075) + ((748.95)*0.15) + ((salario-2995.70)*0.225);
    }
    else if(salario>=2246.76 && salario<=2995.70)
    {
        imposto = ((747.60) * 0.075) + ((salario-2246.76) * 0.15);
    }
    else if(salario>=1499.16 && salario<=2246.75)
    {
        imposto = (salario-1499.15) * 0.075;
    }
    printf("o valor a ser pago de imposto eh:%.2f", imposto);

}

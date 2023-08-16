#include <stdio.h>

int main() {
    int numero = 16;

    if (numero % 2 == 0 && numero >= 10 && numero <= 20) 
    {
        printf("O número é par e está entre 10 e 20.\n");
    } 
    else 
    {
        printf("O número não atende às condições.\n");
    }

    return 0;
}

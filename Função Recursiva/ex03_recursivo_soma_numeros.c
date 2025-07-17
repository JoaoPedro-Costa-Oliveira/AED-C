#include <stdio.h>

int soma_digitos(int n) {
    if (n == 0){
        return 0;   
    }
    else{
    return (n % 10) + soma_digitos(n / 10);
    }
}

int main() {
    int numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);

    int resultado = soma_digitos(numero);
    printf("A soma dos digitos de %d e %d\n", numero, resultado);

    return 0;
}

#include <stdio.h>

int soma_digitos(int n) {
    int soma = 0;
    while (n > 0) {
        soma += n % 10;  
        n = n / 10;      
    }
    return soma;
}

int main() {
    int numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);

    int resultado = soma_digitos(numero);
    printf("A soma dos digitos de %d e %d\n", numero, resultado);

    return 0;
}

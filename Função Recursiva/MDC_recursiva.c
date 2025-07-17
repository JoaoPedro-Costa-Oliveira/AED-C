#include <stdio.h>

int mdcRecursivo(int a, int b) {
    if (b == 0){ 
        return a;
    }  
    return mdcRecursivo(b, a % b);  
}

int main() {
    int num1, num2;

    printf("Digite dois números: ");
    scanf("%d %d", &num1, &num2);

    printf("MDC Recursivo: %d\n", mdcRecursivo(num1, num2));

    return 0;
}

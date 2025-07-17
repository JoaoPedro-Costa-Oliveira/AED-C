#include <stdio.h>

int mdcIterativo(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;

    printf("Digite dois números: ");
    scanf("%d %d", &num1, &num2);

    printf("MDC Iterativo: %d\n", mdcIterativo(num1, num2));

    return 0;
}

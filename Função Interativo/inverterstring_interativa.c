#include <stdio.h>
#include <string.h>

void inverterStringIterativa(char str[]) {
    int inicio = 0, fim = strlen(str) - 1;

    while (inicio < fim) {
        char temp = str[inicio];
        str[inicio] = str[fim];
        str[fim] = temp;

        inicio++;
        fim--;
    }
}

int main() {
    char str[100];

    printf("Digite uma string: ");
    scanf("%s", str);

    inverterStringIterativa(str);

    printf("String invertida: %s\n", str);

    return 0;
}

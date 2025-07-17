#include <string.h>
#include <stdio.h>

int palindromo(char str[], int inicio, int fim) {
    if (inicio >= fim) {
        return 1;
    }
    if (str[inicio] != str[fim]) {
        return 0;
    }
    return palindromo(str, inicio + 1, fim - 1);
}

int main() {
    char str[100];

    printf("Digite uma palavra: ");
    scanf("%s", str);

    if (palindromo(str, 0, strlen(str) - 1)) {
        printf("E palindromo!\n");
    } else {
        printf("Nao e palindromo.\n");
    }

    return 0;
}

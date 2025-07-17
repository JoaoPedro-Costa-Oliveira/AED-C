#include <stdio.h>
#include <string.h>

int comecaCom(const char *str, const char *prefixo) {
    while (*prefixo) {
        if (*str != *prefixo) return 0;
        str++;
        prefixo++;
    }
    return 1;
}

void buscaPorPrefixo(char *livros[], int n, const char *prefixo) {
    int inicio = 0, fim = n - 1, meio;
    int encontrado = -1;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (comecaCom(livros[meio], prefixo)) {
            encontrado = meio;
            break;
        }
        else if (strcmp(livros[meio], prefixo) < 0) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }

    if (encontrado != -1) {
        int i = encontrado;

        while (i >= 0 && comecaCom(livros[i], prefixo)) {
            i--;
        }
        i++;

        // Imprime todos os que têm o prefixo
        printf("Titulos encontrados:\n");
        while (i < n && comecaCom(livros[i], prefixo)) {
            printf("- %s\n", livros[i]);
            i++;
        }
    } else {
        printf("Nenhum titulo encontrado com o prefixo \"%s\".\n", prefixo);
    }
}

int main() {
    char *livros[] = {
        "Aprendendo C",
        "Banco de Dados",
        "C Completo",
        "Harpa Crista",
        "Harry Potter",
        "Java Facil",
        "Python Basico"
    };
    int tamanho = sizeof(livros) / sizeof(livros[0]);
    
    char prefixo[50];
    printf("Digite o prefixo a ser buscado: ");
    scanf("%s", prefixo);
    
    buscaPorPrefixo(livros, tamanho, prefixo);
    
    return 0;
}

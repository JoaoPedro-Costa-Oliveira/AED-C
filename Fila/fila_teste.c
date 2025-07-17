#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Fila {
    char nome[50]; // Armazena nomes completos
    struct Fila* prox;
} Fila;

// Função para inserir no final da fila
Fila* inserirPessoa(Fila* fila, char nome[]) {
    Fila* novo = (Fila*)malloc(sizeof(Fila));
    if (!novo) return fila; // Verifica se a alocação de memória falhou

    strcpy(novo->nome, nome);
    novo->prox = NULL;

    if (!fila) return novo; // Se a fila estiver vazia, retorna o novo nó

    Fila* temp = fila;
    while (temp->prox) {
        temp = temp->prox;
    }
    temp->prox = novo;
    
    return fila;
}

// Função para remover a pessoa no início da fila
Fila* removerPessoa(Fila* fila) {
    if (!fila) {
        printf("A fila está vazia!\n");
        return NULL;
    }

    Fila* temp = fila;
    printf("Atendendo: %s\n", temp->nome);
    fila = fila->prox;
    free(temp);
    
    return fila;
}

// Função para imprimir a fila atual
void imprimirFila(Fila* fila) {
    if (!fila) {
        printf("Fila vazia.\n");
        return;
    }
    
    Fila* temp = fila;
    while (temp) {
        printf("%s <- ", temp->nome);
        temp = temp->prox;
    }
    printf("NULL\n");
}

int main() {
    Fila* fila = NULL;
    int opcao;
    char nome[50];

    do {
        printf("\n1 - Adicionar pessoa\n");
        printf("2 - Atender pessoa\n");
        printf("3 - Exibir fila\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch (opcao) {
            case 1:
                printf("Nome da pessoa: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0'; // Remove o '\n' do fgets
                fila = inserirPessoa(fila, nome);
                break;
            case 2:
                fila = removerPessoa(fila);
                break;
            case 3:
                imprimirFila(fila);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}

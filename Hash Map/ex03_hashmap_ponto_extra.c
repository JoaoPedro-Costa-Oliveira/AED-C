#include <stdio.h>

#define TAM 10
#define VAZIO -1
#define REMOVIDO -2

int tabelaHash[TAM];

void inicializarTabela() {
    for (int i = 0; i < TAM; i++)
        tabelaHash[i] = VAZIO;
}

int hash(int chave) {
    return chave % TAM;
}

int inserir(int chave) {
    int indice = hash(chave);
    for (int i = 0; i < TAM; i++) {
        int tentativa = (indice + i) % TAM;
        if (tabelaHash[tentativa] == VAZIO || tabelaHash[tentativa] == REMOVIDO) {
            tabelaHash[tentativa] = chave;
            return tentativa;
        }
    }
    return -1;
}

int buscar(int chave) {
    int indice = hash(chave);
    for (int i = 0; i < TAM; i++) {
        int tentativa = (indice + i) % TAM;
        if (tabelaHash[tentativa] == VAZIO)
            return -1; 
        if (tabelaHash[tentativa] == chave)
            return tentativa; 
    }
    return -1;
}

int remover(int chave) {
    int pos = buscar(chave);
    if (pos != -1) {
        tabelaHash[pos] = REMOVIDO;
        return 1;
    }
    return 0;
}

void imprimirTabela() {
    printf("Tabela Hash:\n");
    for (int i = 0; i < TAM; i++) {
        printf("[%d]: ", i);
        if (tabelaHash[i] == VAZIO)
            printf("VAZIO\n");
        else if (tabelaHash[i] == REMOVIDO)
            printf("REMOVIDO\n");
        else
            printf("%d\n", tabelaHash[i]);
    }
}

int main() {
    inicializarTabela();

    inserir(17);
    inserir(27);
    inserir(37);
    inserir(47);
    inserir(57);

    imprimirTabela();

    int busca = 37;
    int pos = buscar(busca);
    if (pos != -1)
        printf("\nElemento %d encontrado na posicao: %d\n", busca, pos);
    else
        printf("\nElemento %d nao encontrado\n", busca);

    remover(37);

    printf("\nTabela apos remover o valor 37:\n");
    imprimirTabela();

    return 0;
}

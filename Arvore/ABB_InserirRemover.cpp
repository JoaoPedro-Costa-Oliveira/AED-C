#include <iostream>
#include <stdlib.h>

// Estrutura do nó
struct Node {
    int valor;
    struct Node* esquerda;
    struct Node* direita;
};

// Criação de um novo nó
Node* novoNo(int valor) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->valor = valor;
    node->esquerda = node->direita = NULL;
    return node;
}

// Inserção em árvore binária de busca
Node* inserir(Node* raiz, int valor) {
    if (raiz == NULL) return novoNo(valor);
    if (valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = inserir(raiz->direita, valor);
    return raiz;
}

// Busca em árvore binária
Node* buscar(Node* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor)
        return raiz;
    if (valor < raiz->valor)
        return buscar(raiz->esquerda, valor);
    return buscar(raiz->direita, valor);
}

// Encontrar o menor valor da subárvore
Node* encontrarMinimo(Node* node) {
    while (node->esquerda != NULL)
        node = node->esquerda;
    return node;
}

// Remoção em árvore binária
Node* remover(Node* raiz, int valor) {
    if (raiz == NULL) return raiz;
    if (valor < raiz->valor)
        raiz->esquerda = remover(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = remover(raiz->direita, valor);
    else {
        if (raiz->esquerda == NULL) {
            Node* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            Node* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        Node* temp = encontrarMinimo(raiz->direita);
        raiz->valor = temp->valor;
        raiz->direita = remover(raiz->direita, temp->valor);
    }
    return raiz;
}

// Travessia em ordem
void emOrdem(Node* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        std::cout << raiz->valor << " ";
        emOrdem(raiz->direita);
    }
}

// Função principal
int main() {
    Node* raiz = NULL;

    // Inserções
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    std::cout << "\nArvore em ordem: ";
    emOrdem(raiz);

    // Remoção
    raiz = remover(raiz, 20); // Nó sem filhos
    raiz = remover(raiz, 30); // Nó com um filho
    raiz = remover(raiz, 50); // Nó com dois filhos

    std::cout << "\nArvore apos remocoes: ";
    emOrdem(raiz);

    return 0;
}
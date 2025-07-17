#include <stdio.h>
#include <stdlib.h>
typedef  struct No{
   int numero;
   struct No*prox;
}No;

void inserirComeco(No** head, int valor){
    No* newNo = (No*)malloc(sizeof(No));
    newNo->numero = valor;
    newNo-> prox = *head;
    *head = newNo;
    
}

void inserirFim(No** head, int valor){
    No* newNo = (No*)malloc(sizeof(No));
    newNo-> numero = valor;
    newNo->prox = NULL;

    if(*head == NULL){
        *head = newNo;
        return;
    }
    
    No* temp = *head;
    while (temp->prox != NULL){
        temp = temp->prox;
    }
    temp->prox = newNo;    
}

void imprimir_lista(No* head){
    No*  temp = head;
    while (temp != NULL){
        printf("%d", temp->numero);
        temp =temp->prox;
    }
    printf("NULL/n");
}
int main(){
    No* head = NULL;
    inserirComeco(&head, 10);
    inserirComeco(&head, 20);
    inserirComeco(&head, 30);

    inserirFim(&head, 40);
    inserirFim(&head, 50);
    
    imprimir_lista(head);


    return 0;
}
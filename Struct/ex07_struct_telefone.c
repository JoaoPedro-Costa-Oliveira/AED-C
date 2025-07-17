#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Telefonica {
    char nome[50];
    char telefone[15];

} Telefonica ;

void procurarContato(Telefonica telefone[], char nome[], int n){
    printf("---------------------\n");
    printf("Procurar por nome\n");
    
    for (int i = 0; i < n; i++){
        if (strcmp(telefone[i].nome, nome) == 0) {
            printf("Contato encontrado!\n");
            printf("Nome: %s\n", telefone[i].nome);
            printf("Telefone: %s\n", telefone[i].telefone);
        }
        
    }

}


int main(){
    int N;
    scanf("%d", &N);
    
    Telefonica tel[N];
    for (int i = 0; i < N; i++){
        printf("----------------\n");
        printf("Contato %d\n", i +1);
        printf("Nome: ");
        scanf("%s", tel[i].nome);
        printf("Telefone: ");
        scanf("%s", tel[i].telefone);
    }

    char nomeBusca[50];
    printf("Digie o nome do contato: ");
    scanf("%s", nomeBusca);

    procurarContato(tel,nomeBusca,N);

    return 0;
}
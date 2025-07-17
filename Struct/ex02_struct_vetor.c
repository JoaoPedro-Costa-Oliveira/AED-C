#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Aluno{
    char nome[50];
    int matri;
    float nota;
} Aluno;

int main(){
    Aluno alunos[5];
    float notas,media = 0;

    for (int i = 0; i < 5; i++){
        printf("----------------------------------\n");
        printf("Aluno %d\n", i +1);
        printf("Nome: ");
        scanf("%s", alunos[i].nome);
        printf("Matricula: ");
        scanf("%d", &alunos[i].matri);
        printf("Nota: ");
        scanf("%f", &alunos[i].nota);

        notas += alunos[i].nota;
        media = notas / 5;
    }
    
    for (int i = 0; i < 5; i++){
        printf("----------------------------------\n");
        printf("Aluno %d\n", i +1);
        printf("Nome: %s\n",alunos[i].nome);
        printf("Matricula: %d\n", alunos[i].matri);
        printf("Nota: %f\n", alunos[i].nota);
    }
    printf("----------------------------------\n");
    printf("Media: %f", media);
    
    return 0;
}
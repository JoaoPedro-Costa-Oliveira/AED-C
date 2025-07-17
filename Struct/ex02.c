#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct {
    char nome[40];
    float nota_mat, nota_fisi, media;

    
    
} Alunos;


int main(){
    Alunos A1, A2, A3;

    
        printf("Nome 1: ");
        scanf("%s", A1.nome);
        printf("Nota MAt  aluno1: ");
        scanf("%f", &A1.nota_mat);
        printf("Nota FISICA aluno1: ");
        scanf("%f", &A1.nota_fisi);
        A1.media = (A1.nota_mat + A1.nota_fisi) /2;
        printf("Media: %f", A1.media);
        printf("----------------------\n");

        printf("Nome 2: ");
        scanf("%s", A2.nome);
        printf("Nota MAt  aluno2: ");
        scanf("%f", &A2.nota_mat);
        printf("Nota FISICA aluno1: ");
        scanf("%f", &A2.nota_fisi);
        A1.media = (A2.nota_mat + A2.nota_fisi) /2;
        printf("Media: %f", A2.media);
        
        printf("----------------------\n");
        printf("Nome 3: ");
        scanf("%s", A3.nome);
        printf("Nota MAt  aluno3: ");
        scanf("%f", &A3.nota_mat);
        printf("Nota FISICA aluno3: ");
        scanf("%f", &A3.nota_fisi);
        A1.media = (A3.nota_mat + A3.nota_fisi) /2;
        printf("Media: %f", A3.media);
        printf("----------------------\n");
         
     

    return 0;
}
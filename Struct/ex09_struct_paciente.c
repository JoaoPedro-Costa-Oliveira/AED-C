#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Paciente{
    char nome[50];
    int idade;
    char diagn[100];
} Paciente;

void pacientesAcima60(Paciente pacientes[], int n){
    printf("Mostrando Pacientes acima de 60 anos\n");
    for (int i = 0; i < n; i++){
        if (pacientes[i].idade > 60){
            printf("--------------------\n");
            printf("Paciente n %d\n", i+1);
            printf("Nome: %s\n", pacientes[i].nome);
            printf("Idade: %d\n", pacientes[i].idade);
            printf("Diagnostico: %s\n", pacientes[i].diagn);
        }
    }
}


int main(){
    int N;
    printf("Digite a quantidade de pacientes: ");
    scanf("%d", &N);
    
    Paciente pacientes[N];
    for (int i = 0; i < N; i++){
        printf("--------------------\n");
        printf("Paciente n %d\n", i+1);
        printf("Nome: ");
        scanf("%s", pacientes[i].nome);
        printf("Idade: ");
        scanf("%d", &pacientes[i].idade);
        printf("Diagnostico: ");
        scanf("%s", pacientes[i].diagn);
    }
    
    pacientesAcima60(pacientes,N);

    return 0;
}
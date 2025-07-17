#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Registro{
    char nome[50];
    char cargo[30];
    float salario;

} Registro;

int main(){
    int n;
    
    printf("Voce quer cadastrar qauntos funcioarios? [Digite um numero] ");
    scanf("%d", &n);
    Registro func[n];

    for (int i = 0; i < n; i++){
        printf("---------------------------\n");
        printf("Funcionario %d\n", i +1);
        printf("Nome: ");
        scanf("%s", func[i].nome);
        printf("Cargo: ");
        scanf("%s", func[i].cargo);
        printf("Salario: ");
        scanf("%f", &func[i].salario);
    }

    for (int i = 0; i < n; i++){
        printf("---------------------------\n");
        printf("Funcionario %d\n", i +1);
        printf("Nome: %s\n", func[i].nome);
        printf("Cargo: %s\n", func[i].cargo);
        printf("Salario: %f\n", func[i].salario);
        
    }
    printf("---------------------------\n");

    return 0;
}
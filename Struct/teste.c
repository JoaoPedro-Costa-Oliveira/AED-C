#include <stdio.h>
typedef struct {
    int idade;
    char nome[40];
    float salario;

} Func;


int main() {

Func funcionarios[3];

for (int i = 0; i < 3; i++){
    printf("Nome: ");
    scanf("%s", &funcionarios[i].nome);
    printf("\nIdade: ");
    scanf("%d", &funcionarios[i].idade);
    printf("\nSalario: ");
    scanf("%f", &funcionarios[i].salario); 
}
for (int i = 0; i < 3; i++){
    printf("%d, %s, %f", funcionarios[i].idade, funcionarios[i].nome, funcionarios[i].salario);
}




return 0;
}
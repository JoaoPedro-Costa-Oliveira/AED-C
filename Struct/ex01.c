#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct {
    int dia;
    char mes[20];
    int ano;

} Data;

typedef struct{
    char nome[40];
    int idade;
    float salario;
    Data nasci;

} Funcionarios;


int main(){
    Funcionarios Func[3];
    for (int i = 0; i < 3; i++){
        printf("Funcionario n %d\n",i+1);
        printf("Nome: ");
        scanf("%s", Func[i].nome);
        printf("Idade: ");
        scanf("%d", &Func[i].idade);
        printf("Salario: ");
        scanf("%f", &Func[i].salario);
        printf("Nascimento\n");
        printf("Dia: ");
        scanf("%d", &Func[i].nasci.dia);
        printf("Mes: ");
        scanf("%s", Func[i].nasci.mes);
        printf("Ano: ");
        scanf("%d",&Func[i].nasci.ano);
        printf("-----------------------");
    }
    

}
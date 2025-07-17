#include<iostream>
#include<stdlib.h>
#include<stdio.h>

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
        std::cout<<"Funcioanario " <<i+1<<"\n";

        std::cout<<"Nome: \n";
        std::cin>> Func[i].nome;
        std::cout<<"Idade: \n";
        std::cin>> Func[i].idade;
        std::cout<<"Salario: \n";
        std::cin>> Func[i].salario;
        std::cout<<"Ano: \n";
        std::cin>> Func[i].nasci.ano;
        std::cout<<"Mes: \n";
        std::cin>> Func[i].nasci.mes;
        std::cout<<"Dia: \n";
        std::cin>> Func[i].nasci.dia;
        std::cout<<"---------------------------------------\n\n";

    }
    

}
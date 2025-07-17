#include <iostream>

int buscaBin(int v[], int tamanho, int chave){
    
    int inicio = 0, fim = tamanho -1, meio;

    
    while (inicio <= fim)
    {
        meio = (inicio + fim )/2;

        if (v[meio] == chave)
        {
            return meio;
        }
        else if(v[meio] < chave){
            inicio = meio + 1;
        }
        else{
            fim = meio - 1;
        }
        
    }
    
    return -1;
}

int main(){

    int vetor[] = {10,20,30,40,50,60};
    int tam = 6;

    int valor = 50;

    int retorno;

    retorno = buscaBin(vetor, tam, valor);

    if(retorno != -1){
        std::cout<<"Valor: " <<valor <<"na posição: "<<retorno<<" encontrado. \n";

    }
    else{
        std::cout<<"Valor não encontrado";
    }
    

    return 0;
}
#include <iostream>

int buscaSeq(int v[], int tamanho, int chave){

    for (int i = 0; i < tamanho; i++){
        if (v[i] == chave)
        {
            return i;
        }
        
        
    }

    return -1;
    
}


int main(){

    int vetor[] = {10,20,30,40,50,60};
    int tam = 6;

    int valor = 50;

    int retorno;

    retorno = buscaSeq(vetor, tam, valor);

    if(retorno != -1){
        std::cout<<"Valor: " <<valor <<"na posição: "<<retorno<<" encontrado. \n";

    }
    else{
        std::cout<<"Valor não encontrado";
    }
    

    return 0;
}
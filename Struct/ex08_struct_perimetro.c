#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Retangulo{
    float altura, base;
} Retangulo;

float area(float a, float b){
    return a * b;
}

float perimetro(float a, float b){
    return 2*(a + b);
}


int main(){
    Retangulo retan;
    printf("Digite a altura do retangulo: ");
    scanf("%f", &retan.altura);
    printf("Digite a base do retangulo: ");
    scanf("%f", &retan.base);

    printf("Perimetro do retangulo: %.2f + %.2f = %.2f\n", retan.altura, retan.base,perimetro(retan.altura, retan.base));
    

    printf("Area do retangulo: %.2f x %.2f = %.2f", retan.altura, retan.base,area(retan.altura, retan.base));
    



    return 0;
}
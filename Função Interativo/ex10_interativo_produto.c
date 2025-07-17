#include <stdio.h>

int produto(int a, int b ){
    int resul = 0;
    for (int i = 0; i < b; i++){
        resul+= a;
    }
    return resul;
}

int main(){
    
    printf("%d\n",produto(5,3));
    printf("%d", produto(7,3));

    return 0;
}
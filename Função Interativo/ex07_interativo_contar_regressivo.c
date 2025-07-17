#include <stdio.h>

void contagem_regresiva(int n){
    for (int i = n; i >= 0; i--){
        printf("%d ", i);
    }

}


int main(){

    contagem_regresiva(5);

    return 0;
}
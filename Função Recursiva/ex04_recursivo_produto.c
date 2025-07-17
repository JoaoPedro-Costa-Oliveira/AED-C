#include <stdio.h>

int produto(int a, int b){
    if(b == 0){
        return 0;
    }
    else{
        return a +produto(a,b -1);
    }
}

int main(){

    printf("%d\n",produto(5,3));
    printf("%d",produto(7,2));
    
    return 0;
}
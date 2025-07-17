#include <stdio.h>

void insertionSort(int arr[], int tam){
    for (int i = 0; i < tam; i++)
    {
        int key =arr[i];
        int j =i -1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j +1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    
}

void insertionSortPares(int arr[], int tam) {
    int pares[tam];     
    int posicoes[tam];  
    int nPares = 0;

    for (int i = 0; i < tam; i++) {
        if (arr[i] % 2 == 0) {
            pares[nPares] = arr[i];
            posicoes[nPares] = i;
            nPares++;
        }
    }

    for (int i = 1; i < nPares; i++) {
        int key = pares[i];
        int j = i - 1;
        while (j >= 0 && pares[j] > key) {
            pares[j + 1] = pares[j];
            j--;
        }
        pares[j + 1] = key;
    }

    for (int i = 0; i < nPares; i++) {
        arr[posicoes[i]] = pares[i];
    }
}

void insertionSortdecrescente(int arr[], int tam){
    for (int i = 0; i < tam; i++)
    {
        int key =arr[i];
        int j =i -1;
        while (j >= 0 && arr[j] < key)
        {
            arr[j +1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    
}


int main(){

    int arr[] = {22, 11, 99, 88, 9, 7, 42, 65, 33, 10};
    int tam = 10;

    insertionSort(arr, tam);
    printf("----------------\n");
    printf("Questao 1\n");
    printf("Array inicial: {22, 11, 99, 88, 9, 7, 42, 65, 33, 10}, tam %d \n", tam);

    for (int i = 0; i < tam; i++)
    {
        printf("%d ", arr[i]);
    }

    int arr1[] = {9, 8, 3, 4, 7, 6, 1, 2, 5, 0};

    printf("----------------\n");
    printf("Questao 2\n");
    printf("Array inicial: {9, 8, 3, 4, 7, 6, 1, 2, 5, 0}, tam %d \n", tam);

    insertionSortPares(arr1, tam);

    for (int i = 0; i < tam; i++)
    {
        printf("%d ", arr1[i]);
    }
    
    printf("----------------\n");
    printf("Questao 3\n");
    printf("Array inicial: {30, 20, 10, 40, 50, 70, 60, 90, 80, 100}, tam %d \n", tam);

    int arr2[] = {30, 20, 10, 40, 50, 70, 60, 90, 80, 100};
    insertionSortdecrescente(arr2, tam);

    for (int i = 0; i < tam; i++)
    {
        printf("%d ",arr2[i]);
    }
    
    
    

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ContaBancaria {
    char nometitular[50];
    int numeroconta;
    float saldo;
} ContaBancaria;

void depositar(ContaBancaria *conta) {
    float valor;
    printf("Quer depositar quanto na conta? ");
    scanf("%f", &valor);
    
    if (valor > 0) {
        conta->saldo += valor;
        printf("Depósito de R$ %.2f realizado com sucesso!\n", valor);
    } else {
        printf("Erro: o valor do depósito deve ser positivo!\n");
    }
}

int sacar(ContaBancaria *conta) {
    float valor;
    printf("Digite o valor para sacar na conta: ");
    scanf("%f", &valor);

    if (valor > conta->saldo) {
        printf("Erro: saldo insuficiente!\n");
        return 0;
    } else if (valor <= 0) {
        printf("Erro: o valor do saque deve ser positivo!\n");
        return 0;
    } else {
        conta->saldo -= valor;
        printf("Saque de R$ %.2f realizado com sucesso!\n", valor);
        return 1;
    }
}

void exibir_saldo(ContaBancaria *conta) {
    printf("\n--- Dados da Conta ---\n");
    printf("Titular: %s\n", conta->nometitular);
    printf("Numero da Conta: %d\n", conta->numeroconta);
    printf("Saldo: R$ %.2f\n", conta->saldo);
    printf("----------------------\n");
}

int main() {
    ContaBancaria conta;
    
    strcpy(conta.nometitular, "Joao");
    conta.numeroconta = 12345;
    conta.saldo = 1000.0;

    int opcao;
    
    do {
        printf("\n=== MENU ===\n");
        printf("1 - Depositar\n");
        printf("2 - Sacar\n");
        printf("3 - Ver dados da conta\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                depositar(&conta); 
                break;
            case 2:
                sacar(&conta); 
                break;
            case 3:
                exibir_saldo(&conta);
                break;
            case 4:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção invalida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

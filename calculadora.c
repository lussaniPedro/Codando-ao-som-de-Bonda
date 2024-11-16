#include <stdio.h>
#include <stdlib.h>

void calcular(int op, float num1, float num2);

int main(){
    int op;
    float num1, num2;

    do{
        system("cls");
        printf("-- Calculadora --\n");
        printf("- (1) Adicao\n");
        printf("- (2) Subtracao\n");
        printf("- (3) Multiplicacao\n");
        printf("- (4) Divisao\n");
        printf("- (5) Sair\n");
        printf("Digite a opcao: ");
        scanf("%d", &op);

        if(op >= 1 && op <= 4){
            system("cls");
            printf("Digite o primeiro numero: ");
            scanf("%f", &num1);

            printf("Digite o segundo numero: ");
            scanf("%f", &num2);
        }

        system("cls");
        calcular(op, num1, num2);
    } while(op != 5);

    return 0;
}

void calcular(int op, float num1, float num2){
    float res;

    switch(op){
        case 1:
            res = num1 + num2;
            printf("O resultado da soma de %.2f e %.2f eh %.2f\n", num1, num2, res);
            break;
        case 2:
            res = num1 - num2;
            printf("O resultado da subtracao de %.2f e %.2f eh %.2f\n", num1, num2, res);
            break;
        case 3:
            res = num1 * num2;
            printf("O resultado da multiplicacao de %.2f e %.2f eh %.2f\n", num1, num2, res);
            break;
        case 4:
            if(op == 4 && num2 != 0){
                res = num1 / num2;
                printf("O resultado da divisao de %.2f e %.2f eh %.2f\n", num1, num2, res);
            } else{
                printf("Erro! divsao por 0 nao permitida!!!\n");
            }
            break;
        case 5:
            printf("Saindo...");
            return;
        default:
            printf("Erro! Opcao invalida!!!\n");
            break;
    }
    system("pause");
}
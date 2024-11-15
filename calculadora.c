#include <stdio.h>
#include <stdlib.h>

void menu();
int OpcaoCalcular();
int calcular(int op, double num1, double num2);
void exibirHistorico();

double *_result;
int _historico = 0;

int main(){
    menu();
    return 0;
}

void menu(){

    do{
        system("cls");
        printf("-- Calculadora --\n");
        printf("- (1) Adicao\n");
        printf("- (2) Subtracao\n");
        printf("- (3) Multiplicacao\n");
        printf("- (4) Divisao\n");
        printf("- (5) Historico\n");
        printf("- (6) Sair\n\n");
    } while(OpcaoCalcular() != 6);
}

int OpcaoCalcular(){
    int op;
    double num1, num2;

    printf("Digite a opcao: ");
    scanf("%d", &op);

    if(op >= 1 && op <= 4){
        system("cls");
        printf("Digite o primeiro numero: ");
        scanf("%lf", &num1);

        printf("Digite o segundo numero: ");
        scanf("%lf", &num2);
    }

    if(op == 4 && num2 == 0){
        system("cls");
        printf("*** ERRO!! Divisao por 0 NAO permitida!! SEU VERME IMUNDO!!! ***\n");
        printf("*** ERRO!! Divisao por 0 NAO permitida!! SEU VERME IMUNDO!!! ***\n");
        printf("*** ERRO!! Divisao por 0 NAO permitida!! SEU VERME IMUNDO!!! ***\n");
        exit(1);
    }

    if(_historico == 0){
        _result = (double*)malloc(1 * sizeof(double));
    } else{
        _result = (double*)realloc(_result, (_historico + 1) * sizeof(double));
    }
    _result[_historico] = calcular(op, num1, num2);
    _historico++;

    return op;
}

int calcular(int op, double num1, double num2){
    double res;

    system("cls");
    switch(op){
        case 1:
            res = num1 + num2;
            printf("O resultado da soma de %.1lf e %.1lf eh %.1lf\n", num1, num2, res);
            break;
        case 2:
            res = num1 - num2;
            printf("O resultado da subtracao de %.1lf e %.1lf eh %.1lf\n", num1, num2, res);
            break;
        case 3:
            res = num1 * num2;
            printf("O resultado da multiplicacao de %.1lf e %.1lf eh %.1lf\n", num1, num2, res);
            break;
        case 4:
            res = num1 / num2;
            printf("O resultado da divisao de %.1lf e %.1lf eh %.1lf\n", num1, num2, res);
            break;
        case 5:
            exibirHistorico();
            break;
        case 6:
            printf("Saindo...");
            exit(0);
        default:
            printf("Opcao invalida!!!\n");
            break;
    }
    system("pause");

    return res;
}

void exibirHistorico(){
    if(_historico == 0){
        printf("** Historico vazio! **\n");
        system("pause");
        return;
    }
    printf("-- Historico --\n");
    for(int i = 0; i < _historico; i++){
        if(i < 10 && _result[i] < 10){
            printf("[0%d]|  0%.1lf  |\n", i + 1, _result[i]);
        } else if(i >= 10 && _result[i] < 10){
            printf("[%d]|  0%.1lf  |\n", i + 1, _result[i]);
        } else if(i < 10 && _result[i] >= 10){
            printf("[0%d]|  %.1lf  |\n", i + 1, _result[i]);
        } else{
            printf("[%d]|  %.1lf  |\n", i + 1, _result[i]);
        }
    }
}
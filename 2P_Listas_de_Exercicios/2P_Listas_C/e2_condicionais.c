#include <stdio.h>
#include <stdbool.h>

int main() {
    //Checagem básica de par ou ímpar
    int num;
    printf("\nDigite um numero inteiro: ");
    scanf("%d", &num);
    if (num % 2 == 0){
        printf("Eh par!\n");
    } else {
        printf("Eh impar!\n");
    }
    
    //Checagem básica - é ou não adulto
    int idade;
    printf("\nDigite sua idade: ");
    scanf("%d", &idade);
    if (idade <= 0) {
        printf("Idade invalida!\n");
    } else if (idade < 18) {
        printf("Voce nao eh um adulto.\n");
    } else {
        printf("Voce eh legalmente um adulto!\n");
    }
    
    //Condicional para determinar aprovação de um estudante
    float nota_aluno;
    printf("\nDigite a nota de um aluno: ");
    scanf("%f", &nota_aluno);
    if (0 > nota_aluno || nota_aluno > 10){
        printf("Nota invalida!\n");
    } else if (nota_aluno < 5.0){
        printf("Voce foi reprovado!\n");
    } else {
        printf("Voce foi aprovado!\n");
    }
    
    //Usa-se Switch-Case para imprimir o dia da semana baseado no input 
    int dia_semana;
    printf("\nDigite um numero entre 1 e 7: ");
    scanf("%d", &dia_semana);
    if(dia_semana < 1 || dia_semana > 7) {
        printf("Erro! Digite um numero entre 1 e 7!\n");
    } else {
        switch (dia_semana){
        case 1:
            printf("Domingo\n");
            break;
        case 2:
            printf("Segunda-Feira\n");
            break;
        case 3:
            printf("Terca-Feira\n");
            break;
        case 4:
            printf("Quarta-Feira\n");
            break;
        case 5:
            printf("Quinta-Feira\n");
            break;
        case 6:
            printf("Sexta-Feira\n");
            break;
        case 7:
            printf("Sabado\n");
            break;
        }
    }

    //Condicional comparando dois inteiros
    int n1, n2;
    printf("\nDigite 2 (dois) numeros inteiros: ");
    scanf("%d %d", &n1, &n2);
    if (n1 > n2) {
        printf("Numero %d eh maior que %d!\n", n1, n2);
    } else if (n1 < n2) {
        printf("Numero %d eh maior que %d!\n", n2, n1);
    } else {
        printf("Ambos sao iguais!\n");
    }

    //Calculadora simples, desta vez com Switch-Case
    double num_a, num_b, resultado;
    char operador;
    printf("\nDigite dois numeros: ");
    scanf("%lf %lf", &num_a, &num_b);
    printf("\nDigite um operador aritmetico: ");
    scanf(" %c", &operador);
    switch (operador){
        case '+':
            resultado = num_a + num_b;
            break;
        case '-':
            resultado = num_a - num_b;
            break;
        case '*':
            resultado = num_a * num_b;
            break;
        case '/':
            if (num_b != 0) {
                resultado = num_a / num_b;
            } else {
                printf("Erro - Divisao por Zero!");
                return 1;
            }
            break;
        default:
        printf("Operador invalido! Somente '+', '-', '*' ou '/'.");
        return 1;
    }
    printf("Resultado: %.2lf\n", resultado);

    //Condicionais analisam um triângulo, e determinam seu tipo de acordo com as expressões matemáticas 
    double lado_a, lado_b, lado_c;
    printf("\nDigite 3 (tres) lados de um triangulo: ");
    scanf("%lf %lf %lf", &lado_a, &lado_b, &lado_c);
    bool triangulo = (lado_a>0) && (lado_b>0) && (lado_c>0) &&
    (lado_a+lado_b>lado_c) && (lado_a+lado_c>lado_b) && (lado_b+lado_c>lado_a);
    if (triangulo) {
        printf("Eh um triângulo: ");
    if (lado_a == lado_b && lado_b == lado_c) {
        printf("Equilatero (todos lados iguais)\n");
        }
    else if (lado_a == lado_b || lado_a == lado_c || lado_b == lado_c) {
        printf("Isosceles (dois lados iguais)\n");
        }
    else {
        printf("Escaleno (todos lados diferentes)\n");
        }
    } else {
        printf("Nao forma um triangulo!\n");
    }
    
    //Mostra a quantidade mínima de cédulas para representar um dado valor
    int valor_pago, aux;
    printf("\nDigite o valor em dinheiro: ");
    scanf("%d", &valor_pago);
    aux = valor_pago;
    printf("Notas de 100: %d\n", aux / 100);
    aux %= 100;
    printf("Notas de 50: %d\n", aux / 50);
    aux %= 50;
    printf("Notas de 20: %d\n", aux / 20);
    aux %= 20;
    printf("Notas de 10: %d\n", aux / 10);
    aux %= 10;
    // Cálculo das notas de R$5 com ajuste para notas de R$2
    int notas5 = aux / 5;
    int resto = aux % 5;
    // Condicional para ajustar entre notas de R$5 e R$2
    if (resto % 2 != 0 && notas5 > 0) {
        notas5--;
        resto += 5;
    }
    int notas2 = resto / 2;
    printf("Notas de 5: %d\n", notas5);
    printf("Notas de 2: %d\n", notas2);

    return 0;
}
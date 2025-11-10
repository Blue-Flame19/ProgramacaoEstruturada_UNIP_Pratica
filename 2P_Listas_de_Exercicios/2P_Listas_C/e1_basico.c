#include <stdio.h>
#include <stdbool.h>

int main() {
    //Converte anos para meses
    int idade_anos, idade_meses;
    printf("\nDigite sua idade (em anos): ");
    scanf("%d", &idade_anos);
    idade_meses = idade_anos * 12;
    printf("\nSua idade em meses eh: %d\n", idade_meses);
    
    //Cálculo do dobro/triplo de um valor
    int num;
    printf("\nDigite um numero inteiro: ");
    scanf("%d", &num);
    printf("Dobro: %d\n", num*2);
    printf("Triplo: %d\n", num*3);
    
    //Calcula a média de duas notas
    float nota1, nota2;
    printf("\nDigite a nota 1, e a nota 2 de um aluno: ");
    scanf("%f" "%f", &nota1, &nota2);
    printf("Media das notas: %.2f\n", (nota1 + nota2)/2);
    
    //Confere se um número é positivo - 0 é considerado 'não positivo'
    int num_int;
    printf("\nDigite um numero inteiro: ");
    scanf("%d", &num_int);
    int n_positivo = num_int > 0; 
    printf("O numero eh %s",n_positivo ? "positivo.\n": "nao positivo.\n");
    
    //Converte Celsius -> Fahrenheit
    float t_celsius;
    printf("\nDigite a temperatura em Celsius: ");
    scanf("%f", &t_celsius);
    float t_fahrenheit = (9.0 / 5.0 * t_celsius) + 32;
    printf("Temperatura em Fahrenheit: %.2f\n", t_fahrenheit);
    
    //Cálculo do IMC
    float peso, altura;
    printf("\nDigite seu peso (em Kg), e altura (em metros): ");
    scanf("%f %f", &peso, &altura);
    float calc_imc = peso / (altura * altura);
    printf("Seu IMC eh: %.2f.\n", calc_imc);
    
    //Determina se o usuário pode ou não votar
    int idade;
    printf("\nDigite sua idade: ");
    scanf("%d", &idade);
    bool adulto = (idade > 18);
    printf("Voce pode votar? %s", adulto ? "Sim.\n" : "Nao.\n");
    
    //Converte segundos para minutos/segundos
    int segundos_total;
    printf("\nDigite uma qtd. de segundos: ");
    scanf("%d", &segundos_total);
    int minutos = segundos_total / 60;
    int segundos = segundos_total % 60;
    printf("%d segundos = %d minutos e %d segundos.\n", segundos_total, minutos, segundos);
    
    //Calculadora simples para dois inteiros
    int n1, n2;
    printf("\nDigite dois numeros inteiros: ");
    scanf("%d %d", &n1, &n2);
    printf("\nSoma de %d + %d = %d\n", n1, n2, (n1 + n2));
    printf("Subtracao de %d - %d = %d\n", n1, n2, (n1 - n2));
    printf("Multiplicacao de %d * %d = %d\n", n1, n2, (n1 * n2));
    //Utiliza-se um 'short-circuit' para simular um 'if-else'. ('&&' precisa que ambos os argumentos sejam verdade) 
    n2 && printf("Divisao de %d / %d = %d, resto = %d\n", n1, n2, (n1 / n2), (n1 % n2));
    !n2 && printf("Divisao por zero nao permitida!\n");
    
    //Cálculo de média ponderada com três notas
    float nota_a, nota_b, nota_c;
    int peso_a, peso_b, peso_c;
    printf("\nDigite tres notas: ");
    scanf("%f %f %f", &nota_a, &nota_b, &nota_c);
    printf("e seus respectivos pesos (para calculo de media ponderada): ");
    scanf("%d %d %d", &peso_a, &peso_b, &peso_c);
    float media_ponderada = ((nota_a * peso_a) + (nota_b * peso_b) + (nota_c * peso_c)) / ((peso_a + peso_b + peso_c) + !(peso_a + peso_b + peso_c));
    printf("A media ponderada de %.2f, %.2f, %.2f, eh: %.2f\n", nota_a, nota_b, nota_c, media_ponderada);
        
    return 0;
}
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define LER_NOME 51
typedef enum {
    CALCULO_AREA = 1, CALCULO_FATORIAL = 2, NPRIMO_VERIFICAR = 3, SAIDA = 4
} Operacao;

void limparBuffer () { //Simples função para evitar overflow de input
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void boasVindas() { //Mensagem inicial - pede o nome do usuário
    char nome[LER_NOME];
    printf("Digite seu nome: "); fgets(nome, LER_NOME, stdin);
    //Esse 'for' loop funciona de maneira similar a 'strcspn' - apaga a newline após o 'fgets'
    for (int i = 0; nome[i]; i++) if (nome[i] == '\n') nome[i] = '\0';
    printf("Bem-vinda (o), %s!\n", nome);
}

float lerFloat() { //Validação de input para números reais
    float valor;
    while (1) {
        if (scanf("%f", &valor) == 1) {
            limparBuffer();
            return valor;
        }
        printf("Entrada invalida! Digite um numero valido: ");
        limparBuffer();
    }
}

int lerInteiro() { //Validação de input para números inteiros
    int valor;
    while (1) {
        if (scanf("%d", &valor) == 1) {
            limparBuffer();
            return valor;
        }
        printf("Entrada invalida! Digite um numero inteiro: ");
        limparBuffer();
    }
}

void menuPrint () { //Exibe as opções da função 'menu'
    printf("\nEscolha uma opcao (digite o numero correspondente): \n");
    printf("'1' - Area de um quadrado\n");
    printf("'2' - Calculo de fatorial\n");
    printf("'3' - Confere se um numero eh, ou nao, primo\n");
    printf("'4' - Encerra o programa\n");
}

float areaQuadrado(float n) { //Calcula a área de um quadrado
    return n * n;
}

int calcFatorial(int n) { //Calcula o fatorial de 'n'
    int fatorial = 1;
    for (; n >= 1; n--) {
        fatorial *= n;
    }
    return fatorial;
}

bool ehPrimo(int n) { //Função booleana para verificação de nº primo
    if (n < 2) return false; //0 e 1 não são primos
    if (n == 2) return true; //2 é primo
    if (n % 2 == 0) return false; //Números pares não são primos
    for (int i = 3; i * i <= n; i += 2) { //Analisa somente ímpares
        if (n % i == 0) return false;
    }
    return true;
}

void menu() { //Menu de escolha entre 3 operações
    int opcao;
    bool repetir_escolha = true;

    do { 
        menuPrint();
        scanf("%d", &opcao); limparBuffer();

        switch(opcao) { //Esta opção chama 'areaQuadrado' para obter a área do quadrado
            case CALCULO_AREA:
                {printf("\nDigite o lado de um quadrado: "); float l_quadrado = lerFloat();
                printf("A area do quadrado eh %.2f.\n", areaQuadrado(l_quadrado));
                break;
                }
            case CALCULO_FATORIAL: //Esta opção chama 'calcFatorial' para obter o fatorial de 'num'
                {printf("\nDigite um numero (inteiro): "); int num = lerInteiro();
                int resultado = calcFatorial(num);
                
                if (resultado == -1) { //Validação necessária para evitar overflow (cálculo de fatoriais acima de 12 podem ser problemáticos)
                    printf("Erro: Numero deve estar entre 0 e 12.\n");
                } else {
                    printf("O fatorial de %d eh %d.\n", num, resultado);
                }
                break;
                }
            case NPRIMO_VERIFICAR: //Esta chama 'ehPrimo' para verificar se 'num' é, ou não, primo
                {printf("\nDigite um numero (inteiro): "); int num = lerInteiro();
    
                if (eh_primo(num)) {
                    printf("%d eh primo!\n", num);
                } else {
                    printf("%d nao eh primo. :(\n", num);
                }
                break;
                }
            case SAIDA: //Encerra o menu
                printf("\n=== FIM ===\n");
                repetir_escolha = false;
                break;
            default:
                printf("Opcao invalida! Digite uma opcao: 1/2/3/4!\n");
                break;
        }
    } while (repetir_escolha);
}

int main() {
    boasVindas();
    menu();
    
    return 0;
}
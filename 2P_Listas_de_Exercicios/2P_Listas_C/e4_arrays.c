#include <stdio.h>
#define VETOR_P 5
#define LER_NOME 51
#define NOME_COMPLETO 101
#define FRASE_TAM 1000
#define VETOR_INT 4
#define CONJ_I 6

int main () {
    int c; //Variável a ser usada na limpeza de input buffers

    //Leitura e display de 5 notas
    float notas[VETOR_P];
    printf("\n=== Conjunto de 5 notas ===\n");
    for (int i = 0; i < VETOR_P; i++) {
        printf("\nDigite a nota %d: \n", i+1); //'i+1' mostra qual a nota a ser inserida
            //Verifica se o input é válido (float)
            if (scanf("%f", &notas[i]) != 1) {
            printf("Erro: Por favor, digite um numero valido!\n");
            //Limpa o input buffer para evitar loop infinito
            while ((c = getchar()) != '\n' && c != EOF);
            i--; //Repete esse passo no loop
            continue;
            }
            //Validação das notas (devem estar entre 0 e 10)
            if (notas[i] < 0.0 || notas[i] > 10.0) {
            printf("Erro: A nota deve estar entre 0.0 e 10.0!\n");
            i--;
            continue;
            }
    }
    printf("Notas Digitadas:\n");
    for (int i = 0; i < VETOR_P; i++) {
        printf("%.2f ", notas[i]);
    }
    while ((c = getchar()) != '\n' && c != EOF);

    //Leitura de uma matriz 2x2, depois somando todos os elementos
    float matriz[2][2], soma_matriz = 0;
    printf("\n\nDigite 4 numeros de uma matriz: ");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int elem_valido = 0;
            while (!elem_valido) {
                if (scanf("%f", &matriz[i][j]) == 1) {
                elem_valido = 1;
                soma_matriz += matriz[i][j];
            } else {
                printf("Entrada invalida! Digite um numero para a matriz[%d][%d]: .\n", i, j);
                while ((c = getchar()) != '\n' && c != EOF);
            }
            }
        }
    }
    printf("Soma dos valores: %.2f.\n", soma_matriz);
    while ((c = getchar()) != '\n' && c != EOF);

    //O usuário digita uma frase; imprime-se na tela a quantidade de vogais
    char frase[FRASE_TAM];
    int cont_vogais = 0;
    printf("\nDigite uma frase: ");
    if (fgets(frase, FRASE_TAM, stdin) != NULL) {
        for (int i = 0; frase[i] != '\0'; i++) {
            char c = tolower(frase[i]);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                cont_vogais ++;
            }
        }
        printf("Num. de vogais: %d.\n", cont_vogais);
    }
    
    //Um vetor recebe 4 números inteiros; calcula e retorna a soma de todos os elementos
    int vetor_inteiros[VETOR_INT], soma_vetor = 0;
    printf("\nAdicione 4 numeros a uma lista/vetor: ");
    for (int i = 0; i < VETOR_INT; i++) {
            int elem_valido = 0;
            while (!elem_valido) {
            if (scanf("%d", &vetor_inteiros[i]) == 1) {
                elem_valido = 1;
                soma_vetor += vetor_inteiros[i];
            } else {
                printf("Entrada invalida! Digite um numero inteiro para o vetor[%d]: .\n", i);
                while ((c = getchar()) != '\n' && c != EOF);
            }
            }
    }
    printf("Lista: ");
    for (int i = 0; i < VETOR_INT; i++) {
        printf("%d ", vetor_inteiros[i]);
    }
    printf("\nSoma dos valores: %d.\n", soma_vetor);
    while ((c = getchar()) != '\n' && c != EOF);

    //Lê uma palavra (máximo de 50 caracteres), e retorna a qtd. de caracteres
    char palavra[LER_NOME];
    int cont_letras = 0;
    printf("\nDigite uma palavra (max. de 50 caracteres):");
    if (fgets(palavra, LER_NOME, stdin)) {
    //Verifica se o input foi truncado (sem '\n')
    while (palavra[cont_letras] != '\0' && palavra[cont_letras] != '\n') {
        cont_letras++;
    }
    if (palavra[cont_letras] == '\n') {
        //Se o input não foi truncado, substitui '\n' com '\0'
        palavra[cont_letras] = '\0';
    } else {
        //Se o input foi truncado, limpa o input buffer, evitando overflow
        while ((c = getchar()) != '\n' && c != EOF);
    }
    printf("\nA palavra '%s' tem '%d' caracteres.\n", palavra, cont_letras);
    }

    //Após receber 6 números, mostra qual desses é o maior
    int conjunto_i[CONJ_I];
    printf("\n === Conjunto I - 6 valores ===\n");
    for (int i = 0; i < 6;) {
        printf("\nAdicione um numero (inteiro) ao conjunto I: \n");
        if (scanf("%d", &conjunto_i[i]) == 1) {
            i++;
        } else {
            printf("\nErro! Digite um numero inteiro valido!\n");
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }
    printf("Conjunto I: \n"); //Mostra o conjunto I completo
    for (int i = 0; i < CONJ_I; i++){
        printf("%d ", conjunto_i[i]);
    }
    int max_conj_i = conjunto_i[0]; //Inicializa essa variável com o primeiro elemento do conjunto I
    for (int i = 1; i < 6; i++) { //Inicia do índice [1], por que [0] foi encrontrado acima
        if (conjunto_i[i] > max_conj_i) { //Compara o número atual com o maior número encontrado
            max_conj_i = conjunto_i[i];  //Caso o novo número seja maior, substitui o nº anterior
        }
    }
    printf("\nO maior numero do conjunto I: %d.\n", max_conj_i);
    while ((c = getchar()) != '\n' && c != EOF);

    //Recebe duas palavras, e as concatena em uma única string
    char palavra_a[LER_NOME], palavra_b[LER_NOME], palavra_ab[NOME_COMPLETO];
    //Obs.: Se 'palavra_a' for maior que 50 caracteres, os extras entram em 'palavra_b' - bug 
    printf("\nDigite a primeira palavra (max. 50 caracteres): \n"); fgets(palavra_a, LER_NOME, stdin);
    printf("\nDigite a segunda palavra (max. 50 caracteres): \n"); fgets(palavra_b, LER_NOME, stdin);
    //Remoção de '\n' (substitui com '\0')
    for (int i = 0; palavra_a[i]; i++) if (palavra_a[i] == '\n') palavra_a[i] = '\0';
    for (int i = 0; palavra_b[i]; i++) if (palavra_b[i] == '\n') palavra_b[i] = '\0';
    {//Concatenação é isolada para evitar conflitos
        int j = 0;
        for (int i = 0; palavra_a[i]; i++) palavra_ab[j++] = palavra_a[i]; //Copia 'palavra_a' para 'palavra_ab' 
        palavra_ab[j++] = ' '; //Adiciona um espaço
        for (int i = 0; palavra_b[i]; i++) palavra_ab[j++] = palavra_b[i]; //Copia 'palavra_b' para 'palavra_ab'
        palavra_ab[j] = '\0'; //Adiciona um '\0' para terminar a string
    }
    printf("\nConcatenacao: %s\n", palavra_ab);

    //Analisa dois nomes, informando se são iguais ou diferentes
    char texto_1[LER_NOME], texto_2[LER_NOME];
    int comparar_strings;
    //Obs.: Se 'texto_1' for maior que 50 caracteres, os extras entram em texto_2' - bug 
    printf("\nDigite uma palavra (max. 50 caracteres): \n"); fgets(texto_1, LER_NOME, stdin);
    printf("\nDigite outra palavra (max. 50 caracteres): \n"); fgets(texto_2, LER_NOME, stdin);
    //Verifica se há overflow após a segunda string
    int eh_newline = 0;
    for (int i = 0; i < LER_NOME && texto_2[i] != '\0'; i++) {
    if (texto_2[i] == '\n') {
        eh_newline = 1;
        break;
        }
    }
    //Remove '\n', usando a abordagem simples (até encontrar '\n'; converte para '\0')
    for (int i = 0; texto_1[i]; i++) if (texto_1[i] == '\n') texto_1[i] = '\0';
    for (int i = 0; texto_2[i]; i++) if (texto_2[i] == '\n') texto_2[i] = '\0';
    //Agora verifica se é preciso limpar o buffer
    if (!eh_newline) {
        while ((c = getchar()) != '\n' && c != EOF);
    }
    comparar_strings = 1; //Após limpar as duas strings, faz a comparação
    for (int i = 0; i < LER_NOME; i++) {
        if (texto_1[i] != texto_2[i]) {
            comparar_strings = 0;
            break;
        }
        if (texto_1[i] == '\0') {
            break;
        }
    }
    if (comparar_strings) {
        printf("\nAmbas as palavras sao iguais!\n");
    } else {
        printf("\nAs palavras sao diferentes!\n");
    }
    
    //Lê os números de uma matriz 3x3, retornando a soma da diagonal principal
    float q_magico[3][3], soma_qm_diagonal = 0;
    printf("\nDigite 9 numeros de um quadrado magico: ");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int elem_valido = 0;
            while (!elem_valido) {
                if (scanf("%f", &q_magico[i][j]) == 1) {
                elem_valido = 1;
            } else {
                printf("Entrada invalida! Digite um numero para o quadrado [%d][%d]: .\n", i, j);
                while ((c = getchar()) != '\n' && c != EOF);
            }
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        soma_qm_diagonal+= q_magico[i][i];
    }
    printf("Soma da diagonal principal: %.2f.\n", soma_qm_diagonal);
    while ((c = getchar()) != '\n' && c != EOF);
    
    return 0;
}
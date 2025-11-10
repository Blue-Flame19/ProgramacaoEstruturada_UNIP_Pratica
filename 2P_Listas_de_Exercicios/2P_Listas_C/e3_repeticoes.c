#include <stdio.h>
#include <limits.h>

int main() {
    //Analisa 5 números, determinando se cada um é par ou ímpar (Usar um 'for' seria melhor)
    int contador_a = 0;
    while (contador_a < 5) {
        int n;
        printf("\nDigite um numero inteiro: ");
        if (scanf("%d", &n) != 1) {
        //Em caso de input errado, limpa o input buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        printf("Entrada invalida! Digite apenas numeros.\n");
        continue; //Não aumenta o contador - tenta novamente
        }
        //Certifica-se que não tem input extra após o número (evita números decimais)
        int prox_char = getchar();
        if (prox_char != '\n' && prox_char != EOF) {
            while ((prox_char = getchar()) != '\n' && prox_char != EOF); //Limpa o input buffer e informa o erro
            printf("Entrada invalida! Digite apenas numeros inteiros (sem decimais).\n");
            continue;
        }
        if (n % 2 == 0){
            printf("%d eh par!\n", n);
        } else {
            printf("%d eh impar!\n", n);
        }
        contador_a++;
    }

    //Mostra a tabuada de 1 a 10 de um dado número
    int numero, cont_tabuada;
    float aux;
    while (1) {
        printf("\nDigite um numero: ");
        if (scanf("%f", &aux) != 1) {
        int c;
        while ((c = getchar ()) != '\n' && c != EOF);
        printf("Entrada invalida! Digite apenas numeros.\n");
        continue;
        }
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        //Converte input para número inteiro
        if (aux != (int)aux) {
        printf("Aviso: Convertendo %.2f para %d (apenas a parte inteira)\n", aux, (int)aux);
        }
        numero = (int)aux;
        break;
    }
    printf("\nTabuada de %d:\n", numero);
    printf("===========================================================================\n");
    //Usa um loop 'for' para criar a tabuada
    for (cont_tabuada = 1; cont_tabuada<= 10; cont_tabuada++) {
        int soma = numero + cont_tabuada;
        int subtracao = numero - cont_tabuada;
        int multiplicacao = numero * cont_tabuada;
        float divisao = (float)numero / cont_tabuada; //Casting para 'float' - para divisões decimais
        //Mostra os resultados
        printf("%d + %d = %d\t", numero, cont_tabuada, soma);
        printf("%d - %d = %d\t", numero, cont_tabuada, subtracao);
        printf("%d * %d = %d\t", numero, cont_tabuada, multiplicacao);
        printf("%d / %d = %.2f\n", numero, cont_tabuada, divisao);
    }

    //Menu de escolhas dentro de um loop 'while'
    int opcao;
    int menu_escolha = 1;
    while (menu_escolha) {
        printf("\n=== Menu ===\n");
        printf("1 - Soma\t2 - Subtracao\t3 - Sair\n");
        printf("\nDigite sua escolha (1/2/3): \n");
    //Tenta ler um número
    while (scanf("%d", &opcao) != 1) {
        printf("\nEntrada invalida! Digite apenas numeros (1/2/3): ");
        int c;
        while ((c = getchar()) != '\n' && c != EOF); //Limpa input buffer
    }
        //Switch-Case trabalhando com a opção desejada
        switch (opcao) {
        case 1: {
            float n1, n2;
            printf("\nDigite dois numeros: ");
            scanf("%f %f", &n1, &n2);
            printf("Soma de %.2f + %.2f = %.2f\n", n1, n2, n1 + n2);
            break;
        }
        case 2: {
            float n1, n2;
            printf("\nDigite dois numeros: ");
            scanf("%f %f", &n1, &n2);
            printf("Subtracao de %.2f - %.2f = %.2f\n", n1, n2, n1 - n2);
            break;
        }
        case 3: {
            menu_escolha = 0; //Sai do loop
            printf("\nSaindo...\n");
            break;
        }
        default: {
            printf("\nOpcao invalida! Tente novamente.\n");
            break;
            }
        }
    }

    //O usuário digita 'n' números dentro de um loop, parando ao se inserir '0'
    float num, soma_positivos = 0;
    do {
        printf("\nDigite um numero (Digite '0' para terminar a operacao): ");
        if (scanf("%f", &num) != 1) {
            printf("Entrada invalida! Digite apenas numeros.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        //Condição de parada
        if (num == 0) {
            break;
        }
        //Soma somente os números positivos
        if (num > 0) {
            soma_positivos += num;
            printf("%.2f adicionado. Soma atual: %.2f\n", num, soma_positivos);
        } else {
            printf("Numero negativo - ignorado.\n");
        }
    } while (1); //Loop infinito - terminado com input do usuário
    printf("Soma final dos positivos: %.2f\n", soma_positivos);

    //O usuário digita 'n' números; retorna-se o maior entre eles
    int n_atual;
    int cont_n = 0;
    int max_n = INT_MIN, min_n = INT_MAX; //INT_MIN/INT_MAX é usado neste bloco para evitar overflow
    printf("\nDigite numeros inteiros (ou qualquer letra para interromper): ");
    while (scanf("%d", &n_atual) == 1) {
        //Comparação de números
        if (n_atual > max_n) max_n = n_atual;
        if (n_atual < min_n) min_n = n_atual;
        cont_n ++;
    }
    {
        int c; //Limpa o input buffer se scanf falhar
        while ((c = getchar()) != '\n' && c != EOF);
    }
    //Comparação entre o número inserido e o anterior
    if (cont_n > 0) {
        printf("Maior: %d, Menor: %d (entre %d numeros).\n", max_n, min_n, cont_n);
    } else {
        printf("Nenhum numero inserido!\n");
    }

    //Recebe a qtd. de alunos, a nota de cada aluno, depois calcula a média da turma
    int qtd_alunos = 0;
    float nota_aluno, total_notas = 0, media_turma = 0;
    while (1) {
    printf("\nDigite o total de alunos: ");
    scanf("%d", &qtd_alunos);
    if (qtd_alunos <= 0) {
        printf("Erro: A quantidade de alunos deve ser maior que zero.\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        } else {
        break; //Termina o loop quando o input é válido
        }
    }
    //qtd_alunos > 0
    for (int i = 0; i < qtd_alunos; i++) {
    printf("Digite a nota de um aluno: ");
    if (scanf("%f", &nota_aluno) != 1 || nota_aluno < 0 || nota_aluno > 10) {
        printf("Erro! Digite uma nota válida entre 0 e 10.\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF); //Limpa input buffer
        i--;
        continue;
        }
    total_notas += nota_aluno;
    }
    media_turma = total_notas / qtd_alunos;
    printf("A media da turma eh %.2f.\n", media_turma);

    //Analisa e informa se um dado número é ou não primo
    int x;
    printf("\nDigite um numero: ");
    if (scanf("%d", &x) != 1) {
        printf("Entrada invalida!\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        x = 0;
    } else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    if (x < 2) {
        printf("Nao eh primo!\n");
    } else if (x == 2) {
        printf("Eh primo!\n");
    } else {
        int eh_primo = 1;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                eh_primo = 0;
                break;
            }
        }
        if (eh_primo) {
            printf("Eh primo!\n");
        } else {
            printf("Nao eh primo!\n");
        }
    }

    //Faz a leitura de um caixa, mostrando: total da compra, qtd. de itens e média dos preços
    float preco, preco_total = 0;
    int qtd_itens, qtd_total_itens = 0;
    do {
        printf("\nDigite o preco ('0' para terminar): ");
        scanf("%f", &preco);
        //Condição de término do loop
        if (preco == 0) {
            break;
        }
        //Validação do preço
        if (preco < 0) {
            printf("Erro: Preco nao pode ser negativo.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF); // Limpa o input buffer
            continue;
        }
        printf("Digite a quantidade de itens: ");
        scanf("%d", &qtd_itens);
        //Validação da quantidade de itens
        if (qtd_itens <= 0) {
            printf("Erro - A quantidade de itens deve ser positiva.");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        //Agrupa todos os valores
        preco_total += preco * qtd_itens;
        qtd_total_itens += qtd_itens;
    } while (1); //Loop infinito até que o preço inserido seja '0'
    //Cálculo da média
    if (qtd_total_itens > 0) {
        float media_compra = preco_total / qtd_total_itens;
        printf("Preco medio: %.2f Reais.\n", media_compra);
    } else {
        printf("Nenhum item valido foi processado.\n");
    }

    return 0;
}
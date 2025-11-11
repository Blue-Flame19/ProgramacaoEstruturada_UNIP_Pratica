
#Classifica uma pessoa de acordo com a idade fornecida
def gruposIdade():
    try: #Esse bloco 'try-else' aponta erro caso seja inserido um valor não inteiro 
        idade = int(input("\nDigite sua idade: "))
    except ValueError:
        print("\nErro, número inválido.\n")
    else: #Esse else será executado somente se não houver erro, i.e. as condições anteriores forem falsas
        match idade: #Demonstração do 'match-case' - com valores discretos
            case _ if 0 <= idade <= 12:
                print("\nVocê é uma criança.\n")
            case _ if 13 <= idade <= 17:
                print("\nVocê é um(a) adolescente.\n")
            case _ if 18 <= idade <= 150:
                print("\nVocê é um adulto.\n")
            case _:
                print("\nDigite uma idade válida, por favor.\n") 
        
        return idade

#Atribui um conceito a uma dada Média Final (0 a 100)
def mediaFinal():
    try:
        media_final = float(input("\nDigite a média final: ")) #A variável é tipo 'float', então usa-se 'if-elif-else', e não 'match-case'
    except ValueError:
        print("\nErro, número inválido.\n")
    else:
        if (90 <= media_final <= 100): print("Nota A.\n") #Executa se for verdade
        elif (70 <= media_final < 90): print("Nota B.\n") #Se a condição anterior for falsa e essa, verdadeira
        elif (0 <= media_final < 70): print("Nota C.\n") #Se as duas condições anteriores forem falsas e essa, verdadeira
        else:
            print("Digite uma nota entre 0 e 100, por favor.\n") #Executa se todas as outras forem falsas
        
        return media_final
    
#Calcula e exibe a soma dos inteiros de 1 a 5, usando 'while'
def somaConjunto_5():
    soma, i = 0, 1 #'soma' e 'i': 'int'
    while (i <= 5): #É usado '<=', NÃO '<', para incluir o 5 na soma
        soma += i
        i += 1

    print(f"A soma dos inteiros de 1 a 5 é {soma}.\n")
    return soma

#Exibe somente os números pares de 2 a 10, usando 'for' e 'range'
def conjuntoPares_2_10():
    i = 0
    for i in range(2, 11, 2): #'range(2, "11", 2)' faz com que '10' seja incluído
        print(f' {i}', end = '') #Remove a quebra de linha
        i += 1

#Percorre um conjunto de 1 a 10, parando quando '7' é encontrado e mostrando uma mensagem
def nMagico_7():
    for i in range(1, 11):
        if i == 7:
            break #Para a iteração quando chega no '7'
    
    print(f"\n\nEncontrei o número mágico! {i}.\n")

#Demonstração do comando 'continue' para manipular loops
def pular_3():
    for i in range(1, 6): #Conjunto de 1 a 5
        if i == 3:    #'continue' para a execução e move para o próximo passo;
            continue  # nesse caso, o 'próximo passo' é a próxima iteração de 'i'
        print(f' {i}', end = '') #1: imprime, 2: imprime, 3:pula, 4: imprime, 5: imprime

#Conta, e exibe, a qtd. de números pares e ímpares entre 1 e 15
def contagemParImpar_1_15():
    q_pares, q_impares = 0, 0 #Inicializa os contadores
    for i in range (1, 16):
        if (i % 2 == 0): #Verificação de paridade
            q_pares += 1 
        else:
            q_impares += 1
    
    print(f'\n\n Esse conjunto tem {q_pares} números pares, e {q_impares} números ímpares.')
    return q_pares, q_impares

if __name__ == '__main__':
    gruposIdade()
    mediaFinal()
    somaConjunto_5()
    conjuntoPares_2_10()
    nMagico_7()
    pular_3()
    contagemParImpar_1_15()
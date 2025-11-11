
#Validação de input para números inteiros
def int_valido(numero):
    while True:
        try:
            return int(input(numero))
        except ValueError:
            print("Digite um número inteiro válido!")

#Validação de input para números reais
def float_valido(numero):
    while True:
        try:
            return float(input(numero))
        except ValueError:
            print("Digite um número válido!")

#Calcula o dobro de 'x' e 'y', soma os dois resultados, exibe o resultado
def somar_dobro(x, y):
    dobro_x, dobro_y = x * 2, y * 2
    dobros_soma = dobro_x + dobro_y
    return dobros_soma

#Verifica se alguém é maior de idade, de acordo com a idade fornecida
def verificar_idade(idade):
    if (idade >= 18): print(f'Maior de idade.\n')
    elif (idade >= 0): print(f'Menor de idade.\n')
    else:
        print("Idade deve ser um número inteiro positivo!\n")

#Calcula e retorna o valor do imposto a ser pago
def calcular_imposto(salario, aliquota = 0.10):
    imposto = salario * aliquota
    return imposto

#Formata a exibição do imposto obtido (com input do usuário)
def mostrar_imposto():
    salario = float_valido("Digite o salário: ")
    usar_aliquota_padrao = input("Usar alíquota padrão de 10%? (s/n): ").lower()
    
    if usar_aliquota_padrao == 's': #Aqui, o usuário pode escolher entre usar, ou não, a alíquota padrão de 10% 
        imposto = calcular_imposto(salario)
    else:
        aliquota_usuario = float_valido("Digite a alíquota (ex: 0.15 para 15%): ") #Substitui 'aliquota' original
        imposto = calcular_imposto(salario, aliquota_usuario)
    
    print(f"Imposto devido: R$ {imposto:.2f}\n")
    return imposto

#Retorna 'True' se for par, 'False' se for ímpar 
def eh_par(numero):
    if (numero % 2 == 0): return True
    else:
        return False
    
#Soma somente os números pares
def somar_apenas_pares(n1, n2, n3):
    soma_total_pares = 0
    if (eh_par(n1)): soma_total_pares += n1
    if (eh_par(n2)): soma_total_pares += n2
    if (eh_par(n3)): soma_total_pares += n3
    
    print(f'Soma de todos os pares:')
    return soma_total_pares

#Mostra o tamamho total de uma string, e seu primeiro caractere 
def analisar_string(palavra):
    print(f'"{palavra}" possui {len(palavra)} caracteres.') #'len' percorre a string e retorna a qtd. de caracteres
    print(f'Primeiro caractere: {palavra[0]}\n') #Sintaxe para mostrar o índice '0' da string

#Outro exemplo de manipulação de strings
def string_slicing():
    palavra = "Programação Estruturada"
    print(palavra[12:23:1]) #Corta a primeira palavra usando slicing
    print(palavra[::-1]) #String invertida

#Faz a formatação do input de login do usuário
def formatar_login(entrada_usuario):
    if not entrada_usuario: #Pede um input não-vazio para continuar, retorna 'None' se a entrada estiver vazia
        return None
    
    entrada_usuario_formatada = entrada_usuario.strip() #Remove espaços em branco ao final da string
    return entrada_usuario_formatada.lower() #Retorna a string original, formatada com letras minúsculas

#Formata um cabeçalho a partir de um título inserido, sem uso de f-string
def formatar_cabecalho(titulo):
    print("="*20)
    print("["+ titulo.upper() +"]") #'.upper()' converte a string para maiúsculas
    print("="*20)

if __name__ == '__main__':
    print(f'Resultado: {somar_dobro(int_valido("Digite o primeiro número: "), (int_valido("Digite o segundo número: ")))}\n') #Eu S2 f-strings
    verificar_idade(int_valido("Digite sua idade: ")) #Nunca chamar print dentro de outro print
    mostrar_imposto() #Aninhamento de funções
    print(f'{somar_apenas_pares(int_valido("Digite 'n1': "), int_valido("Digite 'n2': "), int_valido("Digite 'n3': "))}\n') #...
    analisar_string(input("Digite uma palavra: "))
    string_slicing() 
    print(f'{formatar_login(input("Digite seu nome: "))}\n') 
    formatar_cabecalho(input("Digite um título:"))
    
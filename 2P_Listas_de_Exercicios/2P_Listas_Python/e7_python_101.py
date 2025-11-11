    
#Exemplos de tipagem e casting em Python
def exemplos():
    a = "5" #string 
    b = 3 #int
    resultado = int(a) + float(b) #agora 'a' é 'int', e 'b' é 'float', permitindo a soma dos dois
    print(resultado)

#Usagem de f-strings
def fStrings_exemplo():
    nome = "João"
    saldo = 1500.758
    print(f"O saldo de {nome} é R${saldo:.2f}") #A formatação ':.2f' mostra apenas 2 casas após a vírgula
    
#O código abaixo está tecnicamente errado, pois não retorna uma soma,
#e sim uma concatenação de strings
def somarNumeros():    
    num1 = input("\nDigite o primeiro número: ")
    num2 = input("\nDigite o segundo número: ")
    soma = num1 + num2
    print(soma)

#Pode-se converter uma variável múltiplas vezes
def varCasting():
    a = "3.5" #string
    b = 2 #int
    w = int(float(a)) + b + 0.5 #"3.5" (string) é convertido para 'float' (3.5), depois para 'int' (3) - NÃO é arredondamento
    print(w) #(3 + 2 + 0.5 = 5.5) Somente 'a' recebeu casting para 'int'; como é somado com dois 'float', 'w' é float (precedência)

#Python reconhece a variável 'check' abaixo como booleana (retorna 'True' ou 'False')
def expressaoNumerica():
    a, b, c = 10, 5, 15
    check = (a > b and c < b) or not (c ==15) #'15' NÃO é menor que '5', então a expressão é 'False'
    return check

#Cálculo de média ponderada
def mediaPonderada():
    nota1, peso1 = float(input("\nDigite a primeira nota: \n")), int(input("Digite o peso dessa nota 1: \n"))
    nota2, peso2 = float(input("Digite a segunda nota: \n")), int(input("Digite o peso dessa nota 2: \n"))
    media_pond = ((nota1 * peso1) + (nota2 * peso2)) / (peso1 + peso2)
    print(f"A média ponderada é: {media_pond:.2f}.\n")
    return media_pond #Essa função retorna valor

#Converte minutos para horas/minutos
def coversaoMinutosHoras():
    minutos_totais = int(input("Digite o total de minutos: "))
    horas = minutos_totais // 60
    minutos = minutos_totais % 60
    print(f'{horas} hora(s) e {minutos} minuto(s).\n')
    return horas #Essa também retorna valor

#Calcula o troco que deve ser pago a um cliente
def valorTroco():
    preco_compra, valor_pago = float(input("Preço total: ")), float(input("Quantia paga: ")) 
    troco = valor_pago - preco_compra
    print(f'O valor do troco é R$ {troco:.2f}.\n')

#Calcula o IMC de uma pessoa
def calculoIMC():
    nome = str(input("Por favor, digite seu nome: "))
    peso, altura = float(input("Digite seu peso: ")), float(input("Digite sua altura: "))
    imc = peso / (altura*altura)
    print(f"{nome}\nIMC: {imc:.2f}.")

if __name__ == '__main__':
    exemplos()
    fStrings_exemplo()
    somarNumeros()
    varCasting()
    print(expressaoNumerica()) #Nunca chamar prints dentro de prints 
    mediaPonderada()
    coversaoMinutosHoras()
    valorTroco()
    calculoIMC() 
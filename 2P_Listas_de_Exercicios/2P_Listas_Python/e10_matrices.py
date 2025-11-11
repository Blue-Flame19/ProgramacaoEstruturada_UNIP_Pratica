import numpy as np 

#Booleana simples de paridade
def eh_impar(n):
    return n % 2 != 0

#Cria 'Matriz A' usando 'numpy.sum' e 'enumerate' 
def soma_matriz_linha(matriz):
   soma_linhas = np.sum(matriz, axis=1)
   for i, soma in enumerate(soma_linhas):
        print(f"Soma da linha {i+1}: {soma}")

#A função cria uma matriz com 'n' linhas usando 'for' loops e '.append()'
def criar_matriz_a(*linhas):
    matriz = []
    for linha in linhas:
        linha_matriz = []
        for indice in linha:
            linha_matriz.append(indice)
        matriz.append(linha_matriz)
    return matriz

#Função para imprimir a matriz com espaçamento  
def format_matriz(matriz):
     for linha in matriz:
        for indice in linha:
            print(f'{indice:>4}', end=' ')
        print()

#Essa função obtém a diagonal principal da matriz      
def diagonal_matriz(matriz):
    if not matriz or not isinstance(matriz, list):
        raise ValueError("Matriz deve ser uma lista não vazia.\n")
    n = len(matriz)
    if n != len(matriz[0]):
        raise ValueError("Matriz deve ser NxN.\n")
    return [matriz[i][i] for i in range(n)] 

#Obtém a diagonal secundária - tanto essa quanto a função acima assumem que a matriz terá o mesmo nº de linhas/colunas
def diagonal_secundaria(matriz):
    if not matriz or not isinstance(matriz, list):
        raise ValueError("Matriz deve ser uma lista não vazia.\n")
    n = len(matriz)
    if n != len(matriz[0]):
        raise ValueError("Matriz deve ser 'NxN.\n")
    return [matriz[i][n-1-i] for i in range(n)]

#Usa 'for' loops para criar uma matriz - a própria função pede o input de linhas/colunas
def criar_matriz(linhas, colunas):
    matriz = []
    print(f"Digite os números da matriz {linhas}x{colunas}, linha por linha:")
    for i in range(linhas):
        linha = [] 
        for j in range(colunas):
            while True:
                try: #Somente aceita valores inteiros
                    valor = int(input(f"Digite o número na posição ({i+1},{j+1}): "))
                    linha.append(valor)
                    break
                except ValueError:
                    print("Número Inválido.")
        matriz.append(linha)
    return matriz

#Multiplica os elementos da diagonal principal de uma dada matriz
def mult_diagonal_principal(matriz):
    indices_diagonal = diagonal_matriz(matriz)
    impares_diagonal = [num for num in indices_diagonal if eh_impar(num)]

    if not impares_diagonal:
        return 1
    produto = 1
    for num in impares_diagonal:
        produto *= num
    return produto

#Soma todos os elementos pares de uma matriz; chama a função booleana 'eh_impar', para comparação 
def soma_matriz_pares(matriz):
    return sum(item for linha in matriz for item in linha if not eh_impar(item))

#Subtrai todos os elementos ímpares de uma matriz; chama a função booleana 'eh_impar', para comparação
def subtrair_matriz_impares(matriz):
    return [[item - 5 if eh_impar(item) else item for item in linha] for linha in matriz]

#Multiplica todos os elementos de uma matriz por um valor escalar (por padrão, 3)
def multiplicar_matriz(matriz, scalar=3):
    return [[item * scalar for item in linha] for linha in matriz]

#Soma os elementos das duas diagonais de uma matriz; depois, divide a principal pela secundária
def divisao_matriz_diagonais(matriz):
    soma_diagonal_p = sum(diagonal_matriz(matriz))
    soma_diagonal_s = sum(diagonal_secundaria(matriz))
    return soma_diagonal_p / soma_diagonal_s if soma_diagonal_s != 0 else float('inf') #Somente divide valores inteiros

if __name__ == '__main__':
    
    #Essa lista foca mais em criação e formatação de matrizes
    print(f"=== Manipulação de matrizes ===\n")
    print(f"\n=== Matriz M ===")
    matriz_m =  np.array([[10, 5, 2], [8, 12, 4], [1, 3, 7]]) #Cria 'Matriz M' usando 'np.array'
    
    matriz_a = criar_matriz_a([10,2,5], [1,15,3], [4,6,20])
    diagonal_a = diagonal_matriz(matriz_a)
    
    print(f"\n{matriz_m}\n")
    soma_matriz_linha(matriz_m)
    
    print("\n=== Matriz A ===\n")
    format_matriz(matriz_a)
    print(f"\nValor [2][1]: {matriz_a[2][1]}\n")
    print(f"Diagonal principal de A: {diagonal_a}\n")
    
    print("\n" + "="*30)
    
    matriz_4x4 = criar_matriz(4,4)
    print("\n=== Matriz 4x4 ===\n")
    format_matriz(matriz_4x4)
    print(f"\nDiagonal principal de 4x4: {diagonal_matriz(matriz_4x4)}")
    print(f"Multiplicação dos ímpares nessa diagonal: {mult_diagonal_principal(matriz_4x4)}\n")

    matriz_3x3 = criar_matriz(3,3)
    print("\n=== Matriz 3x3 ===\n")
    format_matriz(matriz_3x3)
    
    print(f"\n=== Operações ===\n")
    print(f"Soma dos pares: {soma_matriz_pares(matriz_3x3)}.")
    print(f"Subtração dos ímpares por 5: {subtrair_matriz_impares(matriz_3x3)}.")
    print(f"Multiplicação de todos os elementos por 3: {multiplicar_matriz(matriz_3x3, scalar=3)}.")
    print(f"Divisão da diagonal primária pela secundária: {divisao_matriz_diagonais(matriz_3x3)}\n.")
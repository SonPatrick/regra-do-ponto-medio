#Aqui é declarado a função a ser resolvida
def func (x):
    from math import exp, pow
    #f = 1/x
    f = float((pow(x,2))*exp(-x))
    return f
#Aqui é onde acontece tudo, "a" e "b" são os intervalos definidos e "n" é o número de divisões
def integral(a, b, n):
    #Calculo do delta x
    dx = (b-a)/n
    #Declaração da lista que irá receber os valores dos pontos médios
    lista = []
    #"pm1" é o primeiro ponto médio encontrado... ele é tratado agora para não dar dor de cabeça depois
    pm1 = (dx / 2) + a
    #"pm1" é inserido na lista
    lista.append(pm1)
    #"soma" será a variável responsável pelo somatório de todos os pontos médios na f(x)
    #"func(pm1)" indica que o valor recebido por "soma" já é o resultado do calculo do "pm1" na função
    soma = func(pm1)
    #Aqui "i" é incializado em 1 
    for i in range(1, n):
        #Aqui é adicionado na lista os pontos médios
        #Ponto anterior mais o valor de dx
        lista.append(lista[i-1]+dx)
        #Aqui é adicionado na soma os valores dos pontos seguintes aplicados na função definida
        soma +=func(lista[i])
    #"result" recebe a multiplicação de delta x com a soma de todos os pontos médios já aplicados na função
    result = dx*soma
    #Enfeites de impressão
    #print("lista =", lista)
    #print("soma =", soma)
    print("resultado =", result)
integral(0, 1000, 100000)
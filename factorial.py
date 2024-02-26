#Programa para calcular el factorial de un numero

def factorio(num):
    if num == 0 or num == 1:
        return 1
    return num * factorio(num-1)

numero = int(input())
resultado = factorio(numero)
print("el factorial de ", numero," es: ", resultado)
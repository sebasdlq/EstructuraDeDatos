#Programa en python para elevar un numero a un exponente entero

def potencia(base, exponente):
    if(exponente == 0):
        return 1
    
    if(exponente > 0):
        return base * potencia(base, exponente - 1)
    else:
        return (1/base)*potencia(base, exponente + 1)
    
    
base = float(input("base: "))
exponente = int(input("exponente: "))

print("el resultado es: ", potencia(base, exponente))
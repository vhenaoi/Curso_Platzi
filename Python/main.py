'''
Recibe una oración como string.
Indica la posición de la letra con la cual empieza nuestro subtexto (la parte que vamos a “recortar”).
Indicar la posición de la letra con la cual termina nuestro subtexto.
Imprime el subtexto.
'''

# Mi codigo
oracion = input('Escriba una oración: ')
posicion1 = int(input('Escriba la posición para inciar el recorte: '))
posicion2 = int(input('Escriba la posición para finalizar: '))
resultado = oracion[:posicion1] + oracion[posicion2:]

print(resultado)

#El codigo de la profe
frase = 'las flores amarillas'
inicial = 4
final = 10
palabra = frase[inicial:final]

print(palabra)

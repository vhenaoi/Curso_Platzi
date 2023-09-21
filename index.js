//El reto de esta clase es que encuentres el número más grande de una lista usando JavaScript.
//El algoritmos/ diagrama de flujo es el siguiente:
//Recibe un array de números (de cualquier cantidad).
//Crea una variable “máxima” que inicie en 0.
//Recorre el array valor por valor.
//Pregunta si el valor de la variable máxima es mayor que el valor del número en la posición actual del array.
//Si la condición anterior es verdadera, asigna el valor de la posición actual del array a la variable máxima.
//Imprime el número más grande del array.
  
// Definición de variables
let numeros = [5, 10, 15, 60, 8] //variable local
let numeroMaximo = 0 //variable local
let tamano = numeros.length // longitud de la variable


// Ciclo
for(let i=0; i<tamano; i++) {
  if(numeroMaximo < numeros[i]){
    numeroMaximo = numeros[i]
  }
}

//Mostrar en pantalla
console.log(numeroMaximo)

//Uso de funciones de la libreria Math que encuentra el maximo en una lista
let maximo = Math.max(5, 10, 15, 60, 8)

//Mostrar en pantalla
console.log(maximo)



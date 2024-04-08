#ifndef INFO2_H
#define INFO2_H

const int MAX_NUMEROS = 100;

// Función para ingresar los números desde el usuario
int ingresarNumeros(int numeros[]);

// Función para obtener el mayor número entre los dos primeros
int obtenerMayor(int numeros[], int numElementos);

// Función para determinar el tamaño de las matrices
int determinarTamanoMatriz(int mayor);

// Función para crear una matriz con números desde 1 hasta el tamaño y 0 en el centro
void crearMatriz(int matriz[][MAX_NUMEROS], int tamano, int filaInicial, int columnaInicial);

// Función para imprimir una matriz
void imprimirMatriz(int matriz[][MAX_NUMEROS], int tamano);

// Función para girar la matriz en sentido horario según el ángulo dado (en grados)
void girarMatriz(int matriz[][MAX_NUMEROS], int tamano, int grados);

// Función para rotar una matriz 90° en sentido horario
void rotarMatriz90(int matriz[][MAX_NUMEROS], int tamano);

#endif // INFO2_H

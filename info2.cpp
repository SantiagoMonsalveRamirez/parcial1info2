#include "info2.h"
#include <iostream>

using namespace std;

// Función para ingresar los números desde el usuario
int ingresarNumeros(int numeros[]) {
    int numElementos = 0;
    cout << "Ingrese los números (ingrese un punto '.' para finalizar): ";
    while (numElementos < MAX_NUMEROS) {
        if (!(cin >> numeros[numElementos])) {
            cin.clear(); // Limpiar el estado de cin en caso de error
            char c;
            cin >> c; // Leer el carácter incorrecto
            if (c == '.') {
                break; // Salir del bucle si se ingresa un punto
            }
        } else {
            if (numElementos >= 2 && (numeros[numElementos] != 1 && numeros[numElementos] != 0 && numeros[numElementos] != -1)) {
                cout << "Error: Los valores después del segundo parámetro solo pueden ser 1, 0 o -1." << endl;
                return -1; // Finalizar el programa con código de error
            }
            numElementos++;
        }
    }
    return numElementos;
}

// Función para obtener el mayor número entre los dos primeros
int obtenerMayor(int numeros[], int numElementos) {
    return numeros[0] > numeros[1] ? numeros[0] : numeros[1];
}

// Función para determinar el tamaño de las matrices
int determinarTamanoMatriz(int mayor) {
    return (mayor % 2 == 0) ? mayor + 1 : mayor;
}

// Función para crear una matriz con números desde 1 hasta el tamaño y 0 en el centro
void crearMatriz(int**& matriz, int tamano) {
    matriz = new int*[tamano];
    for (int i = 0; i < tamano; ++i) {
        matriz[i] = new int[tamano];
        for (int j = 0; j < tamano; ++j) {
            if (i == tamano / 2 && j == tamano / 2) {
                matriz[i][j] = 0;
            } else {
                matriz[i][j] = (i * tamano) + j + 1;
            }
        }
    }
}

// Función para liberar la memoria ocupada por la matriz
void liberarMatriz(int**& matriz, int tamano) {
    for (int i = 0; i < tamano; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;
    matriz = nullptr;
}

// Función para imprimir una matriz
void imprimirMatriz(int** matriz, int tamano) {
    for (int i = 0; i < tamano; ++i) {
        for (int j = 0; j < tamano; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

// Función para girar la matriz en sentido horario según el ángulo dado (en grados)
void girarMatriz(int**& matriz, int tamano, int grados) {
    int** temp = new int*[tamano];
    for (int i = 0; i < tamano; ++i) {
        temp[i] = new int[tamano];
    }

    int vueltas = grados / 90;

    // Copiar la matriz original en una temporal
    for (int i = 0; i < tamano; ++i) {
        for (int j = 0; j < tamano; ++j) {
            temp[i][j] = matriz[i][j];
        }
    }

    // Girar la matriz original según el ángulo dado
    for (int k = 0; k < vueltas; ++k) {
        for (int i = 0; i < tamano; ++i) {
            for (int j = 0; j < tamano; ++j) {
                matriz[j][tamano - 1 - i] = temp[i][j];
            }
        }
        // Actualizar la matriz temporal para la próxima iteración
        for (int i = 0; i < tamano; ++i) {
            for (int j = 0; j < tamano; ++j) {
                temp[i][j] = matriz[i][j];
            }
        }
    }

    // Liberar la memoria de la matriz temporal
    for (int i = 0; i < tamano; ++i) {
        delete[] temp[i];
    }
    delete[] temp;
}




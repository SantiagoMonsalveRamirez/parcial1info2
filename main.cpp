#include <iostream>
#include <cstdlib>
#include <ctime>
#include "info2.h"

using namespace std;

int main() {
    int numeros[MAX_NUMEROS];
    int numElementos = ingresarNumeros(numeros);

    if (numElementos >= 3) {
        int fila = numeros[0];
        int columna = numeros[1];

        int mayor = obtenerMayor(numeros, numElementos);
        int tamanoMatriz = determinarTamanoMatriz(mayor);
        int cantidadMatrices = numElementos - 2;

        srand(time(0));

        // Crear las matrices
        int*** matrices = new int**[cantidadMatrices];

        // Crear y mostrar la primera matriz sin rotar
        cout << "Matriz 1 (original):" << endl;
        crearMatriz(matrices[0], tamanoMatriz);
        imprimirMatriz(matrices[0], tamanoMatriz);
        cout << "Valor en la posición indicada por el usuario: " << matrices[0][fila][columna] << endl;
        cout << endl;

        // Crear y mostrar las matrices restantes con tamaños, rotaciones y posiciones diferentes
        int tamanoInicial = tamanoMatriz;
        int angulo = 90;
        for (int i = 1; i < cantidadMatrices; ++i) {
            // Ajustar el tamaño para que sea mayor o igual al de la primera matriz y sea impar
            tamanoMatriz = tamanoInicial + (i * 2);
            if (tamanoMatriz % 2 == 0) {
                tamanoMatriz += 1;
            }

            cout << "Matriz " << i + 1 << " (rotada " << angulo << "°, tamaño " << tamanoMatriz << "x" << tamanoMatriz << "):" << endl;
            crearMatriz(matrices[i], tamanoMatriz);
            girarMatriz(matrices[i], tamanoMatriz, angulo);
            imprimirMatriz(matrices[i], tamanoMatriz);
            cout << "Valor en la posición indicada por el usuario: " << matrices[i][fila - i][columna - i] << endl;
            cout << endl;
            angulo += 90;
        }

        // Verificar las comparaciones
        int intentos = 0;
        bool todasLasCondicionesCumplidas = false;
        while (!todasLasCondicionesCumplidas) {
            todasLasCondicionesCumplidas = true;
            for (int i = 0; i < cantidadMatrices - 1; ++i) {
                int verificacion = numeros[2 + i];
                int siguienteVerificacion = numeros[2 + (i + 1) % cantidadMatrices];

                int valorActual = matrices[i][fila - i][columna - i];
                int valorSiguiente = matrices[(i + 1) % cantidadMatrices][fila - (i + 1)][columna - (i + 1)];

                bool resultado;
                if (verificacion == 1) {
                    resultado = (valorActual > valorSiguiente);
                } else if (verificacion == -1) {
                    resultado = (valorActual < valorSiguiente);
                } else {
                    resultado = (valorActual == valorSiguiente);
                }

                if (!resultado) {
                    todasLasCondicionesCumplidas = false;
                    break;
                }
            }

            if (!todasLasCondicionesCumplidas) {
                // Rotar las matrices
                int matrizARotar = rand() % cantidadMatrices;
                int tamanoActual = tamanoInicial + (matrizARotar * 2);
                if (tamanoActual % 2 == 0) {
                    tamanoActual += 1;
                }
                girarMatriz(matrices[matrizARotar], tamanoActual, 90);
                ++intentos;
            }
        }

        // Imprimir el resultado final
        if (intentos > 0) {
            cout << "Se cumplieron todas las condiciones después de " << intentos << " rotaciones." << endl;
        } else {
            cout << "Las condiciones ya se cumplen con las matrices originales." << endl;
        }

        // Liberar la memoria ocupada por las matrices
        for (int i = 0; i < cantidadMatrices; ++i) {
            liberarMatriz(matrices[i], tamanoInicial + (i * 2));
        }
        delete[] matrices;
    } else {
        cout << "Debe ingresar al menos dos números y una verificación después del segundo número." << endl;
    }

    return 0;
}
















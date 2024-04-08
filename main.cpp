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
        int matrices[cantidadMatrices][MAX_NUMEROS][MAX_NUMEROS];

        // Crear y mostrar la primera matriz sin rotar
        cout << "Matriz 1 (original):" << endl;
        crearMatriz(matrices[0], tamanoMatriz, 0, 0);
        imprimirMatriz(matrices[0], tamanoMatriz);
        cout << "Valor en la posición indicada por el usuario: " << matrices[0][fila][columna] << endl;
        cout << endl;

        // Crear y mostrar las matrices restantes con tamaños, rotaciones y posiciones diferentes
        int tamanoInicial = tamanoMatriz;
        int angulo = 90;
        for (int i = 1; i < cantidadMatrices; ++i) {
            // Ajustar el tamaño para que sea mayor o igual al de la primera matriz y sea impar
            tamanoMatriz = tamanoInicial + (i * 2); // Aumentar el tamaño por cada matriz
            if (tamanoMatriz % 2 == 0) {
                tamanoMatriz += 1; // Asegurar que el tamaño sea impar
            }

            cout << "Matriz " << i + 1 << " (rotada " << angulo << "°, tamaño " << tamanoMatriz << "x" << tamanoMatriz << "):" << endl;
            crearMatriz(matrices[i], tamanoMatriz, i, i);
            girarMatriz(matrices[i], tamanoMatriz, angulo);
            imprimirMatriz(matrices[i], tamanoMatriz);

            // Ajustar las coordenadas de la posición indicada por el usuario para la matriz actual
            int filaAjustada = fila - i * 2;
            int columnaAjustada = columna - i * 2;

            cout << "Valor en la posición indicada por el usuario: " << matrices[i][filaAjustada][columnaAjustada] << endl;
            cout << endl;
            angulo += 90; // Incrementar el ángulo para la próxima matriz
        }

        // Verificar las comparaciones
        int intentos = 0;
        bool todasLasCondicionesCumplidas = false;
        while (!todasLasCondicionesCumplidas) {
            todasLasCondicionesCumplidas = true;
            for (int i = 0; i < cantidadMatrices - 1; ++i) {
                int verificacion = numeros[2 + i];
                int siguienteVerificacion = numeros[2 + (i + 1) % cantidadMatrices];

                int valorActual = matrices[i][fila - i * 2][columna - i * 2];
                int valorSiguiente = matrices[(i + 1) % cantidadMatrices][fila - (i + 1) * 2][columna - (i + 1) * 2];

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
                girarMatriz(matrices[matrizARotar], tamanoInicial + (matrizARotar * 2), 90); // Rotar 90° en cada intento
                ++intentos;
            }
        }

        // Imprimir el resultado final
        if (intentos > 0) {
            cout << "Se cumplieron todas las condiciones después de " << intentos << " rotaciones." << endl;
        } else {
            cout << "Las condiciones ya se cumplen con las matrices originales." << endl;
        }
    } else {
        cout << "Debe ingresar al menos dos números y una verificación después del segundo número." << endl;
    }

    return 0;
}















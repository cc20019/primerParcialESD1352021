
#include <stdio.h>
#include <stdlib.h>
#include "funcionesParcial.h"

int main() {

    int columna, fila;
    char nombreArchivoEnt[] = "peliculasFavoritasESD135_2021.csv";
    int numeroAlumnos = contarAlumnos(nombreArchivoEnt);
    char matrizTodo[numeroAlumnos][20], matrizCarnets[numeroAlumnos][7], matrizPelicula[6][15], *matrizFinal[59][7], matrizJunto[59][14], *matrizCarnetsSegunda[59][1];
    int matrizNumeros[numeroAlumnos][6], matrizTranspuestaNumeros[6][numeroAlumnos], matrizResultadoMultiplicado[59][59];
    matrizTodosLosDatos(nombreArchivoEnt, matrizTodo);
    extrarCarnets(matrizTodo, matrizCarnets);
    extraerMatrizNumeros(matrizTodo, matrizNumeros);
    crearCSVCarnets();
    crearMatrizTranspuestaNumero(numeroAlumnos, matrizNumeros, matrizTranspuestaNumeros);
    multiplicarMatrices(matrizNumeros, matrizTranspuestaNumeros, matrizResultadoMultiplicado);

    for (fila = 0; fila < 59; fila++) {
        for (columna = 0; columna < 19; columna++) {
            printf("[%c] ", matrizTodo[fila][columna]);
        }
        printf("\n");
    }

    for (fila = 0; fila < 59; fila++) {
        for (columna = 0; columna < 7; columna++) {
            printf("[%c]", matrizCarnets[fila][columna]);
        }
        printf("\n");
    }

    printf("\n");

    for (fila = 0; fila < 59; fila++) {
        for (columna = 0; columna < 6; columna++) {
            printf("%c", matrizNumeros[fila][columna]);
        }
        printf("\n");
    }

    printf("\n");

    for (fila = 0; fila < 6; fila++) {
        for (columna = 0; columna < numeroAlumnos; columna++) {
            printf("%c", matrizTranspuestaNumeros[fila][columna]);
        }
        printf("\n");
    }
    return 0;
}


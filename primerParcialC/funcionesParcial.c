/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funcionesParcial.h"

int contarAlumnos(char *nombreArchivo) {
    FILE *pa = fopen(nombreArchivo, "r");
    if (pa == NULL) {
        printf("Problema al abri el archivo %s. Termino el programa.\n", nombreArchivo);
        exit(-1);
    }
    //n = cantidad de alumnos
    int n = 0;
    char c = fgetc(pa);
    while (!feof(pa)) {
        if (c == '\n')n++;
        c = fgetc(pa);
    }
    fclose(pa);
    return n - 1;
}

void matrizTodosLosDatos(char *nombreArchivo, char matriz[][20]) {
    int contador = 0, columna, fila;
    FILE *pa = fopen(nombreArchivo, "r");
    if (pa == NULL) {
        printf("Problema al abri el archivo %s. Termino el programa.\n", nombreArchivo);
        exit(-1);
    }
    char temp;
    for (columna = 0; columna < 19; columna++) {
        contador = 0;
        for (fila = 0; fila < 60; fila++) {
            char line[100];
            char temp;
            fgets(line, sizeof (line), pa);
            if (contador == 0) {
                contador = 1;
                char line[100];
            } else {
                while (line != NULL) {
                    temp = line[columna];
                    matriz[fila - 1][columna] = temp;
                    break;
                }
            }
        }
        rewind(pa);
    }
}

void extrarCarnets(char matriz[][20], char matrizNueva[][7]) {
    int fila, columna;
    for (fila = 0; fila < 59; fila++) {
        for (columna = 0; columna < 7; columna++) {
            matrizNueva[fila][columna] = matriz[fila][columna];
        }
    }
}

void extraerMatrizNumeros(char matriz[][20], int matrizNumeros[][6]) {
    int fila, columna, columna2, numero = 0;
    for (fila = 0; fila < 59; fila++) {
        for (columna = 0, columna2 = 8; columna < 6; columna++, columna2 += 2) {
            matrizNumeros[fila][columna] = (int) matriz[fila][columna2];
        }
    }
}

void crearMatrizTranspuestaNumero(int numeroAlumnos, int matrizNumero[][6], int matrizTranspuestaNumero[][numeroAlumnos]) {
    int fila, columna;
    for (fila = 0; fila < numeroAlumnos; fila++) {
        for (columna = 0; columna < 6; columna++) {
            matrizTranspuestaNumero[columna][fila] = matrizNumero[fila][columna];
        }
    }
}

void multiplicarMatrices(int primeraMatriz[][6], int segundaMatriz[][59], int matrizResultado[][59]) {
    int i, j, k;

    for (i = 0; i < 59; i++) {
        for (j = 0; j < 59; j++) {
            matrizResultado[i][j] = 0;
            for (k = 0; k < 6; k++) {
                matrizResultado[i][j] += primeraMatriz[i][k] * segundaMatriz[k][j];
            }
        }
    }
}

void crearCSVCarnets() {
    char *carnetUno = "CC20019";
    char *carnetDos = "VC20009";

    FILE *sal = fopen("carnets de los Integrantes.csv", "w");
    if (sal == NULL) {
        printf("erro no se pudo crear el archivo");
        exit(-1);

    }
    fprintf(sal, "%s,%s", carnetUno, carnetDos);
}
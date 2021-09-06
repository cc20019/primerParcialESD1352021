#ifndef FUNCIONESPARCIAL_H
#define FUNCIONESPARCIAL_H

int contarAlumnos(char *nombreArchivo);
void matrizTodosLosDatos(char *nombreArchivo, char matriz[][20]);
void extrarCarnets(char matriz[][20], char matrizNueva[][7]);
void extraerMatrizNumeros(char matriz[][20], int matrizNumeros[][6]);
void crearMatrizTranspuestaNumero(int numeroAlumnos, int matrizNumero[][6], int matrizTranspuestaNumero[][numeroAlumnos]);
void multiplicarMatrices(int primeraMatriz[][6], int segundaMatriz[][59], int matrizResultado[][59]);
void crearCSVCarnets();
#endif /* FUNCIONESPARCIAL_H */


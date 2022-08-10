#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** leLinhas(char** linhasRecebidas, char* file, int* tam);

void swap(char** linhasAlocadas, int i, int j);
int particionar(char** linhasAlocadas, int a, int b);
void quickSort(char** linhasAlocadas, int a, int b);
void liberar(char** linhasAlocadas, int tam);
void imprimir(char** linhasAlocadas, int tam);
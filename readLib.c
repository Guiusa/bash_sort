#include "readLib.h"

void imprimir(char** linhasAlocadas, int tam){
    for(int i = 0; i < tam; i++)
        printf("%s", linhasAlocadas[i]);
    return;
}

char** leLinhas(char** linhasRecebidas, char* file, int* tam){
    char** linhasAlocadas;
    //Se for o primeiro arquivo, ele cria o linhasAlocadas para retornar, se não, pega do vetor já existente
    if(!linhasRecebidas)
        linhasAlocadas = malloc(sizeof(char*));
    if(linhasRecebidas)
        linhasAlocadas = linhasRecebidas;

    char* linha = malloc(80 * sizeof(char));
    FILE* arch = fopen(file, "r");
    if(!arch){
        perror("ERRO ao abrir um dos diretórios dados");
        exit(1);
    }
    //começa de onde o último arquivo parou no vetor
    int index = *tam;

    while(fgets(linha, 80, arch)){
        //realoca para cada linhas
        linhasAlocadas = realloc(linhasAlocadas, (index+1)*sizeof(char*));
        linhasAlocadas[index] = malloc(80 * sizeof(char));
        strcpy(linhasAlocadas[index], linha);
        index++;
    }
    
    fclose(arch);
    free(linha);
    *tam = index;
    return linhasAlocadas;
}

void swap(char** linhasAlocadas, int i, int j){
    char* aux = linhasAlocadas[i];
    linhasAlocadas[i] = linhasAlocadas[j];
    linhasAlocadas[j] = aux;
    return;
}

int particionar(char** linhasAlocadas, int a, int b){
    int m = a;
    for(int i = a; i < b; i++){
        if(strcmp(linhasAlocadas[i], linhasAlocadas[b]) < 0){
            swap(linhasAlocadas, m, i);
            m++;
        }
    }
    
    swap(linhasAlocadas, b, m);
    
    return m;
}

void quickSort(char** linhasAlocadas, int a, int b){
    if(a >= b)
        return;
    int pivot = particionar(linhasAlocadas, a, b);

    quickSort(linhasAlocadas, a, pivot-1);
    quickSort(linhasAlocadas, pivot+1, b);
}

void liberar(char** linhasAlocadas, int tam){
    for(int i = 0; i < tam; i++)
        free(linhasAlocadas[i]);
    free(linhasAlocadas);
    return;
}
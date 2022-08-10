#include "readLib.h"

int main(int argv, char** argc){
    int tam = 0;

    //executa caso haja arquivos a serem lidos na linha de comando
    char** linhasStr;
    if(argv > 1){
        for(int i = 1; i<argv; i++){
            if(i==1)
                linhasStr = leLinhas(NULL, argc[i], &tam);
            if(i>1)
                linhasStr = leLinhas(linhasStr, argc[i], &tam);
        }
    }




    //lê nessa var caso não haja input na linha de comando
    else{
        char* notInLine = malloc(80 * sizeof(char));
        printf("Sem arquivos na linha de texto, digite o nome de um agora: \n");
        scanf("%s", notInLine);
        linhasStr = leLinhas(NULL, notInLine, &tam);
        free(notInLine);
    }

    //ordena, imprime e libera os mallocs
    quickSort(linhasStr, 0, tam-1);
    imprimir(linhasStr, tam);
    liberar(linhasStr, tam);
    return 0;
}
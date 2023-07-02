#include "../include/dicionario.hpp"

int alturaArvore(No *raiz){
    int esq, dir;
    if(raiz == NULL){
        return -1;
    }
    else{
        esq = alturaArvore(raiz->esq) + 1;
        dir = alturaArvore(raiz->dir) + 1;
        if(esq > dir){
            return esq;
        }
        else{
            return dir;
        }
    }
}

char** alocaDicionario(int colunas){
    char **dicionario;
    dicionario = (char**) malloc(TAM * sizeof(char*));

    for(int i = 0; i < TAM; i++){
        dicionario[i] = (char*) calloc(colunas, sizeof(char));
    }
    return dicionario;
}

void gerarDicionario(char **dicionario, No *raiz, char *caminho, int colunas){
    char esquerda[colunas], direita[colunas];
    if(raiz->esq == NULL && raiz->dir == NULL)
       strcpy(dicionario[raiz->caractere], caminho); 
    else{
        strcpy(esquerda, caminho);
        strcpy(direita, caminho);

        strcat(esquerda, "0");
        strcat(direita, "1");

        gerarDicionario(dicionario, raiz->esq, esquerda, colunas);
        gerarDicionario(dicionario, raiz->dir, direita, colunas);
    }
}

void imprimeDicionario(char **dicionario){
    printf("\n\tDicionario:\n");
    for(int i = 0;i < TAM; i++){
        if(dicionario[i][0] != '\0')
            printf("\t%3d: %s\n", i, dicionario[i]);
    }
}
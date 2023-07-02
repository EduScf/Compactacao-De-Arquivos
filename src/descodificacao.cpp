#include "../include/descodificacao.hpp"


char* decodificar(unsigned char texto[], No *raiz){
    int i = 0;
    No *aux = raiz;
    char temp[2];
    char *decodificado = (char*) calloc(strlen((const char*)texto) ,sizeof(char));

    while(texto[i] != '\0'){
        if(texto[i] == '0')
            aux = aux->esq;
        else
            aux = aux->dir;

        if(aux->esq == NULL && aux->dir == NULL){
            temp[0] = aux->caractere;
            temp[1] = '\0';
            strcat(decodificado, temp);
            aux = raiz;
        }
        i++;
    }
    return decodificado;
}
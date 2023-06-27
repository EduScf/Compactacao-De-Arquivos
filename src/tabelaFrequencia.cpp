#include "../include/tabelaFrequencia.hpp"

void inicializaTabelaComZero(unsigned int tab[]){
    for(int i = 0; i < TAM; i++){
        tab[i] = 0;
    }
}

void preencheTabelaFrequencia(unsigned char texto[], unsigned int tab[]){
    int i = 0;
    printf("\tTabela de Frequencia\n");
    while(texto[i] != '\0'){
        tab[texto[i]]++;
        i++;
    }
}

void imprimeTabelaFrequencia(unsigned int tab[]){
    for(int i = 0; i < TAM; i++){
        if(tab[i] != 0){
            printf("\t%d = %d = %c\n", i, tab[i], i);
        }
    }
}
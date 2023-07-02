#include "../include/tabelaFrequencia.hpp"

void inicializaTabelaComZero(unsigned int tab[]){
    for(int i = 0; i < TAM; i++){
        tab[i] = 0;
    }
}

void preencheTabelaFrequencia(unsigned char texto[], unsigned int tab[]){
    int i = 0;
    while(texto[i] != '\0'){
        tab[texto[i]]++;
        i++;
    }
}

void imprimeTabelaFrequencia(unsigned int tab[]){
    printf("\tTabela de Frequencia\n");
    for(int i = 0; i < TAM; i++){
        if(tab[i] != 0){
            printf("\t%d = %u = %c\n", i, tab[i], i);
        }
    }
}

void imprimeTextoLido(unsigned char texto[]){
    printf("\n%s", texto);
    for(int i = 0; i < 12; i++){
        printf("\n%c", texto[i]);
        printf("\n%d", texto[i]);
    }
}
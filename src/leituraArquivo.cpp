#include <iostream>
#include <cstring>
#include "../include/leituraArquivo.hpp"
#include "../include/tabelaFrequencia.hpp"

char texto[100];
char* textoLido = NULL;
int tamanho = 0;

void LeituraArquivo(char* nomeArquivo) {
    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        std::cout << "Erro ao abrir o arquivo" << std::endl;
        exit(1);
    }
    while (fgets(texto, 100, arquivo) != NULL) {
        tamanho += strlen(texto);
        textoLido = (char*) realloc(textoLido, tamanho * sizeof(char));
        strcat(textoLido, texto);
    }
    fclose(arquivo);
}

void ExecutaOperacoes(){
    unsigned int tabelaFrequencia[TAM];

    setlocale(LC_ALL, "Portuguese");

    inicializaTabelaComZero(tabelaFrequencia);
    preencheTabelaFrequencia((unsigned char*) textoLido, tabelaFrequencia);
    imprimeTabelaFrequencia(tabelaFrequencia);

    free(textoLido);
}


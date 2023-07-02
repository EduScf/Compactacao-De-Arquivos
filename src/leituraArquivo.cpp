#include <iostream>
#include <cstring>
#include "../include/leituraArquivo.hpp"
#include "../include/tabelaFrequencia.hpp"
#include "../include/listaOrdenada.hpp"
#include "../include/dicionario.hpp"
#include "../include/codificacao.hpp"
#include "../include/descodificacao.hpp"
#include "../include/compactacao.hpp"
#include "../include/descompactacao.hpp"

int descobrirTamanho(char *nomeArquivo){
    FILE *arq = fopen(nomeArquivo, "r");
    int tam = 0;
    if(arq){
        while(fgetc(arq) != -1){ //Enquanto não chegar no fim do arquivo
            tam++;
        }
    }
    else{
        std::cout << "Erro ao abrir o arquivo em descobrirTamanho()" << std::endl;
        exit(1);
    }
    fclose(arq);
    return tam;
}

void lerTexto(char *nomeArquivo, unsigned char *texto){
    FILE *arq = fopen(nomeArquivo, "r");
    char letra;
    int i = 0;

    if(arq){
        while(!feof(arq)){
            letra = fgetc(arq);
            if(letra != -1){
                texto[i] = letra;
                i++;
            }
        }
    }
    else{
        std::cout << "Erro ao abrir o arquivo em lerTexto()" << std::endl;
        exit(1);
    }
    fclose(arq);
}

void copiaTexto(const char *nomeArquivoDestino, unsigned char *texto, int tamanho) {
    FILE *arq = fopen(nomeArquivoDestino, "w");
    if (arq) {
        fwrite(texto, sizeof(unsigned char), tamanho, arq);
        fclose(arq);
    } else {
        std::cout << "Erro ao criar o arquivo em copiaTexto()" << std::endl;
        exit(1);
    }
}

void ExecutaOperacoes(char *nomeArquivo, char *nomeArquivoDestino, int flag){
    unsigned int tabelaFrequencia[TAM];
    //unsigned char teste[] = "Isso está funcionando para qualquer exemplo com acentuação?";
    unsigned char *texto;
    lista listaOrdenada;
    No *arvore = NULL;
    int colunas, tam;
    char **dicionario;
    char *codificado, *descodificado;

    setlocale(LC_ALL, "Portuguese");

    //Leitura do texto se for -c
    if(flag == 0){
        tam = descobrirTamanho(nomeArquivo);
        texto = (unsigned char*)calloc(tam + 2, sizeof(unsigned char));
        lerTexto(nomeArquivo, texto);

        //Arquivo auxiliar
        copiaTexto("arquivoAuxiliar.txt", texto, tam);

        //Inicialização da tabela de frequência
        inicializaTabelaComZero(tabelaFrequencia);
        preencheTabelaFrequencia(texto, tabelaFrequencia);

        //Inicialização da lista ordenada
        listaOrdenada.preencherLista(tabelaFrequencia, &listaOrdenada);

        //Montagem da árvore
        arvore = montarArvore(&listaOrdenada);

        //Geração do dicionário
        colunas = alturaArvore(arvore) + 1;
        dicionario = alocaDicionario(colunas);
        gerarDicionario(dicionario, arvore, "", colunas);

        //Codificação
        codificado = codificar(dicionario, texto);

        //Descodificação
        descodificado = decodificar((unsigned char*)codificado, arvore);

        //Compactação
        compactar((unsigned char*)codificado, nomeArquivoDestino);

        printf("\nArquivo compactado com sucesso!\n");
    }
    else if(flag == 1){
        tam = descobrirTamanho("arquivoAuxiliar.txt");
        texto = (unsigned char*)calloc(tam + 2, sizeof(unsigned char));
        lerTexto("arquivoAuxiliar.txt", texto);

        //Inicialização da tabela de frequência
        inicializaTabelaComZero(tabelaFrequencia);
        preencheTabelaFrequencia(texto, tabelaFrequencia);

        //Inicialização da lista ordenada
        listaOrdenada.preencherLista(tabelaFrequencia, &listaOrdenada);

        //Montagem da árvore
        arvore = montarArvore(&listaOrdenada);

        //Geração do dicionário
        colunas = alturaArvore(arvore) + 1;
        dicionario = alocaDicionario(colunas);
        gerarDicionario(dicionario, arvore, "", colunas);

        //Codificação
        codificado = codificar(dicionario, texto);

        //Descodificação
        descodificado = decodificar((unsigned char*)codificado, arvore);

        //Descompactação
        descompactar(arvore, nomeArquivo, nomeArquivoDestino);
        printf("\nArquivo descompactado com sucesso!\n");
    }
    else{
        printf("Use: %s <nome do arquivo fonte> <nome do arquivo destino> <-c ou -d>\n", nomeArquivo);
        exit(1);
    }
    free(texto);
    free(codificado);
    free(descodificado);
}


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

void copiaTabelaFrequencia(unsigned int tabelaFrequencia[], char *arquivoDestino){
    FILE *arq = fopen(arquivoDestino, "wb");
    if(arq){
        fwrite(tabelaFrequencia, sizeof(unsigned int), TAM, arq);	
        //Adicionar um simbolo 	© para indicar o fim do tabela frequencia
        fwrite("`", sizeof(unsigned char), 1, arq);
        fclose(arq);
    }
    else{
        std::cout << "Erro ao criar o arquivo em copiaTabelaFrequencia()" << std::endl;
        exit(1);
    }
}

void carregaTabela(unsigned int tabelaFrequencia[], char *arquivoFonte){
    FILE* arq = fopen(arquivoFonte, "rb");
    if (arq) {
        size_t bytesRead = 0;
        unsigned int byte;
        bool encontradoDivisor = false;

        size_t tamanhoTotalBytes = TAM * sizeof(unsigned int);

        while (bytesRead < tamanhoTotalBytes && !encontradoDivisor) {
            size_t bytes = fread(&byte, sizeof(unsigned int), 1, arq);
            if (bytes == 0) {
                // Fim do arquivo ou erro de leitura
                break;
            }

            tabelaFrequencia[bytesRead / sizeof(unsigned int)] = byte;

            bytesRead += sizeof(unsigned int);

            // Verifica se encontrou o divisor "`"
            if (byte == '`') {
                encontradoDivisor = true;
                break;
            }
        }

        fclose(arq);
    } else {
        std::cout << "Erro ao abrir o arquivo em carregaTabela()" << std::endl;
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

        //Inicialização da tabela de frequência
        inicializaTabelaComZero(tabelaFrequencia);
        preencheTabelaFrequencia(texto, tabelaFrequencia);
        printf("\nTabela de frequência inicializa com sucesso!\n");

        //Cópia da tabela de frequência
        copiaTabelaFrequencia(tabelaFrequencia, nomeArquivoDestino);

        //Inicialização da lista ordenada
        listaOrdenada.preencherLista(tabelaFrequencia, &listaOrdenada);
        printf("\nLista ordenada inicializa com sucesso!\n");

        //Montagem da árvore
        arvore = montarArvore(&listaOrdenada);
        printf("\nÁrvore montada com sucesso!\n");

        //Geração do dicionário
        colunas = alturaArvore(arvore) + 1;
        dicionario = alocaDicionario(colunas);
        gerarDicionario(dicionario, arvore, "", colunas);
        printf("\nDicionário gerado com sucesso!\n");

        //Codificação
        codificado = codificar(dicionario, texto);
        printf("\nTexto codificado com sucesso!\n");

        //Compactação
        compactar((unsigned char*)codificado, nomeArquivoDestino);

        printf("\nArquivo compactado com sucesso!\n");

        free(texto);
        free(codificado);
        liberarDicionario(dicionario, colunas);
    }
    //Descompactação se for -d
    //OBS: na hora de descompactar, é criado um arquivo auxiliar com o texto original para definir novamente a tabela de frequência e a arvore
    else if(flag == 1){

        //Carrega a tabela de frequência do arquivo auxiliar
        carregaTabela(tabelaFrequencia, nomeArquivo);

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
        printf("\nTexto descodificado com sucesso!\n");

        //Descompactação
        descompactar(arvore, nomeArquivo, nomeArquivoDestino);
        printf("\nArquivo descompactado com sucesso!\n");

        free(codificado);
        free(descodificado);
        liberarDicionario(dicionario, colunas);
    }
    else{
        printf("Use: %s <nome do arquivo fonte> <nome do arquivo destino> <-c ou -d>\n", nomeArquivo);
        exit(1);
    }
}


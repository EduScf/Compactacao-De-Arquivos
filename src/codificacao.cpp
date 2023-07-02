#include "../include/codificacao.hpp"

int calculaTamanhoString(char **dicionario, unsigned char *texto){
    int i=0 ,tam = 0;
    while(texto[i] != '\0'){
        tam += strlen(dicionario[texto[i]]);
        i++;
    }
    return tam + 1;
}

char* codificar(char **dicionario, unsigned char *texto){
    int i=0, tam = calculaTamanhoString(dicionario, texto);
    char *codigo = (char*)calloc(tam, sizeof(char));
    while(texto[i] != '\0'){
        strcat(codigo, dicionario[texto[i]]);
        i++;
    }
    return codigo;
}
#include "../include/compactacao.hpp"

void compactar(unsigned char str[], char *nomeArquivoDestino){
    FILE *arquivo = fopen(nomeArquivoDestino, "ab");
    int i = 0, j = 7;
    unsigned char mascara, byte = 0; //00000000 1000000

    if(arquivo){
        while(str[i] != '\0'){
            mascara = 1;
            if(str[i] == '1'){
                mascara = mascara << j;
                byte = byte | mascara;
            }
            j--;
            if(j < 0){ //tem um byte formado
                fwrite(&byte, sizeof(unsigned char), 1, arquivo);
                j = 7;
                byte = 0;
            }
            i++;
        }
        if(j != 7){ //ainda tem bits para escrever
            fwrite(&byte, sizeof(unsigned char), 1, arquivo);
        }
        fclose(arquivo);
    }
    else{
        printf("Erro ao abrir/criar o arquivo de compactação\n");
        exit(1);
    }
}
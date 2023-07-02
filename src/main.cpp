#include "../include/leituraArquivo.hpp"

int main(int argc, char *argv[]){
    int flag; //0 = -c / 1 = -d
    if (argc != 4){
        printf("Use: %s <nome do arquivo fonte> <nome do arquivo destino> <-c ou -d>\n", argv[0]);
        exit(1);
    }
    if(strcmp(argv[3], "-c") == 0){
        flag = 0;
    }
    else if(strcmp(argv[3], "-d") == 0){
        flag = 1;
    }
    else{
        printf("Use: %s <nome do arquivo fonte> <nome do arquivo destino> <-c ou -d>\n", argv[0]);
        exit(1);
    }

    ExecutaOperacoes(argv[1], argv[2], flag);

    return 0;
}
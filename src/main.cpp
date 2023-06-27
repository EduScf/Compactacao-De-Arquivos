#include "../include/leituraArquivo.hpp"

int main(int argc, char *argv[]){ 
    if (argc != 2){
        printf("Use: %s <nome do arquivo>\n", argv[0]);
        exit(1);
    }
    LeituraArquivo(argv[1]);
   
    ExecutaOperacoes();
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arquivo.h"


int main()
{
    srand(time(null));
    //cria_arquivo("teste.dat", 50);
    //printf("%d", getQuantidadeRegistros("teste.dat"));//pega tf do arquivo
    registro r2;
    r2.cod = 78;
    strcpy(r2.nome, "teste");
    set(3, "teste.dat", r2);
    registro r = get(3, "teste.dat");//pega o elemento da posicao informada
    printf("%d, %s", r.cod, r.nome);
    //exibe("teste.dat");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arquivo.h"


int main()
{
    srand(time(null));
    cria_arquivo("dados.dat", 50);
    printf("%d\n", getQuantidadeRegistros("dados.dat"));//pega tf do arquivo
    registro r2;
    r2.cod = 78;
    strcpy(r2.nome, "inicio");
    insere_inicio("dados.dat", r2);
    //bouble_sort("dados.dat");
    //bouble_sort("dados.dat");
    exibe("dados.dat");
    return 0;
}
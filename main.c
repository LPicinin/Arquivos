#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arquivo.h"
#define null NULL
void cria_arquivo(char nome[], int quantidade_de_registros)
{
    FILE *arq = fopen("dados.dat", "wb");//arquivo binário
    FILE *narq = fopen("nomes.txt", "r");//arquivo texto +-1000 nomes
    registro reg;
    char aux_nome[50];
    int aux_pos;
    if(narq != null)
    {
        for (int i = 0; i < quantidade_de_registros && quantidade_de_registros < 1000; ++i)
        {
            aux_pos = rand()%1000;
            fseek(arq, sizeof(registro)*aux_pos, 0);
            fgets(aux_nome, 50, arq);
            reg.cod = rand()%quantidade_de_registros;
            strcpy(reg.nome, aux_nome);
            fwrite(&reg, sizeof(registro), 1, arq);
        }
    }
    fclose(arq);
    fclose(narq);
}
int main()
{
    srand(time(null));
    cria_arquivo("teste.dat", 50);
    printf("hum");
    return 0;
}
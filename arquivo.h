//
// Created by Luish on 11/10/2018.
//
#define null NULL
struct Registro
{
    int cod;
    char nome[50];
};
typedef struct Registro registro;

void cria_arquivo(char nome[], int quantidade_de_registros)
{
    FILE *arq = fopen("dados.dat", "wb");//arquivo bin?rio
    registro reg;
    int aux_pos, i;
    for (i = 0; i < quantidade_de_registros; ++i)
    {
        reg.cod = i;
        sprintf(reg.nome, "nome%d", reg.cod);
        fwrite(&reg, sizeof(registro), 1, arq);
    }
    fclose(arq);
}
int getQuantidadeRegistros(char nomearq[])
{
	FILE *arq = fopen("dados.dat", "rb+");
	if(arq != null)
	{
		fseek(arq, 0, 2);//posiciona no final do arquivo
		return ftell(arq) / sizeof(registro);
	}
	else
		return -1;
}
registro get(int n, char nomearq[])
{
	FILE *arq = fopen("dados.dat", "rb+");
	registro reg;
	if(arq != null)
	{
		fseek(arq, sizeof(registro)*n, 0);//posiciona na posição selecionada
		fread(&reg,sizeof(registro), 1, arq);
		fclose(arq);
	}
	return reg;
}
void set(int n, char nomearq[], registro r)
{
	FILE *arq = fopen("dados.dat", "rb+");
	if(arq != null)
	{
		fseek(arq, sizeof(registro)*n, 0);//posiciona na posição selecionada
		fwrite(&r,sizeof(registro), 1, arq);
		fclose(arq);
	}
}
void exibe(char nome[])
{
	FILE *arq = fopen("dados.dat", "rb");
	registro r;
	if(arq != null)
	{
		do
		{
			fread(&r, sizeof(registro), 1, arq);
			printf("cod = %d, nome = %s\n", r.cod, r.nome);
		}while(!feof(arq));
		fclose(arq);
	}
}
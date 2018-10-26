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
    FILE *arq = fopen(nome, "wb");//arquivo bin?rio
    registro reg;
    int aux_pos, i;
    for (i = quantidade_de_registros-1; i >= 0; i--)
    {
        reg.cod = i;
        sprintf(reg.nome, "nome%d", reg.cod);
        fwrite(&reg, sizeof(registro), 1, arq);
    }
    fclose(arq);
}

int getQuantidadeRegistros(char nomearq[])
{
	FILE *arq = fopen(nomearq, "rb+");
	long int aux;
	if(arq != null)
	{
		fseek(arq, 0, 2);//posiciona no final do arquivo
		aux = ftell(arq);
		fclose(arq);
		return aux / sizeof(registro);
	}
	else
		return -1;
}
registro get(int n, char nomearq[])
{
	FILE *arq = fopen(nomearq, "rb+");
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
	FILE *arq = fopen(nomearq, "rb+");
	if(arq != null)
	{
		fseek(arq, sizeof(registro)*n, 0);//posiciona na posição selecionada
		fwrite(&r,sizeof(registro), 1, arq);
		fclose(arq);
	}
}
void insere_fim(char na[], registro r)//insere registro no final do arquivo
{
	FILE *arq = fopen(na, "ab");
	if(arq != null)
		fwrite(&r, sizeof(registro), 1, arq);
	fclose(arq);
}
void insere_inicio(char na[], registro r)//insere registro no inicio do arquivo
{
	insere_fim(na, r);
	int i, max;
	max = getQuantidadeRegistros(na);
	for(i = max-1; i >0; i--)
	{
		set(i, na, get(i-1, na));
	}
	set(0, na, r);
}
void exibe(char nome[])
{
	registro r;
	int i, tf = getQuantidadeRegistros(nome);
	for(i = 0; i < tf; i++)
	{
		r = get(i, nome);
		printf("cod = %d, nome = %s\n", r.cod, r.nome);
	}
}
void bouble_sort(char n[])
{
	registro r, r2;
	int i, j, tf;
	tf = getQuantidadeRegistros(n);
	for(i = 0; i < tf; i++)
	{
		for(j = 0; j < tf-1; j++)
		{
			r = get(j, n);
			r2 = get(j+1, n);
			if(r.cod >r2.cod)
			{
				set(j+1, n, r);
				set(j, n, r2);
			}
		}
	}
}

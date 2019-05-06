#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include "floodit_b.h"

void novo_jogo(int m[14][14])
{
	srand(time(NULL));
	int i, j;
	int cont[6] = {0};
	int limite = (14*14)/6;
	for(i=0;i<14;++i)
	{
		for(j=0;j<14;++j)
		{
			m[i][j] = rand() % 6;
			if(cont[m[i][j]]<=limite)
				cont[m[i][j]]++;
			else
				--j;
		}
	}
}

void salvar(int c[14][14], char n[100], int *jn)
{
	int i,j;
	FILE * arquivo;
	
	arquivo = fopen(n,"w");
	if (arquivo == NULL)
	{
		printw("Arquivo Inválido");
		refresh();
	}
	else
	{
		fprintf(arquivo, "%i\n", *jn);
		for (i=0;i<14;++i)
		{
			for (j=0;j<14;++j)
			{
				fprintf(arquivo, " %i ", c[i][j]);
			}
			fprintf(arquivo," \n");
		}
	}
    fclose (arquivo);
}

void carregar(int c[14][14], char n[100], int *jn)
{
	int i,j;
	FILE * arquivo;
	
	arquivo = fopen(n,"r");
	if (arquivo == NULL)
	{
		printw("Arquivo Inválido. Pressione qualquer tecla...");
		getch();
		refresh();
	}
	else
	{
		fscanf(arquivo, "%i\n", jn);
		for (i=0;i<14;++i)
		{
			for (j=0;j<14;++j)
			{
				fscanf(arquivo, "%i ", &c[i][j]);
			}
		}	
	}
}

boolean ganhou(int c[14][14])
{
	boolean r = verdadeiro;
	int n = c[0][0], i, j;
	for (i=0;i<14;++i)
	{
		for (j=0;j<14;++j)
		{
			if(c[i][j] != n)
			{
				r = falso;
			}
		}
	}
	return r;
}

void jogada(int i, int casa[14][14], int c, int j)
{
	int temp = casa[c][j];
	casa[c][j] = i;
	
	if(j<13 && casa[c][j+1] == temp)
	{
		jogada(i, casa, c, j+1);
	}
	if(c<13 && casa[c+1][j] == temp)
	{
		jogada(i, casa, c+1, j);
	}
	if(c>0 && casa[c-1][j] == temp)
	{
		jogada(i, casa, c-1, j);
	}
	if(j>0 && casa[c][j-1] == temp)
	{
		jogada(i, casa, c, j-1);
	}
}	
	

void printf_casa(int m[14][14])
{	
	int i, j;
	for(i=0;i<14;++i)
	{
		for(j=0;j<14;++j)
		{
			attrset(COLOR_PAIR(m[i][j]+1));
			printw("[%i] ", m[i][j]);
		
		}
		printw("\n");
	}
	attrset(A_NORMAL);
}

void menu(char r, int m[14][14], int *jn)
{
	system("clear");
	char a[100];

	if(r=='j')
	{	
		novo_jogo(m);
		*jn = 0;

	}
	else if (r=='c')
	{
		system("clear");
		printw("Digite o nome do jogo que deseja carregar: ");
		refresh();
		scanw("%s", a);
		carregar(m, a, jn);
	}
	else if (r=='s')
	{
		system("clear");
		printw("Digite o nome do jogo que deseja salvar: ");
		refresh();
		scanw("%s", a);
		salvar(m, a, jn);
	}
	else if(r=='u')
	{
		carregar(m, "undo.txt", jn);
		*jn = *jn-1;
	}
	else if(r=='q')
	{
		printw("Programa finalizado com sucesso!");
		refresh();
		exit(0);
	}
	
	
}



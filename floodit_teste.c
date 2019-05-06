#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include "floodit_b.h"
#include "floodit_b.c"

int main()
{
	initscr();
	start_color();
	
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_YELLOW, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	char recomecar = 's';
	
	while(recomecar=='s')
	{
		int jogadas = 0;
		int casa[14][14];
		char r = 'z';
		novo_jogo(casa);
		while (jogadas < 25 && ganhou(casa)!=1)
		{
			erase();
			refresh();
			printw("Jogada %i/25\n\n", jogadas);
			printf_casa(casa);
			printw("Digite o número da jogada; Digite 10 para o menu;\n");
			refresh();
			int num;
			scanw("%i", &num);
		
			if(num == 10)
			{
				
				printw("Menu -> Voltar[v]; Undo[u] Novo Jogo [j]; Salvar [s]; Carregar[c]; Sair[q];\n");
				refresh();
				scanw("%c", &r);
				
				menu(r, casa, &jogadas);
			}
			else
			{
				while(num == casa[0][0] || num<0 || num>5)
				{	
					printw("Numero invalido. ");
					printw("Digite o numero diferente da primeira casa e entre 0 e 5: \n");
					refresh();
					scanw("%i", &num);
				
				}
				jogadas++;
				salvar(casa, "undo.txt", &jogadas);
				jogada(num, casa, 0, 0);
				
			}
			
			system("clear");
		}

		erase();
		refresh();
		if(ganhou(casa))
		{
			printw("\nParabens! Voce ganhou com %i jogada(s) \n", jogadas);
			refresh();
			printf_casa(casa);
		}
		else
		{
			printw("\nVoce perdeu. Tente outra vez!\n");
			refresh();
		}
		
		printw("Deseja continuar jogando? [s/n]\n");
		refresh();
		scanw("%c", &recomecar);
	}	
	endwin();
	return 0;
}


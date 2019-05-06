#ifndef __FUNCOES_H
#define __FUNCOES_H

/* Tipos defindos */

typedef enum
{
	falso, verdadeiro
} boolean;

/* Sub-rotinas */

/**
 * Reinicia a matriz com valores aleatórios
 * @param m Matriz de inteiros que será alterada
 */
void novo_jogo(int m[14][14]);



/**
 * Salva a matriz e o numero de jogadas em um arquivo com nome definido através de parâmetros
 * @param c Matriz que terá seus valores salvos
 * @param n Nome do aquivo que será criado
 * @param jn Número de jogadas, que também terá seu valor salvo
 */
void salvar(int c[14][14], char n[100], int *jn);



/**
 * Carrega a matriz e o numero de jogadas de um arquivo com nome definido através de parâmetros
 * @param c Matriz que terá seus valores alterados
 * @param n Nome do aquivo que será carregado
 * @param jn Número de jogadas, que também terá seu valor carregado
 */
void carregar(int c[14][14], char n[100], int *j);



/**
 * Verifica se a matriz está completamente preenchida pelos mesmos valores, no caso, se o jogador ganhou.
 * @param c Matriz que terá seus valores verificados
 * @return Retorna "verdadeiro" (1) se todos os valores do arranjo sejam iguais e "falso" (0) caso não sejam
 */
boolean ganhou(int c[14][14]);



/**
 * Verifica as casas ao redor da matriz definida através de um parâmetro. Executa o flood fill nas 4 direções e com o limite de 
 * extenção da matriz(Da posição 0 a 13 das linhas e colunas).
 * @param casa Matriz que terá seus valores verificados
 * @param c Variável responsável pela verificação das linhas da matriz
 * @param j Variável responsável pela verificação das colunas da matriz
 */
void jogada(int i, int casa[14][14], int c, int j);



/**
 * Imprime na tela os valores da matriz atribuindo cores aos números da matriz.
 * @param m Matriz que terá seus valores alterados e impressos.
 */
void printf_casa(int m[14][14]);



/**
 * Chama menu com opções para reiniciar, salvar, carregar e desfazer o jogo.
 * @param r Char responsável pela leitura do comando do usuário
 * @param m Matriz trabalhada no menu
 * @param *jn Ponteiro responsável por armazenar o número de jogadas do usuário.
 */
void menu(char r, int m[14][14], int *jn);

#endif

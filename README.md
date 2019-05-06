	=== README ===

DESENVOLVEDORES: 
João Victor Marques de Oliveira e Matheus Fellipe da Costa Andrade
		 

-------------------------------------------------------------------------------------------------
FUNCIONALIDADES REALIZADAS:
	1. Tipos de dados necessários (typedef, structse enums);
	2. Modularização do programa (.c .h);
	3. Geração aleatória do tabuleiro (14x14 células);
	4. Apresentação da interface inicial do jogo com o tabuleiro gerado;
	5. Leitura da entrada do usuário e atualização do tabuleiro de forma recursiva,
	   preenchendo os adjacentes de mesma cor;
	6. Implementação da condição de término do jogo (máximo 25 rodadas ou tabuleiro
	   completamente preenchido);
	7. Salvamento e carregamento do estado de um jogo;
	8. Estabelecer uma distribuição uniforme na geração das cores no tabuleiro;
	9. Dar a possibilidade de Salvar e Carregar vários jogos;
	10. Implementar o jogo usando bibliotecas (ncurses) externas para dar suporte a cores;
	11. Possibilidade de realizar um “Undo” (desfazer) inúmeras vezes;

-------------------------------------------------------------------------------------------------
COMO COMPILAR:
	- Entrar com o comando no terminal: "sudo apt-get install libncurses5-dev" para instalar a biblioteca ncurses;
	- É necessário o comando "-lncurses" no final da linha de código utilizada para compilação no terminal;


sudoku: principal.c verificacao.c verificacao.h dica.c dica.h
	gcc principal.c verificacao.c dica.c -g -pthread -o sudoku

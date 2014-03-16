sudoku: principal.c  completar.c completar.h verificacao.c verificacao.h dica.c dica.h
	gcc principal.c  completar.h verificacao.c dica.c -g -pthread -o sudoku

typedef struct{
  int valor;
  int dicas[9];
} sudoku;

void moduloDicas();
void preencheDicas(sudoku matriz[][9]);
void checaDicasCelula(int x, int y, sudoku matriz[][9]);


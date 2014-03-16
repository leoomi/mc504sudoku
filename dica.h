typedef struct{
  int valor;
  int dicas[9];
}sudoku;

typedef struct{
  int x;
  int y;
  int inicio;
  int fim;
  int retorno;
  sudoku *matriz;
 }argumento;

void moduloDicas();
void preencheDicas(sudoku matriz[][9]);
void checaDicasCelula(int x, int y, sudoku matriz[][9]);
void imprimeDicas(sudoku matriz[][9]);

#include "img_process.h"

// Função principal.
int main(int argc, char **argv) {
  char name[20]; // Vetor que armazena o nome do arquivo.
  char newName[20]; // Vetor que armazena o nome do novo arquivo.
  char imgType[3]; // Vetor que armazena o tipo da imagem.
  int columns = 0; // Variável que armazena o número de colunas da imagem.
  int rows = 0; // Variável que armazena o número de linhas da imagem.
  int colorVar; // Variável que armazena a variação de cores da imagem.
  int pixelQtd; // Variável que armazena a quantidade de pixels da imagem.
  int *columVal = &columns; // Ponteiro para o número de colunas.
  int *rowVal = &rows; // Ponteiro para o número de linhas.
  int *colorVarVal = &colorVar; // Ponteiro para a variação de cores.
  int *pixelQtdVal = &pixelQtd; // Ponteiro para a quantidade de pixels.
  
  openFile(name); // Abrindo o arquivo
  RGB *pixelVector = readFileData(imgType, columVal, rowVal, colorVarVal, pixelQtdVal); // Lendo os dados e definindo o vetor de pixels.
  actions(name, newName, imgType, columns, rows, colorVar, colorVarVal, pixelQtd, pixelVector); // Selecionando a alteração desejada pelo usuário.
}

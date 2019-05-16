#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "img_process.h"

// Função principal.
int main() {
  char name[20]; // Vetor que armazena o nome do arquivo.
  char newName[20]; // Vetor que armazena o nome do novo arquivo.
  char imgType[3]; // Vetor que armazena o tipo da imagem.
  int columns; // Variável que armazena o número de colunas da imagem.
  int rows; // Variável que armazena o número de linhas da imagem.
  int colorVar; // Variável que armazena a variação de cores da imagem.
  int pixelQtd; // Variável que armazena a quantidade de pixels da imagem.
  int *columVal = &columns; // Ponteiro para o número de colunas.
  int *rowVal = &rows; // Ponteiro para o número de linhas.
  int *colorVarVal = &colorVar; // Ponteiro para a variação de cores.
  int *pixelQtdVal = &pixelQtd; // Ponteiro para a quantidade de pixels.

  openFile(name); // Abrindo o arquivo
  RGB *pixelVector = readFileData(imgType, columVal, rowVal, colorVarVal, pixelQtdVal); // Lendo os dados e definindo o vetor de pixels.
  createImg(newName, imgType, columns, rows, colorVar, pixelQtd, pixelVector); // Salvando as alterações e criando um novo arquivo.
}

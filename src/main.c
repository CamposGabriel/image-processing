#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE * file;
FILE * newFile;

typedef struct pixel {
  int red;
  int green;
  int blue;
} RGB;

// Função para abrir a imagem.
void openFile(char name[]) {
  printf("Bem vindo\n");
  printf("Digite o nome da sua imagem: \n");
  scanf("%s", name);

  char imagePath[20] = {"img/"}; // Origem da Imagem.
  strcat(imagePath, name); // Junta o caminho com o nome da imagem.
  strcat(imagePath, ".ppm"); // Adiciona a extensão pmm após o nome da imagem.
  file = fopen(imagePath, "r"); // Abre o Arquivo.
  
  if (file == NULL) { // Lidando com o erro arquivo não existente.
    printf("Arquivo não encontrado\n");
    exit(0);
  }
}

//Função para obter dados da imagem.
RGB* readFileData(char imgType[], int *columns, int *rows, int *colorVar, int *pixelQtd) {
  fscanf(file, "%s", imgType);
  fscanf(file, "%i %i", columns, rows);
  fscanf(file, "%i", colorVar);

  *pixelQtd = *columns * *rows;
  RGB *pixelVector = malloc(*pixelQtd * sizeof(RGB));

  for (int i = 0; i < *pixelQtd; i++){
    fscanf(file, "%i", &pixelVector[i].red);
    fscanf(file, "%i", &pixelVector[i].green);
    fscanf(file, "%i", &pixelVector[i].blue);
  }
  fclose(file);
  return pixelVector;
}

// Função que cria uma nova imagem.
void createImg(char name[], char imgType[], int columns, int rows, int colorVar, int pixelQtd, RGB pixelVector[]) {
  printf("Digite o nome da sua nova imagem: \n");
  scanf("%s", name);
  char imagePath[50] = {"img/"}; // Origem da Imagem.
  strcat(imagePath, name); // Junta o caminho com o nome da imagem.
  strcat(imagePath, ".ppm"); // Adiciona a extensão pmm após o nome da imagem.
  newFile = fopen(imagePath, "w"); // Abre o Arquivo.
  
  fprintf(newFile, "%c%c\n", imgType[0], imgType[1]);
  fprintf(newFile, "%i %i\n", columns, rows);
  fprintf(newFile, "%i\n", colorVar);
  
  for (int i = 0; i < pixelQtd; i++){
    fprintf(newFile, "%i\n", pixelVector[i].red);
    fprintf(newFile, "%i\n", pixelVector[i].green);
    fprintf(newFile, "%i\n", pixelVector[i].blue);
  }
  fclose(newFile);
  free(pixelVector);
}

// Função principal.
int main() {
  char name[20]; // Vetor que armazena o nome do arquivo.
  char newName[20]; // Vetor que armazena o nome do novo arquivo.
  char imgType[3]; // Vetor que armazena o tipo da imagem.
  int auxiliarToColumns; // Variável que armazena o número de colunas da imagem.
  int auxiliarToRows; // Variável que armazena o número de linhas da imagem.
  int *columns = &auxiliarToColumns; // Ponteiro que aponta para a variável que armazena o número de colunas da imagem.
  int *rows = &auxiliarToRows; // Ponteiro que aponta para a variável que armazena o número de linhas da imagem.
  int auxiliarToColorVariation; // Variável que armazena a variação de cores da imagem.
  int *colorVar = &auxiliarToColorVariation; // Ponteiro que aponta para a variável que armazena a variação de cores.
  int auxiliarToPixelQtd;
  int *pixelQtd = &auxiliarToPixelQtd; // Variável que armazena a quantidade de pixels da imagem.

  openFile(name);
  RGB *pixelVector = readFileData(imgType, columns, rows, colorVar, pixelQtd);
  createImg(newName, imgType, *columns, *rows, *colorVar, *pixelQtd, pixelVector);
}

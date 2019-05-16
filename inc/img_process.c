#include "img_process.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE * file;
FILE * newFile;

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

RGB* readFileData(char imgType[], int *columnVal, int *rowVal, int *colorVarVal, int *pixelQtdVal) {
  fscanf(file, "%s", imgType);
  fscanf(file, "%i %i", columnVal, rowVal);
  fscanf(file, "%i", colorVarVal);

  *pixelQtdVal = *columnVal * *rowVal;
  RGB *pixelVector = malloc(*pixelQtdVal * sizeof(RGB));

  for (int i = 0; i < *pixelQtdVal; i++){
    fscanf(file, "%i", &pixelVector[i].red);
    fscanf(file, "%i", &pixelVector[i].green);
    fscanf(file, "%i", &pixelVector[i].blue);
  }
  fclose(file);
  return pixelVector;
}

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
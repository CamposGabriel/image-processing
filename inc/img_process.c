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
  char test[2];
  fscanf(file, "%s", imgType);
  fgets(test, 1, file);
  if(test[0] == '#') {
    fscanf(file, "%i %i", columnVal, rowVal);
  }
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

void thr(int *pixelQtdVal, RGB pixelVector[]) {
  for (int i = 0; i < *pixelQtdVal; i++) {
    if (pixelVector[i].red < 165 && pixelVector[i].green < 165 && pixelVector[i].blue < 165) {
      pixelVector[i].red = 0;
      pixelVector[i].green = 0;
      pixelVector[i].blue = 0;
    } else {
      pixelVector[i].red = 255;
      pixelVector[i].green = 255;
      pixelVector[i].blue = 255;
    }
  }
}

void blu(int *pixelQtdVal, RGB pixelVector[]) {
  for (int i = 0; i < *pixelQtdVal; i++) {
    pixelVector[i].red = (pixelVector[i].red + pixelVector[i+1].red + pixelVector[i+2].red + pixelVector[i+3].red + pixelVector[i+4].red + pixelVector[i+5].red) / 6;
    pixelVector[i].green = (pixelVector[i].green + pixelVector[i+1].green + pixelVector[i+2].green + pixelVector[i+3].green + pixelVector[i+4].green + pixelVector[i+5].green) / 6;
    pixelVector[i].blue = (pixelVector[i].blue + pixelVector[i+1].blue + pixelVector[i+2].blue + pixelVector[i+3].blue + pixelVector[i+4].blue + pixelVector[i+5].blue) / 6;
  }
}

void sha(int *pixelQtdVal, RGB pixelVector[]) {
  for (int i = 0; i < *pixelQtdVal; i++) {
    pixelVector[i].red = (pixelVector[i].red * 0) + (pixelVector[i+1].red * -1) + (pixelVector[i+2].red * 0) + (pixelVector[i+3].red * -1) + (pixelVector[i+4].red * 5) + (pixelVector[i+5].red * -1) + (pixelVector[i+6].red * 0) + (pixelVector[i+7].red * -1) + (pixelVector[i+8].red * 0);
    pixelVector[i].green = (pixelVector[i].green * 0) + (pixelVector[i+1].green * -1) + (pixelVector[i+2].green * 0) + (pixelVector[i+3].green * -1) + (pixelVector[i+4].green * 5) + (pixelVector[i+5].green * -1) + (pixelVector[i+6].green * 0) + (pixelVector[i+7].green * -1) + (pixelVector[i+8].green * 0);
    pixelVector[i].blue = (pixelVector[i].blue * 0) + (pixelVector[i+1].blue * -1) + (pixelVector[i+2].blue * 0) + (pixelVector[i+3].blue * -1) + (pixelVector[i+4].blue * 5) + (pixelVector[i+5].blue * -1) + (pixelVector[i+6].blue * 0) + (pixelVector[i+7].blue * -1) + (pixelVector[i+8].blue * 0);

    if (pixelVector[i].red > 255) {
      pixelVector[i].red = 255;
    } else if (pixelVector[i].red < 0) {
      pixelVector[i].red = 0;
    }
    if (pixelVector[i].green > 255) {
      pixelVector[i].green = 255;
    } else if (pixelVector[i].green < 0) {
      pixelVector[i].green = 0;
    }
    if (pixelVector[i].blue > 255) {
      pixelVector[i].blue = 255;
    } else if (pixelVector[i].blue < 0) {
      pixelVector[i].blue = 0;
    }
  }
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

void actions(char name[], char newName[], char imgType[], int columns, int rows, int colorVar, int *colorVarVal, int pixelQtd, RGB pixelVector[]) {
  char answer1[1];
  char answer2[4];
  
  printf("Deseja fazer alguma alteração na imagem selecionada? [S]/[N]\n");
  scanf("%s", answer1);
  
  if (answer1[0] == 's') {
    printf("Lista de comandos:\n");
    printf("'thr': Fará a binarização da imagem usando thresholding.\n‘blu’: Executará o blurring.\n‘sha’: Executará o sharpening.\n'rot': Fará uma rotação da imagem, de acordo com o ângulo escolhido.\n'amp’: Ampliará a imagem, de acordo com o zoom escolhido.\n‘red’: Reduzirá a imagem, de acordo com o zoom escolhido.\nDigite a alteração que deseja executar: ");
    scanf("%s", answer2);
    if(answer2[0] == 't') {
      thr(&pixelQtd, pixelVector);
      createImg(newName, imgType, columns, rows, *colorVarVal, pixelQtd, pixelVector);
    } else if (answer2[0] == 'b') {
      blu(&pixelQtd, pixelVector);
      createImg(newName, imgType, columns, rows, *colorVarVal, pixelQtd, pixelVector);
    } else if (answer2[0] == 's') {
      sha(&pixelQtd, pixelVector);
      createImg(newName, imgType, columns, rows, *colorVarVal, pixelQtd, pixelVector);
    } else if (answer2[0] == 'r' && answer2[1] == 'o') {
      //rot();
    } else if (answer2[0] == 'a') {
      //amp();
    } else if (answer2[0] == 'r' && answer2[1] == 'e') {
      //red();
    }
  } else {
    createImg(newName, imgType, columns, rows, *colorVarVal, pixelQtd, pixelVector); // Salvando as alterações e criando um novo arquivo.
  }
}
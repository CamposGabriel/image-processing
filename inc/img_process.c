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
    printf("Arquivo não encontrado.\nrecomeçando o programa\n...\n");
    openFile(name);
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

void gsc(int *pixelQtdVal, RGB pixelVector[]) {
  for (int i = 0; i < *pixelQtdVal; i++) {
    pixelVector[i].red = (pixelVector[i].red * 0.3) + (pixelVector[i].green * 0.59) + (pixelVector[i].blue * 0.11);
    pixelVector[i].green = pixelVector[i].red;
    pixelVector[i].blue = pixelVector[i].red;
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

void bdt(int *pixelQtdVal, RGB pixelVector[]) {
  for (int i = 0; i < *pixelQtdVal; i++) {
    pixelVector[i].red = (pixelVector[i].red * -1) + (pixelVector[i+1].red * -1) + (pixelVector[i+2].red * -1) + (pixelVector[i+3].red * -1) + (pixelVector[i+4].red * 8) + (pixelVector[i+5].red * -1) + (pixelVector[i+6].red * -1) + (pixelVector[i+7].red * -1) + (pixelVector[i+8].red * -1);
    pixelVector[i].green = (pixelVector[i].green * -1) + (pixelVector[i+1].green * -1) + (pixelVector[i+2].green * -1) + (pixelVector[i+3].green * -1) + (pixelVector[i+4].green * 8) + (pixelVector[i+5].green * -1) + (pixelVector[i+6].green * -1) + (pixelVector[i+7].green * -1) + (pixelVector[i+8].green * -1);
    pixelVector[i].blue = (pixelVector[i].blue * -1) + (pixelVector[i+1].blue * -1) + (pixelVector[i+2].blue * -1) + (pixelVector[i+3].blue * -1) + (pixelVector[i+4].blue * 8) + (pixelVector[i+5].blue * -1) + (pixelVector[i+6].blue * -1) + (pixelVector[i+7].blue * -1) + (pixelVector[i+8].blue * -1);

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

void amp(char name[], char imgType[], int columns, int rows, int colorVar, int pixelQtd, RGB pixelVector[]) {
  int zoomQtd;
  printf("Digite a quantidade do zoom desejado (2, 4 ou 8 vezes): ");
  scanf("%i", &zoomQtd);

  if (zoomQtd == 2) {
    printf("Digite o nome da sua nova imagem: \n");
    scanf("%s", name);
    char imagePath[50] = {"img/"}; // Origem da Imagem.
    strcat(imagePath, name); // Junta o caminho com o nome da imagem.
    strcat(imagePath, ".ppm"); // Adiciona a extensão pmm após o nome da imagem.
    newFile = fopen(imagePath, "w"); // Abre o Arquivo.

    fprintf(newFile, "%c%c\n", imgType[0], imgType[1]);
    fprintf(newFile, "%i %i\n", 2*columns, 2*rows);
    fprintf(newFile, "%i\n", colorVar);

    RGB pixelMatrix[rows*2][columns*2];

    for (int i = 0; i < rows; i++) {
      for(int j = 0; j < columns; j++) {
        RGB pixel = pixelVector[i * columns + j];
        pixelMatrix[(i*2)][(j*2)] = pixel;
        pixelMatrix[(i*2)][(j*2)+1] = pixel;
        pixelMatrix[(i*2)+1][(j*2)] = pixel;
        pixelMatrix[(i*2)+1][(j*2)+1] = pixel;
      }
    }

    for (int i = 0; i < rows*2; i++) {    
      for(int j = 0; j < columns*2; j++) {
        fprintf(newFile, "%i\n", pixelMatrix[i][j].red);
        fprintf(newFile, "%i\n", pixelMatrix[i][j].green);
        fprintf(newFile, "%i\n", pixelMatrix[i][j].blue);
      }
    }
  } else if (zoomQtd == 4) {
    printf("Digite o nome da sua nova imagem: \n");
    scanf("%s", name);
    char imagePath[50] = {"img/"}; // Origem da Imagem.
    strcat(imagePath, name); // Junta o caminho com o nome da imagem.
    strcat(imagePath, ".ppm"); // Adiciona a extensão pmm após o nome da imagem.
    newFile = fopen(imagePath, "w"); // Abre o Arquivo.

    fprintf(newFile, "%c%c\n", imgType[0], imgType[1]);
    fprintf(newFile, "%i %i\n", 4*columns, 4*rows);
    fprintf(newFile, "%i\n", colorVar);

    RGB pixelMatrix[rows*4][columns*4];

    for (int n = 0; n < 4; n++) {
      for (int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
          RGB pixel = pixelVector[i * columns + j];
          pixelMatrix[(i*4)+n][(j*4)] = pixel;
          pixelMatrix[(i*4)+n][(j*4)+1] = pixel;
          pixelMatrix[(i*4)+n][(j*4)+2] = pixel;
          pixelMatrix[(i*4)+n][(j*4)+3] = pixel;
        }
      }
    }
    
    for (int i = 0; i < (rows * 4); i++) {    
      for(int j = 0; j < (columns * 4); j++) {
        fprintf(newFile, "%i\n", pixelMatrix[i][j].red);
        fprintf(newFile, "%i\n", pixelMatrix[i][j].green);
        fprintf(newFile, "%i\n", pixelMatrix[i][j].blue);
      }
    }
  } else if (zoomQtd == 8) {
    printf("Digite o nome da sua nova imagem: \n");
    scanf("%s", name);
    char imagePath[50] = {"img/"}; // Origem da Imagem.
    strcat(imagePath, name); // Junta o caminho com o nome da imagem.
    strcat(imagePath, ".ppm"); // Adiciona a extensão pmm após o nome da imagem.
    newFile = fopen(imagePath, "w"); // Abre o Arquivo.

    fprintf(newFile, "%c%c\n", imgType[0], imgType[1]);
    fprintf(newFile, "%i %i\n", 8*columns, 8*rows);
    fprintf(newFile, "%i\n", colorVar);

    RGB pixelMatrix[rows*8][columns*8];
    
    for (int n = 0; n < 8; n++) {
      for (int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
          RGB pixel = pixelVector[i * columns + j];
          pixelMatrix[(i*8)+n][(j*8)] = pixel;
          pixelMatrix[(i*8)+n][(j*8)+1] = pixel;
          pixelMatrix[(i*8)+n][(j*8)+2] = pixel;
          pixelMatrix[(i*8)+n][(j*8)+3] = pixel;
          pixelMatrix[(i*8)+n][(j*8)+4] = pixel;
          pixelMatrix[(i*8)+n][(j*8)+5] = pixel;
          pixelMatrix[(i*8)+n][(j*8)+6] = pixel;
          pixelMatrix[(i*8)+n][(j*8)+7] = pixel;
        }
      }
    }

    for (int i = 0; i < (rows * 8); i++) {    
      for(int j = 0; j < (columns * 8); j++) {
        fprintf(newFile, "%i\n", pixelMatrix[i][j].red);
        fprintf(newFile, "%i\n", pixelMatrix[i][j].green);
        fprintf(newFile, "%i\n", pixelMatrix[i][j].blue);
      }
    }
  } else {
    printf("Por favor, digite um valor válido (2, 4 ou 8).\n");
    amp(name, imgType, columns, rows, colorVar, pixelQtd, pixelVector);
  }

  fclose(newFile);
  free(pixelVector);
}

void red(char name[], char imgType[], int columns, int rows, int colorVar, int pixelQtd, RGB pixelVector[]) {
  int zoomQtd;
  printf("Digite a quantidade do zoom desejado (2, 4 ou 8 vezes): ");
  scanf("%i", &zoomQtd);

  if (zoomQtd == 2) {
    printf("Digite o nome da sua nova imagem: \n");
    scanf("%s", name);
    char imagePath[50] = {"img/"}; // Origem da Imagem.
    strcat(imagePath, name); // Junta o caminho com o nome da imagem.
    strcat(imagePath, ".ppm"); // Adiciona a extensão pmm após o nome da imagem.
    newFile = fopen(imagePath, "w"); // Abre o Arquivo.

    fprintf(newFile, "%c%c\n", imgType[0], imgType[1]);
    fprintf(newFile, "%i %i\n", columns / 2, rows / 2);
    fprintf(newFile, "%i\n", colorVar);

    RGB pixelMatrix[rows][columns];
    RGB pixelMatrixRedux[rows/2][columns/2];

    int aux = 0;
    for (int i = 0; i < rows; i++) {    
      for(int j = 0; j < columns; j++) {
        pixelMatrix[i][j] = pixelVector[aux];
        aux++;
      }
    }

    for (int i = 0; i < rows/2; i++) {
      for(int j = 0; j < columns/2; j++) {
        pixelMatrixRedux[i][j] = pixelMatrix[i*2][j*2];
      }
    }

    for (int i = 0; i < rows/2; i++) {    
      for(int j = 0; j < columns/2; j++) {
        fprintf(newFile, "%i\n", pixelMatrixRedux[i][j].red);
        fprintf(newFile, "%i\n", pixelMatrixRedux[i][j].green);
        fprintf(newFile, "%i\n", pixelMatrixRedux[i][j].blue);
      }
    }

  } else if (zoomQtd == 4) {
    
    printf("Digite o nome da sua nova imagem: \n");
    scanf("%s", name);
    char imagePath[50] = {"img/"}; // Origem da Imagem.
    strcat(imagePath, name); // Junta o caminho com o nome da imagem.
    strcat(imagePath, ".ppm"); // Adiciona a extensão pmm após o nome da imagem.
    newFile = fopen(imagePath, "w"); // Abre o Arquivo.

    fprintf(newFile, "%c%c\n", imgType[0], imgType[1]);
    fprintf(newFile, "%i %i\n", columns / 4, rows / 4);
    fprintf(newFile, "%i\n", colorVar);
    
    RGB pixelMatrix[rows][columns];
    RGB pixelMatrixRedux[rows/4][columns/4];

    int aux = 0;
    for (int i = 0; i < rows; i++) {    
      for(int j = 0; j < columns; j++) {
        pixelMatrix[i][j] = pixelVector[aux];
        aux++;
      }
    }

    for (int i = 0; i < rows/4; i++) {
      for(int j = 0; j < columns/4; j++) {
        pixelMatrixRedux[i][j] = pixelMatrix[i*4][j*4];
      }
    }

    for (int i = 0; i < rows/4; i++) {    
      for(int j = 0; j < columns/4; j++) {
        fprintf(newFile, "%i\n", pixelMatrixRedux[i][j].red);
        fprintf(newFile, "%i\n", pixelMatrixRedux[i][j].green);
        fprintf(newFile, "%i\n", pixelMatrixRedux[i][j].blue);
      }
    }

  } else if (zoomQtd == 8) {

    printf("Digite o nome da sua nova imagem: \n");
    scanf("%s", name);
    char imagePath[50] = {"img/"}; // Origem da Imagem.
    strcat(imagePath, name); // Junta o caminho com o nome da imagem.
    strcat(imagePath, ".ppm"); // Adiciona a extensão pmm após o nome da imagem.
    newFile = fopen(imagePath, "w"); // Abre o Arquivo.

    fprintf(newFile, "%c%c\n", imgType[0], imgType[1]);
    fprintf(newFile, "%i %i\n", columns / 8, rows / 8);
    fprintf(newFile, "%i\n", colorVar);

    RGB pixelMatrix[rows][columns];
    RGB pixelMatrixRedux[rows/8][columns/8];

    int aux = 0;
    for (int i = 0; i < rows; i++) {    
      for(int j = 0; j < columns; j++) {
        pixelMatrix[i][j] = pixelVector[aux];
        aux++;
      }
    }

    for (int i = 0; i < rows/8; i++) {
      for(int j = 0; j < columns/8; j++) {
        pixelMatrixRedux[i][j] = pixelMatrix[i*8][j*8];
      }
    }

    for (int i = 0; i < rows/8; i++) {    
      for(int j = 0; j < columns/8; j++) {
        fprintf(newFile, "%i\n", pixelMatrixRedux[i][j].red);
        fprintf(newFile, "%i\n", pixelMatrixRedux[i][j].green);
        fprintf(newFile, "%i\n", pixelMatrixRedux[i][j].blue);
      }
    }

  } else {
    printf("Por favor, digite um valor válido (2, 4 ou 8).\n");
    red(name, imgType, columns, rows, colorVar, pixelQtd, pixelVector);
  }

  fclose(newFile);
  free(pixelVector);
}

void rot(char name[], char imgType[], int columns, int rows, int colorVar, int pixelQtd, RGB pixelVector[]) {
  int rotQtd = 0;
  printf("Digite o grau de rotação desejado (90, 180 ou 270 graus): ");
  scanf("%i", &rotQtd);

  if (rotQtd == 90) {

    printf("Digite o nome da sua nova imagem: \n");
    scanf("%s", name);
    char imagePath[50] = {"img/"}; // Origem da Imagem.
    strcat(imagePath, name); // Junta o caminho com o nome da imagem.
    strcat(imagePath, ".ppm"); // Adiciona a extensão pmm após o nome da imagem.
    newFile = fopen(imagePath, "w"); // Abre o Arquivo.

    fprintf(newFile, "%c%c\n", imgType[0], imgType[1]);
    fprintf(newFile, "%i %i\n", rows, columns);
    fprintf(newFile, "%i\n", colorVar);

    RGB pixelMatrix[rows][columns];
    
    int aux = pixelQtd;
    for (int i = 0; i < rows; i++) {    
      for(int j = 0; j < columns; j++) {
        pixelMatrix[i][j] = pixelVector[aux];
        aux--;
      }
    }

    for (int i = columns; i > 0; i--) {  
      for(int j = 0; j < rows; j++) {
        fprintf(newFile, "%i\n", pixelMatrix[j][i].red);
        fprintf(newFile, "%i\n", pixelMatrix[j][i].green);
        fprintf(newFile, "%i\n", pixelMatrix[j][i].blue);
      }
    }

  } else if (rotQtd == 180) {

    printf("Digite o nome da sua nova imagem: \n");
    scanf("%s", name);
    char imagePath[50] = {"img/"}; // Origem da Imagem.
    strcat(imagePath, name); // Junta o caminho com o nome da imagem.
    strcat(imagePath, ".ppm"); // Adiciona a extensão pmm após o nome da imagem.
    newFile = fopen(imagePath, "w"); // Abre o Arquivo.

    fprintf(newFile, "%c%c\n", imgType[0], imgType[1]);
    fprintf(newFile, "%i %i\n", columns, rows);
    fprintf(newFile, "%i\n", colorVar);

    RGB pixelMatrix[rows][columns];
    
    int aux = rows * columns;
    for (int i = 0; i < rows; i++) {    
      for (int j = 0; j < columns; j++) {
        pixelMatrix[i][j] = pixelVector[aux];
        aux--;
      }
    }

    for (int i = 0; i < rows; i++) {    
      for (int j = 0; j < columns; j++) {
        fprintf(newFile, "%i\n", pixelMatrix[i][j].red);
        fprintf(newFile, "%i\n", pixelMatrix[i][j].green);
        fprintf(newFile, "%i\n", pixelMatrix[i][j].blue);
      }
    }

  } else if (rotQtd == 270) {

    printf("Digite o nome da sua nova imagem: \n");
    scanf("%s", name);
    char imagePath[50] = {"img/"}; // Origem da Imagem.
    strcat(imagePath, name); // Junta o caminho com o nome da imagem.
    strcat(imagePath, ".ppm"); // Adiciona a extensão pmm após o nome da imagem.
    newFile = fopen(imagePath, "w"); // Abre o Arquivo.

    fprintf(newFile, "%c%c\n", imgType[0], imgType[1]);
    fprintf(newFile, "%i %i\n", rows, columns);
    fprintf(newFile, "%i\n", colorVar);

    RGB pixelMatrix[rows][columns];
    
    int aux = 0;
    for (int i = 0; i < rows; i++) {    
      for(int j = 0; j < columns; j++) {
        pixelMatrix[i][j] = pixelVector[aux];
        aux++;
      }
    }

    for (int i = columns; i > 0; i--) {  
      for(int j = 0; j < rows; j++) {
        fprintf(newFile, "%i\n", pixelMatrix[j][i].red);
        fprintf(newFile, "%i\n", pixelMatrix[j][i].green);
        fprintf(newFile, "%i\n", pixelMatrix[j][i].blue);
      }
    }

  } else {
    printf("Por favor, digite um valor válido (90, 180 ou 270).\n");
    rot(name, imgType, columns, rows, colorVar, pixelQtd, pixelVector);
  }

  fclose(newFile);
  free(pixelVector);
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

  int shaVector[] = {0, -1, 0, -1, 5, -1, 0, -1, 0};

  int bdtVector[] = {-1, -1, -1, -1, 8, -1, -1, -1, -1};
  
  if (answer1[0] == 's') {
    printf("Lista de comandos:\n");
    printf("'thr': Fará a binarização da imagem usando thresholding.\n'gsc': Transformará a imagem em escala de cinza.\n‘blu’: Executará o blurring.\n‘sha’: Executará o sharpening.\n'bdt': Fará a detecção de bordas da imagem.\n'rot': Fará uma rotação da imagem, de acordo com o ângulo escolhido.\n'amp’: Ampliará a imagem, de acordo com o zoom escolhido.\n‘red’: Reduzirá a imagem, de acordo com o zoom escolhido.\nDigite a alteração que deseja executar: ");
    scanf("%s", answer2);
    if(answer2[0] == 't' && answer2[1] == 'h' && answer2[2] == 'r') {
      thr(&pixelQtd, pixelVector);
      createImg(newName, imgType, columns, rows, *colorVarVal, pixelQtd, pixelVector);
    } else if (answer2[0] == 'b' && answer2[1] == 'l' && answer2[2] == 'u') {
      blu(&pixelQtd, pixelVector);
      createImg(newName, imgType, columns, rows, *colorVarVal, pixelQtd, pixelVector);
    } else if (answer2[0] == 's' && answer2[1] == 'h' && answer2[2] == 'a') {
      sha(&pixelQtd, pixelVector);
      createImg(newName, imgType, columns, rows, *colorVarVal, pixelQtd, pixelVector);
    } else if (answer2[0] == 'b' && answer2[1] == 'd' && answer2[2] == 't') {
       bdt(&pixelQtd, pixelVector);
      createImg(newName, imgType, columns, rows, *colorVarVal, pixelQtd, pixelVector);
    } else if (answer2[0] == 'r' && answer2[1] == 'o' && answer2[2] == 't') {
      rot(newName, imgType, columns, rows, *colorVarVal, pixelQtd, pixelVector);
    } else if (answer2[0] == 'a' && answer2[1] == 'm' && answer2[2] == 'p') {
      amp(newName, imgType, columns, rows, *colorVarVal, pixelQtd, pixelVector);
    } else if (answer2[0] == 'r' && answer2[1] == 'e' && answer2[2] == 'd') {
      red(newName, imgType, columns, rows, *colorVarVal, pixelQtd, pixelVector);
    } else if (answer2[0] == 'g' && answer2[1] == 's' && answer2[2] == 'c') {
      gsc(&pixelQtd, pixelVector);
      createImg(newName, imgType, columns, rows, *colorVarVal, pixelQtd, pixelVector);
    } else {
    exit(0);
    }
  }
}

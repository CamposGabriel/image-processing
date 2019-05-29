#ifndef __IMG_PROCESS_H__
#define __IMG_PROCESS_H__

typedef struct pixel {
  int red;
  int green;
  int blue;
} RGB;

// Abre um arquivo de imagem, dado o nome, localizado na pasta "img" dentro da pasta do projeto.
void openFile(char name[]);

// Coleta os dados de um arquivo de imagem, dado o nome, localizado na pasta "img" dentro da pasta do projeto.
RGB* readFileData(char imgType[], int *columnVal, int *rowVal, int *colorVarVal, int *pixelQtdVal);

// Realiza a binarização da imagem utilizando a técnica threshold.
void thr(int *pixelQtdVal, RGB pixelVector[]);

// Transforma a imagem em uma escala de cinza.
void gsc(int *pixelQtdVal, RGB pixelVector[]);

// Realiza o borramento da imagem.
void blu(int *pixelQtdVal, RGB pixelVector[]);

// Realiza o afiamento das bordas da imagem.
void sha(int *pixelQtdVal, RGB pixelVector[]);

// Amplia a imagem.
void amp(char name[], char imgType[], int columns, int rows, int colorVar, int pixelQtd, RGB pixelVector[]);

// Cria um novo arquivo de imagem localizado dentro da pasta "img" com as alterações feitas.
void createImg(char name[], char imgType[], int columns, int rows, int colorVar, int pixelQtd, RGB pixelVector[]);

// Seleciona qual alteração será feita na imagem através de um input do usuário.
void actions(char name[], char newName[], char imgType[], int columns, int rows, int colorVar, int *colorVarVal, int pixelQtd, RGB pixelVector[]);

#endif
#ifndef __IMG_PROCESS_H__
#define __IMG_PROCESS_H__

typedef struct pixel {
  int red;
  int green;
  int blue;
} RGB;

void openFile(char name[]);

RGB* readFileData(char imgType[], int *columnVal, int *rowVal, int *colorVarVal, int *pixelQtdVal);

void createImg(char name[], char imgType[], int columns, int rows, int colorVar, int pixelQtd, RGB pixelVector[]);

#endif
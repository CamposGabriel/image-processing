# Image processing program in C.

## About
The program will read a PPM image file and do one or more transformations on the image, acording with the user choice.

## Sumary
- [Commands](https://github.com/CamposGabriel/image-processing#commands)
- [End of the program](https://github.com/CamposGabriel/image-processing#end-of-the-program)
- [Extras](https://github.com/CamposGabriel/image-processing#extras)

## How to use the program properly
- Before starting the program, mnake sure that your stack memory is unlimited. If not, use the command on terminal:

```bash
  ulimit -s unlimited
```

- Clone this repository;
- Open the bash terminal in the repository file and run:
```bash
  bin/main
```
- Follow the program steps;

## Commands
- 'thr': Will do the image binarization using thresholding technic.
- 'gsc': Will transform the image into gray scale.
- ‘blu’: Will blur the image.
- ‘sha’: Will sharp the image.
- 'bdt': Will detect the borders of the image.
- 'rot': Will rotate the image, acording with the chosen angle.
- 'amp’: Will zoom in the image, acoording with the chosen quantity.
- ‘red’: Will zoom out the image, acoording with the cosen quantity.

## End of the program
The program will end if one of the three following cases happens:
- 1) The segmentation finish with success;
- 2) Segmentation error;
- 3) User interrupt the program;

## Extras:

### Libraries
- The "img_process.h" was created to help the project.

### Functions
- The "actions" function was created to make the code cleaner.

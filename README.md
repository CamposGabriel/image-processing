# Processamento de imagem usando a linguagem C
Esse é um programa desenvolvido para a disciplina de Introdução as Técnicas de Programação.

## Sobre o programa
O programa lerá um arquivo de imagem no formato PPM e realizará uma ou mais operações de transformação na imagem, de acordo com o que o usuário escolher.

## Comandos
### Os comandos (da linha de comando) serão:
- 'thr': Fará a binarização da imagem usando thresholding.
- ‘blu’: Executará o borramento da imagem.
- ‘sha’: Aumentará a nitidez da imagem.
- 'rot': Fará uma rotação da imagem, de acordo com o ângulo escolhido.
- 'amp’: Ampliará a imagem, de acordo com o zoom escolhido.
- ‘red’: Reduzirá a imagem, de acordo com o zoom escolhido.


### Detalhamento de alguns comandos:
- Thresholding é um método de substituição de cada pixel de uma imagem por um pixel preto se a itensidade for menor do que uma constante T fixada ou um pixel branco se for maior do que a constante.
- Blurring é o embaçamento da imagem.
- Sharpening é o realçamento das bordas e detalhes de uma imagem.


## Término do programa
O programa encerrará caso ocorra uma das três seguintes situações:
- A segmentação foi feita completamente.
- Aconteceu um erro na segmentação da imagem.
- O usuário interrompeu o programa.

## Extras:

### Bibliotecas
- Biblioteca "img_process.h" criada para auxiliar o projeto.

### Comandos:
- Função "actions": Direciona o usuário para a função que faz a alteração desejada.

## Demonstração do projeto: 

### Binarização da imagem:
![Binarização](ex/gifs/thr.gif)

### Borramento da imagem:
![Borramento](ex/gifs/blu.gif)

### Aumento da nitidez da imagem:
![Nitidez](ex/gifs/sha.gif)

### Aumento do tamanho da imagem:
![Amp](ex/amp_2.png)

#include <stdio.h>
#include <stdlib.h>

//Criando nós

typedef struct no {
    int info;
    struct no *esquerda;
    struct no *direita;
} no_binario;

no_binario * cria_no (int);

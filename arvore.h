#include <stdio.h>
#include <stdlib.h>
#include "no_binario.h"

typedef struct {
    no_binario * raiz;
} arvore;

// Protótipos
int arvore_vazia (arvore *);
int insere (int, arvore *);
void inicia_arvore (arvore *);
void mostra_em_ordem (arvore *);
void mostra_pre_ordem (arvore *);

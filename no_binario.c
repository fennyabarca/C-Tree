#include "no_binario.h"

no_binario * cria_no (int i){
    no_binario * auxiliar = (no_binario *) malloc (sizeof(no_binario));
    if (auxiliar != NULL){
        auxiliar -> info = i;
        auxiliar -> esquerda = NULL;
        auxiliar -> direita = NULL;
    }
    return auxiliar;
}

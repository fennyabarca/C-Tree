// Árvore
#include <stdio.h>
#include <time.h>
#include "arvore.h"

int main() {
    int i, j;
    arvore a;
    inicia_arvore(&a);
    srand(time(0));
    
    for (i=1; i<=12; i++){
        j = rand()%20;
        printf("%d ", j);
        insere(j, &a);
    }
    //mostra em ordem
    printf("\n\nArvore - percurso em ordem\n");
    mostra_em_ordem(&a);
    
    //mostra em pre ordem
    printf("\n\nArvore - percurso em pre orderm\n");
    mostra_pre_ordem(&a);
     
    //mostra o maior nó
    if (arvore_vazia(&a))
        printf("A arvore esta vazia!\n");
    else
        printf("\n\nO maior elemento da arvore e: %d\n", maior(&a));
    
    //mostra a quantidade de nós
    printf("\nA arvore tem %d nos\n", numero_de_nos(&a));
    
    //mostra os nos que estao na franja
    printf("\nEstao na franja %d nos\n", nos_franja(&a));
    
    //mostra o menor nó
    if (arvore_vazia(&a))
        printf("A arvore esta vazia!\n");
    else
        printf("\nO menor elemento da arvore e: %d\n", menor(&a));
    
    //mostra a soma dos nos
    printf("\nA soma de todos os nos e: %d", soma_nos(&a));
    
    //mostra decrescente
    printf("\n\nArvore - ordem decrescente\n");
    ordem_decrescente(&a);
    
    printf("\n\n");
    return 0;
}

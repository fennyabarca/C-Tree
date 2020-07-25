#include "arvore.h"

//inicia a árvores
void inicia_arvore (arvore *ponteiro_arvore){
    ponteiro_arvore->raiz = NULL; // nao tem nada na raiz
}

//verifica árvore vazia
int arvore_vazia (arvore *ponteiro_arvore){
    return ponteiro_arvore-> raiz == NULL;
}

//cria nó
int insere_no (no_binario *novo, no_binario * atual){
    if (novo->info > atual->info){
        if (atual->direita == NULL){
            atual->direita = novo;
            return 1;
        }
        return insere_no(novo, atual->direita); //insere um nó
    }else{
        if (atual->esquerda == NULL){
            atual->esquerda = novo;
            return 1;
        }
        return insere_no(novo, atual->esquerda);
    }
}

//insere nó criado na árvore
int insere (int i, arvore *ponteiro_arvore){
    no_binario *novo = cria_no(i); //insere um elemento dentro de um nó
    if (novo != NULL){
        if (arvore_vazia(ponteiro_arvore)){
            ponteiro_arvore->raiz = novo;
            return 1;
        }
            //procurar a partir da raiz o lugar certo para inserir o novo nó
            return insere_no (novo, ponteiro_arvore->raiz); //posição atual - recursão de cauda
    }
    return 0;
}

//estrutura interna
void mostra_no_em_ordem(no_binario * atual){
    if (atual != NULL){
        mostra_no_em_ordem(atual->esquerda);
        printf("%d ", atual->info);
        mostra_no_em_ordem(atual->direita);
    }
}//fim da estrutura interna

//mostra ordem dos nós
void mostra_em_ordem (arvore *ponteiro_arvore){
    if (arvore_vazia(ponteiro_arvore)){
        printf("A arvore esta vazia!\n");
    }else{
        mostra_no_em_ordem(ponteiro_arvore->raiz);
    }
}

//estrutura interna
void mostra_no_pre_ordem(no_binario *atual) {
    if(atual != NULL){
        printf("%d ", atual->info);
        mostra_no_pre_ordem(atual->esquerda);
        mostra_no_pre_ordem(atual->direita);
    }
}//fim da estrutura interna

//mostra em pré-ordem
void mostra_pre_ordem(arvore *ponteiro_arvore) {
    if(arvore_vazia(ponteiro_arvore))
        printf("A arvore esta vazia!\n");
    else
        mostra_no_pre_ordem(ponteiro_arvore->raiz);
}

//mostra maior valor da árvore
int maior_arvore (no_binario *atual){
    if (atual->direita == NULL)
        return atual->info;
    return maior_arvore(atual->direita);
}
int maior (arvore *ponteiro_arvore){
    return maior_arvore(ponteiro_arvore->raiz);
}

//devolve o numero de nós da árevore
int conta_nos (no_binario *atual){
    if (atual != NULL){
        return 1 + conta_nos(atual->esquerda) + conta_nos(atual->direita);
    }
    return 0;
}
int numero_de_nos (arvore *ponteiro_arvore){
    if (arvore_vazia(ponteiro_arvore))
        return 0;
    return conta_nos(ponteiro_arvore->raiz);
}

/* devolve maior com outra logica
int conta_nos_recursivo (no_binario *atual){
    int contador =1;
    if (atual->direita != NULL){
        contador += conta_nos_recursivo (atual->direita);
    }
    if (atual->esquerda != NULL){
        contador += conta_nos_recursivo (atual->esquerda);
    }
    return contador;
 }
 int numero_de_nos (arvore *ponteiro_arvore){
    if (arvore *ponteiro_arvore->raiz !=NULL){
        return conta_nos_recursivo (ponteiro_arvore->raiz;
    }
    return 0;
 }
        */

//mostra a quantidade de nos nas franjas da árvore
int nos_franja_rec (no_binario * atual) {
    if (atual != NULL) {
        if (atual->direita == NULL && atual->esquerda == NULL)
            return 1;
        return nos_franja_rec(atual->direita) + nos_franja_rec(atual->esquerda);
    }
    return 0;
}

int nos_franja (arvore *ponteiro_arvore){
    if(arvore_vazia(ponteiro_arvore))
        return 0;
    return nos_franja_rec(ponteiro_arvore->raiz);
}

//mostrar o menor valor da árvore
int menor_arvore (no_binario *atual){
    if (atual->esquerda == NULL){
        return atual->info;
    }
    return menor_arvore(atual->esquerda);
}
int menor (arvore *ponteiro_arvore){
    return menor_arvore(ponteiro_arvore->raiz);
}

//soma todos os valores da arvore
int soma (no_binario *atual){
    int galho_direito, galho_esquerdo, soma_item = 0;
    if (atual != NULL){
        galho_direito = soma (atual->direita);
        galho_esquerdo = soma (atual->esquerda);
        soma_item = (atual->info) + galho_direito + galho_esquerdo;
        return soma_item;
    }
    return 0;
}

int soma_nos (arvore *ponteiro_arvore){
    return soma(ponteiro_arvore->raiz);
}

//exibir os valores em ordem decrescente
//estrutura interna
void decrescente(no_binario * atual){
    if (atual != NULL){
        decrescente(atual->direita);
        printf("%d ", atual->info);
        decrescente(atual->esquerda);
    }
}//fim da estrutura interna

//mostra ordem dos nós
void ordem_decrescente (arvore *ponteiro_arvore){
    if (arvore_vazia(ponteiro_arvore)){
        printf("A arvore esta vazia!\n");
    }else{
        decrescente(ponteiro_arvore->raiz);
    }
}

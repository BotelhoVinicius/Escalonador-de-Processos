/*!
*\file
*\brief Arquivo contendo a implementação das funções da biblioteca no.
*\author Vinicius Botelho Souza
*\date Jun 2016
*\version 1.1
*/
//LISTA_ENC
/*!
*\struct nos
*\brief Estrutura dos nós.
*/

#include <stdio.h>
#include <stdlib.h>

#include "no.h"

struct nos{
    void* dados;
    no_t *proximo;
    no_t *anterior;
};

// Cria um novo no
no_t *criaNo(void *dado)
{
    no_t *p = malloc(sizeof(no_t));

    if (p == NULL){
        perror("cria_no:");
        exit(EXIT_FAILURE);
    }

    p->dados = dado;
    p->proximo = NULL;
    p->anterior = NULL;

    return p;
}

void ligaNo (no_t *fonte, no_t *destino)
{
    if (fonte == NULL || destino == NULL){
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    fonte->proximo = destino;
    destino->anterior = fonte;
}

void desligaNo (no_t *no)
{
    if (no == NULL) {
        fprintf(stderr,"desliga_no: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    no->proximo = NULL;
    no->anterior = NULL;
}

no_t *obtemProximo (no_t *no)
{
    if (no == NULL) {
        fprintf(stderr,"obtem_proximo: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    return no->proximo;
}

no_t *obtemAnterior (no_t *no){
    if (no == NULL) {
        fprintf(stderr,"obtem_proximo: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    return no->anterior;
}

void *obtemDado (no_t *no)
{
    if (no == NULL) {
        fprintf(stderr,"obtem_dado: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    return no->dados;
}

void liberaNo(no_t *no){
    if (no != NULL) {
        no_t *temp;
        while(no){
            temp = obtemProximo(no);
            free(no);
            no = temp;
        }
    }
}

void swap_nos(no_t *fonte,no_t *destino){
    if (fonte == NULL || destino == NULL){
        fprintf(stderr,"swap_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    no_t *fonte_anterior = fonte->anterior;
    no_t *destino_proximo = destino->proximo;

    if (fonte_anterior == NULL)
        destino->anterior = NULL;
    else
        ligaNo(fonte_anterior, destino);


    if (destino_proximo == NULL)
        fonte->proximo = NULL;
    else
        ligaNo(fonte, destino_proximo);

    ligaNo(destino, fonte);
}

void desligaProximo(no_t *no){
    if (no == NULL) {
        fprintf(stderr,"desliga_proximo: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    no->proximo = NULL;
}

void desligaAnterior(no_t *no){
    if (no == NULL) {
        fprintf(stderr,"desliga_anterior: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    no->anterior = NULL;
}

no_t *copiaNo(no_t *no){
    if (no == NULL) {
        fprintf(stderr,"copiaNo: Ponteiros invalídos");
        exit(EXIT_FAILURE);
    }

    no_t* noCopiado;

    noCopiado = criaNo(obtemDado(no));
    noCopiado->anterior = no->anterior;
    noCopiado->proximo = no->proximo;

    return noCopiado;
}

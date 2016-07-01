/*!
*\file
*\brief Arquivo contendo as implementações das funções da biblioteca listaEnc.
*\author Vinicius Botelho Souza
*\date Jun 2016
*\version 1.0
*/
//LISTA_ENC
/*!
*\struct listas_enc
*\brief Estrutura que forma a lista duplamente encadeada.
*/
#include <stdio.h>
#include <stdlib.h>
#include "listaEnc.h"/**< Biblioteca referente a lista duplamente encadeada */
#include "no.h"/**< Biblioteca referente a nós */

struct listas_enc {
    no_t *cabeca;
    no_t *cauda;
    int tamanho;
};

lista_enc_t *criaListaEncadeada (void) {
    lista_enc_t *p = malloc(sizeof(lista_enc_t));

    if (p == NULL){
        perror("cria_lista_enc:");
        exit(EXIT_FAILURE);
    }

    p->cabeca = NULL;
    p->cauda = NULL;
    p->tamanho = 0;

    return p;
}

void addCauda(lista_enc_t *lista, no_t* elemento){
    if (lista == NULL || elemento == NULL){
        fprintf(stderr,"add_cauda: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    if (lista->tamanho == 0){
        lista->cauda = elemento;
        lista->cabeca = elemento;
        lista->tamanho++;
        desligaNo(elemento);
    }
   else{
        desligaNo(elemento);
        ligaNo(lista->cauda, elemento);
        lista->tamanho++;
        lista->cauda = elemento;
   }
}

void addCabeca(lista_enc_t *lista, no_t* elemento){
    if (lista == NULL || elemento == NULL){
        fprintf(stderr,"add_cauda: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    if (lista->tamanho == 0){
        lista->cauda = elemento;
        lista->cabeca = elemento;
        lista->tamanho++;
        desligaNo(elemento);
    }
    else {
        desligaNo(elemento);
        ligaNo(elemento,lista->cabeca);
        lista->cabeca = elemento;
        lista->tamanho++;
    }
}

no_t* removeElemento(lista_enc_t *lista, int pos){
    if(lista == NULL){
        fprintf(stderr,"remove_elemento: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }
    if(pos > lista->tamanho || pos < 0){
        return NULL;
    }

    no_t *no,*temp1,*temp2;
    int j = pos;

    if(!listaTamanho(lista)){
        return NULL;
    }

    no = lista->cabeca;
    if(pos == 1){
        lista->cabeca = obtemProximo(no);
        desligaNo(no);
        return no;
    }
    while(no){
        if(j == 1){
            if(temp1 != NULL){
                if(obtemProximo(temp1) == NULL){
                    desligaNo(temp2);
                    lista->cauda = temp2;
                    lista->tamanho--;
                    return temp1;
                }
                ligaNo(temp2,obtemProximo(temp1));
            }
            lista->tamanho--;
            return temp1;
        }
        temp1 = obtemProximo(no);
        temp2 = no;
        no = temp1;
        j--;
    }
    return NULL;
}

int listaPosicao(lista_enc_t *lista,void* dado){
    if(lista == NULL || dado == NULL){
        fprintf(stderr,"posicao: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    no_t* no=lista->cabeca;
    int i=1;

    do{
        if(dado == obtemDado(no)){
            return i;
        }
        no = obtemProximo(no);
        i++;
    }while(no);
    return 0;
}

int listaTamanho(lista_enc_t *lista){
    if(lista == NULL){
        fprintf(stderr,"tamanho: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }
    return lista->tamanho;
}

no_t* listaCabeca(lista_enc_t *lista){
    if(lista == NULL){
        fprintf(stderr,"lista_cabeca: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }
    if(lista->tamanho > 0){
        return lista->cabeca;
    }
    return NULL;
}

no_t* listaCauda(lista_enc_t *lista){
    if(lista == NULL){
        fprintf(stderr,"lista_cauda: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }
    if(lista->tamanho > 0){
        return lista->cauda;
    }
    return NULL;
}

void liberaLista(lista_enc_t *lista){
    free(lista);

    no_t *no = listaCabeca(lista);

    liberaNo(no);
}

void swapLista(lista_enc_t *lista,no_t *fonte,no_t *destino){
    if (lista == NULL)
    {
        fprintf(stderr, "swap_list: Invalid pointer!");
        exit(EXIT_FAILURE);
    }

    if (lista->cabeca == fonte)
        lista->cabeca = destino;

    if (lista->cauda == destino)
        lista->cauda = fonte;

    swap_nos(fonte, destino);
}

void desligaNoLista(lista_enc_t *lista, no_t* elemento){
    if (lista == NULL || elemento == NULL)
    {
        fprintf(stderr,"desliga_no_lista: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    if(elemento == lista->cabeca){
        lista->cabeca = obtemProximo(elemento);
        desligaAnterior(obtemProximo(elemento));
        desligaNo(elemento);
    }
    else if(elemento == lista->cauda){
        lista->cauda = obtemAnterior(elemento);
        desligaProximo(obtemAnterior(elemento));
        desligaNo(elemento);
    }
    else{
        ligaNo(obtemAnterior(elemento),obtemProximo(elemento));
        desligaNo(elemento);

    }
    lista->tamanho--;
}

/*!
*\file
*\brief Arquivo contendo as implementações das funções da biblioteca BubbleSort.
*\author Vinicius Botelho Souza
*\date Jun 2016
*\version 1.1
*/
#include <stdio.h>
#include <stdlib.h>

#include "no.h"
#include "listaEnc.h"
#include "escalonador.h"
#include "BubbleSort.h"

#define TRUE 1
#define FALSE 0

void bubbleSortPrioridade(lista_enc_t *lista){
    int swaped=TRUE;

    no_t *elementoUM,*elementoDOIS;
    task_t *dadoUM,*dadoDOIS;

    while(swaped){
        swaped = FALSE;

        elementoUM = listaCabeca(lista);

        while(obtemProximo(elementoUM) != NULL){
            elementoDOIS = obtemProximo(elementoUM);

            dadoUM = obtemDado(elementoUM);
            dadoDOIS = obtemDado(elementoDOIS);

            if(taskObtemPeriodo(dadoUM) > taskObtemPeriodo(dadoDOIS)){
                swapLista(lista,elementoUM,elementoDOIS);
                elementoUM = obtemProximo(elementoDOIS);
                swaped = TRUE;
            }
            else
                elementoUM = elementoDOIS;

        }
    }
}

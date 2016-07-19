/*!
*\file
*\brief Arquivo contendo os protótipos das funções da biblioteca BubbleSort.
*\author Vinicius Botelho Souza
*\date Jun 2016
*\version 1.0
*/
/*!
*\fn void bubbleSortPrioridade(lista_enc_t *lista);
*\brief Ordena uma lista em ordem de prioridade das tarefas.
*\details Caso o parâmetro de entrada seja NULL a função irá terminar a aplicação. Esta função utiliza as bibliotecas: no.h, listaEnc.h e escalonador.h.
*\param lista Lista para ser ordenada.
*\return void
*/
#ifndef BUBBLESORT_H
#define BUBBLESORT_H

void bubbleSortPrioridade(lista_enc_t *lista);

#endif // BUBBLESORT_H



/*!
*\file
*\brief Arquivo contendo a declara��o das fun��es para impress�o do diagrama do escalonador.
*\author Bruno Eduardo Ferreira
*\date Jul 2016
*\version 2.0
*/
/*!
 *\fn void taskImprimeCabecalho(lista_enc_t *listaDeID,FILE *outputTEX)
 *\brief Esta imprime o cabe�alho do arquivo .TEX do diagrama.
 *\details Caso algum dos par�metros de entrada seja NULL a fun��o termina a execu��o.
 *\param listaDeID Lista contendo as tarefas que o programa ir� escalonar.
 *\param outputTEX Arquivo de escrita do diagrama.
 *\return void
 */
 /*!
 *\fn void taskImprimeFim(lista_enc_t *listaDeID,FILE *outputTEX)
 *\brief Esta imprime o fim do arquivo .TEX do diagrama.
 *\details Caso algum dos par�metros de entrada seja NULL a fun��o termina a execu��o.
 *\param listaDeID Lista contendo as tarefas que o programa ir� escalonar.
 *\param outputTEX Arquivo de escrita do diagrama.
 *\return void
 */
 /*!
 *\fn void taskImprimeLatex(lista_enc_t *listaDeID,lista_enc_t *listaDePrioridades,int CicloAtual,FILE *outputTEX)
 *\brief Esta imprime as task's do diagrama.
 *\details Caso algum dos par�metros de entrada seja NULL a fun��o termina a execu��o.
 *\param listaDeID Lista contendo as tarefas que o programa ir� escalonar.
 *\param listaDePrioridades Lista contendo as task's escalonadas
 *\param CicloAtual Ciclo atual do escalonador
 *\param outputTEX Arquivo de escrita do diagrama.
 *\return void
 */
#include "listaEnc.h"
#include "escalonador.h"

#ifndef DIAGRAMA_H
#define DIAGRAMA_H

void taskImprimeCabecalho(lista_enc_t *listaDeID,FILE *outputTEX);

void taskImprimeFim(lista_enc_t *listaDeID,FILE *outputTEX);

void taskImprimeLatex(lista_enc_t *listaDeID,lista_enc_t *listaDePrioridades,int CicloAtual,FILE *outputTEX);

#endif // DIAGRAMA_H

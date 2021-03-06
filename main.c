/*!
*\file
*\author Vinicius Botelho Souza & Bruno Eduardo Ferreira
*\date Jul 2016
*\brief Arquivo principal do programa escalonador de processos.
*\details Este programa ir� implementar um escalonador de processos, onde os processos ser�o dados a partir de um arquivo de texto e este programa ir� gerencia-los visando executa-los na sequ�ncia correta. O Primeiro argumento � o arquivo de entrada contendo a lista de tarefas, o segundo � o arquivo de sa�da contendo o escalonamento.
*/
#include <stdio.h>
#include <stdlib.h>
#include "escalonador.h"/**< Biblioteca referente ao Escalonador */
#include "listaEnc.h"/**< Biblioteca referente a Lista Duplamente Encadeada */
#include "no.h"/**< Biblioteca referente a N�s */
#include "diagrama.h"/**< Biblioteca da impress�o do Diagrama */
//#include "testGenerator.h"

#define DEBUG

void imprimeLista(lista_enc_t* lista);

int main(int argc,char** argv)
{
    FILE *input = NULL,*output = NULL;
    lista_enc_t *listaTarefas = NULL,*listaPrioridade = NULL;
    int i;
    no_t *no;
    task_t *runningTask=NULL,*previousTask=NULL;

    input = fopen(argv[1],"r");
    if(input == NULL){
        fprintf(stderr,"Erro: Arquivo de leitura invalido.");
        exit(EXIT_FAILURE);
    }

    int HP = hiperPeriod(input);

    listaTarefas = criaListaDeTarefas(input);
    listaPrioridade = criaListaEncadeada();

    fclose(input);

    output = fopen(argv[2],"w");

    if(output != NULL)
        taskImprimeCabecalho(listaTarefas,output);
    for(i=0;i<=HP;i++){
        taskManegement(listaTarefas,listaPrioridade,&runningTask,&previousTask,i,output);
    }
    if(output != NULL){
        taskImprimeFim(listaTarefas,output);
        fclose(output);
    }

    no = listaCabeca(listaPrioridade);
    liberaNo(no);
    liberaLista(listaPrioridade);
    no = listaCabeca(listaTarefas);
    liberaNo(no);
    liberaLista(listaTarefas);

    return 0;
}

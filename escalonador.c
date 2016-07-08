/*!
*\file
*\brief Arquivo contendo a implementação das funções da biblioteca escalonador.
*\author Vinicius Botelho Souza
*\date Jun 2016
*\version 1.2
*/
/*!
*\enum TASK_STATE
*\brief Enumeração do estado possíveis da tarefa.
*/
/*!
*\struct task
*\brief Estrutura de dados da Tarefa da implementação.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escalonador.h"    /**< Biblioteca referente ao Escalonador */
#include "BubbleSort.h"     /**< Biblioteca de ordenação */

enum TASK_STATE{
    P_STOPPED=1,    /**< 1 */
    P_RUNNING,      /**< 2 */
    P_READY,        /**< 3 */
    P_BLOCKED       /**< 4 */
};

struct task{
    unsigned char   ID;                 /**< ID */
    unsigned char   periodo;            /**< Periodo */
    unsigned char   ciclo;              /**< Ciclo */
    enum TASK_STATE uc_status;          /**< Estado atual */
    unsigned char   ciclosExecutados;   /**< Ciclos Executados */
};
//CRIA LISTA DE TAREFAS
lista_enc_t* criaListaDeTarefas(FILE *fp){
    if(fp == NULL){
        fprintf(stderr,"cria_lista_de_tarefas: Ponteiro Invalido do arquivo.");
        exit(EXIT_FAILURE);
    }
    rewind(fp);

    lista_enc_t *lista;
    lista = criaListaEncadeada();

    int Ntask;

    fscanf(fp,"N;%d\n",&Ntask);
    fscanf(fp,"id;C;T\n");

    int i,ID,C,T;
    task_t *task;
    no_t *elemento;
    for(i=0;i<Ntask;i++){
        fscanf(fp,"T%d;%d;%d\n",&ID,&C,&T);
        task = criaTarefa((unsigned char)ID,(unsigned char)C,(unsigned char)T);
        elemento = criaNo((void*)task);
        addCauda(lista,elemento);
    }

    return lista;
}
//ORDENA LISTA
lista_enc_t* ordenaListaPorPrioridade(lista_enc_t* lista){
    if(lista == NULL){
        fprintf(stderr,"ordenaListaPorPrioridade: Ponteiro invalido.");
        exit(EXIT_FAILURE);
    }

    lista_enc_t* listaOrdenada = NULL;

    listaOrdenada = copiaLista(lista);

    bubbleSortPrioridade(listaOrdenada);

    return listaOrdenada;
}
//TASK FUNCTIONS:
//CRIA TAREFA
task_t* criaTarefa(unsigned char ID,unsigned char C,unsigned char T){
    task_t* task = NULL;
    task = malloc(sizeof(task_t));
    if(task == NULL){
        fprintf(stderr,"cria_tarefa: Nao foi possivel alocar memoria");
        exit(EXIT_FAILURE);
    }

    task->ID = ID;
    task->ciclo = C;
    task->periodo = T;

    return task;
}
//OBTEM_ID
unsigned char   taskObtemID(task_t* task){
    if(task == NULL){
        fprintf(stderr,"taskObtemID: Ponteiro invalido.");
        exit(EXIT_FAILURE);
    }

    return task->ID;
}
//OBTEM PERIODO
unsigned char   taskObtemPeriodo(task_t* task){
    if(task == NULL){
        fprintf(stderr,"taskObtemPeriodo: Ponteiro invalido.");
        exit(EXIT_FAILURE);
    }

    return task->periodo;
}
//OBTEM_CICLO
unsigned char   taskObtemCiclo(task_t* task){
    if(task == NULL){
        fprintf(stderr,"taskObtemCiclo: Ponteiro invalido.");
        exit(EXIT_FAILURE);
    }

    return task->ciclo;
}
//OBTEM_CICLOS_EXECUTADOS
unsigned char   taskObtemCiclosExecutados(task_t* task){
    if(task == NULL){
        fprintf(stderr,"taskObtemCiclo: Ponteiro invalido.");
        exit(EXIT_FAILURE);
    }

    return task->ciclosExecutados;
}
//CALCULA HIPERPERIODO
int hiperPeriod(FILE *fp){
    if(fp == NULL){
        fprintf(stderr,"hiper_period: Ponteiro Invalido do arquivo.");
        exit(EXIT_FAILURE);
    }

    int Ntask;

    rewind(fp);
    fscanf(fp,"N;%d\n",&Ntask);
    if(Ntask == 0){
        return 0;
    }
    fscanf(fp,"id;C;T\n");

    int i,index,C,T,HP=1;
    for(i=1;i<=Ntask;i++){
        fscanf(fp,"T%d;%d;%d\n",&index,&C,&T);
        HP = MMC(HP,T);
    }

    return HP;
}
//CALCULA MMC
int MMC(int a,int b){
    int resto,num1=a,num2=b;

    do{
        resto  = num1 % num2;
        num1 = num2;
        num2 = resto;
    }while(resto != 0);

    return (a*b)/num1;
}

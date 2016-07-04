/*!
*\file
*\brief Arquivo contendo a implementa��o das fun��es da biblioteca escalonador.
*\author Vinicius Botelho Souza
*\date Jun 2016
*\version 1.1
*/
/*!
*\enum TASK_STATE
*\brief Enumera��o do estado poss�veis da tarefa.
*/
/*!
*\struct task
*\brief Estrutura de dados da Tarefa da implementa��o.
*/

#include <stdio.h>
#include <stdlib.h>
#include "escalonador.h"/**< Biblioteca referente ao Escalonador */

enum TASK_STATE{
    P_STOPPED=1,/**< 1 */
    P_RUNNING,/**< 2 */
    P_READY,/**< 3 */
    P_BLOCKED/**< 4 */
};

struct task{
    unsigned char   prioridade;/**< Prioridade */
    unsigned char   ID;/**< ID */
    enum TASK_STATE uc_status;/**< Estado atual */
    unsigned char   periodo;/**<  */
    unsigned char   ciclo;/**<  */
    unsigned char   ciclosExecutados;/**<  */
};

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
//TASK FUNCTIONS:
unsigned char   taskObtemID(task_t* task){
    if(task == NULL){
        fprintf(stderr,"taskObtemID: Ponteiro invalido.");
        exit(EXIT_FAILURE);
    }

    return task->ID;
}
unsigned char   taskObtemPeriodo(task_t* task){
    if(task == NULL){
        fprintf(stderr,"taskObtemPeriodo: Ponteiro invalido.");
        exit(EXIT_FAILURE);
    }

    return task->periodo;
}
unsigned char   taskObtemCiclo(task_t* task){
    if(task == NULL){
        fprintf(stderr,"taskObtemCiclo: Ponteiro invalido.");
        exit(EXIT_FAILURE);
    }

    return task->ciclo;
}
unsigned char   taskObtemCiclosExecutados(task_t* task){
    if(task == NULL){
        fprintf(stderr,"taskObtemCiclo: Ponteiro invalido.");
        exit(EXIT_FAILURE);
    }

    return task->ciclosExecutados;
}

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

int MMC(int a,int b){
    int resto,num1=a,num2=b;

    do{
        resto  = num1 % num2;
        num1 = num2;
        num2 = resto;
    }while(resto != 0);

    return (a*b)/num1;
}
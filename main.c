/*!
*\file
*\author Vinicius Botelho Souza
*\date Jun 2016
*\brief Arquivo principal do programa escalonador de processos.
*\details Este programa ir� implementar um escalonador de processos, onde os processos ser�o dados a partir de um arquivo de texto e este programa ir� gerencia-los visando executa-los na sequ�ncia correta.
*/
#include <stdio.h>
#include <stdlib.h>
#include "escalonador.h"/**< Biblioteca referente ao Escalonador */
#include "listaEnc.h"/**< Biblioteca referente a Lista Duplamente Encadeada */
#include "no.h"/**< Biblioteca referente a N�s */
//#include "testGenerator.h"

#define DEBUG

void imprimeLista(lista_enc_t* lista);

int main(int argc,char** argv)
{
    FILE *input = NULL;
    lista_enc_t *listaTarefas = NULL,*listaPrioridade = NULL;

    input = fopen(argv[1],"r");
    if(input == NULL){
        fprintf(stderr,"Erro: Arquivo de leitura invalido.");
        exit(EXIT_FAILURE);
    }

    int HP = hiperPeriod(input);

    listaTarefas = criaListaDeTarefas(input);
    listaPrioridade = criaListaEncadeada();

    fclose(input);

    imprimeLista(listaTarefas);
    printf("\n");
    imprimeLista(listaPrioridade);

    int i;
    task_t *runningTask,*previousTask=NULL;
    for(i=0;i<=HP;i++){
        addTaskDoCiclo(listaTarefas,listaPrioridade,i);

        runningTask = obtemDado(listaCabeca(listaPrioridade));

        taskSetStatus(runningTask,2);
        if(previousTask == runningTask){

            if(taskIncrementaCiclos(runningTask)){
                taskSetStatus(runningTask,4);
                desligaNoLista(listaPrioridade,listaCabeca(listaPrioridade));
            #ifdef DEBUG
                printf("Ciclo: %d RUNNING_TASK: ID:%d CiclosExecutados:%d Status: %s\n",i,taskObtemID(runningTask)
                       ,taskObtemCiclosExecutados(runningTask)
                       ,"TERMINATED");
            #endif // DEBUG
            }
            else{
            #ifdef DEBUG
                printf("Ciclo: %d RUNNING_TASK: ID:%d CiclosExecutados:%d Status: %s\n",i,taskObtemID(runningTask)
                       ,taskObtemCiclosExecutados(runningTask)
                       ,"RUNNING");
            #endif // DEBUG
            }
        }
        else if(previousTask != NULL){
            if(!taskCheckTerminated(previousTask)){
                taskSetStatus(previousTask,3);
                #ifdef DEBUG
                printf("Ciclo: %d BLOCKED_TASK: ID:%d CiclosExecutados:%d Status: %s\n",i,taskObtemID(previousTask)
                       ,taskObtemCiclosExecutados(previousTask)
                       ,"BLOCKED");
                printf("Ciclo: %d RUNNING_TASK: ID:%d CiclosExecutados:%d Status: %s\n",i,taskObtemID(runningTask)
                       ,taskObtemCiclosExecutados(runningTask)
                       ,"RUNNING");
                #endif // DEBUG
            }
            if(taskIncrementaCiclos(runningTask)){
                taskSetStatus(runningTask,4);
                desligaNoLista(listaPrioridade,listaCabeca(listaPrioridade));
                #ifdef DEBUG
                printf("Ciclo: %d RUNNING_TASK: ID:%d CiclosExecutados:%d Status: %s\n",i,taskObtemID(runningTask)
                       ,taskObtemCiclosExecutados(runningTask)
                       ,"TERMINATED");
                #endif // DEBUG
            }
            else if(taskCheckTerminated(previousTask)){
                #ifdef DEBUG
                printf("Ciclo: %d RUNNING_TASK: ID:%d CiclosExecutados:%d Status: %s\n",i,taskObtemID(runningTask)
                       ,taskObtemCiclosExecutados(runningTask)
                       ,"RUNNING");
                #endif // DEBUG
            }
        }
        previousTask = runningTask;
    }

    printf("\n");
    imprimeLista(listaPrioridade);

    printf("HIPERCICLO: %d\n",HP);

    fclose(input);

    return 0;
}

void imprimeLista(lista_enc_t* lista){
    no_t* no;
    int i;

    no = listaCabeca(lista);

    printf("ANTERIOR:\tNO:\t\tPROXIMO:\tID:\tC:\tT:\tC_Exec:\n");
    for(i=0;i<listaTamanho(lista);i++){
        printf("%p\t%p\t%p\t%d\t%d\t%d\t%d\n"
                ,obtemAnterior(no)
                ,no
                ,obtemProximo(no)
                ,(int)taskObtemID(obtemDado(no))
                ,(int)taskObtemCiclo(obtemDado(no))
                ,(int)taskObtemPeriodo(obtemDado(no))
                ,(int)taskObtemCiclosExecutados(obtemDado(no)));

        no = obtemProximo(no);
    }
}

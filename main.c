/*!
*\file
*\author Vinicius Botelho Souza
*\date Jun 2016
*\brief Arquivo principal do programa escalonador de processos.
*\details Este programa ir� implementar um escalonador de processos, onde os processos ser�o dados a partir de um arquivo de texto e este programa ir� gerencia-los visando executa-los na sequ�ncia correta. O Primeiro argumento � o arquivo de entrada contendo a lista de tarefas, o segundo � o arquivo de sa�da contendo o escalonamento.
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
    FILE *input = NULL,*output = NULL;
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

    output = fopen(argv[2],"w");
    if(output == NULL){
        fprintf(stderr,"Erro: Arquivo de saida invalido.");
        exit(EXIT_FAILURE);
    }
    fprintf(output,"NT;%d\n",listaTamanho(listaTarefas));
    fprintf(output,"HP;%d\n",HP);
    fprintf(output,"C;ID;CE;S\n");

    int i;
    no_t *no;
    task_t *runningTask,*previousTask=NULL;
    for(i=0;i<=HP;i++){
        addTaskDoCiclo(listaTarefas,listaPrioridade,i);
        no = listaCabeca(listaPrioridade);

        if(no != NULL){
            runningTask = obtemDado(no);

            taskSetStatus(runningTask,2);
            fprintf(output,"%d-I;%d;%d;%d\n",i,taskObtemID(runningTask),taskObtemCiclosExecutados(runningTask),2);
        #ifdef DEBUG
            printf("Ciclo-I: %d RUNNING_TASK: ID:%d CiclosExecutados:%d Status: %s\n",i,taskObtemID(runningTask)
                        ,taskObtemCiclosExecutados(runningTask)
                        ,"RUNNING");
        #endif // DEBUG
            if(previousTask == runningTask){
                if(taskIncrementaCiclos(runningTask)){
                    taskSetStatus(runningTask,4);
                    desligaNoLista(listaPrioridade,listaCabeca(listaPrioridade));
                    fprintf(output,"%d-F;%d;%d;%d\n",i,taskObtemID(runningTask),taskObtemCiclosExecutados(runningTask),4);
                #ifdef DEBUG
                    printf("Ciclo-F: %d RUNNING_TASK: ID:%d CiclosExecutados:%d Status: %s\n",i,taskObtemID(runningTask)
                           ,taskObtemCiclosExecutados(runningTask)
                           ,"TERMINATED");
                #endif // DEBUG
                }
                else{
                    fprintf(output,"%d-F;%d;%d;%d\n",i,taskObtemID(runningTask),taskObtemCiclosExecutados(runningTask),2);
                #ifdef DEBUG
                    printf("Ciclo-F: %d RUNNING_TASK: ID:%d CiclosExecutados:%d Status: %s\n",i,taskObtemID(runningTask)
                           ,taskObtemCiclosExecutados(runningTask)
                           ,"RUNNING");
                #endif // DEBUG
                }
            }
            else if(previousTask != NULL){
                if(!taskCheckTerminated(previousTask)){
                    taskSetStatus(previousTask,3);
                    fprintf(output,"%d-I;%d;%d;%d\n",i,taskObtemID(previousTask),taskObtemCiclosExecutados(previousTask),3);
                    fprintf(output,"%d-I;%d;%d;%d\n",i,taskObtemID(runningTask),taskObtemCiclosExecutados(runningTask),2);
                #ifdef DEBUG
                    printf("Ciclo-I: %d BLOCKED_TASK: ID:%d CiclosExecutados:%d Status: %s\n",i,taskObtemID(previousTask)
                           ,taskObtemCiclosExecutados(previousTask)
                           ,"BLOCKED");
                    printf("Ciclo-I: %d RUNNING_TASK: ID:%d CiclosExecutados:%d Status: %s\n",i,taskObtemID(runningTask)
                           ,taskObtemCiclosExecutados(runningTask)
                           ,"RUNNING");
                #endif // DEBUG
                }
                if(taskIncrementaCiclos(runningTask)){
                    taskSetStatus(runningTask,4);
                    desligaNoLista(listaPrioridade,listaCabeca(listaPrioridade));
                    fprintf(output,"%d-F;%d;%d;%d\n",i,taskObtemID(runningTask),taskObtemCiclosExecutados(runningTask),4);
                #ifdef DEBUG
                    printf("Ciclo-F: %d RUNNING_TASK: ID:%d CiclosExecutados:%d Status: %s\n",i,taskObtemID(runningTask)
                           ,taskObtemCiclosExecutados(runningTask)
                           ,"TERMINATED");
                #endif // DEBUG
                }
                else if(taskCheckTerminated(previousTask)){
                    fprintf(output,"%d-F;%d;%d;%d\n",i,taskObtemID(runningTask),taskObtemCiclosExecutados(runningTask),2);
                    #ifdef DEBUG
                    printf("Ciclo-F: %d RUNNING_TASK: ID:%d CiclosExecutados:%d Status: %s\n",i,taskObtemID(runningTask)
                           ,taskObtemCiclosExecutados(runningTask)
                           ,"RUNNING");
                    #endif // DEBUG
                }
            }
            else if(i == 0){
                if(taskIncrementaCiclos(runningTask)){
                    taskSetStatus(runningTask,4);
                    desligaNoLista(listaPrioridade,listaCabeca(listaPrioridade));
                    fprintf(output,"%d-F;%d;%d;%d\n",i,taskObtemID(runningTask),taskObtemCiclosExecutados(runningTask),4);
                #ifdef DEBUG
                    printf("Ciclo-F: %d RUNNING_TASK: ID:%d CiclosExecutados:%d Status: %s\n",i,taskObtemID(runningTask)
                           ,taskObtemCiclosExecutados(runningTask)
                           ,"TERMINATED");
                #endif // DEBUG
                }
                else if(taskCheckTerminated(previousTask)){
                    fprintf(output,"%d-F;%d;%d;%d\n",i,taskObtemID(runningTask),taskObtemCiclosExecutados(runningTask),2);
                #ifdef DEBUG
                    printf("Ciclo-F: %d RUNNING_TASK: ID:%d CiclosExecutados:%d Status: %s\n",i,taskObtemID(runningTask)
                           ,taskObtemCiclosExecutados(runningTask)
                           ,"RUNNING");
                #endif // DEBUG
                }
            }

        }
        previousTask = runningTask;
    }
    printf("\n");
    imprimeLista(listaPrioridade);

    printf("HIPERCICLO: %d\n",HP);

    fclose(output);

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

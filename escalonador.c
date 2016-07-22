/*!
*\file
*\brief Arquivo contendo a implementação das funções da biblioteca escalonador.
*\author Vinicius Botelho Souza
*\date Jul 2016
*\version 1.5
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
#include "diagrama.h"

enum TASK_STATE{
    P_READY=1,  /**< 1 */
    P_RUNNING,  /**< 2 */
    P_BLOCKED,  /**< 3 */
    P_TERMINATED/**< 4 */
};

struct task{
    unsigned char   ID;                 /**< ID */
    unsigned char   periodo;            /**< Periodo */
    unsigned char   ciclo;              /**< Ciclo */
    enum TASK_STATE status;             /**< Estado atual */
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
        task            = criaTarefa((unsigned char)ID,(unsigned char)C,(unsigned char)T);
        task->status    = 1;
        elemento        = criaNo((void*)task);
        addCauda(lista,elemento);
    }

    return lista;
}
//FAZ O ESCALONAMENTO DAS TAREFAS
void taskManegement(lista_enc_t* listaTarefas,lista_enc_t* listaPrioridade,task_t** runningTask,task_t** previousTask,int cicloAtual,FILE *outputTEX){
    if(listaTarefas == NULL || listaPrioridade == NULL){
        fprintf(stderr,"taskManegement: Ponteiro Invalido do arquivo.");
        exit(EXIT_FAILURE);
    }
    no_t* no;

    addTaskDoCiclo(listaTarefas,listaPrioridade,cicloAtual);
    no = listaCabeca(listaPrioridade);

    if(no != NULL){
        *runningTask = (task_t*)obtemDado(no);

        taskSetStatus(*runningTask,2);
        if(*previousTask == *runningTask){
            if(taskIncrementaCiclos(*runningTask)){
                taskSetStatus(*runningTask,4);
                if(outputTEX != NULL)
                    taskImprimeLatex(listaTarefas,listaPrioridade,cicloAtual,outputTEX);
                desligaNoLista(listaPrioridade,listaCabeca(listaPrioridade));
                free(no);
            }
            else{
                if(outputTEX != NULL)
                    taskImprimeLatex(listaTarefas,listaPrioridade,cicloAtual,outputTEX);
            }
        }
        else if(*previousTask != NULL){
            if(!taskCheckTerminated(*previousTask)){
                taskSetStatus(*previousTask,3);
            }
            if(taskIncrementaCiclos(*runningTask)){
                taskSetStatus(*runningTask,4);
                if(outputTEX != NULL)
                    taskImprimeLatex(listaTarefas,listaPrioridade,cicloAtual,outputTEX);
                desligaNoLista(listaPrioridade,listaCabeca(listaPrioridade));
                free(no);
            }
            else{
                if(outputTEX != NULL)
                    taskImprimeLatex(listaTarefas,listaPrioridade,cicloAtual,outputTEX);
            }
        }
        else if(cicloAtual == 0){
            if(taskIncrementaCiclos(*runningTask)){
                taskSetStatus(*runningTask,4);
                if(outputTEX != NULL)
                    taskImprimeLatex(listaTarefas,listaPrioridade,cicloAtual,outputTEX);
                desligaNoLista(listaPrioridade,listaCabeca(listaPrioridade));
                free(no);
            }
            else{
                if(outputTEX != NULL)
                    taskImprimeLatex(listaTarefas,listaPrioridade,cicloAtual,outputTEX);
            }
        }
    }
    *previousTask = *runningTask;
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
//SET_STATUS
void taskSetStatus(task_t* task,int status){
    if(task == NULL){
        fprintf(stderr,"taskSetStatus: Ponteiro invalido.");
        exit(EXIT_FAILURE);
    }
    if(!(status >= 1 || status <= 4)){
        fprintf(stderr,"taskSetStatus: Status invalido.");
        exit(EXIT_FAILURE);
    }

    task->status = status;
}
//INCREMENTA_CICLOS
int taskIncrementaCiclos(task_t* task){
    if(task == NULL){
        fprintf(stderr,"taskSetStatus: Ponteiro invalido.");
        exit(EXIT_FAILURE);
    }

    task->ciclosExecutados++;

    if(task->ciclosExecutados >= task->ciclo){
        return 1;
    }
    else{
        return 0;
    }

}
//CHECK_TERMINATED
int taskCheckTerminated(task_t* task){
    if(task == NULL){
        fprintf(stderr,"taskSetStatus: Ponteiro invalido.");
        exit(EXIT_FAILURE);
    }

    if(task->status == 4){
        return 1;
    }
    else{
        return 0;
    }
}
//ADD_TAREFA_DO_CICLO
void addTaskDoCiclo(lista_enc_t* listaDeID,lista_enc_t* listaDeTarefas,int CicloAtual){
    if(listaDeID == NULL || listaDeTarefas == NULL){
        fprintf(stderr,"addTaskDoCiclo: Ponteiro invalido.");
        exit(EXIT_FAILURE);
    }
    no_t* elemento = listaCabeca(listaDeID);

    while(elemento != NULL){
        if(CicloAtual%(taskObtemPeriodo(obtemDado(elemento))) == 0){
            task_t* tarefa = obtemDado(elemento);
            task_t* tarefaParaAdicionar = malloc(sizeof(task_t));
            no_t*   no = NULL;

            tarefaParaAdicionar->ID         = tarefa->ID;
            tarefaParaAdicionar->ciclo      = tarefa->ciclo;
            tarefaParaAdicionar->periodo    = tarefa->periodo;
            tarefaParaAdicionar->status     = 1;
            tarefaParaAdicionar->ciclosExecutados = 0;

            no = criaNo((void*)tarefaParaAdicionar);

            taskInsertion(listaDeTarefas,no);
        }
        elemento = obtemProximo(elemento);
    }
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

void taskInsertion(lista_enc_t *lista,no_t *elemento){
    if(lista == NULL || elemento == NULL){
        fprintf(stderr,"binarySearch: Ponteiro invalido.");
        exit(EXIT_FAILURE);
    }

    no_t* no;
    no = listaCabeca(lista);

    while(no){
        if(taskObtemCiclo(obtemDado(elemento)) < taskObtemCiclo(obtemDado(no))){
            intercalaElemento(lista,obtemAnterior(no),no,elemento);
            break;
        }
        no = obtemProximo(no);
    }
    if(no==NULL){
        addCauda(lista,elemento);
    }

}

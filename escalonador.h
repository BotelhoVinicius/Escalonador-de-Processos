/*!
*\file
*\brief Arquivo contendo os prot�tipos das fun��es da biblioteca escalonador.
*\author Vinicius Botelho Souza
*\date Jun 2016
*\version 1.3
*/
//STRUCT
/*!
*\typedef struct task task_t
*\brief Estrutura de dados din�micos da Tarefa.
*/
//CRIA_LISTA_DE_TAREFAS
/*!
*\fn lista_enc_t* criaListaDeTarefas(FILE *fp);
*\brief Adiciona todas as tarefas presentes no arquivo de entrada na lista por ordem de ID.
*\details Caso o par�metro de entrada seja NULL a fun��o ir� terminar a aplica��o. Esta fun��o utiliza as bibliotecas: no.h e listaEnc.h. Exemplo de arquivo:
*\code
 N;10
 id;C;T
 T1;3;7
 T2;2;7
 T3;1;5
 T4;1;3
 T5;2;6
 T6;1;4
 T7;2;9
 T8;2;10
 T9;5;20
 T10;3;8
*\endcode
*\param fp Arquivo de entrada.
*\return lista_enc_t* - Lista contendo as tarefas.
*/
//FAZ O ESCALONAMENTO DAS TAREFAS
/*!
*\fn void taskManegement(lista_enc_t* listaTarefas,lista_enc_t* listaPrioridade,task_t** runningTask,task_t** previousTask,int cicloAtual)
*\brief Esta fun��o o escalonamento das tarefas.
*\details O escalonamento se dar� por um loop incrementando o ciclo atual e chamando est� fun��o, mas para funcionar corretamente a contagem dos ciclos precisa ser continua nos inteiros. Caso um destes parametros forem nulos o programa encerrar� a execu��o
*\param listaTarefas - Lista contendo todas as tarefas.
*\param listaPrioridade - Lista contendo tarefas em execu��o e bloqueadas.
*\param runningTask - Tafera atualmente rodando.
*\param previousTask - Tarefa que executou no ciclo anterior.
*\param cicloAtual - Ciclo de execu��o atual.
*\return void
*/
//CRIA_TAREFA
/*!
*\fn task_t* criaTarefa(unsigned char ID,unsigned char C,unsigned char T)
*\brief Esta fun��o cria uma tarefa baseado na estrutura task.
*\details Cria uma tarefa com as entradas do ID da tarefa, do ciclo C da tarefa e o periodo T da tarefa.
*\param ID da tarefa.
*\param C Ciclo da tarefa.
*\param T Periodo da tarefa.
*\return task_t* - Endere�o da tarefa.
*/
//OBTEM_ID
/*!
*\fn unsigned char taskObtemID(task_t* task)
*\brief Esta fun��o obtem o ID da tarefa.
*\details Caso o parametro de entrada seja NULL a fun��o ir� terminar a aplica��o.
*\param task Tarefa o qual deseja-se obter o ID.
*\return unsigned char - ID da tarefa.
*/
//OBTEM_PERIODO
/*!
*\fn unsigned char taskObtemPeriodo(task_t* task)
*\brief Esta fun��o obtem o periodo T da tarefa.
*\details Caso o parametro de entrada seja NULL a fun��o ir� terminar a aplica��o.
*\param task Tarefa o qual deseja-se obter o periodo T.
*\return unsigned char - Periodo da tarefa.
*/
//OBTEM_CICLO
/*!
*\fn unsigned char taskObtemCiclo(task_t* task)
*\brief Esta fun��o obtem o ciclo C da tarefa.
*\details Caso o parametro de entrada seja NULL a fun��o ir� terminar a aplica��o.
*\param task Tarefa o qual deseja-se obter o ciclo C.
*\return unsigned char - Ciclo da tarefa.
*/
//OBTEM_EXECUTADOS
/*!
*\fn unsigned char taskObtemCiclosExecutados(task_t* task)
*\brief Esta fun��o obtem o numero de ciclos executados da tarefa.
*\details Caso o parametro de entrada seja NULL a fun��o ir� terminar a aplica��o.
*\param task Tarefa o qual deseja-se obter o numero de ciclos executados.
*\return unsigned char - numero de ciclos executados da tarefa.
*/
//CONFIGURA O STATUS ATUAL DA TASK
/*!
*\fn void taskSetStatus(task_t* task,int status);
*\brief Esta fun��o confugura o status atual de uma tarefa.
*\details Caso o parametro de entrada seja NULL a fun��o ir� terminar a aplica��o.
*\param task Tarefa o qual deseja-se configurar o status.
*\param status Status o qual deseja alterar
*\return void
*/
//INCREMENTA CICLOS
/*!
*\fn int taskIncrementaCiclos(task_t* task)
*\brief Esta fun��o incrementa os ciclos de uma tarefa.
*\details Caso o parametro de entrada seja NULL a fun��o ir� terminar a aplica��o.
*\param task Tarefa o qual deseja-se incrementar o ciclo executado.
*\return int - Retorna 1 em caso de os ciclos executados serem igual ao numero de execu��o de ciclo da tarefa e 0 em caso contrario.
*/
//CHECAGEM DE TERMINO
/*!
*\fn int taskCheckTerminated(task_t* task)
*\brief Esta fun��o verifica se a tarefa foi terminada.
*\details Caso o parametro de entrada seja NULL a fun��o ir� terminar a aplica��o.
*\param task Tarefa o qual deseja-se fazer a verifica��o.
*\return int - Retorna 1 em caso de sim e 0 em caso de n�o.
*/
//ADD TASK DO CICLO
/*!
*\fn void addTaskDoCiclo(lista_enc_t* listaDeID,lista_enc_t* listaDeTarefas,int CicloAtual)
*\brief Esta fun��o adiciona todas as tarefas que devem ser adicionadas no ciclo atual de execu��o.
*\details Caso o parametro de entrada seja NULL a fun��o ir� terminar a aplica��o.
*\param listaDeID Lista contendo todas as tarefas.
*\param listaDeTarefas Lista do escalonamento.
*\param CicloAtual Ciclo atual de execu��o.
*\return void
*/
//CALCULA_HIPER_PERIODO
/*!
*\fn int hiperPeriod(FILE *fp)
*\brief Esta fun��o obtem o hiper-periodo da tarefa ( periodo de ciclos que o escalonamento se repete ).
*\details Caso o par�metro de entrada seja NULL a fun��o ir� terminar a aplica��o. Exemplo de Arquivo de Entrada:
*\code
 N;10
 id;C;T
 T1;3;7
 T2;2;7
 T3;1;5
 T4;1;3
 T5;2;6
 T6;1;4
 T7;2;9
 T8;2;10
 T9;5;20
 T10;3;8
*\endcode
*\param fp Arquivo de entrada.
*\return int - Hiper-periodo da tarefa.
*/
//MMC
/*!
*\fn int MMC(int a,int b);
*\brief Esta fun��o calcula o minimo multiplo comum.
*\details Esta func�o � utilizada pela fun��o do hiper-periodo para calcular o mesmo.
*\return int - Minimo multiplo entre "a" e "b".
*/
//TASK_INSERTION
/*!
*\fn void taskInsertion(lista_enc_t *lista,no_t *elemento);
*\brief Esta fun��o faz a inser��o de uma tarefa na lista.
*\details Inser��o de uma tarefa na lista, j� ordenando a mesma por prioridade. Se algum dos par�metros forem nulos o programa encerra a execu��o.
*\param lista - Lista para a tarefa ser inserida.
*\param elemento - N� j� criado com a task a ser inserida.
*\return void
*/

#include "listaEnc.h"

#ifndef ESCALONADOR_H
#define ESCALONADOR

typedef struct  task task_t;

lista_enc_t*    criaListaDeTarefas(FILE *fp);
void            taskManegement(lista_enc_t* listaTarefas,lista_enc_t* listaPrioridade,task_t** runningTask,task_t** previousTask,int cicloAtual);

//TASK FUNCTIONS:
task_t*         criaTarefa(unsigned char ID,unsigned char C,unsigned char T);
unsigned char   taskObtemID(task_t* task);
unsigned char   taskObtemPeriodo(task_t* task);
unsigned char   taskObtemCiclo(task_t* task);
unsigned char   taskObtemCiclosExecutados(task_t* task);
void            taskSetStatus(task_t* task,int status);
int             taskIncrementaCiclos(task_t* task);
int             taskCheckTerminated(task_t* task);
void            addTaskDoCiclo(lista_enc_t* listaDeID,lista_enc_t* listaDeTarefas,int CicloAtual);

//USEFUL FUNCTIONS:
int             hiperPeriod(FILE *fp);
int             MMC(int a,int b);
void            taskInsertion(lista_enc_t *lista,no_t *elemento);

#endif // ESCALONADOR_H

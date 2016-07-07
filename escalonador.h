/*!
*\file
*\brief Arquivo contendo os protótipos das funções da biblioteca escalonador.
*\author Vinicius Botelho Souza
*\date Jun 2016
*\version 1.1
*/
//STRUCT
/*!
*\typedef struct task task_t
*\brief Estrutura de dados dinâmicos da Tarefa.
*/
//CRIA_LISTA_DE_TAREFAS
/*!
*\fn lista_enc_t* criaListaDeTarefas(FILE *fp);
*\brief Adiciona todas as tarefas presentes no arquivo de entrada na lista por ordem de ID.
*\details Caso o parâmetro de entrada seja NULL a função irá terminar a aplicação. Esta função utiliza as bibliotecas: no.h e listaEnc.h. Exemplo de arquivo:
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
//CRIA_TAREFA
/*!
*\fn task_t* criaTarefa(unsigned char ID,unsigned char C,unsigned char T)
*\brief Esta função cria uma tarefa baseado na estrutura task.
*\details Cria uma tarefa com as entradas do ID da tarefa, do ciclo C da tarefa e o periodo T da tarefa.
*\param ID da tarefa.
*\param C Ciclo da tarefa.
*\param T Periodo da tarefa.
*\return task_t* - Endereço da tarefa.
*/
//OBTEM_ID
/*!
*\fn unsigned char taskObtemID(task_t* task)
*\brief Esta função obtem o ID da tarefa.
*\details Caso o parametro de entrada seja NULL a função irá terminar a aplicação.
*\param task Tarefa o qual deseja-se obter o ID.
*\return unsigned char - ID da tarefa.
*/
//OBTEM_PERIODO
/*!
*\fn unsigned char taskObtemPeriodo(task_t* task)
*\brief Esta função obtem o periodo T da tarefa.
*\details Caso o parametro de entrada seja NULL a função irá terminar a aplicação.
*\param task Tarefa o qual deseja-se obter o periodo T.
*\return unsigned char - Periodo da tarefa.
*/
//OBTEM_CICLO
/*!
*\fn unsigned char taskObtemCiclo(task_t* task)
*\brief Esta função obtem o ciclo C da tarefa.
*\details Caso o parametro de entrada seja NULL a função irá terminar a aplicação.
*\param task Tarefa o qual deseja-se obter o ciclo C.
*\return unsigned char - Ciclo da tarefa.
*/
//OBTEM_EXECUTADOS
/*!
*\fn unsigned char taskObtemCiclosExecutados(task_t* task)
*\brief Esta função obtem o numero de ciclos executados da tarefa.
*\details Caso o parametro de entrada seja NULL a função irá terminar a aplicação.
*\param task Tarefa o qual deseja-se obter o numero de ciclos executados.
*\return unsigned char - numero de ciclos executados da tarefa.
*/
//CALCULA_HIPER_PERIODO
/*!
*\fn int hiperPeriod(FILE *fp)
*\brief Esta função obtem o hiper-periodo da tarefa ( periodo de ciclos que o escalonamento se repete ).
*\details Caso o parâmetro de entrada seja NULL a função irá terminar a aplicação. Exemplo de Arquivo de Entrada:
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
*\brief Esta função calcula o minimo multiplo comum.
*\details Esta funcão é utilizada pela função do hiper-periodo para calcular o mesmo.
*\return int - Minimo multiplo entre "a" e "b".
*/
#include "listaEnc.h"

#ifndef ESCALONADOR_H
#define ESCALONADOR_H

typedef struct  task task_t;

lista_enc_t*    criaListaDeTarefas(FILE *fp);

//TASK FUNCTIONS:
task_t*         criaTarefa(unsigned char ID,unsigned char C,unsigned char T);
unsigned char   taskObtemID(task_t* task);
unsigned char   taskObtemPeriodo(task_t* task);
unsigned char   taskObtemCiclo(task_t* task);
unsigned char   taskObtemCiclosExecutados(task_t* task);

//USEFUL FUNCTIONS:
int             hiperPeriod(FILE *fp);
int             MMC(int a,int b);

#endif // ESCALONADOR_H

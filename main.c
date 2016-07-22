/*!
*\file
*\author Vinicius Botelho Souza & Bruno Eduardo Ferreira
*\date Jul 2016
*\brief Arquivo principal do programa escalonador de processos.
*\details Este programa irá implementar um escalonador de processos, onde os processos serão dados a partir de um arquivo de texto e este programa irá gerencia-los visando executa-los na sequência correta. O Primeiro argumento é o arquivo de entrada contendo a lista de tarefas, o segundo é o arquivo de saída contendo o escalonamento.
*/
#include <stdio.h>
#include <stdlib.h>
#include "escalonador.h"/**< Biblioteca referente ao Escalonador */
#include "listaEnc.h"/**< Biblioteca referente a Lista Duplamente Encadeada */
#include "no.h"/**< Biblioteca referente a Nós */
#include "diagrama.h"/**< Biblioteca da impressão do Diagrama */
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
    if(output == NULL){
        fprintf(stderr,"Erro: Arquivo de saida invalido.");
        exit(EXIT_FAILURE);
    }

    taskImprimeCabecalho(listaTarefas,output);
    for(i=0;i<=HP;i++){
        taskManegement(listaTarefas,listaPrioridade,&runningTask,&previousTask,i,output);
    }
    taskImprimeFim(listaTarefas,output);

    fclose(output);

    no = listaCabeca(listaPrioridade);
    liberaNo(no);
    liberaLista(listaPrioridade);
    no = listaCabeca(listaTarefas);
    liberaNo(no);
    liberaLista(listaTarefas);

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
    printf("\n\n");
}

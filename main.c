/*!
*\file
*\author Vinicius Botelho Souza
*\date Jun 2016
*\brief Arquivo principal do programa escalonador de processos.
*\details Este programa irá implementar um escalonador de processos, onde os processos serão dados a partir de um arquivo de texto e este programa irá gerencia-los visando executa-los na sequência correta.
*/
#include <stdio.h>
#include <stdlib.h>
#include "escalonador.h"/**< Biblioteca referente ao Escalonador */
#include "listaEnc.h"/**< Biblioteca referente a Lista Duplamente Encadeada */
#include "no.h"/**< Biblioteca referente a Nós */
#include "diagrama.h"

void imprimeLista(lista_enc_t* lista);

int main(int argc,char** argv)
{
    FILE *input = NULL;
    lista_enc_t *lista = NULL;

    input = fopen(argv[1],"r");
    if(input == NULL){
        fprintf(stderr,"Erro: Arquivo de leitura invalido.");
        exit(EXIT_FAILURE);
    }

    int HP = hiperPeriod(input);

    lista = criaListaDeTarefas(input);

    imprimeLista(lista);

    taskImprimeLatex(lista);

    fclose(input);

    return 0;
}

void imprimeLista(lista_enc_t* lista){
    no_t* no;
    int i;

    no = listaCabeca(lista);

    printf("ANTERIOR:\tNO:\t\tPROXIMO:\tID:\tC:\tT:\n");
    for(i=0;i<listaTamanho(lista);i++){
        printf("%p\t%p\t%p\t%d\t%d\t%d\n"
                ,obtemAnterior(no)
                ,no
                ,obtemProximo(no)
                ,(int)taskObtemID(obtemDado(no))
                ,(int)taskObtemCiclo(obtemDado(no))
                ,(int)taskObtemPeriodo(obtemDado(no)));

        no = obtemProximo(no);
    }
}

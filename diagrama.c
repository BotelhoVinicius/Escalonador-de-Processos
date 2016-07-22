/*!
*\file
*\brief Arquivo contendo a implementação das funções para impressão do diagrama do escalonador.
*\author Bruno Eduardo Ferreira
*\date Jul 2016
*\version 2.1
*/

#include <stdio.h>
#include <stdlib.h>
#include "diagrama.h"
#include "listaEnc.h"
#include "escalonador.h"

#define CICLO_MAX 70

void taskImprimeCabecalho(lista_enc_t *listaDeID,FILE *outputTEX){
    if(outputTEX == NULL || listaDeID == NULL){
        fprintf(stderr,"taskImprimeCabecalho: Ponteiro Invalido do arquivo.");
        exit(EXIT_FAILURE);
    }

    int nperiodos=0;

    fprintf(outputTEX,"%s\n%s\n%s\n\n","\\documentclass[a4paper,10pt]{article}","\\usepackage[utf8]{inputenc}","\\usepackage[brazil]{babel}");
    fprintf(outputTEX,"%s\n%s\n%s\n%s\n%s\n","\\usepackage{xcolor}","\\usepackage{listings}","\\usepackage{listingsutf8}","\\usepackage{rtsched}","\\usepackage{pdflscape}");
    fprintf(outputTEX,"%s\n%s\n%s\n\n%s\n\n","\\title{Diagrama de execucao}","\\author{Bruno Eduardo Ferreira","   \\\\Vinicius Botelho Souza}","\\begin{document}");
    fprintf(outputTEX,"%s\n","\\maketitle");
    fprintf(outputTEX,"\\definecolor{1}{rgb}{0.0, 0.0, 0.5}\n\\definecolor{2}{rgb}{0.0, 0.5, 0.0}\n\\definecolor{3}{rgb}{0.0, 0.0, 1.0}\n");
    fprintf(outputTEX,"\\definecolor{4}{rgb}{0.55, 0.71, 0.0}\n\\definecolor{5}{rgb}{0.36, 0.54, 0.66}\n\\definecolor{6}{rgb}{0.53, 0.66, 0.42}\n");
    fprintf(outputTEX,"\\definecolor{7}{rgb}{0.03, 0.91, 0.87}\n\\definecolor{8}{rgb}{0.4, 1.0, 0.0}\n\\definecolor{9}{rgb}{0.0, 0.75, 1.0}\n\\definecolor{10}{rgb}{0.0, 0.26, 0.15}\n");
    fprintf(outputTEX,"%s\n%s\n%s\n\n","\\begin{landscape}","\\begin{figure}[h]","  \\centering");
    fprintf(outputTEX,"\\begin{flushleft}\n  \\begin{RTGrid}[nosymbols=1,width=20cm,numoffset=0]{%d}{%d}\n", listaTamanho(listaDeID)+1, CICLO_MAX);

    no_t *no = listaCabeca(listaDeID);
    while(no){
        fprintf(outputTEX,"\\RowLabel{%d}{$\\tau_%d$}\n", (int)taskObtemID(obtemDado(no)), (int)taskObtemID(obtemDado(no)));
        nperiodos = CICLO_MAX/(int)taskObtemPeriodo(obtemDado(no))+1;
        fprintf(outputTEX,"\\TaskNArrival{%d}{%d}{%d}{%d}\n", (int)taskObtemID(obtemDado(no)), 0, (int)taskObtemPeriodo(obtemDado(no)), nperiodos); //{linha}{inicio}{periodo}{repetições}
        no = obtemProximo(no);
    }
    fprintf(outputTEX,"\\RowLabel{%d}{CPU}\n", listaTamanho(listaDeID)+1);
}

void taskImprimeFim(lista_enc_t *listaDeID,FILE *outputTEX){
    if(outputTEX == NULL || listaDeID == NULL){
        fprintf(stderr,"taskImprimeFim: Ponteiro Invalido do arquivo.");
        exit(EXIT_FAILURE);
    }

    fprintf(outputTEX,"%s\n%s\n%s\n%s\n","  \\end{RTGrid}","\\end{flushleft}","\\caption{Escalonador para ate 10 tarefas}","\\label{fig:ex1}");
    fprintf(outputTEX,"%s\n%s\n","\\end{figure}","\\end{landscape}");
    fprintf(outputTEX,"%s\n","\\end{document}");
}

void taskImprimeQuebraPagina(lista_enc_t *listaDeID,FILE *outputTEX,int CicloAtual){
    if(outputTEX == NULL || listaDeID == NULL){
        fprintf(stderr,"taskImprimeQuebraPagina: Ponteiro Invalido do arquivo.");
        exit(EXIT_FAILURE);
    }
    int nperiodos=0;

    fprintf(outputTEX,"%s\n%s\n%s\n%s\n","  \\end{RTGrid}","\\end{flushleft}","\\caption{Escalonador para ate 10 tarefas}","\\label{fig:ex1}");
    fprintf(outputTEX,"%s\n%s\n","\\end{figure}","\\end{landscape}");
    fprintf(outputTEX,"%s\n%s\n%s\n\n","\\begin{landscape}","\\begin{figure}[h]","  \\centering");
    fprintf(outputTEX,"\\begin{flushleft}\n  \\begin{RTGrid}[nosymbols=1,width=20cm,numoffset=%d]{%d}{%d}\n",CICLO_MAX*(CicloAtual/CICLO_MAX), listaTamanho(listaDeID)+1, CICLO_MAX);
    no_t *no = listaCabeca(listaDeID);
    while(no){
        fprintf(outputTEX,"\\RowLabel{%d}{$\\tau_%d$}\n", (int)taskObtemID(obtemDado(no)), (int)taskObtemID(obtemDado(no)));
        nperiodos = CICLO_MAX/(int)taskObtemPeriodo(obtemDado(no))+1;
        fprintf(outputTEX,"\\TaskNArrival{%d}{%d}{%d}{%d}\n", (int)taskObtemID(obtemDado(no)), 0, (int)taskObtemPeriodo(obtemDado(no)), nperiodos); //{linha}{inicio}{periodo}{repetições}
        no = obtemProximo(no);
    }
}

void taskImprimeLatex(lista_enc_t *listaDeID,lista_enc_t *listaDePrioridades,int CicloAtual,FILE *outputTEX){
    if(listaDeID == NULL || listaDePrioridades == NULL){
        fprintf(stderr,"taskImprimeLatex: Ponteiro Invalido do arquivo.");
        exit(EXIT_FAILURE);
    }

    no_t* no;
    no = listaCabeca(listaDePrioridades);
    if(!(CicloAtual%70) && CicloAtual != 0){
        taskImprimeQuebraPagina(listaDeID,outputTEX,CicloAtual);
    }
    if(no != NULL && outputTEX != NULL){
        fprintf(outputTEX,"\\TaskExecution[color=%d]{%d}{%d}{%d}\n", (int)taskObtemID((task_t*)obtemDado(no))
                ,(int)taskObtemID((task_t*)obtemDado(no))
                , CicloAtual - CICLO_MAX*(CicloAtual/CICLO_MAX)
                , CicloAtual - CICLO_MAX*(CicloAtual/CICLO_MAX) +1);//{linha}{inicio}{fim}

        fprintf(outputTEX,"\\TaskExecution[color=%d]{%d}{%d}{%d}\n", (int)taskObtemID((task_t*)obtemDado(no))
                , listaTamanho(listaDeID)+1
                , CicloAtual - CICLO_MAX*(CicloAtual/CICLO_MAX)
                , CicloAtual - CICLO_MAX*(CicloAtual/CICLO_MAX) +1);//{linha}{inicio}{fim}
    }
}


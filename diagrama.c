#include <stdio.h>
#include <stdlib.h>
#include "diagrama.h"
#include "listaEnc.h"

void taskImprimeLatex(lista_enc_t *lista){

    no_t* no;
    int i, j, periodo=0, nperiodos=0;

    no = listaCabeca(lista);

    FILE * fp;

    fp = fopen ("TESTE.tex","w");

    if (fp == NULL)
        exit(1);
    fprintf(fp,"%s\n%s\n%s\n\n","\\documentclass[a4paper,10pt]{article}","\\usepackage[utf8]{inputenc}","\\usepackage[brazil]{babel}");
    fprintf(fp,"%s\n%s\n%s\n\n","\\usepackage{listings}","\\usepackage{listingsutf8}","\\usepackage{rtsched}");
    fprintf(fp,"%s\n%s\n%s\n\n%s\n\n","\\title{Diagrama de execucao}","\\author{Bruno Eduardo Ferreira","   \\\\Vinicius Botelho Souza}","\\begin{document}");
    fprintf(fp,"%s\n\n%s\n%s\n\n","\\maketitle","\\begin{figure}[h]","  \\centering");
    fprintf(fp,"  \\begin{RTGrid}[nosymbols=1,width=10cm]{%d}{30}\n", listaTamanho(lista));
    for(i=0; i < listaTamanho(lista) ;i++){

        fprintf(fp,"\\RowLabel{%d}{$\\tau_%d$}\n", (int)taskObtemID(obtemDado(no)), (int)taskObtemID(obtemDado(no)));

        nperiodos = 30/(int)taskObtemPeriodo(obtemDado(no));

        for(j=0; j < nperiodos; j++){

            fprintf(fp,"\\TaskArrival{%d}{%d}\n", (int)taskObtemID(obtemDado(no)), periodo);

            periodo = periodo + (int)taskObtemPeriodo(obtemDado(no));
        }
        j = 0;
        periodo = 0;

        for(j=0; j < nperiodos; j++){

            fprintf(fp,"\\TaskExecution{%d}{%d}{%d}\n", (int)taskObtemID(obtemDado(no)), periodo, (int)taskObtemCiclo(obtemDado(no)) + periodo);

            periodo = periodo + (int)taskObtemPeriodo(obtemDado(no));

        }
        fprintf(fp,"\n");

        nperiodos = 0;
        periodo = 0;

        no = obtemProximo(no);

    }
    fprintf(fp,"%s\n%s\n%s\n","  \\end{RTGrid}","\\caption{Escalonador para ate 10 tarefas}","\\label{fig:ex1}");
    fprintf(fp,"%s\n%s\n","\\end{figure}","\\end{document}");
    fclose(fp);
}

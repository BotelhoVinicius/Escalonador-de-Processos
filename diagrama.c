#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "diagrama.h"
#include "listaEnc.h"
#include "escalonador.h"

#define LATEX 70

void taskImprimeLatex(lista_enc_t *lista){

    no_t* no;

    int nperiodos=0;

    int i, j, NT, HP, C, ID, CE, S;
    char CS;

    no = listaCabeca(lista);

    FILE *fp, *diagramfile;
    diagramfile = fopen("output.txt","r");
    fp = fopen ("TESTE.tex","w");

    fscanf(diagramfile,"NT;%d\n",&NT);
    fscanf(diagramfile,"HP;%d\n",&HP);
    fscanf(diagramfile,"C;ID;CE;S\n");

    if (fp == NULL)
        exit(1);
    fprintf(fp,"%s\n%s\n%s\n\n","\\documentclass[a4paper,10pt]{article}","\\usepackage[utf8]{inputenc}","\\usepackage[brazil]{babel}");
    fprintf(fp,"%s\n%s\n%s\n%s\n","\\usepackage{listings}","\\usepackage{listingsutf8}","\\usepackage{rtsched}","\\usepackage{pdflscape}");
    fprintf(fp,"%s\n%s\n%s\n\n%s\n\n","\\title{Diagrama de execucao}","\\author{Bruno Eduardo Ferreira","   \\\\Vinicius Botelho Souza}","\\begin{document}");
    fprintf(fp,"%s\n\n%s\n%s\n%s\n\n","\\maketitle","\\begin{landscape}","\\begin{figure}[h]","  \\centering");
    fprintf(fp,"  \\begin{RTGrid}[nosymbols=1,width=20cm]{%d}{%d}\n", listaTamanho(lista), LATEX);


    for(i=0; i < listaTamanho(lista); i++){

        fprintf(fp,"\\RowLabel{%d}{$\\tau_%d$}\n", (int)taskObtemID(obtemDado(no)), (int)taskObtemID(obtemDado(no)));

        nperiodos = LATEX/(int)taskObtemPeriodo(obtemDado(no))+1;

        fprintf(fp,"\\TaskNArrival{%d}{%d}{%d}{%d}\n", (int)taskObtemID(obtemDado(no)), 0, (int)taskObtemPeriodo(obtemDado(no)), nperiodos); //{linha}{inicio}{periodo}{repetições}

        while(C != HP){

            fscanf(diagramfile,"%d-%c;%d;%d;%d\n", &C, &CS, &ID, &CE, &S);

            if(S != 3 && C < LATEX)
                fprintf(fp,"\\TaskExecution{%d}{%d}{%d}\n", ID, C, C+1);//{linha}{inicio}{fim}
        }

        printf("\n");

        no = obtemProximo(no);
    }
 //   fprintf(fp,"\\RowLabel{%d}{CPU}\n", (int)taskObtemID(obtemDado(no))+1);
 //   fprintf(fp,"\\TaskExecution{%d}{%d}{%d}\n", (int)taskObtemID(obtemDado(no))+1, 0, C+1);
    fprintf(fp,"%s\n%s\n%s\n","  \\end{RTGrid}","\\caption{Escalonador para ate 10 tarefas}","\\label{fig:ex1}");
    fprintf(fp,"%s\n%s\n%s\n","\\end{figure}","\\end{landscape}","\\end{document}");
    fclose(diagramfile);
    fclose(fp);
}

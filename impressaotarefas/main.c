#include <stdio.h>
#include <stdlib.h>

int print_diagram();

int main()
{
    /*FILE * fp;
    fp = fopen ("TESTE.tex","w");
    if (fp == NULL)
        exit(1);
    fprintf(fp,"%s\n%s\n%s\n\n","\\documentclass[a4paper,10pt]{article}","\\usepackage[utf8]{inputenc}","\\usepackage[brazil]{babel}");
    fprintf(fp,"%s\n%s\n%s\n\n","\\usepackage{listings}","\\usepackage{listingsutf8}","\\usepackage{rtsched}");
    fprintf(fp,"%s\n%s\n%s\n\n%s\n\n","\\title{Diagrama de execução}","\\author{Bruno Eduardo Ferreira","    \\\\Vinicius Botelho Souza}","\\begin{document}");
    fprintf(fp,"%s\n\n%s\n%s\n\n","\\maketitle","\\begin{figure}[h]","  \\centering");
    fprintf(fp,"%s\n","  \\begin{RTGrid}[nosymbols=1,width=10cm]{3}{20}");
    //chamada de funcao
    fprintf(fp,"%s\n%s\n%s\n","  \\end{RTGrid}","\\caption{Escalonador para duas tarefas.}","\\label{fig:ex1}");
    fprintf(fp,"%s\n%s\n","\\end{figure}","\\end{document}");
    fclose(fp);*/

    print_diagram();

    return 0;
}

int print_diagram(){

 //   int a[9]={1,2,3,2,4,3,1,1};//unidade
    int b[9]={2,2,3,1,3,2,1,4};//unidade de tempo, frequencia
    int i;//contador
    int n=8;//numero de tarefas

    for(i=0; i<n; i++){
        printf("\\RowLabel{%d}{$\tau_1$}\n",i+1);
        printf("\\TaskArrDead{%d}{%d}{%d}\n",i+1,i,b[i]);
        printf("\\TaskExecution{1}{0}{1}\n");
    }
        printf("\\RowLabel{%d}{$\tau_1$}\n",i+1);
 //   for( ; ; ){
        printf("\\TaskExecution{1}{0}{1}\n");
    }
    return 0;
};

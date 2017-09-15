/*!
*\file
*\brief Arquivo contendo os prot�tipos das fun��es da biblioteca no.
*\author Vinicius Botelho Souza
*\date Jul 2016
*\version 1.3
*/
//TYPEDEF
/*!
*\typedef struct nos no_t
*\brief Estrutura din�mica da lista duplamente encadeada.
*/
//CRIA_NO
/*!
*\fn void no_t *criaNo(void *dado)
*\brief Esta fun��o cria um n� para armazenar um respectivo dado.
*\details O dado contino no n� � de resposabilidade do uso da fun��o, fun��o termina o programa caso n�o tenha mem�ria suficiente para alocar o n�. Exemplo:
*\code
 char string1[] = "IFSC";
 char string2[] = "DAELN";
 char string3[] = "PROGRAMA";
 no_t *elemento1 = criaNo((void*)string1);
 no_t *elemento2 = criaNo((void*)string2);
 no_t *elemento3 = criaNo((void*)string3);
*\endcode
*\param dado Dado a ser alocado no n�.
*\return no_t Endere�o do n� criado.
*/
//LIGA_NO
/*!
*\fn void ligaNo(no_t *fonte, no_t *destino)
*\brief Esta fun��o faz a liga��o entre dois n�s.
*\details Caso um dos n�s sejam NULL a fun��o ir� terminar a aplica��o. Exemplo:
*\code
 char string1[] = "IFSC";
 char string2[] = "DAELN";
 char string3[] = "PROGRAMA";
 no_t *elemento1 = criaNo((void*)string1);
 no_t *elemento2 = criaNo((void*)string2);
 no_t *elemento3 = criaNo((void*)string3);
 ligaNo(elemento1,elemento2);
 ligaNo(elemento2,elemento3);
*\endcode
*\param fonte N� de origem a ser ligado.
*\param destino N� de destino a ser ligado.
*\return void.
*/
//DESLIGA_NO
/*!
*\fn void desligaNo(no_t *no);
*\brief Esta fun��o desfaz a liga��o existende de um n�.
*\details Caso o n� seja NULL a fun��o ir� terminar a aplica��o. Exemplo:
*\code
 char string1[] = "IFSC";
 char string2[] = "DAELN";
 char string3[] = "PROGRAMA";
 no_t *elemento1 = criaNo((void*)string1);
 no_t *elemento2 = criaNo((void*)string2);
 no_t *elemento3 = criaNo((void*)string3);
 ligaNo(elemento1,elemento2);
 ligaNo(elemento2,elemento3);
 desligaNo(elemento2); //R: proximo: NULL anterior: NULL
 ligaNo(elemento1,elemento3); //Liga elemento 1 ao elemento 2
*\endcode
*\param no N� a ser desligado.
*\return void.
*/
//OBTEM_PROXIMO
/*!
*\fn no_t *obtemProximo(no_t *no);
*\brief Esta fun��o busca o endere�o do proximo n� ligado ao respectivo n�.
*\details Caso o n� seja NULL a fun��o ir� terminar a aplica��o. Exemplo:
*\code
 char string1[] = "IFSC";
 char string2[] = "DAELN";
 char string3[] = "PROGRAMA";
 no_t *elemento1 = criaNo((void*)string1);
 no_t *elemento2 = criaNo((void*)string2);
 no_t *elemento3 = criaNo((void*)string3);
 ligaNo(elemento1,elemento2);
 ligaNo(elemento2,elemento3);
 no_t *proximo = obtemProximo(elemento1); //R: elemento2
*\endcode
*\param no N� no qual se deseja obter o endere�o do elemento ligado a ele.
*\return no_t Endere�o do pr�ximo elemento.
*/
//OBTEM_ANTERIOR
/*!
*\fn no_t *obtemAnterior(no_t *no);
*\brief Esta fun��o busca o endere�o do n� anterior ligado ao respectivo n�.
*\details Caso o n� seja NULL a fun��o ir� terminar a aplica��o. Exemplo:
*\code
 char string1[] = "IFSC";
 char string2[] = "DAELN";
 char string3[] = "PROGRAMA";
 no_t *elemento1 = criaNo((void*)string1);
 no_t *elemento2 = criaNo((void*)string2);
 no_t *elemento3 = criaNo((void*)string3);
 ligaNo(elemento1,elemento2);
 ligaNo(elemento2,elemento3);
 no_t *proximo = obtemAnterior(elemento2); //R: elemento1
*\endcode
*\param no N� no qual se deseja obter o endere�o do elemento ligado a ele.
*\return no_t Endere�o do elemento anterior.
*/
//OBTEM_DADO
/*!
*\fn void *obtemDado(no_t *no);
*\brief Esta fun��o retorna o endere�o do dado contido no n�.
*\details Caso o n� seja NULL a fun��o ir� terminar a aplica��o. Exemplo:
*\code
 char string1[] = "IFSC";
 char string2[] = "DAELN";
 char string3[] = "PROGRAMA";
 no_t *elemento1 = criaNo((void*)string1);
 no_t *elemento2 = criaNo((void*)string2);
 no_t *elemento3 = criaNo((void*)string3);
 printf("%s",*(char*)obtemDado(elemento2));
*\endcode
*\param no N� no qual se deseja obter o endere�o do dado contido nele.
*\return void* Endere�o do dado.
*/
//LIBERA_NO
/*!
*\fn void liberaNo(no_t *no);
*\brief Esta fun��o desaloca a mem�ria alocada para o respectivo n� e todos n�s ligados ap�s este.
*\details Exemplo:
*\code
 char string1[] = "IFSC";
 char string2[] = "DAELN";
 char string3[] = "PROGRAMA";
 no_t *elemento1 = criaNo((void*)string1);
 no_t *elemento2 = criaNo((void*)string2);
 no_t *elemento3 = criaNo((void*)string3);
 ligaNo(elemento1,elemento2);
 ligaNo(elemento2,elemento3);
 liberaNo(elemento1);
*\endcode
*\param no N� no qual se deseja desalocar mem�ria do mesmo e de seus sucessores.
*\return void
*/
//SWAP_NOS
/*!
*\fn void swap_nos(no_t *fonte,no_t *destino);
*\brief Esta fun��o troca as posi��es de liga��es entre os n�s.
*\details Caso um dos n�s sejam NULL a fun��o ir� terminar a aplica��o. Exemplo:
*\code
 char string1[] = "IFSC";
 char string2[] = "DAELN";
 char string3[] = "PROGRAMA";
 no_t *elemento1 = criaNo((void*)string1);
 no_t *elemento2 = criaNo((void*)string2);
 no_t *elemento3 = criaNo((void*)string3);
 ligaNo(elemento1,elemento2);
 ligaNo(elemento2,elemento3);
 swap(elemento1,elemento2);
*\endcode
*\param fonte N� fonte para a troca.
*\param destino N� destino para troca.
*\return void
*
*/
//DESLIGA_PROXIMO
/*!
*\fn void desligaProximo(no_t *no);
*\brief Esta fun��o desliga a liga��o com o pr�ximo elemento do n�, deixando como NULL.
*\details Caso o n� seja NULL a fun��o ir� terminar a aplica��o. Exemplo:
*\code
 char string1[] = "IFSC";
 char string2[] = "DAELN";
 char string3[] = "PROGRAMA";
 no_t *elemento1 = criaNo((void*)string1);
 no_t *elemento2 = criaNo((void*)string2);
 no_t *elemento3 = criaNo((void*)string3);
 ligaNo(elemento1,elemento2);
 ligaNo(elemento2,elemento3);
 desligaProximo(elemento1);
*\endcode
*\param no N� no qual se deseja desligar o endere�o do proximo elemento ligado a ele.
*\return void
*/
//DESLIGA_ANTERIOR
/*!
*\fn void desligaAnterior(no_t *no);
*\brief Esta fun��o desliga a liga��o com o elemento anterior do n�, deixando como NULL.
*\details Caso o n� seja NULL a fun��o ir� terminar a aplica��o. Exemplo:
*\code
 char string1[] = "IFSC";
 char string2[] = "DAELN";
 char string3[] = "PROGRAMA";
 no_t *elemento1 = criaNo((void*)string1);
 no_t *elemento2 = criaNo((void*)string2);
 no_t *elemento3 = criaNo((void*)string3);
 ligaNo(elemento1,elemento2);
 ligaNo(elemento2,elemento3);
 desligaAnterior(elemento1);
*\endcode
*\param no N� no qual se deseja desligar o endere�o do elemento anterior ligado a ele.
*\return void
*/
//COPIA_NO
/*!
*\fn no_t *copiaNo(no_t *no)
*\brief Esta fun��o copia um n�.
*\details Caso o n� seja NULL a fun��o ir� terminar a aplica��o.
*\param no N� no qual se deseja copiar.
*\return no_t* - N� copiado.
*/
#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

typedef struct nos no_t;

no_t *criaNo(void *dado);
void ligaNo(no_t *fonte, no_t *destino);
void desligaNo(no_t *no);
no_t *obtemProximo(no_t *no);
no_t *obtemAnterior(no_t *no);
void *obtemDado(no_t *no);
void liberaNo(no_t *no);
void swap_nos(no_t *fonte,no_t *destino);
void desligaProximo(no_t *no);
void desligaAnterior(no_t *no);
no_t *copiaNo(no_t *no);

#endif // NO_H_INCLUDED

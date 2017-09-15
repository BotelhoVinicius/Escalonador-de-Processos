/*!
*\file
*\brief Arquivo contendo os protótipos das funções da biblioteca no.
*\author Vinicius Botelho Souza
*\date Jul 2016
*\version 1.3
*/
//TYPEDEF
/*!
*\typedef struct nos no_t
*\brief Estrutura dinâmica da lista duplamente encadeada.
*/
//CRIA_NO
/*!
*\fn void no_t *criaNo(void *dado)
*\brief Esta função cria um nó para armazenar um respectivo dado.
*\details O dado contino no nó é de resposabilidade do uso da função, função termina o programa caso não tenha memória suficiente para alocar o nó. Exemplo:
*\code
 char string1[] = "IFSC";
 char string2[] = "DAELN";
 char string3[] = "PROGRAMA";
 no_t *elemento1 = criaNo((void*)string1);
 no_t *elemento2 = criaNo((void*)string2);
 no_t *elemento3 = criaNo((void*)string3);
*\endcode
*\param dado Dado a ser alocado no nó.
*\return no_t Endereço do nó criado.
*/
//LIGA_NO
/*!
*\fn void ligaNo(no_t *fonte, no_t *destino)
*\brief Esta função faz a ligação entre dois nós.
*\details Caso um dos nós sejam NULL a função irá terminar a aplicação. Exemplo:
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
*\param fonte Nó de origem a ser ligado.
*\param destino Nó de destino a ser ligado.
*\return void.
*/
//DESLIGA_NO
/*!
*\fn void desligaNo(no_t *no);
*\brief Esta função desfaz a ligação existende de um nó.
*\details Caso o nó seja NULL a função irá terminar a aplicação. Exemplo:
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
*\param no Nó a ser desligado.
*\return void.
*/
//OBTEM_PROXIMO
/*!
*\fn no_t *obtemProximo(no_t *no);
*\brief Esta função busca o endereço do proximo nó ligado ao respectivo nó.
*\details Caso o nó seja NULL a função irá terminar a aplicação. Exemplo:
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
*\param no Nó no qual se deseja obter o endereço do elemento ligado a ele.
*\return no_t Endereço do próximo elemento.
*/
//OBTEM_ANTERIOR
/*!
*\fn no_t *obtemAnterior(no_t *no);
*\brief Esta função busca o endereço do nó anterior ligado ao respectivo nó.
*\details Caso o nó seja NULL a função irá terminar a aplicação. Exemplo:
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
*\param no Nó no qual se deseja obter o endereço do elemento ligado a ele.
*\return no_t Endereço do elemento anterior.
*/
//OBTEM_DADO
/*!
*\fn void *obtemDado(no_t *no);
*\brief Esta função retorna o endereço do dado contido no nó.
*\details Caso o nó seja NULL a função irá terminar a aplicação. Exemplo:
*\code
 char string1[] = "IFSC";
 char string2[] = "DAELN";
 char string3[] = "PROGRAMA";
 no_t *elemento1 = criaNo((void*)string1);
 no_t *elemento2 = criaNo((void*)string2);
 no_t *elemento3 = criaNo((void*)string3);
 printf("%s",*(char*)obtemDado(elemento2));
*\endcode
*\param no Nó no qual se deseja obter o endereço do dado contido nele.
*\return void* Endereço do dado.
*/
//LIBERA_NO
/*!
*\fn void liberaNo(no_t *no);
*\brief Esta função desaloca a memória alocada para o respectivo nó e todos nós ligados após este.
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
*\param no Nó no qual se deseja desalocar memória do mesmo e de seus sucessores.
*\return void
*/
//SWAP_NOS
/*!
*\fn void swap_nos(no_t *fonte,no_t *destino);
*\brief Esta função troca as posições de ligações entre os nós.
*\details Caso um dos nós sejam NULL a função irá terminar a aplicação. Exemplo:
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
*\param fonte Nó fonte para a troca.
*\param destino Nó destino para troca.
*\return void
*
*/
//DESLIGA_PROXIMO
/*!
*\fn void desligaProximo(no_t *no);
*\brief Esta função desliga a ligação com o próximo elemento do nó, deixando como NULL.
*\details Caso o nó seja NULL a função irá terminar a aplicação. Exemplo:
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
*\param no Nó no qual se deseja desligar o endereço do proximo elemento ligado a ele.
*\return void
*/
//DESLIGA_ANTERIOR
/*!
*\fn void desligaAnterior(no_t *no);
*\brief Esta função desliga a ligação com o elemento anterior do nó, deixando como NULL.
*\details Caso o nó seja NULL a função irá terminar a aplicação. Exemplo:
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
*\param no Nó no qual se deseja desligar o endereço do elemento anterior ligado a ele.
*\return void
*/
//COPIA_NO
/*!
*\fn no_t *copiaNo(no_t *no)
*\brief Esta função copia um nó.
*\details Caso o nó seja NULL a função irá terminar a aplicação.
*\param no Nó no qual se deseja copiar.
*\return no_t* - Nó copiado.
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

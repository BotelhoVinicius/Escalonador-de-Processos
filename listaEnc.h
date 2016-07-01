//BEGIN
/*!
*\file
*\brief Arquivo contendo os prototipos das fun��es da biblioteca listaEnc.
*\author Vinicius Botelho Souza
*\date Jun 2016
*\version 1.0
*/
//TYPEDEF
/*!
*\typedef struct listas_enc lista_enc_t
*\brief Estrutura din�mica da lista duplamente encadeada.
*/
//CRIA_LISTA_ENCADEADA
/*!
 *\fn lista_enc_t* criaListaEncadeada(void)
 *\brief Esta fun��o cria a lista encadeada, alocando mem�ria para os argumentos da mesma.
 *\details Caso n�o seja possiv�l alocar mem�ria a mesma termina a aplica��o.
 *\return lista_enc_t* Lista alocada.
 */
//ADD_CAUDA
/*!
 *\fn void addCauda(lista_enc_t *lista, no_t* elemento)
 *\brief Esta fun��o adiciona um elemento na cauda da lista.
 *\details Caso a lista seja NULL ou o elemento seja NULL, a fun��o termina a aplica��o. Exemplo:
 *\code
 char string[] = "IFSC";
 no_t *elemento = criaNo((void*)string);
 lista_enc_t *lista = criaListaEncadeada();
 addCauda(lista,elemento);
 *\endcode
 *\param lista Lista a qual o elemento ir� ser adicionado.
 *\param elemento N� ao qual ir� adicionar na cauda.
 *\return void
 */
//ADD_CABECA
/*!
 *\fn void addCabeca(lista_enc_t *lista, no_t* elemento)
 *\brief Esta fun��o adiciona um elemento na cabeca da lista.
 *\details Caso a lista seja NULL ou o elemento seja NULL, a fun��o termina a aplica��o. Exemplo:
 *\code
 char string[] = "IFSC";
 no_t *elemento = criaNo((void*)string);
 lista_enc_t *lista = criaListaEncadeada();
 addCabeca(lista,elemento);
 *\endcode
 *\param lista Lista a qual o elemento ir� ser adicionado.
 *\param elemento N� ao qual ir� adicionar na cabeca.
 */
//REMOVE_ELEMENTO
/*!
*\fn no_t *removeElemento(lista_enc_t *lista, int pos)
*\brief Esta fun��o remove um elemento em uma determinada posi��o da lista
*\details Caso a lista seja NULL a fun��o ir� terminar a aplica��o. Exemplo:
*\code
 char string1[] = "IFSC";
 char string2[] = "DAELN";
 char string3[] = "PROGRAMA";
 no_t *elemento1 = criaNo((void*)string1);
 no_t *elemento2 = criaNo((void*)string2);
 no_t *elemento3 = criaNo((void*)string3);
 lista_enc_t *lista = criaListaEncadeada();
 addCabeca(lista,elemento1);
 addCabeca(lista,elemento2);
 addCabeca(lista,elemento3);
 no_t *elementoRemovido = removeElemento(lista,2);
*\endcode
*\param lista Lista a qual o elemento ir� ser removido.
*\param pos Posi��o da lista a qual o elemento ser� removido, indo de '1' para o primeiro elemento at� o ultimo elemento dado por listaTamanho(lista).
*\return no_t* Elemento que foi removido.
*\return NULL Caso a posi��o seja inval�da.
*/
//LISTA_POSI��O
/*!
*\fn int listaPosicao(lista_enc_t *lista,void* dado)
*\brief Esta fun��o retorna a posi��o de um dado na lista
*\details Caso a lista seja NULL ou dado seja NULL a fun��o ir� terminar a aplica��o. Exemplo:
*\code
 char string1[] = "IFSC";
 char string2[] = "DAELN";
 char string3[] = "PROGRAMA";
 no_t *elemento1 = criaNo((void*)string1);
 no_t *elemento2 = criaNo((void*)string2);
 no_t *elemento3 = criaNo((void*)string3);
 lista_enc_t *lista = criaListaEncadeada();
 addCabeca(lista,elemento1);
 addCabeca(lista,elemento2);
 addCabeca(lista,elemento3);
 int posicao = listaPosicao(lista,(void*)string1);
*\endcode
*\param lista Lista a qual o elemento ir� ser removido.
*\param dado Informa��o que ser� testada para encontrar a posi��o do elemento.
*\return int Posi��o do dado caso encontre ele na lista.
*\return 0 Caso n�o encontre o dado na lista.
*/
//LISTA_TAMANHO
/*!
*\fn int listaTamanho(lista_enc_t *lista)
*\brief Esta fun��o indica quantos elementos h� na lista.
*\details Caso a lista seja NULL a fun��o ir� terminar a aplica��o.Exemplo:
*\code
 char string1[] = "IFSC";
 char string2[] = "DAELN";
 char string3[] = "PROGRAMA";
 no_t *elemento1 = criaNo((void*)string1);
 no_t *elemento2 = criaNo((void*)string2);
 no_t *elemento3 = criaNo((void*)string3);
 lista_enc_t *lista = criaListaEncadeada();
 addCabeca(lista,elemento1);
 addCabeca(lista,elemento2);
 addCabeca(lista,elemento3);
 int tamanho = listaTamanho(lista);
*\endcode
*\param lista Lista a qual deseja-se saber a quantidade de elementos presentes.
*\return int N�mero de elementos presentes na lista.
*/
//LISTA_CABECA
/*!
*\fn no_t *listaCabeca(lista_enc_t *lista);
*\brief Esta fun��o indica qual � o n� que � a cabe�a da lista.
*\details Caso a lista seja NULL a fun��o ir� terminar a aplica��o. Exemplo:
*\code
 char string1[] = "IFSC";
 char string2[] = "DAELN";
 char string3[] = "PROGRAMA";
 no_t *elemento1 = criaNo((void*)string1);
 no_t *elemento2 = criaNo((void*)string2);
 no_t *elemento3 = criaNo((void*)string3);
 lista_enc_t *lista = criaListaEncadeada();
 addCabeca(lista,elemento1);
 addCabeca(lista,elemento2);
 addCabeca(lista,elemento3);
 no_t *cabeca = listaCabeca(lista);
*\endcode
*\param lista Lista a qual deseja-se saber o n� que atualmente � a cabeca da lista.
*\return no_t* Endere�o do n� que � atualmente a cabe�a da lista.
*/
//LISTA_CAUDA
/*!
*\fn no_t *listaCauda(lista_enc_t *lista);
*\brief Esta fun��o indica qual � o n� que � a cauda da lista.
*\details Caso a lista seja NULL a fun��o ir� terminar a aplica��o. Exemplo:
*\code
 char string1[] = "IFSC";
 char string2[] = "DAELN";
 char string3[] = "PROGRAMA";
 no_t *elemento1 = criaNo((void*)string1);
 no_t *elemento2 = criaNo((void*)string2);
 no_t *elemento3 = criaNo((void*)string3);
 lista_enc_t *lista = criaListaEncadeada();
 addCauda(lista,elemento1);
 addCauda(lista,elemento2);
 addCauda(lista,elemento3);
 no_t *cauda = listaCauda(lista);
*\endcode
*\param lista Lista a qual deseja-se saber o n� que atualmente � a cauda da lista.
*\return no_t* Endere�o do n� que � atualmente a cauda da lista.
*/
//LIBERA_LISTA
/*!
*\fn void liberaLista(lista_enc_t *lista);
*\brief Esta fun��o libera a aloca��o de mem�ria de toda sua lista e n�s.
*\details Caso a lista seja NULL a fun��o ir� terminar a aplica��o. Exemplo:
*\code
 char string1[] = "IFSC";
 char string2[] = "DAELN";
 char string3[] = "PROGRAMA";
 no_t *elemento1 = criaNo((void*)string1);
 no_t *elemento2 = criaNo((void*)string2);
 no_t *elemento3 = criaNo((void*)string3);
 lista_enc_t *lista = criaListaEncadeada();
 addCauda(lista,elemento1);
 addCauda(lista,elemento2);
 addCauda(lista,elemento3);
 liberaLista(lista);
*\endcode
*\param lista Lista a qual deseja-se liberar mem�ria.
*\return void
*/
//SWAP_LISTA
/*!
*\fn void swapLista(lista_enc_t *lista,no_t *fonte,no_t *destino)
*\brief Esta fun��o troca de posi��o na lista dois n�s.
*\details Caso a lista ou um dos n�s sejam NULL a fun��o ir� terminar a aplica��o. Exemplo:
*\code
 char string1[] = "IFSC";
 char string2[] = "DAELN";
 no_t *elemento1 = criaNo((void*)string1);
 no_t *elemento2 = criaNo((void*)string2);
 lista_enc_t *lista = criaListaEncadeada();
 addCauda(lista,elemento1);
 addCauda(lista,elemento2);
 swapLista(lista,elemento1,elemento2);
*\endcode
*\param lista Lista a qual deseja-se trocar a ordem dos elementos.
*\param fonte N� a ser trocado de posi��o.
*\param destino N� a ser trocado de posi��o.
*\return void
*/
//DESLIGA_NO_LISTA
/*!
*\fn void desligaNoLista(lista_enc_t *lista, no_t* elemento)
*\brief Esta fun��o desliga uma liga��o de uma lista, ligando o antecessor do elemento ao seu sucessor.
*\details Caso a lista ou o n� sejam NULL a fun��o ir� terminar a aplica��o. Exemplo:
*\code
 char string1[] = "IFSC";
 char string2[] = "DAELN";
 char string3[] = "PROGRAMA";
 no_t *elemento1 = criaNo((void*)string1);
 no_t *elemento2 = criaNo((void*)string2);
 no_t *elemento3 = criaNo((void*)string3);
 lista_enc_t *lista = criaListaEncadeada();
 addCauda(lista,elemento1);
 addCauda(lista,elemento2);
 addCauda(lista,elemento3);
 desligaNoLista(lista,elemento2);
*\endcode
*\param lista Lista a qual deseja-se desligar o elemento.
*\param elemento N� a ser desligado.
*\return void
*/
#ifndef LISTA_ENC_H_INCLUDED
#define LISTA_ENC_H_INCLUDED

#include "no.h"

typedef struct listas_enc lista_enc_t;

lista_enc_t *criaListaEncadeada(void);
void        addCauda(lista_enc_t *lista, no_t* elemento);
void        addCabeca(lista_enc_t *lista, no_t* elemento);
no_t        *removeElemento(lista_enc_t *lista, int pos);
int         listaPosicao(lista_enc_t *lista,void* dado);
int         listaTamanho(lista_enc_t *lista);
no_t        *listaCabeca(lista_enc_t *lista);
no_t        *listaCauda(lista_enc_t *lista);
void        liberaLista(lista_enc_t *lista);
void        swapLista(lista_enc_t *lista,no_t *fonte,no_t *destino);
void        desligaNoLista(lista_enc_t *lista, no_t* elemento);

#endif

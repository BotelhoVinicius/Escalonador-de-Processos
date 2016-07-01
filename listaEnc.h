//BEGIN
/*!
*\file
*\brief Arquivo contendo os prototipos das funções da biblioteca listaEnc.
*\author Vinicius Botelho Souza
*\date Jun 2016
*\version 1.0
*/
//TYPEDEF
/*!
*\typedef struct listas_enc lista_enc_t
*\brief Estrutura dinâmica da lista duplamente encadeada.
*/
//CRIA_LISTA_ENCADEADA
/*!
 *\fn lista_enc_t* criaListaEncadeada(void)
 *\brief Esta função cria a lista encadeada, alocando memória para os argumentos da mesma.
 *\details Caso não seja possivél alocar memória a mesma termina a aplicação.
 *\return lista_enc_t* Lista alocada.
 */
//ADD_CAUDA
/*!
 *\fn void addCauda(lista_enc_t *lista, no_t* elemento)
 *\brief Esta função adiciona um elemento na cauda da lista.
 *\details Caso a lista seja NULL ou o elemento seja NULL, a função termina a aplicação. Exemplo:
 *\code
 char string[] = "IFSC";
 no_t *elemento = criaNo((void*)string);
 lista_enc_t *lista = criaListaEncadeada();
 addCauda(lista,elemento);
 *\endcode
 *\param lista Lista a qual o elemento irá ser adicionado.
 *\param elemento Nó ao qual irá adicionar na cauda.
 *\return void
 */
//ADD_CABECA
/*!
 *\fn void addCabeca(lista_enc_t *lista, no_t* elemento)
 *\brief Esta função adiciona um elemento na cabeca da lista.
 *\details Caso a lista seja NULL ou o elemento seja NULL, a função termina a aplicação. Exemplo:
 *\code
 char string[] = "IFSC";
 no_t *elemento = criaNo((void*)string);
 lista_enc_t *lista = criaListaEncadeada();
 addCabeca(lista,elemento);
 *\endcode
 *\param lista Lista a qual o elemento irá ser adicionado.
 *\param elemento Nó ao qual irá adicionar na cabeca.
 */
//REMOVE_ELEMENTO
/*!
*\fn no_t *removeElemento(lista_enc_t *lista, int pos)
*\brief Esta função remove um elemento em uma determinada posição da lista
*\details Caso a lista seja NULL a função irá terminar a aplicação. Exemplo:
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
*\param lista Lista a qual o elemento irá ser removido.
*\param pos Posição da lista a qual o elemento será removido, indo de '1' para o primeiro elemento até o ultimo elemento dado por listaTamanho(lista).
*\return no_t* Elemento que foi removido.
*\return NULL Caso a posição seja invalída.
*/
//LISTA_POSIÇÂO
/*!
*\fn int listaPosicao(lista_enc_t *lista,void* dado)
*\brief Esta função retorna a posição de um dado na lista
*\details Caso a lista seja NULL ou dado seja NULL a função irá terminar a aplicação. Exemplo:
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
*\param lista Lista a qual o elemento irá ser removido.
*\param dado Informação que será testada para encontrar a posição do elemento.
*\return int Posição do dado caso encontre ele na lista.
*\return 0 Caso não encontre o dado na lista.
*/
//LISTA_TAMANHO
/*!
*\fn int listaTamanho(lista_enc_t *lista)
*\brief Esta função indica quantos elementos há na lista.
*\details Caso a lista seja NULL a função irá terminar a aplicação.Exemplo:
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
*\return int Número de elementos presentes na lista.
*/
//LISTA_CABECA
/*!
*\fn no_t *listaCabeca(lista_enc_t *lista);
*\brief Esta função indica qual é o nó que é a cabeça da lista.
*\details Caso a lista seja NULL a função irá terminar a aplicação. Exemplo:
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
*\param lista Lista a qual deseja-se saber o nó que atualmente é a cabeca da lista.
*\return no_t* Endereço do nó que é atualmente a cabeça da lista.
*/
//LISTA_CAUDA
/*!
*\fn no_t *listaCauda(lista_enc_t *lista);
*\brief Esta função indica qual é o nó que é a cauda da lista.
*\details Caso a lista seja NULL a função irá terminar a aplicação. Exemplo:
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
*\param lista Lista a qual deseja-se saber o nó que atualmente é a cauda da lista.
*\return no_t* Endereço do nó que é atualmente a cauda da lista.
*/
//LIBERA_LISTA
/*!
*\fn void liberaLista(lista_enc_t *lista);
*\brief Esta função libera a alocação de memória de toda sua lista e nós.
*\details Caso a lista seja NULL a função irá terminar a aplicação. Exemplo:
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
*\param lista Lista a qual deseja-se liberar memória.
*\return void
*/
//SWAP_LISTA
/*!
*\fn void swapLista(lista_enc_t *lista,no_t *fonte,no_t *destino)
*\brief Esta função troca de posição na lista dois nós.
*\details Caso a lista ou um dos nós sejam NULL a função irá terminar a aplicação. Exemplo:
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
*\param fonte Nó a ser trocado de posição.
*\param destino Nó a ser trocado de posição.
*\return void
*/
//DESLIGA_NO_LISTA
/*!
*\fn void desligaNoLista(lista_enc_t *lista, no_t* elemento)
*\brief Esta função desliga uma ligação de uma lista, ligando o antecessor do elemento ao seu sucessor.
*\details Caso a lista ou o nó sejam NULL a função irá terminar a aplicação. Exemplo:
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
*\param elemento Nó a ser desligado.
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

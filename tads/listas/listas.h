#ifndef LISTAS_H
#define LISTAS_H

#include <stdbool.h>
#include "tipo_elemento/tipo_elemento.h"

struct ListaRep;
typedef struct ListaRep *Lista;

struct IteradorRep;
typedef struct IteradorRep *Iterador;

/**
 * Crea una nueva lista vacía.
 *
 * @return Lista - una nueva instancia de lista vacía.
 */
Lista l_crear();

/**
 * Comprueba si la lista recibida como parámetro está vacía.
 *
 * @param lista - una instancia de tipo Lista.
 * @return bool - true si la lista está vacía, false en caso contrario.
 */
bool l_es_vacia(Lista lista);

/**
 * Comprueba si la lista recibida como parámetro está llena.
 * @param lista - una instancia de tipo Lista.
 * @return bool - true si la lista está llena, false en caso contrario.
 */
bool l_es_llena(Lista lista);

/**
 * Devuelve la cantidad de elementos que contiene la lista recibida como parámetro.
 *
 * @param lista - una instancia de tipo Lista.
 * @return int - la cantidad de elementos en la lista.
 */
int l_longitud(Lista lista);

/**
 * Agrega un elemento a la lista recibida como parámetro.
 *
 * @param lista - una instancia de tipo Lista.
 * @param elemento - el elemento a agregar a la lista.
 */
bool l_agregar(Lista lista, TipoElemento elemento);

/**
 * Elimina el elemento con la clave especificada de la lista recibida como parámetro.
 *
 * @param lista - una instancia de tipo Lista.
 * @param clave - la clave del elemento a eliminar.
 */
bool l_borrar(Lista lista, int clave);

/**
 * Busca el elemento con la clave especificada en la lista recibida como parámetro y lo devuelve.
 *
 * @param lista - una instancia de tipo Lista.
 * @param clave - la clave del elemento a buscar.
 * @return TipoElemento - el elemento con la clave especificada.
 */
TipoElemento l_buscar(Lista lista, int clave);

/**
 * Inserta un elemento en la posición especificada de la lista recibida como parámetro.
 *
 * @param lista - una instancia de tipo Lista.
 * @param elemento - el elemento a insertar en la lista.
 * @param pos - la posición en la que se insertará el elemento.
 */
bool l_insertar(Lista lista, TipoElemento elemento, int pos);

/**
 * Elimina el elemento en la posición especificada de la lista recibida como parámetro.
 *
 * @param lista - una instancia de tipo Lista.
 * @param pos - la posición del elemento a eliminar.
 */
bool l_eliminar(Lista lista, int pos);

/**
 * Recupera el elemento en la posición especificada de la lista recibida como parámetro y lo devuelve.
 *
 * @param lista - una instancia de tipo Lista.
 * @param pos - la posición del elemento a recuperar.
 * @return TipoElemento - el elemento en la posición especificada.
 */
TipoElemento l_recuperar(Lista lista, int pos);

/**
 * Muestra por pantalla los elementos de la lista recibida como parámetro.
 *
 * @param lista - una instancia de tipo Lista.
 */
void l_mostrar(Lista lista);

/**
 * Devuelve una representación de la lista recibida como parámetro en forma de cadena de caracteres.
 *
 * @param lista - una instancia de tipo Lista.
 * @return char * - una representación de la lista en forma de cadena de caracteres.
 */
char *l_to_string(Lista lista);

/**
 * Devuelve un iterador para la lista recibida como parámetro.
 *
 * @param lista - una instancia de tipo Lista.
 * @return Iterador - un iterador para la lista.
 */
Iterador iterador(Lista lista);

/**
 * Comprueba si hay un elemento siguiente en la iteración a través de la lista.
 *
 * @param iterador - una instancia de tipo Iterador.
 * @return bool - true si hay un elemento siguiente, false en caso contrario.
 */
bool hay_siguiente(Iterador iterador);

/**
 * Devuelve el siguiente elemento en la iteración a través de la lista.
 *
 * @param iterador - una instancia de tipo Iterador.
 */
TipoElemento siguiente(Iterador iterador);

#endif // LISTAS_H

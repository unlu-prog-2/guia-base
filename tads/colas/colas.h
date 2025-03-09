#ifndef COLAS_H
#define COLAS_H

#include <stdbool.h>
#include "tipo_elemento/tipo_elemento.h"

struct ColaRep;
typedef struct ColaRep *Cola;

/**
 * Crea una nueva cola vacía.
 *
 * @return una nueva instancia de cola vacía.
 */
Cola c_crear();

/**
 * Agrega un elemento al final de la cola recibida como parámetro.
 *
 * @param cola una instancia de tipo Cola.
 * @param elemento El elemento a agregar.
*/
bool c_encolar(Cola cola, TipoElemento elemento);

/**
 * Desencola y devuelve el elemento del frente de la cola.
 *
 * @param cola La cola de la que se va a desencolar el elemento.
 * @return el elemento desencolado.
*/
TipoElemento c_desencolar(Cola cola);

/**
 * Verifica si la cola está vacía.
 *
 * @param cola La cola a verificar.
 * @return true si la cola está vacía, false de lo contrario.
*/
bool c_es_vacia(Cola cola);

bool c_es_llena(Cola cola);

/**
 * Devuelve el elemento del frente de la cola sin desencolarlo.
 *
 * @param cola La cola de la que se quiere recuperar el elemento del frente.
 * @return el elemento del frente de la cola.
*/
TipoElemento c_recuperar(Cola cola);

/**
 * Muestra en consola los elementos de la cola recibida como parámetro.
 *
 * @param cola la cola a mostrar.
*/
void c_mostrar(Cola cola);

/**
 * Devuelve una representación de la cola recibida como parámetro en forma de cadena de caracteres.
 *
 * @param cola - una instancia de tipo Cola.
 * @return char * - una representación de la cola en forma de cadena de caracteres.
 */
char *c_to_string(Cola cola);

#endif // COLAS_H

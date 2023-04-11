#ifndef TIPO_ELEMENTO_H
#define TIPO_ELEMENTO_H

struct TipoElementoRep {
    int clave;
    void *valor;
};
typedef struct TipoElementoRep *TipoElemento;

/**
 * Crea un nuevo TipoElemento con la clave especificada y sin valor.
 *
 * @param clave - un valor entero que se utilizará como clave del nuevo TipoElemento.
 * @return TipoElemento - una nueva instancia de TipoElemento sin valor.
 */
TipoElemento te_crear(int clave);

/**
 * Crea un nuevo TipoElemento con la clave y valor especificados.
 *
 * @param clave - un valor entero que se utilizará como clave del nuevo TipoElemento.
 * @param valor - un puntero void que se utilizará como valor del nuevo TipoElemento.
 * @return TipoElemento - una nueva instancia de TipoElemento con la clave y valor especificados.
 */
TipoElemento te_crear_con_valor(int clave, void *valor);

#endif // TIPO_ELEMENTO_H

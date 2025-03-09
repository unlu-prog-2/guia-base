#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listas/listas.h"
#include "colas/colas.h"
#include "util_arboles.h"

void mostrar_arbol_binario(NodoArbol nodo, enum Recorrido recorrido) {
    if (nodo == NULL) {
        printf("El árbol está vacío.\n");
        return;
    }

    Iterador iterador;
    if (recorrido == PRE_ORDEN) {
        printf("Contenido del árbol en pre-orden: ");
        iterador = iterador_pre_orden(nodo);
    } else if (recorrido == IN_ORDEN) {
        printf("Contenido del árbol en in-orden: ");
        iterador = iterador_in_orden(nodo);
    } else if (recorrido == POST_ORDEN) {
        printf("Contenido del árbol en pos-orden: ");
        iterador = iterador_post_orden(nodo);
    } else {
        printf("Contenido del árbol en BFS: ");
        iterador = iterador_bfs(nodo);
    }

    while (hay_siguiente(iterador)) {
        TipoElemento te = siguiente(iterador);
        printf("%d ", te->clave);
    }
    printf("\n");
    free(iterador);
}

void iterador_pre_orden_recursivo(Lista l, NodoArbol nodo) {
    if (nodo != NULL) {
        l_agregar(l, nodo->datos);
        iterador_pre_orden_recursivo(l, nodo->hi);
        iterador_pre_orden_recursivo(l, nodo->hd);
    }
}

Iterador iterador_pre_orden(NodoArbol nodo_arbol) {
    Lista l = l_crear();
    iterador_pre_orden_recursivo(l, nodo_arbol);
    return iterador(l);
}

void iterador_in_orden_recursivo(Lista l, NodoArbol nodo) {
}

Iterador iterador_in_orden(NodoArbol nodo_arbol) {
    Lista l = l_crear();
    iterador_in_orden_recursivo(l, nodo_arbol);
    return iterador(l);
}

void iterador_pos_orden_recursivo(Lista l, NodoArbol nodo) {
}

Iterador iterador_post_orden(NodoArbol nodo_arbol) {
    Lista l = l_crear();
    iterador_pos_orden_recursivo(l, nodo_arbol);
    return iterador(l);
}

Iterador iterador_bfs(NodoArbol nodo_arbol) {
    Lista lista = l_crear();

    if (nodo_arbol != NULL) {
        Cola aux = c_crear();
        c_encolar(aux, te_crear_con_valor(nodo_arbol->datos->clave, nodo_arbol));

        while (!c_es_vacia(aux)) {
            TipoElemento actual = c_desencolar(aux);
            NodoArbol nodoArbol = (NodoArbol) actual->valor;
            l_agregar(lista, nodoArbol->datos);
            if (nodoArbol->hi != NULL) {
                c_encolar(aux, te_crear_con_valor(nodoArbol->hi->datos->clave, nodoArbol->hi));
            }
            if (nodoArbol->hd != NULL) {
                c_encolar(aux, te_crear_con_valor(nodoArbol->hd->datos->clave, nodoArbol->hd));
            }
            free(actual);
        }
        free(aux);
    }

    return iterador(lista);
}


// Rutinas para imprimir el árbol en ASCII

typedef struct asciinode_struct asciinode;

struct asciinode_struct {
    asciinode *left, *right;

    // length of the edge from this node to its children
    int edge_length;

    int height;

    unsigned long lablen;

    // -1=I am left, 0=I am root, 1=right
    int parent_dir;

    // max supported unit32 in dec, 10 digits max
    char label[11];
};


#define MAX_HEIGHT 1000
int lprofile[MAX_HEIGHT];
int rprofile[MAX_HEIGHT];
#define INFINITY (1<<20)

// adjust gap between left and right nodes
int gap = 3;

// used for printing next node in the same level,
// this is the x coordinate of the next char printed
int print_next;

int MIN(int X, int Y) {
    return ((X) < (Y)) ? (X) : (Y);
}

int MAX(int X, int Y) {
    return ((X) > (Y)) ? (X) : (Y);
}

asciinode *build_ascii_tree_recursive(NodoArbol t) {
    if (t == NULL) return NULL;

    asciinode *node = malloc(sizeof(asciinode));
    node->left = build_ascii_tree_recursive(t->hi);
    node->right = build_ascii_tree_recursive(t->hd);

    if (node->left != NULL) {
        node->left->parent_dir = -1;
    }

    if (node->right != NULL) {
        node->right->parent_dir = 1;
    }

    sprintf(node->label, "%d", t->datos->clave);
    node->lablen = strlen(node->label);

    return node;
}


//Copy the tree into the ascii node structure
asciinode *build_ascii_tree(NodoArbol t) {
    if (t == NULL) return NULL;
    asciinode *node = build_ascii_tree_recursive(t);
    node->parent_dir = 0;
    return node;
}

//Free all the nodes of the given tree
void free_ascii_tree(asciinode *node) {
    if (node == NULL) return;
    free_ascii_tree(node->left);
    free_ascii_tree(node->right);
    free(node);
}

//The following function fills in the lprofile array for the given tree.
//It assumes that the center of the label of the root of this tree
//is located at a position (x,y).  It assumes that the edge_length
//fields have been computed for this tree.
void compute_lprofile(const asciinode *node, const int x, const int y) {
    if (node == NULL) return;
    int isleft = (node->parent_dir == -1);
    lprofile[y] = MIN(lprofile[y], x - ((node->lablen - isleft) / 2));
    if (node->left != NULL) {
        for (int i = 1; i <= node->edge_length && y + i < MAX_HEIGHT; i++) {
            lprofile[y + i] = MIN(lprofile[y + i], x - i);
        }
    }
    compute_lprofile(node->left, x - node->edge_length - 1, y + node->edge_length + 1);
    compute_lprofile(node->right, x + node->edge_length + 1, y + node->edge_length + 1);
}

void compute_rprofile(const asciinode *node, const int x, const int y) {
    if (node == NULL) return;
    int notleft = (node->parent_dir != -1);
    rprofile[y] = MAX(rprofile[y], x + ((node->lablen - notleft) / 2));
    if (node->right != NULL) {
        for (int i = 1; i <= node->edge_length && y + i < MAX_HEIGHT; i++) {
            rprofile[y + i] = MAX(rprofile[y + i], x + i);
        }
    }
    compute_rprofile(node->left, x - node->edge_length - 1, y + node->edge_length + 1);
    compute_rprofile(node->right, x + node->edge_length + 1, y + node->edge_length + 1);
}

//This function fills in the edge_length and
//height fields of the specified tree
void compute_edge_lengths(asciinode *node) {
    if (node == NULL) return;
    compute_edge_lengths(node->left);
    compute_edge_lengths(node->right);

    /* first fill in the edge_length of node */
    if (node->right == NULL && node->left == NULL) {
        node->edge_length = 0;
    } else {
        int hmin;
        if (node->left != NULL) {
            for (int i = 0; i < node->left->height && i < MAX_HEIGHT; i++) {
                rprofile[i] = -INFINITY;
            }
            compute_rprofile(node->left, 0, 0);
            hmin = node->left->height;
        } else {
            hmin = 0;
        }
        if (node->right != NULL) {
            for (int i = 0; i < node->right->height && i < MAX_HEIGHT; i++) {
                lprofile[i] = INFINITY;
            }
            compute_lprofile(node->right, 0, 0);
            hmin = MIN(node->right->height, hmin);
        } else {
            hmin = 0;
        }
        int delta = 4;
        for (int i = 0; i < hmin; i++) {
            delta = MAX(delta, gap + 1 + rprofile[i] - lprofile[i]);
        }

        //If the node has two children of height 1, then we allow the
        //two leaves to be within 1, instead of 2
        if (((node->left != NULL && node->left->height == 1) ||
             (node->right != NULL && node->right->height == 1)) && delta > 4) {
            delta--;
        }

        node->edge_length = ((delta + 1) / 2) - 1;
    }

    //now fill in the height of node
    int h = 1;
    if (node->left != NULL) {
        h = MAX(node->left->height + node->edge_length + 1, h);
    }
    if (node->right != NULL) {
        h = MAX(node->right->height + node->edge_length + 1, h);
    }
    node->height = h;
}

void print_level(asciinode *node, const int x, const int level) {
    if (node == NULL) return;
    const int isleft = node->parent_dir == -1;
    if (level == 0) {
        int i;
        for (i = 0; i < x - print_next - (node->lablen - isleft) / 2; i++) {
            printf(" ");
        }
        print_next += i;
        printf("%s", node->label);
        print_next += node->lablen;
    } else if (node->edge_length >= level) {
        if (node->left != NULL) {
            int i;
            for (i = 0; i < x - print_next - level; i++) {
                printf(" ");
            }
            print_next += i;
            printf("/");
            print_next++;
        }
        if (node->right != NULL) {
            int i;
            for (i = 0; i < x - print_next + level; i++) {
                printf(" ");
            }
            print_next += i;
            printf("\\");
            print_next++;
        }
    } else {
        print_level(node->left,
                    x - node->edge_length - 1,
                    level - node->edge_length - 1);
        print_level(node->right,
                    x + node->edge_length + 1,
                    level - node->edge_length - 1);
    }
}

void mostrar_arbol_binario_ascii(NodoArbol nodo_arbol) {
    printf("Contenido del árbol en ascii:\n");
    if (nodo_arbol == NULL) return;
    asciinode *proot = build_ascii_tree(nodo_arbol);
    compute_edge_lengths(proot);
    for (int i = 0; i < proot->height && i < MAX_HEIGHT; i++) {
        lprofile[i] = INFINITY;
    }
    compute_lprofile(proot, 0, 0);
    int xmin = 0;
    for (int i = 0; i < proot->height && i < MAX_HEIGHT; i++) {
        xmin = MIN(xmin, lprofile[i]);
    }
    for (int i = 0; i < proot->height; i++) {
        print_next = 0;
        print_level(proot, -xmin, i);
        printf("\n");
    }
    if (proot->height >= MAX_HEIGHT) {
        printf("(This tree is taller than %d, and may be drawn incorrectly.)\n", MAX_HEIGHT);
    }
    free_ascii_tree(proot);
    printf("\n");
}

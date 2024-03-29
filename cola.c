#include "cola.h"
#include <stdlib.h>


typedef struct nodo {
    void* dato;
    struct nodo* proximo;
} nodo_t;


struct cola{
    nodo_t* primero;
    nodo_t* ultimo;
};




nodo_t* nodo_crear(void* valor){
    nodo_t* nodo_nuevo = malloc(sizeof(nodo_t));
    if (nodo_nuevo == NULL){
        return NULL;
    }
    nodo_nuevo->dato = valor;
    nodo_nuevo->proximo = NULL;
    return nodo_nuevo;
}


cola_t* cola_crear(void){
    cola_t* cola_nueva = malloc(sizeof(cola_t));
    if (cola_nueva == NULL){
        return NULL;
    }
    cola_nueva->primero = NULL;
    cola_nueva->ultimo = NULL;
    return cola_nueva;
}


bool cola_esta_vacia(const cola_t *cola){
    return(cola->primero == NULL);
}


void* cola_ver_primero(const cola_t *cola){
    if (cola_esta_vacia(cola)){
        return NULL;
    }
    return cola->primero->dato;
}


bool cola_encolar(cola_t *cola, void* valor){
    nodo_t* nodo_agregar = nodo_crear(valor);
    if (nodo_agregar == NULL){
        return false;
    }
    if (cola_esta_vacia(cola)){
        cola->primero = nodo_agregar;
        cola->ultimo = nodo_agregar;
        return true;
    }
    cola->ultimo->proximo = nodo_agregar;
    cola->ultimo = nodo_agregar;
    return true;
}


void manejo_nodos_eliminados(cola_t* cola){
    nodo_t* nodo_desencolado = cola->primero;
    cola->primero = cola->primero->proximo;
    free(nodo_desencolado);
    if (cola->primero == NULL){
        cola->ultimo = NULL;
    }

}


void* cola_desencolar(cola_t *cola){
    if (cola_esta_vacia(cola)){
        return NULL;
    }
    void* dato_desencolado = cola_ver_primero(cola);
    manejo_nodos_eliminados(cola);
    return dato_desencolado;

}


void cola_destruir(cola_t *cola, void destruir_dato(void*)){
    if(destruir_dato != NULL){
        while(!cola_esta_vacia(cola)){
            void* auxiliar = cola_desencolar(cola);
            destruir_dato(auxiliar);
        }
    }else{
        while(!cola_esta_vacia(cola)){
            manejo_nodos_eliminados(cola);
        }
    }
    free(cola);
}

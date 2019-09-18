#include "cola.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "pila.h"
#define ELEMENTOS_PRUEBA_VOLUMEN 10000


bool apilar_volumen(cola_t* cola, int* vector_pruebas){
    for(int i = 0; i < ELEMENTOS_PRUEBA_VOLUMEN; i++){
        if (cola_encolar(cola,&vector_pruebas[i]) == false){
            return false;
        }
    }
    return true;
}

bool desapilar_volumen(cola_t* cola, int* vector_pruebas){
    int posicion = 0;
    while (cola_esta_vacia(cola) == false){
        if (cola_ver_primero(cola) != &vector_pruebas[posicion]){
            return false;
        }
        cola_desencolar(cola);
        posicion += 1;
    }
    return true;
}

void prueba_volumen(){
    printf("\nPRUEBAS CON GRAN VOLUMEN DE ELEMENTOS\n");
    cola_t* que = cola_crear();
    int vector_temporal[ELEMENTOS_PRUEBA_VOLUMEN];
    print_test("apilando muchos elementos",apilar_volumen(que,vector_temporal) == true);
    print_test("despilando los elementos de la pila y verificando tope de pila",desapilar_volumen(que,vector_temporal) == true);
    print_test("pila vacia? ",cola_ver_primero(que) == NULL);
    cola_destruir(que,NULL);
}

void prueba_crear_destruir(){
    printf("\nPRUEBAS CREANDO/DESTUYENDO COLA\n");
    cola_t* que = cola_crear();
    cola_destruir(que,NULL);
}

void prueba_null(){
    printf("\nPRUEBAS CON ELEMENTOS NULL\n");
    cola_t* que = cola_crear();
    print_test("encolo elemento NULL",cola_encolar(que,NULL) == true);
    print_test("verificacion NULL encolado correcto",cola_esta_vacia(que) == false);
    print_test("elemento NULL es tope de cola",cola_ver_primero(que) == NULL);
    print_test("desencolo elemento NULL",cola_desencolar(que) == NULL);
    print_test("verificacion NULL desencolado correcto",cola_esta_vacia(que) == true);
    cola_destruir(que,NULL);
}

void prueba_cola_nueva(){
    printf("\nPRUEBAS SOBRE COLA NUEVA\n");
    cola_t* que = cola_crear();
    print_test("verificacion cola esta vacia", cola_esta_vacia(que) == true);
    print_test("verificacion tope de cola",cola_ver_primero(que) == NULL);
    print_test("desencolar no esta permitido",cola_desencolar(que) == NULL);
    cola_destruir(que,NULL);
}

void prueba_encolar_desencolar_estaticos(){
    printf("\nPRUEBAS ENCOLAR/DESENCOLAR ELEMENTOS ESTATICOS\n");
    int a = 5;
    int b = 12;
    int c = 436;
    cola_t* que = cola_crear();
    print_test("encolar elemento",cola_encolar(que,&a) == true);
    print_test("ver primero de cola",*(int*)cola_ver_primero(que) == a);
    print_test("encolar elemento",cola_encolar(que,&b) == true);
    print_test("ver primero de cola",*(int*)cola_ver_primero(que) == a);
    print_test("encolar elemento",cola_encolar(que,&c) == true);
    print_test("ver primero de cola",*(int*)cola_ver_primero(que) == a);
    print_test("desencolo elemento",*(int*)cola_desencolar(que) == a);
    print_test("ver primero de cola",*(int*)cola_ver_primero(que) == b);
    print_test("desencolo elemento",*(int*)cola_desencolar(que) == b);
    print_test("ver primero de cola",*(int*)cola_ver_primero(que) == c);
    print_test("desencolo elemento",*(int*)cola_desencolar(que) == c);
    print_test("verificacion cola esta vacia", cola_esta_vacia(que) == true);
    cola_destruir(que,NULL);
}

void destruir_estaticos(){
    printf("\nDESTRUIR COLA CON ELEMENTOS ESTATICOS RESTANTES\n");
    int a = 5;
    int b = 12;
    cola_t* que = cola_crear();
    print_test("encolar elemento",cola_encolar(que,&a) == true);
    print_test("encolar elemento",cola_encolar(que,&b) == true);
    cola_destruir(que,NULL);
}

void prueba_encolar_desencolar_dinamicos(){
    printf("\nPRUEBAS ENCOLAR/DESENCOLAR PUNTEROS DINAMICOS\n");
    int* ptr0 = (int*)malloc(5*sizeof(int));
    int* ptr1 = (int*)malloc(5*sizeof(int));
    int* ptr2 = (int*)malloc(5*sizeof(int));
    cola_t* que = cola_crear();
    print_test("encolar elemento",cola_encolar(que,ptr0) == true);
    print_test("ver primero de cola",cola_ver_primero(que) == ptr0);
    print_test("encolar elemento",cola_encolar(que,ptr1) == true);
    print_test("ver primero de cola",cola_ver_primero(que) == ptr0);
    print_test("encolar elemento",cola_encolar(que,ptr2) == true);
    print_test("ver primero de cola",cola_ver_primero(que) == ptr0);
    print_test("desencolo elemento",cola_desencolar(que) == ptr0);
    print_test("ver primero de cola",cola_ver_primero(que) == ptr1);
    print_test("desencolo elemento",cola_desencolar(que) == ptr1);
    print_test("ver primero de cola",cola_ver_primero(que) == ptr2);
    print_test("desencolo elemento",cola_desencolar(que) == ptr2);
    print_test("verificacion cola esta vacia", cola_esta_vacia(que) == true);
    cola_destruir(que,free);
    free(ptr0);
    free(ptr1);
    free(ptr2);
}

void destruir_dinamicos(){
    printf("\nPRUEBAS DESTRUIR PILA CON ELEMENTOS DINAMICOS RESTANTES\n");
    int* ptr0 = (int*)malloc( 5*sizeof(int));
    int* ptr1 = (int*)malloc( 5*sizeof(int));
    int* ptr2 = (int*)malloc( 5*sizeof(int));
    cola_t* que = cola_crear();
    print_test("encolar elemento",cola_encolar(que,ptr0) == true);
    print_test("encolar elemento",cola_encolar(que,ptr1) == true);
    print_test("encolar elemento",cola_encolar(que,ptr2) == true);
    cola_destruir(que,free);
}

void destruir_pilas(){
    printf("\nPRUEBAS DESTRUIR PILA CON PILAS RESTANTES\n");
    int a = 5;
    int b = 212;
    pila_t* p1 = pila_crear();
    pila_apilar(p1,&a);
    pila_t* p2 = pila_crear();
    pila_apilar(p2,&b);
    cola_t* que = cola_crear();
    print_test("encolar elemento",cola_encolar(que,p1) == true);
    print_test("encolar elemento",cola_encolar(que,p2) == true);
    print_test("verificacion cola no esta vacia", cola_esta_vacia(que) == false);

    void pila_destruir_wrapper(void* elem){
        pila_destruir((pila_t*) elem);
    }

    cola_destruir(que,pila_destruir_wrapper);

}

void pruebas_cola_alumno(void){
    prueba_crear_destruir();
    prueba_cola_nueva();
    prueba_null();
    prueba_encolar_desencolar_estaticos();
    prueba_volumen();
    destruir_estaticos();
    prueba_encolar_desencolar_dinamicos();
    destruir_dinamicos();
    destruir_pilas();

}

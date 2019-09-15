#include "cola.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>



void pruebas_cola_alumno(void){
    cola_t* col = cola_crear();
    int a = 11;
    int b = 22;
    int c = 33;
    //int test = malloc(sizeof(int)*5);
    //char g = 'r';
    //cola_encolar(col,&test);
    cola_encolar(col,&a);
    cola_encolar(col,&b);
    cola_encolar(col,&c);
    cola_encolar(col,&a);
    cola_encolar(col,&b);
    //printf("%d\n",*(int*)cola_desencolar(col));
    //cola_encolar(col,&g);
    //printf("%c\n",*(char*)cola_desencolar(col));
    //printf("%d\n",*(int*)cola_desencolar(col));
    printf("%d\n",*(int*)cola_desencolar(col));
    printf("%d\n",*(int*)cola_desencolar(col));
    printf("%d\n",*(int*)cola_desencolar(col));
    printf("%d\n",*(int*)cola_desencolar(col));
    cola_destruir(col,NULL);
}

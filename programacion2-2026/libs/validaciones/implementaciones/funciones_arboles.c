#include "../headers/funciones_arboles.h"
#include "../../colas/headers/colas.h"
#include "../../pilas/headers/pilas.h"
#include "../../listas/headers/listas.h"
#include "../headers/validaciones.h"
#include "../../../05-trabajoPractico-Arboles/tp_arboles.h"
#include <stdio.h>
#include <stdlib.h>

int printMenu(){
    printf("|=====================================|\n");
    printf("|      BIENVENIDO AL TP DE COLAS      |\n");
    printf("|1) Salir                             |\n");
    printf("|2) Ejercicios con una cola           |\n");
    printf("|3) Colas iguales                     |\n");
    printf("|4) Cola de no repetidos              |\n");
    printf("|5) Divisores totales y/o parciales   |\n");
    printf("|6) Valores comunes entre cola y pila |\n");
    printf("|7) Colas en el negocio               |\n");
    printf("|=====================================|\n");
    int n = enteroEnRango(1, 9);
    printf("\n\n");
    return n;
}

void ejercicio2(){
    printf("|=================     EJERCICIO 2     ==================|\n");
    printf("|===========     EJERCICIOS CON UN ARBOL     ============|\n");
    ArbolBinario a = a_crear();
    cargarArbolBinario(a);

    printf("\na)Lista con nodos terminales u hojas\n");
    Lista resA = a_ej2_hojas(a);
    l_mostrar(resA);

    printf("\na)Lista con nodos interiores (ni raiz ni hojas)\n");
    Lista resB = a_ej2_interiores(a);
    l_mostrar(resB);


    printf("\n|========================================================|\n");

}

void ejercicio3(){
    printf("|=================     EJERCICIO 3     ==================|\n");
    printf("|===========     EJERCICIOS CON UN NODO      ============|\n");
    printf("\n(Artol)\n ");
    ArbolBinario a = a_crear();
    cargarArbolBinario(a);
    printf("\n(Clave del nodo a realizar los ejercicios)\t ");
    int nodoClave = entero();

    printf("\na)Indicar el nombre del nodo padre (clave).\n");
    int padre = a_ej3_clavepadre(a, nodoClave);
    if(padre == -1){
        printf("\nEl nodo no existe");
    }else{
        printf("\nClave del padre: %d\n", padre);

    }

    printf("\nb)Listar claves de los hijos.\n");
    Lista resB = a_ej3_hijos(a, nodoClave);
    if(!l_es_vacia(resB)){
        l_mostrar(resB);
    }else{
        printf("\nEl nodo no tiene hijos");
    }

    printf("\nc)Indicar la clave del hermano.\n");
    int hermano = a_ej3_hermano(a, nodoClave);
    if(hermano == -1){
        printf("\nNo tiene hermano o el nodo no existe");
    }else{
        printf("\nClave del hermano: %d\n", hermano);

    }

    printf("\nd)Calcular el nivel en el que se encuentra.\n");
    int nivel = a_ej3_nivel(a, nodoClave);
    if(hermano == -1){
        printf("\nNo se encontro el nodo");
    }else{
        printf("\nNivel del nodo: %d\n", nivel);

    }



    printf("\n\n===          COMPLEJIDAD ALGORITMICA -->        ===\n");
    printf("\n|========================================================|\n");

}


void ejercicio4(){
    printf("|===================   EJERCICIO 4  ===================|\n");
    printf("|=============   EJERCICIOS CON N-ARIOS  ==============|\n");
    printf("\n(Arbol)\n ");
    ArbolBinario a = a_crear();
    cargarArbolBinario(a);

    int hojas = a_ej4_q_hojas(a);
    printf("\nb)Cantidad de hojas del arbol: %d\n\n", hojas);

    printf("\nc)Determinar si el arbol ingresado y otro son similares: \n");
    printf("(Arbol a comparar)\n");
    ArbolBinario b = a_crear();
    cargarArbolBinario(b);

    bool res = a_ej4_similares(a,b);
    if(res){
        printf("\nLos arboles SON similares\n");
    }else{
        printf("\nLos arboles NO SON similares\n");
    }

    printf("\n\ne)Determinar hermanos de un nodo: \n");
    printf("(Clave del nodo a listar hermanos)\t");
    int clave = entero();
    Lista hermanos = a_ej4_hermanos(a, clave);
    l_mostrar(hermanos);

    printf("\n\n===        COMPLEJIDAD ALGORITMICA --> )    ===\n");
    printf("\n|========================================================|\n");

}

void ejercicio5(){
    printf("|=================     EJERCICIO 5     ==================|\n");
    printf("|===========   DIVISORES TOTALES O PARCIALES ============|\n");


    printf("\n\n===        COMPLEJIDAD ALGORITMICA -->  )   ===\n");
    printf("\n|========================================================|\n");

}

void ejercicio6(){
    printf("|=================     EJERCICIO 6     ==================|\n");
    printf("|============ COMUNES ENTRE PILAS Y COLAS ===============|\n");



    printf("\n\n===        COMPLEJIDAD ALGORITMICA -->     ===\n");
    printf("\n|========================================================|\n");
}

void ejercicio7(){
    printf("|=================     EJERCICIO 7     ==================|\n");
    printf("|===========     EJERCICIOS CON UN NODO      ============|\n");
    printf("(Arbol A)\n");
    ArbolBinario a = a_crear();
    cargarArbolBinario(a);
    printf("(Arbol B)\n");
    ArbolBinario b = a_crear();
    cargarArbolBinario(b);

    bool res = a_ej7_equivalente(a,b);
    if(res){
        printf("SON EQUIVALENTES\n");
    }else{
        printf("NO SON EQUIVALENTES\n");
    }


    printf("\n\n===        COMPLEJIDAD ALGORITMICA -->         ===\n");
    printf("\n|========================================================|\n");
}

void ejercicio8(){
    printf("|=================     EJERCICIO 8     ==================|\n");
    printf("|===============   ATENDIENDO CLIENTES   ================|\n");


    printf("\n\n===        COMPLEJIDAD ALGORITMICA -->         ===\n");
    printf("\n|========================================================|\n");
}

void ejercicio9(){
    printf("|=================     EJERCICIO 9     ==================|\n");
    printf("|===============   ATENDIENDO CLIENTES   ================|\n");


    printf("\n\n===        COMPLEJIDAD ALGORITMICA -->         ===\n");
    printf("\n|========================================================|\n");
}


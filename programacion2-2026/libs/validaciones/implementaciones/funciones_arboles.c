#include "../headers/funciones_arboles.h"
#include "../../colas/headers/colas.h"
#include "../../pilas/headers/pilas.h"
#include "../../listas/headers/listas.h"
#include "../headers/validaciones.h"
#include "../../../05-trabajoPractico-Arboles/tp_arboles.h"
#include <stdio.h>
#include <stdlib.h>

int printMenu(){
    printf("|=========================================|\n");
    printf("|       BIENVENIDOS AL TP DE ARBOLES      |\n");
    printf("|1) Salir                                 |\n");
    printf("|2) Ejercicios con un ARBOL BINARIO       |\n");
    printf("|3) Ejercicios con UN NODO del arbol      |\n");
    printf("|4) Ejercicio con ARBOLES 'N-ARIOS'       |\n");
    printf("|5) DIBUJOS con ARBOLES 'AVL'             |\n");
    printf("|6) DIBUJOS con ARBOLES 'B' y 'B+'        |\n");
    printf("|7) ARBOLES BINARIOS equivalentes         |\n");
    printf("|8) Ejercicios con un ARBOL 'N-ARIO'      |\n");
    printf("|9) Ejercicio RECURSIVO con un ARBOL 'AVL'|\n");
    printf("|=========================================|\n");
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
    printf("Complejidad Algoritmica: O(n)\n");

    printf("\nb)Lista con nodos interiores (ni raiz ni hojas)\n");
    Lista resB = a_ej2_interiores(a);
    l_mostrar(resB);
    printf("Complejidad Algoritmica: O(n)\n");

    printf("\nc)Devolver todas las ocurrencias de una clave dada.\n");
    printf("(Clave a buscar)\n");
    int clave = entero();
    Lista c_res = a_ej2_buscarclave(a, clave);
    l_mostrar(c_res);
    printf("Complejidad Algoritmica: O(n)\n");


    printf("\n|========================================================|\n");

}

void ejercicio3(){
    printf("|=================     EJERCICIO 3     ==================|\n");
    printf("|===========     EJERCICIOS CON UN NODO      ============|\n\n");

    ArbolBinario a = a_crear();
    cargarArbolBinario(a);
    printf("\n(Clave del nodo a realizar los ejercicios)\t ");
    int nodoClave = entero();

    printf("\na)Indicar el nombre del nodo padre (clave).\n");
    int padre = a_ej3_clavepadre(a, nodoClave);
    if(padre == -1){
        printf("El nodo no existe\n");
    }else{
        printf("Clave del padre: %d\n", padre);

    }

    printf("\nb)Listar claves de los hijos.\n");
    Lista resB = a_ej3_hijos(a, nodoClave);
    if(!l_es_vacia(resB)){
        l_mostrar(resB);
    }else{
        printf("El nodo no tiene hijos\n");
    }

    printf("\nc)Indicar la clave del hermano.\n");
    int hermano = a_ej3_hermano(a, nodoClave);
    if(hermano == -1){
        printf("No tiene hermano o el nodo no existe\n");
    }else{
        printf("Clave del hermano: %d\n", hermano);

    }

    printf("\nd)Calcular el nivel en el que se encuentra.\n");
    int nivel = a_ej3_nivel(a, nodoClave);
    if(hermano == -1){
        printf("No se encontro el nodo\n");
    }else{
        printf("Nivel del nodo: %d\n", nivel);

    }

    //E
    printf("\ne)Devuelve la Altura en el que se encuentra el nodo.\n");
    int altura = a_ej3_alturarama(a, nodoClave);
    if(hermano == -1)
        printf("No se encontro el nodo.\n");
    else
        printf("Altura del nodo: %d\n", altura);

    //F
    printf("\nf)Devuelve una lista con todos los nodos del mismo nivel del nodo inicial.\n");
    Lista l = a_ej3_clavesmismonivel(a, nivel);
    l_mostrar(l);

    printf("\n|========================================================|\n");

}


void ejercicio4(){
    printf("|===================   EJERCICIO 4  ===================|\n");
    printf("|=============   EJERCICIOS CON N-ARIOS  ==============|\n");

    printf("\n(Arbol)\n ");
    ArbolBinario a = a_crear();
    cargarArbolBinario(a);

    //A
    printf("\n\na)Devolver una lista con las claves de los nodos en un recorrido de enchura.\n");
    Lista res_a = a_ej4_anchura(a);
    l_mostrar(res_a);

    //B
    int hojas = a_ej4_q_hojas(a);
    printf("\nb)Cantidad de hojas del arbol: %d\n", hojas);

    //C
    printf("\nc)Determinar si el arbol ingresado y otro son similares: \n");
    printf("(Arbol a comparar)\n");
    ArbolBinario b = a_crear();
    cargarArbolBinario(b);

    bool res = a_ej4_similares(a,b);
    if(res){
        printf("########## Los arboles SON similares ##########\n");
    }else{
        printf("########## Los arboles NO SON similares ##########\n");
    }

    //D
    printf("\nd)Retornar el padre de un nodo del arbol: \n");
    printf("(Clave del nodo a buscar su padre)\n");
    int claveNodo = entero();
    TipoElemento padre = a_ej4_padre(a, claveNodo);
    if(padre->clave != -1){
        printf("########## La clave del padre es: %d ##########\n", padre->clave);
    }else{
        printf("########## La clave del padre no existe ##########\n");
    }
    
    //E
    printf("\ne)Determinar hermanos de un nodo: \n");
    printf("(Clave del nodo a listar hermanos)\t");
    int clave = entero();
    Lista hermanos = a_ej4_hermanos(a, clave);
    l_mostrar(hermanos);

    printf("\n|========================================================|\n");

}

void ejercicio5(){
    printf("|=================     EJERCICIO 5    ==================|\n");
    printf("|===========    OPERACIONES EN ARBOL AVL    ============|\n");

    printf("|=======    IMAGENES SUBIDAS AL REPOSITORIO     ========|\n");

    printf("|====   (05-trabajoPractico-Arboles/ejercicio5)     ====|\n");

    printf("\n|=======================================================|\n");

}

void ejercicio6(){
    printf("|=================     EJERCICIO 6    ==================|\n");
    printf("|===========     OPERACIONES EN ARBOL B     ============|\n");

    printf("|=======    IMAGENES SUBIDAS AL REPOSITORIO     ========|\n");
    printf("|====   (05-trabajoPractico-Arboles/ejercicio6)     ====|\n");

    printf("\n|=======================================================|\n");

}

void ejercicio7(){
    printf("|=================     EJERCICIO 7     ==================|\n");
    printf("|===========     EJERCICIOS CON UN NODO      ============|\n");
    printf("\n(Arbol A)\n");
    ArbolBinario a = a_crear();
    cargarArbolBinario(a);
    printf("\n(Arbol B)\n");
    ArbolBinario b = a_crear();
    cargarArbolBinario(b);

    bool res = a_ej7_equivalente(a,b);
    if(res){
        printf("\n#################### SON EQUIVALENTES ####################\n");
    }else{
        printf("\n#################### NO SON EQUIVALENTES ####################\n");
    }

    printf("\n|========================================================|\n");
}

void ejercicio8(){
    printf("|=================     EJERCICIO 8     ==================|\n");
    printf("|==============   EJERCICIOS CON N-ARIO   ===============|\n");

    printf("\n(Arbol)\n");
    ArbolBinario a = a_crear();
    cargarArbolBinario(a);

    //A
    printf("\na)Determinar la altura del arbol.\n");
    int altura =  a_ej8_altura(a);
    if(altura != -1){
        printf("########## La altura del arbol es: %d ##########\n", altura);
    }else{
        printf("########## La altura del arbol no existe ##########\n");
    }

    //B
    printf("\nb)Determinar el nivel de un nodo.\n");
    printf("(Clave del nodo)\t");
    int claveNodo = entero();
    int nivelNodo = a_ej8_nivel(a, claveNodo);
    if(nivelNodo != -1){
        printf("########## El nodo esta en el nivel: %d ##########\n", nivelNodo);
    }else{
        printf("########## El nodo no existe ##########\n");
    }
    
    //C
    printf("\nc)Listar todos los nodos internos.\n");
    Lista internos = a_ej8_internos(a);
    l_mostrar(internos);

    //D
    printf("\nd)Determinar si todas las hojas estan al mismo nivel.\n");
    bool mismoNivel = a_ej8_hojasmismonivel(a);
    if(mismoNivel){
        printf(" ########## Todas las hojas estan al mismo nivel! ##########\n");
    }else{
        printf("########## No todas las hojas estan al mismo nivel ##########\n");
    }
    printf("\n|========================================================|\n");
}

void ejercicio9(){
    printf("|=================     EJERCICIO 9     ==================|\n");
    printf("|============      EJERCICIO CON  A.V.L      ============|\n");
    printf("|=  Transformar arbol binario en avl y comparar altura  =|\n");

    printf("\n(Arbol BINARIO a convertir en avl)\n");
    ArbolBinario a = a_crear();
    cargarArbolBinario(a);
    // Primero llamamos para construir el AVL
    ArbolAVL avl = a_ej9_construiravl(a);

    // Luego con el resultado de la funcion anterior llamamos a una funcion para que nos retorne la diferencia de las alturas
    // comparadas como Altura(ArbolBinario) - Altura(ArbolAVL).
    int difAlturas = a_ej9_diferenciaalturas(a, avl);
    printf("\n########## La diferencia de alturas entre ambos arboles es: %d ##########\n", difAlturas);
    printf("Complejidad Algoritmica: O(n)\n");

    printf("\n|========================================================|\n");
}


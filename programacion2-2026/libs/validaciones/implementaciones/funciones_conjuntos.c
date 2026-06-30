#include "../headers/funciones_conjuntos.h"
#include "../../listas/headers/listas.h"
#include "../headers/validaciones.h"
#include "../../../08-trabajoPractico-Conjuntos/tp_conjunto.h"
#include <stdio.h>
#include <stdlib.h>

int printMenu(){
    printf("|=========================================|\n");
    printf("|     BIENVENIDOS AL TP DE CONJUNTOS      |\n");
    printf("|1) Salir                                 |\n");
    printf("|2) Ejercicios con DOS CONJUNTOS          |\n");
    printf("|3) Ejercicios con una LISTA DE CONJUNTOS |\n");
    printf("|4) TRANSITIVIDAD entre conjuntos         |\n");
    printf("|5) ASIMETRIA entre conjuntos             |\n");
    printf("|6) SUBCONJUNTO PROPIO                    |\n");
    printf("|7) Subconjunto TOTAL O PARCIAL           |\n");
    printf("|8) Los conjuntos IGUALES                 |\n");
    printf("|=========================================|\n");
    int n = enteroEnRango(1, 8);
    printf("\n\n");
    return n;
}


void ejercicio2(){
    printf("|===================== EJERCICIO 2 =====================|\n");
    printf("|============ OPERACIONES CON DOS CONJUNTO =============|\n");

    printf("\n");
    Conjunto cto_1 = cargarConjuntoEnteros();
    cto_mostrar(cto_1);
    printf("\n");
    Conjunto cto_2 = cargarConjuntoEnteros();
    cto_mostrar(cto_2);

    //A
    printf("\na) Verificar la operacion Union.\n");
    Conjunto res_a = c_ej2_union(cto_1, cto_2);
    cto_mostrar(res_a);

    //B
    printf("\nb) Verificar la operacion Interseccion.\n");
    Conjunto res_b = c_ej2_interseccion(cto_1, cto_2);
    cto_mostrar(res_b);

    //C
    printf("\nc) Verificar la operacion Diferencia.\n");
    Conjunto res_c = c_ej2_diferencia(cto_1, cto_2);
    cto_mostrar(res_c);

    //D
    printf("\nd) Verificar la operacion Pertenece.\n");
    int clave = entero();
    if(c_ej2_pertenece(cto_1, clave)){
        printf("\n ########## PERTENECE ########## \n");
    }else{
        printf("\n ########## NO PERTENECE ########## \n");
    }

    printf("\n|=======================================================|\n");
}

void ejercicio3(){
    printf("|===================== EJERCICIO 3 =====================|\n");
    printf("|===========    OPERACIONES CON CONJUNTO    ============|\n");

    Lista l = l_crear();
    cargarConjuntoEnLista_con_valor(l);

    //A
    Conjunto c1 = c_ej3_uniones(l);
    printf("\n(Resultado de Uniones)\n");
    cto_mostrar(c1);

    //B
    Conjunto c2 = c_ej3_intersecciones(l);
    printf("\n(Resultado de Intersecciones)\n");
    cto_mostrar(c2);

    printf("\n|=======================================================|\n");
}

void ejercicio4(){
    printf("|===================== EJERCICIO 4 =====================|\n");
    printf("|===========    OPERACIONES CON CONJUNTO    ============|\n");
    
    Conjunto A = cargarConjuntoEnteros();
    Conjunto B = cargarConjuntoEnteros();
    Conjunto C = cargarConjuntoEnteros();

    if(c_ej4_transitividad(A, B, C)){
        printf("\n########### A 'ES' un subconjunto de C ###########\n");
    }else{
        printf("\n########### A 'NO ES' un subconjunto de C ###########\n");
    }

    printf("\n|=======================================================|\n");
}

void ejercicio5(){
    printf("|===================== EJERCICIO 5 =====================|\n");
    printf("|======= DIFERENCIA SIMETRICA ENTRE 2 CONJUNTOS ========|\n");
    
    Conjunto A = cargarConjuntoEnteros();
    Conjunto B = cargarConjuntoEnteros();
    Conjunto resultado = c_ej5_dif_simetrica(A, B);
    printf("\n\n(Resultado)\n");
    cto_mostrar(resultado);

    printf("\n|=======================================================|\n");
}

void ejercicio6(){
    printf("|===================== EJERCICIO 6 =====================|\n");
    printf("|================= SUBCONJUNTO PROPIO ==================|\n");
    
    Conjunto A = cargarConjuntoEnteros();
    Conjunto B = cargarConjuntoEnteros();
    if (c_ej6_subconjuntopropio(A, B)){
        printf("\n ########## 'ES' UN SUBCONJUNTO PROPIO ########## \n");
    }else{
        printf("\n ########## 'NO ES' UN SUBCONJUNTO PROPIO ########## \n");
    }

    printf("\nComplejidad Algoritmica: O(n)\n");

    printf("\n|=======================================================|\n");
}

void ejercicio7(){
    printf("|===================== EJERCICIO 7 =====================|\n");
    printf("|============= SUBCONJUNTO TOTAL O PARCIAL =============|\n");
    printf("\n ########## NO REALIZADO ########## \n");
    printf("\n|=======================================================|\n");
}

void ejercicio8(){
    printf("|===================== EJERCICIO 8 =====================|\n");
    printf("|============== LOS CONJUNTOS SON IGUALES ==============|\n");
    
    Conjunto A = cargarConjuntoEnteros();
    Conjunto B = cargarConjuntoEnteros();
    if (c_ej8_soniguales(A, B)){
        printf("\n ########## 'SON' IGUALES ########## \n");
    }else{
        printf("\n ########## 'NO SON' IGUALES ########## \n");
    }

    printf("\nComplejidad Algoritmica: O(n)\n");

    printf("\n|=======================================================|\n");
}

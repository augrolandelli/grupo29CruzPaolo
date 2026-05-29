#include "../headers/funciones_pilas.h"
#include "../../listas/headers/listas.h"
#include "../headers/validaciones.h"
#include "../../../03-trabajoPractico-Pilas/tp_pilas.h"
#include <stdio.h>
#include <stdlib.h>

int printMenu(){
    printf("|================================|\n");
    printf("|   BIENVENIDO AL TP DE PILAS    |\n");
    printf("|1) Salir                        |\n");
    printf("|2) Ejercicios con una pila      |\n");
    printf("|3) Det si dos pilas son iguales |\n");
    printf("|4) Decimal a hexadecimal        |\n");
    printf("|5) Invertir una pila            |\n");
    printf("|6) Eliminar clave de una pila   |\n");
    printf("|7) Elem en comun de dos pilas   |\n");
    printf("|8) Elem repetidos de una pila   |\n");
    printf("|================================|\n");
    int n = enteroEnRango(1, 8);
    printf("\n\n");
    return n;
}

void ejercicio2(){
    printf("|=================     EJERCICIO 2     ==================|\n");
    printf("|==========         Ingresar una pila          ==========|\n");

    Pila p = cargarPilaEnteros();
    p_mostrar(p);

    //A
    printf("\n\na) Buscar una clave dada.\n");
    printf("(Clave)\t");
    int clave = entero();
    if(p_ej2_existeclave(p,clave)){
        printf("Se encontro la clave en la pila!");
    }else{
        printf("No se encontro la clave en la pila.");
    }

    //B
    printf("\n\nb) Insertar una clave dada en una posicion dada.\n");
    printf("(Nueva Clave)\t\t");
    int claveInsertar = entero();
    int longitud = PilaLongitud(p);
    printf("(Posicion Ordinal)\t");
    int posicion = enteroEnRango(1,longitud+1);
    Pila pilaB = p_ej2_colocarelemento(p, posicion, te_crear(claveInsertar));
    p_mostrar(pilaB);

    //C
    printf("\n\nc) Eliminar la primer ocurrencia de una clave dada.\n");
    printf("(Clave)\t");
    int claveEliminar = entero();
    Pila pilaC = p_ej2_eliminarclave(p, claveEliminar);
    p_mostrar(pilaC);


    //D
    printf("\n\nd) Intercambiar los valores de dos posiciones dadas.\n");
    printf("(Posicion #1)\t");
    int pos1 = enteroEnRango(1,PilaLongitud(p));
    printf("(Posicion #2)\t");
    int pos2 = enteroEnRango(1,PilaLongitud(p));
    Pila pilaD = p_ej2_intercambiarposiciones(p,pos1,pos2);
    printf("\nPila con valores intercambiados: ");
    p_mostrar(pilaD);

    //E
    printf("\n\ne) Duplicar la pila.\n");
    Pila pDuplicada = p_ej2_duplicar(p);
    printf("Original: ");
    p_mostrar(p);
    printf("Duplicada: ");
    p_mostrar(pDuplicada);

    //F
    printf("\n\nf) Contar los elementos de una pila.\n");
    int elementos = p_ej2_cantidadelementos(p);
    printf("Son %d elementos: ",elementos);
    p_mostrar(p);

    printf("\n=============== COMPLEJIDAD ALGORITMICA ===============\n");
    printf("Para todas las operaciones del Ejercicio 2:\n");
    printf("(TAD Arreglos): O(n) | (TAD Punteros): O(n^2)\n");
    printf("|========================================================|\n");

}

void ejercicio3(){
    printf("|=================     EJERCICIO 3     ==================|\n");
    printf("|=Ingresar dos pilas para ver si son exactamente iguales=|\n");

    printf("\n|=Ingresar primer pila=|\n");
    Pila p1 = cargarPilaEnteros();
    printf("\n|=Ingresar segunda pila=|\n");
    Pila p2 = cargarPilaEnteros();

    if(PilaLongitud(p1) != PilaLongitud(p2)){
        printf("\n=============== LAS PILAS NO SON IGUALES ===============\n");
    }else if(p_ej3_iguales(p1, p2)){
        printf("\n================= LAS PILAS SON IGUALES =================\n");
    }else{
        printf("\n=============== LAS PILAS NO SON IGUALES ===============\n");;
    }
    printf("(Pila 1) ");
    p_mostrar(p1);
    printf("(Pila 2) ");
    p_mostrar(p2);

    printf("\nComplejidad Algoritmica: O(n)\n");

    printf("|========================================================|\n");

}


void ejercicio4(){
    printf("|===================   EJERCICIO 4  ===================|\n");
    printf("|==================   CAMBIAR BASE   ==================|\n\n");

    printf("(Base Decimal)\t");
    int base_decimal = entero();
    printf("(Nueva Base)\t");
    int otra_base = enteroEnRango(2, 16);

    char * res = malloc(sizeof(int) *100);
    res = p_ej4_cambiarbase(base_decimal, otra_base);

    printf("\nResultado: %s\n", res);
    printf("Complejidad Algoritmica: 2n --> O(n)\n");

    printf("\n|======================================================|\n");

}

void ejercicio5(){
    printf("|=================     EJERCICIO 5     ==================|\n");
    printf("|===                INVERTIR UNA PILA                 ===|\n");

    Pila p = cargarPilaEnteros();
    Pila res = p_ej5_invertir(p);

    printf("(Pila original)\t\t");
    p_mostrar(p);
    printf("(Pila invertida)\t");
    p_mostrar(res);

    printf("\n=============== COMPLEJIDAD ALGORITMICA ===============\n");
    printf("       (TAD Arreglos): O(n) | (TAD Punteros): O(n^2)     \n");
    printf("|========================================================|\n");

}

void ejercicio6(){
    printf("|=================     EJERCICIO 6     ==================|\n");
    printf("|===    ELIMINAR TODAS LAS OCURRENCIAS DE UNA CLAVE   ===|\n");
    printf("|===      LO HAREMOS ITERATIVA Y RECURSIVAMENTE       ===|\n");

    Pila p = cargarPilaEnteros();
    printf("\n(Clave Eliminar)\t");
    int clave = entero();

    printf("\n====================   ITERATIVO   ====================\n");
    Pila res = p_ej6_eliminarclave(p, clave);
    printf("(Original)\t");
    p_mostrar(p);
    printf("(Resultado)\t");
    p_mostrar(res);

    printf("\n====================   RECURSIVO   ====================\n");
    printf("|===  USAREMOS LA MISMA PILA Y CLAVE DADA PREVIAMNTE  ===|\n\n");
    Pila resRec = p_ej6_eliminarclaverecursiva(p, clave);
    printf("(Original)\t");
    p_mostrar(p);
    printf("(Resultado)\t");
    p_mostrar(resRec);

    printf("\n=============== COMPLEJIDAD ALGORITMICA ===============\n");
    printf("            Arreglos: O(n) |      Punteros: O(n^2)\n");
    printf("|========================================================|\n");
}

void ejercicio7(){
    printf("|=================     EJERCICIO 7     ==================|\n");
    printf("|===  DETERMINAR LOS ELEMENTOS EN COMUN DE DOS PILAS  ===|\n");

    Pila p1 = cargarPilaEnteros();
    Pila p2 = cargarPilaEnteros();
    Pila res = p_ej7_elementoscomunes(p1, p2);

    printf("(Pila 1)\t\t");
    p_mostrar(p1);
    printf("(Pila 2)\t\t");
    p_mostrar(p2);
    printf("(Pila Resultado)\t");
    p_mostrar(res);

    printf("\n=============== COMPLEJIDAD ALGORITMICA ===============\n");
    printf("(TAD Arreglos):  O(n^2) si son iguales.\n");
    printf("(TAD Punteros): O(N * M^2)\n");
    printf("|========================================================|\n");
}

void ejercicio8(){
    printf("|===================   EJERCICIO 8  ===================|\n");
    printf("|== VALORES SIN REPETIR Y SU CANTIDAD DE APARICIONES ==|\n\n");

    Pila p = cargarPilaEnteros();
    Pila res = p_ej8_sacarrepetidos(p);

    printf("(Pila Original)\t\t");
    p_mostrar(p);
    printf("(Pila Resultado)\t");
    p_mostrar_con_clave(res);

    printf("\n=============== COMPLEJIDAD ALGORITMICA ===============\n");
    printf("(TAD Arreglos): O(n^2).\n");
    printf("(TAD Punteros): O(n^3).\n");
    printf("|========================================================|\n");
}


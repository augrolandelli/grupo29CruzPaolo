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
    return n;
}

void ejercicio2(){
    printf("|=================     EJERCICIO 2     ==================|\n");
    printf("|==========         Ingresar una pila          ==========|\n");

    Pila p = cargarPilaEnteros();
    p_mostrar(p);
    printf("\n\na) Buscar una clave dada. Ingresar la clave.\n");
    int clave = entero();
    if(p_ej2_existeclave(p,clave)){
        printf("Se encontro la clave en la pila!");
    }else{
        printf("No se encontro la clave en la pila...");
    }
    printf("\n\nb) Insertar una clave dada en una posicion dada. Ingresar clave.\n");
    int claveInsertar = entero();
    int longitud = PilaLongitud(p);
    printf("Ingresar posicion.\n");
    int posicion = enteroEnRango(1,longitud+1);
    Pila pilaB = p_ej2_colocarelemento(p, posicion, te_crear(claveInsertar));
    p_mostrar(pilaB);

    printf("\n\nc) Eliminar la primer ocurrencia de una clave dada. Ingrese la clave.\n");
    int claveEliminar = entero();
    Pila pilaC = p_ej2_eliminarclave(p, claveEliminar);
    p_mostrar(pilaC);


    printf("\n\nd) Intercambiar los valores de dos posiciones dadas.\n");

    printf("\n\ne) Duplicar la pila.\n");
    Pila pDuplicada = p_ej2_duplicar(p);
    printf("Original: ");
    p_mostrar(p);
    printf("Duplicada: ");
    p_mostrar(pDuplicada);
    printf("\n\nf) Contar los elementos de una pila.\n");
    int elementos = p_ej2_cantidadelementos(p);
    printf("Son %d elementos: ",elementos);
    p_mostrar(p);

    printf("|========================================================|\n");

}

void ejercicio3(){
    printf("|=================     EJERCICIO 3     ==================|\n");
    printf("|=Ingresar dos pilas para ver si son exactamente iguales=|\n");

    Pila p1 = cargarPilaEnteros();
    Pila p2 = cargarPilaEnteros();

    if(PilaLongitud(p1) != PilaLongitud(p2)){
        printf("\n\nLAS PILAS NO SON IGUALES\n\n");
    }else if(p_ej3_iguales(p1, p2)){
        printf("\n\nLAS PILAS SON IGUALES\n\n");
    }else{
        printf("\n\nLAS PILAS NO SON IGUALES\n\n");
    }
    printf("\n\nPILAS ORIGINALES:\n");
    p_mostrar(p1);
    p_mostrar(p2);

    printf("|========================================================|\n");

}

void ejercicio5(){
    printf("|=================     EJERCICIO 5     ==================|\n");
    printf("|===                INVERTIR UNA PILA                 ===|\n");

    Pila p = cargarPilaEnteros();
    Pila res = p_ej5_invertir(p);

    printf("Pila original: ");
    p_mostrar(p);
    printf("\nPila invertida: ");
    p_mostrar(res);

    printf("|========================================================|\n");

}

void ejercicio6(){
    printf("|=================     EJERCICIO 6     ==================|\n");
    printf("|===    ELIMINAR TODAS LAS OCURRENCIAS DE UNA CLAVE   ===|\n");
    printf("|===      LO HAREMOS ITERATIVA Y RECURSIVAMENTE       ===|\n");
    printf("|===             PRIMERO ITERATIVAMENTE               ===|\n");
    Pila p = cargarPilaEnteros();
    int clave = entero();
    Pila res = p_ej6_eliminarclave(p, clave);

    printf("Pila original: ");
    p_mostrar(p);
    printf("Pila resultante de la ITERATIVIDAD: ");
    p_mostrar(res);

    printf("\n\n|===              AHORA RECURSIVAMENTE                ===|\n");
    printf("|===  USAREMOS LA MISMA PILA Y CLAVE DADA PREVIAMNTE  ===|\n");
    printf("'\n");
    Pila resRec = p_ej6_eliminarclaverecursiva(p, clave);
    printf("Pila original: ");
    p_mostrar(p);
    printf("Pila resultante de la RECURSIVIDAD: ");
    p_mostrar(resRec);

    printf("\n|========================================================|\n");
}

void ejercicio7(){
    printf("|=================     EJERCICIO 7     ==================|\n");
    printf("|===  DETERMINAR LOS ELEMENTOS EN COMUN DE DOS PILAS  ===|\n");

    Pila p1 = cargarPilaEnteros();
    Pila p2 = cargarPilaEnteros();
    Pila res = p_ej7_elementoscomunes(p1, p2);

    printf("Pila 1 original: ");
    p_mostrar(p1);
    printf("Pila 2 original: ");
    p_mostrar(p2);
    printf("Pila resultante: ");
    p_mostrar(res);

    printf("\n|========================================================|\n");
}

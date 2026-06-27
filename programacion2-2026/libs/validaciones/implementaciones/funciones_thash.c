#include "../headers/funciones_thash.h"
#include "../headers/validaciones.h"
#include "../../../07-trabajoPractico-Hash/tp_thash.h"
#include <stdio.h>
#include <stdlib.h>

int printMenu(){
    printf("|=========================================|\n");
    printf("|       BIENVENIDOS AL TP DE ARBOLES      |\n");
    printf("|1) Salir                                 |\n");
    printf("|2) Construir tabla h(x) = x mod 10       |\n");
    printf("|3) Construir tabla h(x) = (4+3(x))mod 10 |\n");
    printf("|4) Tabla hash a partir de archivo        |\n");
    printf("|5) Comparativa en tiempos de acceso      |\n");
    printf("|6) Busqueda de personas vacunadas        |\n");
    printf("|=========================================|\n");
    int n = enteroEnRango(1, 9);
    printf("\n\n");
    return n;
}

void ejercicio2(){
     printf("\n=== EJERCICIO 2: Construir tabla h(x) = x mod 10 ===\n");
     printf("\n= LA IMAGEN SE ENCUENTRA EN LA CARPETA DEL TRABAJO =\n");
}

void ejercicio3(){
     printf("\n= EJERCICIO 3: Construir tabla h(x) = (4+3(x))mod 10 =\n");
     printf("\n= LA IMAGEN SE ENCUENTRA EN LA CARPETA DEL TRABAJO =\n");
}

void ejercicio4(){
    th_ej4_abm();
}

void ejercicio5() {
    printf("\n=== EJERCICIO 5: COMPARACION AVL vs TABLA HASH ===\n");

    printf("\nGeneracion de claves:");
    int q_claves = enteroEnRango(1, 2000);

    printf("\nCantidad de repeticiones de busqueda:");
    int q_repeticiones = enteroMayorQue0();

    printf("\nRango de claves (Desde):");
    int rango_desde = entero();

    printf("\nRango de claves (Hasta):");
    int rango_hasta = entero();

    if (rango_desde > rango_hasta) {
        printf("Corrigiendo rango inverso...\n");
        int aux = rango_desde;
        rango_desde = rango_hasta;
        rango_hasta = aux;
    }

    if ((rango_hasta - rango_desde + 1) < q_claves) {
         printf("Error: No se pueden generar %d claves unicas en un rango tan chico.\n", q_claves);
         return;
    }

    th_ej5_comparacion(q_claves, q_repeticiones, rango_desde, rango_hasta);
}

void ejercicio6(){
    printf("\n=== EJERCICIO 6: BUSQUEDA DE VACUNADOS COVID ===\n");
    th_ej6_covid();
}

#include "../headers/funciones_colas.h"
#include "../../colas/headers/colas.h"
#include "../headers/validaciones.h"
#include "../../../04-trabajoPractico-Colas/tp_colas.h"
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
    int n = enteroEnRango(1, 7);
    printf("\n\n");
    return n;
}

void ejercicio2(){
    printf("|=================     EJERCICIO 2     ==================|\n");
    Cola c = cargarColaEnteros();
    c_mostrar(c);

    //A
    printf("\n\na) Buscar una clave dada.\n");
    printf("(Clave)\t");
    int clave = entero();
    if(c_ej2_existeclave(c, clave)){
        printf("Se encontro la clave en la cola!");
    }else{
        printf("No se encontro la clave en la cola!");
    }
    printf("\n\n(Cola Original)\n");
    c_mostrar(c);

    //B
    printf("\n\nb) Agregar una clave dada en una posicion dada.\n");
    printf("(Nueva Clave)\t\t");
    int claveInsertar = entero();
    int longitud = ColaLongitud(c);
    printf("(Posicion Ordinal)\t");
    int posicion = enteroEnRango(1,longitud+1);
    Cola colaB = c_ej2_colarelemento(c, posicion, te_crear(claveInsertar));;
    c_mostrar(colaB);

    printf("\n\n(Cola Original)\n");
    c_mostrar(c);



    //C
    printf("\n\nc) Sacar todas las ocurrencias de una clave de la cola.\n");
    printf("(Clave)\t");
    int claveEliminar = entero();

    Cola colaC = c_ej2_sacarelemento(c,claveEliminar);
    c_mostrar(colaC);

    printf("\n\n(Cola Original)\n");
    c_mostrar(c);

    //D
    printf("\n\nd) Contar los elementos de la cola.\n");
    int elementos = c_ej2_contarelementos(c);

    printf("\nLa cola tiene %d elementos!\n\n(Cola Original)\n", elementos);
    c_mostrar(c);

    //E
    printf("\n\ne) Realizar una copia de la cola.\n");
    Cola colaE = c_ej2_copiar(c);
    c_mostrar(colaE);
    printf("\n\n(Cola Original)\n");
    c_mostrar(c);

    //F
    printf("\n\nf) Invertir el contenido de la cola.\n");
    Cola colaF = c_ej2_invertir(c);
    c_mostrar(colaF);
    printf("\n\n(Cola Original)\n");
    c_mostrar(c);

    printf("\n|========================================================|\n");

}

void ejercicio3(){
    printf("|=================     EJERCICIO 3     ==================|\n");
    printf("|=== DETERMINAR SI DOS COLAS SON EXACTAMENTE IGUALES  ===|\n");

    printf("\n(Cola 1)\n");
    Cola c1 = cargarColaEnteros();
    c_mostrar(c1);
    printf("\n(Cola 2)\n");
    Cola c2 = cargarColaEnteros();
    c_mostrar(c2);

    bool res = c_ej3_iguales(c1,c2);

    if(res){
        printf("|=== SON EXACTAMENTE IGUALES  ===|\n");
    }else{
        printf("|=== NO SON IGUALES  ===|\n");
    }

    printf("\n\n(Cola 1 Original)\n");
    c_mostrar(c1);
    printf("\n\n(Cola 2 Original)\n");
    c_mostrar(c2);


    printf("\n\n===          COMPLEJIDAD ALGORITMICA --> O(n)       ===\n");
    printf("\n|========================================================|\n");

}


void ejercicio4(){
    printf("|===================   EJERCICIO 4  ===================|\n");
    printf("|===============   COLA SIN REPETIDOS  ================|\n");
    printf("\n(Cola)\n");
    Cola c = cargarColaEnteros();
    c_mostrar(c);

    Cola res = c_ej4_colanorepetidos(c);

     printf("\n(Cola no repetidos)\n");
    c_mostrar(res);

    printf("\n(Cola Original)\n");
    c_mostrar(c);

    printf("\n\n===        COMPLEJIDAD ALGORITMICA --> O(n^2)    ===\n");
    printf("\n|========================================================|\n");

}

void ejercicio5(){
    printf("|=================     EJERCICIO 5     ==================|\n");
    printf("|===========   DIVISORES TOTALES O PARCIALES ============|\n");
    printf("\n(Cola)\n");
    Cola c = cargarColaEnteros();
    c_mostrar(c);
    if (!validarColaEj5(c)) {
        printf("ERROR: La cola no es valida. Contiene valores menores a 2 o repetidos.\n");
        return;
    }
    Cola resultado = c_ej5_divisortotal(c);
    if (c_es_vacia(resultado)) {
        printf("No hay divisores totales ni parciales.\n");
    } else {
        while (!c_es_vacia(resultado)) {
            TipoElemento te = c_desencolar(resultado);
            int divisor = te->clave;

            bool* puntero_bool = (bool*) te->valor;
            bool es_total = *puntero_bool;

            if (es_total) {
                printf("El numero %d es un Divisor TOTAL.\n", divisor);
            } else {
                printf("El numero %d es un Divisor PARCIAL.\n", divisor);
            }

            free(puntero_bool);
            free(te);
        }
    }

    printf("\n\n===        COMPLEJIDAD ALGORITMICA -->  O(n^2)   ===\n");
    printf("\n|========================================================|\n");

}

void ejercicio6(){
    printf("|=================     EJERCICIO 6     ==================|\n");
    printf("|============ COMUNES ENTRE PILAS Y COLAS ===============|\n");

    printf("\n(Pila)\n");
    Pila p = cargarPilaEnteros();
    p_mostrar(p);
    printf("\n(Cola)\n");
    Cola c = cargarColaEnteros();
    c_mostrar(c);
    Lista Resultado = c_ej6_comunesapilaycola(p, c);

    printf("\n(Resultado)\n");
    l_mostrar_con_valor(Resultado);

    printf("\n\n===        COMPLEJIDAD ALGORITMICA -->  O(n^2)   ===\n");
    printf("\n|========================================================|\n");
}

void ejercicio7(){
    printf("|=================     EJERCICIO 7     ==================|\n");
    printf("|===============   ATENDIENDO CLIENTES   ================|\n");
    printf("\n(COLA 1)\n");
    Cola c1 = cargarColaEnteros();
    c_mostrar(c1);
    printf("\n(COLA 2)\n");
    Cola c2 = cargarColaEnteros();
    c_mostrar(c2);
    printf("\n(COLA 3)\n");
    Cola c3 = cargarColaEnteros();
    c_mostrar(c3);
    printf("(Tiempo De Atencion Al Cliente)\n");
    int tiempoAtencion = enteroMayorQue0();
    Cola res = c_ej7_atenderclientes(c1,c2,c3,tiempoAtencion);

    printf("\n(Resultado)\n");
    c_mostrar_con_clave(res);

    printf("\n\n===        COMPLEJIDAD ALGORITMICA -->  O(n)       ===\n");
    printf("\n|========================================================|\n");
}


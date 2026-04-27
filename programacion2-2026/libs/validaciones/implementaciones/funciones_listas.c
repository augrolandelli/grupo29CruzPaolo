#include "../headers/funciones_listas.h"
#include "../headers/validaciones.h"
#include "../../../02-trabajoPractico-Listas/tp_2_listas.h"
#include <stdio.h>
#include <stdlib.h>

int printMenu(){
    printf("|================================|\n");
    printf("|BIENVENIDO AL TP DE RECURSIVIDAD|\n");
    printf("|1) Salir                        |\n");
    printf("|2) Ejercicios con una lista     |\n");
    printf("|3) Lista2 multiplo de Lista1    |\n");
    printf("|4) Comparar listas              |\n");
    printf("|5) Coeficientes de un polinomio |\n");
    printf("|6) Sublistas                    |\n");
    printf("|================================|\n");
    int n = enteroEnRango(1, 6);
    return n;
}
void ejercicio2(){
    printf("|================     EJERCICIO 2     =================|\n");
    printf("|========       Ingrese dos listas para:       ========|\n");
    printf("| a) Retornar valores de L1 que no esten en L2         |\n");
    printf("| b) Retornar valores de L2 que no esten en L1         |\n");
    printf("| c) Retornar valores en comun de ambas listas         |\n");
    printf("| d) Retornar promedio de ambas listas                 |\n");
    printf("| e) Retornar valor minimo de cada lista y su posicion |\n");
    printf("|======================================================|\n");
    printf("\n===============     PRIMER LISTA     ================\n");
    Lista l1 = cargarListaEnteros();
    printf("\n===============    SEGUNDA  LISTA    ================\n");
    Lista l2 = cargarListaEnteros();

    Lista resA = verElementosQueNoSeRepiten(l1, l2);
    printf("\n======   ELEMENTOS DE L1 QUE NO ESTAN EN L2   ======\n");
    l_mostrar(resA);

    Lista resB = verElementosQueNoSeRepiten(l2, l1);
    printf("\n======   ELEMENTOS DE L2 QUE NO ESTAN EN L1   ======\n");
    l_mostrar(resB);


    float promL1 = promedio(l1);
    printf("\n======   PROMEDIO LISTA 1 : %f   ======\n", promL1);
    float promL2 = promedio(l2);
    printf("\n======   PROMEDIO LISTA 2 : %f   ======\n", promL2);

    ResultadoValorMinimo res = valorMinimo(l1,l2);
    printf("\n======   EL MENOR VALOR DE  L1 ES: %d Y ESTA EN LA POSICION '%d'   ======\n", res.valor, res.pos);
    printf("\n======   EL MENOR VALOR DE  L2 ES: %d Y ESTA EN LA POSICION '%d'   ======\n", res.valor_2, res.pos_2);



}
void ejercicio3(){
    printf("|===========EJERCICIO 3===========|\n");
}
void ejercicio4(){
    printf("|================     EJERCICIO 4     =================|\n");
    printf("|========       Ingrese dos listas para:       ========|\n");
    printf("|========     Compararlas de manera l1->l2     ========|\n");
    printf("|======================================================|\n");
    printf("\n===============     PRIMER LISTA     ================\n");
    Lista l1 = cargarListaEnteros();
    printf("\n===============    SEGUNDA  LISTA    ================\n");
    Lista l2 = cargarListaEnteros();
    int res = CompararListas(l1, l2);
    if(res == 0){
        printf("\nL1 == L2\n");
    }else if(res == 1){
        printf("\nL1 > L2\n");
    }else if(res == 0){
        printf("\nL1 < L2\n");
    }
}
void ejercicio5(){
    printf("|===========EJERCICIO 5===========|\n");
}
void ejercicio6(){

    printf("|================     EJERCICIO 4     =================|\n");
    printf("|========       Ingrese dos listas para:       ========|\n");
    printf("|========      Ver si L2 es sublista de L1     ========|\n");
    printf("|======================================================|\n");
    printf("\n===============     PRIMER LISTA     ================\n");
    Lista l1 = cargarListaEnteros();
    printf("\n===============    SEGUNDA  LISTA    ================\n");
    Lista l2 = cargarListaEnteros();
    bool res = esSublista(l1,l2);
    if(res){
        printf("L2 es sublista de L1");
    }else{
        printf("L2 no es sublista de L1");
    }
}

#include <stdio.h>
#include <stdlib.h>
#include "../libs/validaciones/headers/funciones.h"
#include "../libs/validaciones/headers/validaciones.h"
int main()
{
    int x = printMenu();
    switch(x){
        case 0:
            printf("\nSaliendo del programa!!!\n");
            return 0;
        case 1:
            ejercicio1();
            break;
        case 2:
            ejercicio2();
            break;
        case 3:
            ejercicio3();
            break;
        case 4:
            ejercicio4();
            break;
        case 5:
            ejercicio5();
            break;
        case 6:
            ejercicio6();
            break;
        case 7:
            ejercicio7();
            break;
        case 8:
            ejercicio8();
            break;
        case 9:
            ejercicio9();
            break;
        case 10:
            ejercicio10();
            break;
        default:
            printf("Ese ejercicio no existe, solo del 0 al 10.\n\n");
    }
}

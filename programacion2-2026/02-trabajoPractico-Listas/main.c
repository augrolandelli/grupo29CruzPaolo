#include <stdio.h>
#include <stdlib.h>
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/validaciones/headers/funciones_listas.h"

int main()
{
    int x = printMenu();
    switch(x){
        case 1:
            printf("\nSaliendo del programa!!!\n");
            return 0;
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
        default:
            printf("Ese ejercicio no existe, solo del 2 al 6 o 1 para salir.\n\n");
    }
}

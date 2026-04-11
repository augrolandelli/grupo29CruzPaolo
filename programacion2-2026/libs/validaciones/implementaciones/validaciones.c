#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../headers/validaciones.h"

int printMenu(){
    printf("|================================|\n");
    printf("|BIENVENIDO AL TP DE RECURSIVIDAD|\n");
    printf("|0) Salir                        |\n");
    printf("|1) Palindomo                    |\n");
    printf("|2) Otro                         |\n");
    printf("|================================|\n");
    int n = enteroEnRango(0, 10);
    return n;
}

int entero(){
    int numero;
    int resultado;
    do{
        printf("Ingrese un numero: ");
        resultado = scanf("%d", &numero);
        if (resultado != 1) {
            printf("Error: Debe ser un valor numerico.\n");
            while (getchar() != '\n');
        }
    }while(resultado != 1);
    return numero;
}

int enteroEnRango(int minimo, int maximo){
    int numero;
    int resultado;
    do{
        printf("Ingrese un numero entre %d y %d: ", minimo, maximo);
        resultado = scanf("%d", &numero);
        if (resultado != 1) {
            printf("Error: Debe ser un valor numerico.\n");
            while (getchar() != '\n');
        } else if (numero < minimo || numero > maximo) {
            printf("Error: El numero %d esta fuera del rango permitido [%d - %d].\n", numero, minimo, maximo);
        }
    }while(resultado != 1 || numero < minimo || numero > maximo);
    return numero;
}


int enteroPositivo(){
    int numero;
    int resultado;
    do{
        printf("Ingrese un numero positivo: ");
        resultado = scanf("%d", &numero);
        if (resultado != 1) {
            printf("Error: Debe ser un valor numerico.\n");
            while (getchar() != '\n');
        } else if (numero < 0) {
            printf("Error: El numero debe ser positivo.\n");
        }
    }while(resultado != 1 || numero < 0);
    return numero;
}

void sacarEspacios(char* frase){
    int i = 0, j = 0;
    while (frase[i]) {
        if (frase[i] != ' ') {
            frase[j++] = frase[i];
        }
        i++;
    }
    frase[j] = '\0';
}
char* fraseMinuscula(char* cadena){
    for(int i = 0; cadena[i]; i++){
        cadena[i] = tolower(cadena[i]);
    }
    return cadena;
}

char * pedirSenial(){
    char* cadena = malloc(sizeof(char)*100);
    int valida = 0;
    while (!valida) {
        printf("Ingrese la senial (conjuno de caracteres L y H mayusculas): ");
        scanf("%99s", cadena);
        valida = 1;
        for (int i = 0; cadena[i] != '\0'; i++) {
            if (cadena[i] != 'L' && cadena[i] != 'H') {
                printf("Error: Solo se permiten caracteres 'L' y 'H' en mayusculas.\n");
                valida = 0;
                break;
            }
        }
    }
    return cadena;
}

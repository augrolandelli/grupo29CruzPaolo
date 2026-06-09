#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../headers/validaciones.h"


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

int enteroMayorQue0(){
    int numero;
    int resultado;
    do{
        printf("Ingrese un numero positivo: ");
        resultado = scanf("%d", &numero);
        if (resultado != 1) {
            printf("Error: Debe ser un valor numerico.\n");
            while (getchar() != '\n');
        } else if (numero <= 0) {
            printf("Error: El numero debe ser positivo.\n");
        }
    }while(resultado != 1 || numero <= 0);
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

int pedirNumeroNatural(char *mensaje) {
    char linea[100];
    int num;
    char extra;

    while (1) {
        printf("%s", mensaje);

        if (fgets(linea, sizeof(linea), stdin) == NULL) {
            printf("Error al leer entrada. Intente de nuevo.\n");
            continue;
        }

        linea[strcspn(linea, "\n")] = '\0';

        if (sscanf(linea, "%d %c", &num, &extra) != 1) {
            printf("Error: Ingrese solo numeros naturales (0 o mayor).\n");
            continue;
        }

        if (num < 0) {
            printf("Error: No se permiten numeros negativos.\n");
            continue;
        }

        return num;
    }
}
void pedirConjunto(int conjunto[], int *tamano) {
    *tamano = pedirNumeroNatural("Ingrese la cantidad de elementos del conjunto: ");

    printf("Ingrese los %d elementos separados por espacios:\n", *tamano);
    for (int i = 0; i < *tamano; i++) {
        char mensaje[50];
        sprintf(mensaje, "Elemento %d: ", i + 1);
        conjunto[i] = pedirNumeroNatural(mensaje);
    }
}

Lista cargarListaEnteros(){
    Lista l = l_crear();
    int longitud;

    do{
        printf("Cuantos elementos tendra la lista? ");
        longitud = enteroPositivo();

        if (longitud == 0) {
            printf("Error: La lista no puede tener 0 elementos.\n");
        }
    }while(longitud == 0);


    for(int i = 1; i<=longitud; i++){
        printf("Elemento [%d], ", i);
        int e = entero();
        TipoElemento x = te_crear(e);
        l_agregar(l, x);
    }
    return l;
}

Lista cargarListaEnterosPositivos(){
    Lista l = l_crear();
    int longitud;

    do{
        printf("Cuantos elementos tendra la lista? ");
        longitud = enteroPositivo();

        if (longitud == 0) {
            printf("Error: La lista no puede tener 0 elementos.\n");
        }
    }while(longitud == 0);


    for(int i = 1; i<=longitud; i++){
        printf("Elemento [%d], ", i);
        int e = enteroMayorQue0();
        TipoElemento x = te_crear(e);
        l_agregar(l, x);
    }
    return l;
}

void l_mostrar_con_valor(Lista l){
    TipoElemento x;
    Iterador it = iterador(l);
    while(hay_siguiente(it)){
        x = siguiente(it);
        printf(" %d:%s ", x->clave, (char*)x->valor);
    }
}

Pila cargarPilaEnteros(){
    Pila p = p_crear();
    int longitud;

    printf("Cuantos elementos tendra la pila? ");
    longitud = enteroEnRango(0,10);



    for(int i = 1; i<=longitud; i++){
        printf("Elemento [%d], ", i);
        int e = entero();
        TipoElemento x = te_crear(e);
        p_apilar(p, x);
    }
    return p;
}

int PilaLongitud(Pila p){
    int longitud = 0;
    Pila paux = p_crear();
    TipoElemento x;
    while(!p_es_vacia(p)){
        longitud++;
        x = p_desapilar(p);
        p_apilar(paux,x);
    }
    while(!p_es_vacia(paux)){
        x = p_desapilar(paux);
        p_apilar(p,x);
    }
    return longitud;
}

void p_mostrar_con_clave(Pila p){

    Pila p_aux = p_crear();
    TipoElemento x;

    printf("Contenido de la pila: ");

    while(!p_es_vacia(p)){
        x = p_desapilar(p);
        p_apilar(p_aux, x);
        printf(" %d:%d ", x->clave, *(int*)x->valor);
    }

    while(!p_es_vacia(p_aux)){
        p_apilar(p, p_desapilar(p_aux));
    }

}




Cola cargarColaEnteros(){
    Cola c = c_crear();
    int longitud;

    printf("Cuantos elementos tendra la cola? ");
    longitud = enteroEnRango(0,10);



    for(int i = 1; i<=longitud; i++){
        printf("Elemento [%d], ", i);
        int e = entero();
        TipoElemento x = te_crear(e);
        c_encolar(c, x);
    }
    return c;
}

int ColaLongitud(Cola c){
    int longitud = 0;
    Cola caux = c_crear();
    TipoElemento x;
    while(!c_es_vacia(c)){
        longitud++;
        x = c_desencolar(c);
        c_encolar(caux,x);
    }
    while(!c_es_vacia(caux)){
        x = c_desencolar(caux);
        c_encolar(c,x);
    }
    return longitud;
}

void c_mostrar_con_clave(Cola c){

    Cola caux = c_crear();
    TipoElemento x;

    printf("Contenido de la cola con valores: \n");

    while(!c_es_vacia(c)){
        x = c_desencolar(c);
        c_encolar(caux, x);
        printf(" %s \n", (char*)x->valor);
    }

    while(!c_es_vacia(caux)){
        x = c_desencolar(caux);
        c_encolar(c, x);
    }
}

bool validarColaEj5(Cola c){
    bool valida = true;
    TipoElemento x, y, z;
    Cola caux = c_crear();
    Cola caux2 = c_crear();
    while(!c_es_vacia(c)){
        x = c_desencolar(c);
        c_encolar(caux,x);
        if(x->clave < 2){
            valida = false;
        }
        int apariciones = 0;
        while(!c_es_vacia(c)){
            y = c_desencolar(c);
            c_encolar(caux2,y);
            if(x->clave == y->clave){
                apariciones++;
            }
        }
        while(!c_es_vacia(caux2)){
            z = c_desencolar(caux2);
            c_encolar(c,z);
        }
        if(apariciones>0){
            valida = false;
        }

    }
    while(!c_es_vacia(caux)){
        x = c_desencolar(caux);
        c_encolar(c,x);
    }

    return valida;
}

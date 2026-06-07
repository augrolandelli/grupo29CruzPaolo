#include "tp_pilas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
    2.	Dada una pila cargada con valores al azar realizar los siguientes ejercicios:
 */

//  a.	Buscar una clave y determinar si existe en la Pila (sin perder la pila).
// Si la encuentra retorna true, caso contrario false
bool p_ej2_existeclave(Pila p, int clave)
{
    Pila paux = p_crear();
    TipoElemento x;
    bool res = false;
    while(!p_es_vacia(p)){
        x = p_desapilar(p);
        if(x->clave == clave){
            res = true;
        }
        p_apilar(paux,x);
    }
    while(!p_es_vacia(paux)){
        x = p_desapilar(paux);
        p_apilar(p,x);
    }
    return res;
}

//  b.	Colocar en una posición ordinal determinada, recibida por parámetro, un nuevo elemento (Insertar un elemento nuevo).
// Retorna la nueva pila con el nuevo elemento, caso contrario la pila original recibida.
Pila p_ej2_colocarelemento(Pila p, int posicionordinal, TipoElemento x){
    Pila paux = p_crear();
    TipoElemento y;
    int pos = 0;
    while(!p_es_vacia(p)){
        pos++;

        y = p_desapilar(p);
        if(pos == posicionordinal){
            p_apilar(paux,x);
        }
        p_apilar(paux,y);
    }
    pos++;
    if(pos == posicionordinal){
        p_apilar(paux,x);
    }
    while(!p_es_vacia(paux)){
        x = p_desapilar(paux);
        p_apilar(p,x);
    }
    return p;
}

//  c.	Eliminar de una pila un elemento dado (primera ocurrencia encontrada por la clave).
// retorna la nueva pila sin la clave, si la encuentra, sino retorna la misma pila que recibio.
Pila p_ej2_eliminarclave(Pila p, int clave){
    Pila paux = p_crear();
    TipoElemento x;
    while(!p_es_vacia(p)){
        x = p_desapilar(p);
        if(x->clave == clave){
            break;
        }
        p_apilar(paux,x);
    }
    while(!p_es_vacia(paux)){
        x = p_desapilar(paux);
        p_apilar(p,x);
    }
    return p;
}

//  d.	Intercambiar los valores de 2 posiciones ordinales de la pila, por ejemplo la 2da con la 4ta.
// retorna la nueva pila con las posiciones cambiadas, siempre que sea posible haerlo, caso contrario retorna la pila recibida.
Pila p_ej2_intercambiarposiciones(Pila p, int pos1, int pos2){
    Pila res = p_crear();
    int contador = 0;
    Pila paux = p_crear();
    TipoElemento x, epos1, epos2;
    while(!p_es_vacia(p)){
        contador++;
        x = p_desapilar(p);
        if(contador == pos1){
            epos1 = x;
        }else if(contador == pos2){
            epos2 = x;
        }
        p_apilar(paux,x);
    }
    while(!p_es_vacia(paux)){
        x = p_desapilar(paux);
        p_apilar(p,x);
        p_apilar(res,x);
    }
    contador = 0;
    while(!p_es_vacia(res)){
        contador++;
        x = p_desapilar(res);
        if(contador == pos1){
            x = epos2;
        }else if(contador == pos2){
            x = epos1;
        }
        p_apilar(paux,x);
    }
    while(!p_es_vacia(paux)){
        x = p_desapilar(paux);
        p_apilar(res,x);
    }
    return res;
}

//  e.	Duplicar el contenido de una pila.
// retorna la nueva pila. Si esta vacia retorna otra vacia.
Pila p_ej2_duplicar(Pila p){
    Pila paux = p_crear();
    Pila p2 = p_crear();
    TipoElemento x;

    while(!p_es_vacia(p)){
        x = p_desapilar(p);
        p_apilar(paux,x);
    }
    while(!p_es_vacia(paux)){
        x = p_desapilar(paux);
        p_apilar(p,x);
        p_apilar(p2,x);
    }
    return p2;
}

//  f.	Contar los elementos de la pila.
// retorna la cantidad de elementos de la pila. Si esta vacia retorna 0 (cero).
int p_ej2_cantidadelementos(Pila p){
    int elementos = 0;
    Pila paux = p_crear();
    TipoElemento x;
    while(!p_es_vacia(p)){
        elementos++;
        x = p_desapilar(p);
        p_apilar(paux,x);
    }
    while(!p_es_vacia(paux)){
        x = p_desapilar(paux);
        p_apilar(p,x);
    }
    return elementos;
}

/**
 3.	Dadas dos pilas, determinar si sus contenidos son exactamente iguales (solo por la clave), sin destruirlas.
	Utilizar para la resolución del problema una única pila auxiliar.
	Determinar la complejidad algorítmica de la solución.
 */
// retorna true si son exactamente iguales, caso contrario retorna false
bool p_ej3_iguales(Pila p1, Pila p2){
    bool res = true;
    Pila paux = p_crear();
    TipoElemento x, y;
    while(!p_es_vacia(p1) && !p_es_vacia(p2) && res == true){
        x = p_desapilar(p1);
        y = p_desapilar(p2);
        if(x->clave != y->clave){
            res = false;
        }
        p_apilar(paux,x);
        p_apilar(paux,y);
    }
    while(!p_es_vacia(paux)){
        x=p_desapilar(paux);
        p_apilar(p2,x);
        y=p_desapilar(paux);
        p_apilar(p1,y);
    }
    return res;
}

/**
 4.	Construir un algoritmo que, utilizando el TAD Pila, permita convertir un número decimal pasado como parámetro,
	a su correspondiente valor expresado en una base de 2 a 16 (hexadecimal).
	Determinar la complejidad algorítmica de la solución.
 */
// retorna el valor cambiado de base como un string (char*).  Si la base no esta entre 2 y 16 retorno el mismo numero recibido como string (char*).
char* p_ej4_cambiarbase(int nrobasedecimal, int nrootrabase){
    char* resultado = (char*) malloc(100 * sizeof(char));
    Pila p = p_crear();
    TipoElemento x;
    int resto;
    int i = 0;

    if(nrootrabase < 2 || nrootrabase > 16){
        char* resultado = (char*) malloc(20 * sizeof(char));
        sprintf(resultado, "%d", nrobasedecimal);
        return resultado;
    }

    if(nrobasedecimal == 0){
        char* resultado = (char*) malloc(2 * sizeof(char));
        strcpy(resultado, "0");
        return resultado;
    }

    while(nrobasedecimal > 0){
        resto = nrobasedecimal % nrootrabase;
        p_apilar(p, te_crear(resto));
        nrobasedecimal = nrobasedecimal / nrootrabase;
    }

    while(!p_es_vacia(p)){
        x = p_desapilar(p);
        if(x->clave >= 10)  { resultado[i] = 'A' + (x->clave - 10); }
        else                { resultado[i] = x->clave + '0'; }
        i++;
    }

    resultado[i] = '\0';

    return resultado;
}

/**
 5.	Invertir el contenido de una pila sin destruir la pila original.
	Se debe retornar la nueva pila invertida y la original no se debe perder.
	Determinar la complejidad algorítmica de la solución.
 */
Pila  p_ej5_invertir(Pila p){
    Pila res = p_crear();
    Pila paux = p_crear();
    TipoElemento x;
    while(!p_es_vacia(p)){
        x = p_desapilar(p);
        p_apilar(paux,x);
        p_apilar(res,x);
    }
    while(!p_es_vacia(paux)){
        x = p_desapilar(paux);
        p_apilar(p,x);
    }
    return res;
}

/**
6.	Dada una pila con valores al azar eliminar todas las ocurrencias de un determinado ítem sin perder la pila original.
	Deberá retornar una nueva pila sin el ítem en consideración.
	Resolver iterativamente y recursivamente.
	Determinar la complejidad algorítmica de ambas soluciones.
 */
// retornar la nueva pila sin la clave que se debe sacar (eliminar). Si la clave no esta se retorna la pila recibida.
// La definicion vale para ambas resoluciones
Pila p_ej6_eliminarclave(Pila p, int clave){
    Pila paux = p_crear();
    Pila res = p_crear();
    TipoElemento x;
    while(!p_es_vacia(p)){
        x = p_desapilar(p);
        p_apilar(paux,x);

    }
    while(!p_es_vacia(paux)){
        x = p_desapilar(paux);
        if(x->clave != clave){
            p_apilar(res,x);
        }
        p_apilar(p,x);
    }
    return res;
}

void eliminarclaveRecAux(Pila p, Pila paux, Pila res, int clave){
    if(p_es_vacia(p)){
        return;
    }
    TipoElemento x = p_desapilar(p);
    p_apilar(paux,x);
    if(x->clave != clave){
        p_apilar(res,x);
    }
    eliminarclaveRecAux(p,paux,res,clave);
}

Pila p_ej6_eliminarclaverecursiva(Pila p, int clave){
    TipoElemento x;
    Pila res = p_crear();
    Pila paux = p_crear();
    eliminarclaveRecAux(p,paux,res, clave);
    while(!p_es_vacia(paux)){
        x = p_desapilar(paux);
        p_apilar(p,x);
    }
    return res;
}

/**
7.	Dada dos pilas realizar una función que permita determinar los elementos que tienen en común.
	Debe retornar una nueva pila con esos elementos (que están en ambas pilas) sin perder las pilas originales.
	Determinar la complejidad algorítmica de la solución.
 */
// retornar la nueva pila con las claves en comun de ambas Pilas recibidas por parametro.  Si no hay claves en comun retornar una pila vacia.
Pila p_ej7_elementoscomunes(Pila p1, Pila p2){
    bool encontro = false;
    Pila paux1 = p_crear();
    Pila paux2 = p_crear();
    Pila res = p_crear();
    TipoElemento x,y;
    while(!p_es_vacia(p1)){
        encontro = false;
        x = p_desapilar(p1);
        p_apilar(paux1,x);
        while(!p_es_vacia(p2) && encontro == false){
            y = p_desapilar(p2);
            p_apilar(paux2,y);
            if(x->clave == y->clave){
                encontro = true;
                p_apilar(res,x);
            }
        }
        while(!p_es_vacia(paux2)){
            y = p_desapilar(paux2);
            p_apilar(p2,y);
        }
    }

    while(!p_es_vacia(paux1)){
        x = p_desapilar(paux1);
        p_apilar(p1,x);
    }
    return res;
}

/**
8.	Dada una pila con valores repetidos, se desea obtener una nueva pila con todos los valores (sin repetición) y la cantidad de veces que aparecen.
	No debe perderse la pila original.  El proceso recibe la pila con las repeticiones  y retorna una nueva pila.
	Determinar la complejidad algorítmica de la solución.
 */
// retornar la nueva pila con las claves unicas (no deben existir repetidas) y por cada una la cantidad de veces que aparecia en la Pila recibida por parametro
// Si la pila estavacia retorna pila vacia.
Pila p_ej8_sacarrepetidos(Pila p){

    Pila p_aux = p_crear();
    Pila SinRepetidos = p_crear();
    Pila p_resultado = p_crear();
    TipoElemento x,y;
    int cantidad=0;

    //Creo una pilas con elementos sin repetir.
    while(!p_es_vacia(p)){
        x = p_desapilar(p);
        p_apilar(p_aux, x);
        if(!p_ej2_existeclave(SinRepetidos, x->clave)){
            p_apilar(SinRepetidos, x);
        }
    }

    while(!p_es_vacia(p_aux)){
        p_apilar(p, p_desapilar(p_aux));
    }

    //Ahora agarro el primer elemento de la pila sin repetir y evaluo la cantidad de veces que aparece en la pila original.
    //metodo corte de control.
    while(!p_es_vacia(SinRepetidos)){

        x = p_desapilar(SinRepetidos);

        while(!p_es_vacia(p)){
            y = p_desapilar(p);
            p_apilar(p_aux, y);
            if(x->clave == y->clave)    {cantidad ++;}
        }

        int* contador = malloc(sizeof(int));    //creo un puntero CONTADOR y Guardo memoria
        *contador = cantidad;                   //en esa memoria reservada, almaceno la CANTIDAD
        x->valor = contador;  //Ahora si meto en X->valor, la cantidad de veces que se repitio el elemento
        p_apilar(p_resultado, x);  //almaceno el TipoElemento con la clave y la cantidad de veces que aparece.
        cantidad = 0;   //reinicio mi contador.

        //p_cambiar(p, p_aux); Vuelvo a cargar p con los contenidos que le habia desapilado.
        while(!p_es_vacia(p_aux)){
            p_apilar(p, p_desapilar(p_aux));
        }
    }

    return p_resultado;
}

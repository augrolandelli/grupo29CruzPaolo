#include "tp_pilas.h"
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
Pila p_ej2_intercambiarposiciones(Pila p, int pos1, int pos2);

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
    p_mostrar(paux);
    while(!p_es_vacia(paux)){
        x=p_desapilar(paux);
        p_apilar(p2,x);
        y=p_desapilar(paux);
        p_apilar(p1,y);
    }
    return res;
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
        if(x->clave != clave){
            p_apilar(res,x);
        }
    }
    while(!p_es_vacia(paux)){
        x = p_desapilar(paux);
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
Pila p_ej8_sacarrepetidos(Pila p);

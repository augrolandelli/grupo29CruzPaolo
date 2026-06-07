#include "tp_colas.h"
#include "../libs/validaciones/headers/validaciones.h"

/**
    2.	Resolver los siguientes puntos:
 */

//  a.	Informar si un elemento dado se encuentra en la cola.
// Si la encuentra retorna true, caso contrario false
bool c_ej2_existeclave(Cola c, int clave){
    bool encontrado = false;
    Cola caux = c_crear();
    TipoElemento x;
    while(!c_es_vacia(c)){
        x = c_desencolar(c);
        if(x->clave == clave){
            encontrado = true;
        }
        c_encolar(caux,x);
    }
    while(!c_es_vacia(caux)){
        x = c_desencolar(caux);
        c_encolar(c,x);
    }
    return encontrado;
}

//  b.	Agregar un nuevo elemento en una posición dada (colarse).
// Retorna la nueva cola con el elemento insertado, caso contrario la cola original recibida.
Cola c_ej2_colarelemento(Cola c, int posicionordinal, TipoElemento X){
    Cola cb = c_crear();
    int contador = 1;
    Cola caux = c_crear(); //para almacenar lo de cola con el nuevo elemento ya agregado
    Cola caux2 = c_crear(); //para volver la original
    TipoElemento y;
    if(c_es_vacia(c)){
        return c;
    }
    while(!c_es_vacia(c)){
        y = c_desencolar(c);
        if(contador == posicionordinal){
            c_encolar(caux,X);
        }
        c_encolar(caux,y);
        c_encolar(caux2,y);
        contador++;
    }
    if(contador == posicionordinal){ //vuelvo a preguntar por si ingreso cargar en el ultimo lugar
        c_encolar(caux,X);
    }
    while(!c_es_vacia(caux)){
        y = c_desencolar(caux);
        c_encolar(cb,y);
    }
    while(!c_es_vacia(caux2)){
        y = c_desencolar(caux2);
        c_encolar(c,y);
    }

    return cb;
}

//  c.	Dado un elemento sacarlo de la cola todas las veces que aparezca.
// Retorna la nueva cola sin el/los elemento/s, caso contrario la cola original recibida.
Cola c_ej2_sacarelemento(Cola c, int clave){
    if(c_es_vacia(c)){
        return c;
    }
    Cola res = c_crear();
    Cola caux = c_crear();
    TipoElemento x;

    while(!c_es_vacia(c)){
        x = c_desencolar(c);
        c_encolar(caux,x);
        if(x->clave != clave){
            c_encolar(res,x);
        }
    }
    while(!c_es_vacia(caux)){
        x = c_desencolar(caux);
        c_encolar(c,x);
    }
    return res;
}

//  d.	Contar los elementos de la cola.
// Retorna la cantidad de elementos de la cola, o 0 (cero) si esta vacia.
int c_ej2_contarelementos(Cola c){
    int contador = 0;
    Cola caux = c_crear();
    TipoElemento x;
    while(!c_es_vacia(c)){
        contador++;
        x = c_desencolar(c);
        c_encolar(caux,x);
    }
    while(!c_es_vacia(caux)){
        x = c_desencolar(caux);
        c_encolar(c,x);
    }
    return contador;
}

//  e.	Realizar una función que realice una copia de una cola.
// Retorna la cola copia tal cual la original, no debe perserse la original.  Si es vacia retorna vacia.
Cola c_ej2_copiar(Cola c){
    Cola res = c_crear();
    Cola caux = c_crear();
    TipoElemento x;
    while(!c_es_vacia(c)){
        x = c_desencolar(c);
        c_encolar(caux,x);
        c_encolar(res,x);
    }
    while(!c_es_vacia(caux)){
        x = c_desencolar(caux);
        c_encolar(c,x);
    }
    return res;
}

//  f.	Invertir el contenido de una cola sin destruir la cola original.
// Retorna la cola al reves (invertida), no debe perserse la original. Si es vacia retorna vacia.
Cola c_ej2_invertir(Cola c){
    Cola res = c_crear();
    Cola caux = c_crear();
    Pila paux = p_crear();
    TipoElemento x,y;
    while(!c_es_vacia(c)){
        x = c_desencolar(c);
        c_encolar(caux,x);
        p_apilar(paux,x);
    }
    while(!c_es_vacia(caux) && !p_es_vacia(paux)){
        x = c_desencolar(caux);
        y = p_desapilar(paux);

        c_encolar(c,x);
        c_encolar(res,y);
    }
    return res;
}

/**
3.	Dadas dos colas, determinar si sus contenidos son iguales tanto en posición como en datos (solo comparar por la clave),
	sin destruirlas. Utilizar para la resolución del problema una sola cola auxiliar.
 */
// retorna true si son exactamente iguales, caso contrario retorna false.
bool c_ej3_iguales(Cola c1, Cola c2){
    bool iguales = true;
    int long1 = ColaLongitud(c1);
    int long2 = ColaLongitud(c2);
    if(long1 != long2){
        return false;
    }
    TipoElemento x,y;

    for(int i = 0; i<long1 ; i++){
        x = c_desencolar(c1);
        y = c_desencolar(c2);
        if(x->clave != y->clave){
            iguales = false;
        }
        c_encolar(c1,x);
        c_encolar(c2,y);
    }
    return iguales;
}

/**
4.	Dada una cola de números enteros, no ordenada,
	construir un algoritmo que permita pasar a otra cola todos los elementos que no se repiten en la primera,
	sin destruir el contenido de la cola original y dejándola en su estado inicial.
	Ejemplo: si "C" contiene (12,6, 8, 5, 8, 12, 12) la cola resultado del proceso sería (6,5).
 */
// Retorna la cola con las claves que no tienen repeticiones, caso contrario si todas se repiten retorna cola vacia.
Cola  c_ej4_colanorepetidos(Cola c){
    int aparecio = 0;
    Cola colaux = c_crear();
    Cola colaux2 = c_crear();
    Cola colaux3 = c_crear();
    Cola res = c_crear();
    TipoElemento x,y,z;
    while(!c_es_vacia(c)){
        x = c_desencolar(c);
        c_encolar(colaux,x);
        c_encolar(colaux2,x);
    }
    while(!c_es_vacia(colaux)){
        x = c_desencolar(colaux);
        c_encolar(c,x);
        while(!c_es_vacia(colaux2)){
            y = c_desencolar(colaux2);

            if(x->clave == y->clave){
                aparecio++;
            }
            c_encolar(colaux3,y);
        }
        if(aparecio <= 1){
            c_encolar(res,x);
        }
        while(!c_es_vacia(colaux3)){
            z = c_desencolar(colaux3);
            c_encolar(colaux2,z);
        }
        aparecio = 0;
    }
    return res;
}

/**
5.	Dada una cola de valores enteros no repetidos y mayores o iguales a 2,
	obtener todos los valores que son Divisores Totales o parciales.
	Se dice que un valor es Divisor Total si permite dividir a todos los demás valores de la cola en forma exacta.
	Se dice que un divisor es parcial si al menos puede dividir en forma exacta al menos al 50% de la cola
	(es decir a la mitad de los elementos).
 */
// retorna la clave de/los divisor/es total/es o parcial/es en la función.
// Si no hay ni divisor total ni parcial retornar cola vacia.
// En el atributo valor debe venir un "bool" en TRUE cuando el divisor es total, caso contrario false.
Cola c_ej5_divisortotal(Cola c){

}


#include "tp_colas.h"
#include <stdio.h>
#include <stdlib.h>
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
    if(ColaLongitud(c1) != ColaLongitud(c2)){
        return false;
    }

    Cola c_aux = c_crear();
    TipoElemento x, y;
    bool iguales = true;

    while(!c_es_vacia(c1)){
        x = c_desencolar(c1);
        y = c_desencolar(c2);
        if(x->clave != y->clave){
            iguales = false;
        }
        c_encolar(c_aux, x);
        c_encolar(c_aux, y);
    }

    while(!c_es_vacia(c_aux)){
        x = c_desencolar(c_aux);
        c_encolar(c1, x);
        y = c_desencolar(c_aux);
        c_encolar(c2, y);
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

    Cola res = c_crear();
    if(c_es_vacia(c))   return res;

    Cola c_aux = c_crear();
    Cola copia = c_ej2_copiar(c);
    TipoElemento x, y;

    int cant_Divisores = 0;
    int longitud_total = c_ej2_contarelementos(c);
    float longitud_media = longitud_total / 2.0;

    while(!c_es_vacia(copia)){

        x = c_desencolar(copia);

        while(!c_es_vacia(c)) {
            y = c_desencolar(c);
            c_encolar(c_aux, y);
            if( (y->clave % x->clave)==0 )   cant_Divisores++;
        }

        if(cant_Divisores == longitud_total){
            bool* DT = malloc(sizeof(bool));
            *DT = true;
            TipoElemento z = te_crear_con_valor(x->clave, DT);
            c_encolar(res, z);
        }
        else if( (cant_Divisores >= longitud_media) ){
            TipoElemento z = te_crear(x->clave);
            bool* DT = malloc(sizeof(bool));
            *DT = false;
            z->valor = DT;
            c_encolar(res, z);
        }

        //restauro la cola
        while(!c_es_vacia(c_aux)){
            c_encolar(c, c_desencolar(c_aux));
        }

        //reinicio el contador
        cant_Divisores = 0;

    }

    return res;
}

/**
6.	Dada una pila y una cola generada con valores al azar retornar en una lista todos los valores comunes a ambas
	y en qué posición ordinal se encontró cada uno en su estructura.
	Si existe mas de una vez la primer posicion encontrada, se retornará cada ocurrencia.
	No se deben destruir las estructuras originales.
	Ejemplo: si “P” = (2,5,8,19,3,4,5) y “C” = (4, 18, 12, 5, 4, 6)
	la lista tendría L = (5:2:4, 4:6:1, 4:6:5, 5:7:4, ).
 */
// retornar una lista con los valores comunes segun las especificaciones del ejercicio.
// Si no existen valores comunes retornar la lista vacia.
Lista c_ej6_comunesapilaycola(Pila p, Cola c)
{
    Pila p_aux = p_crear();
    Cola c_aux = c_crear();
    Lista final = l_crear();
    TipoElemento x, y;
    int pos_p = 0;
    int pos_c = 0;

    //la pila la lee de manera inversa. Mirar EJEMPLO DEL PDF
    while(!p_es_vacia(p)){
        p_apilar(p_aux, p_desapilar(p));
    }

    while (!p_es_vacia(p_aux)) {
        x = p_desapilar(p_aux);
        pos_p ++;
        while (!c_es_vacia(c)) {
            y = c_desencolar(c);
            pos_c++;
            if (x->clave == y->clave) {
                TipoElemento z = te_crear(x->clave);
                char* txt = (char*) malloc(sizeof(char) * 10);
                sprintf(txt ,"%i:%i", pos_p, pos_c);
                z->valor = txt;
                l_agregar(final, z);
            }
            c_encolar(c_aux, y);
        }
        //Restauro la cola original
        while(!c_es_vacia(c_aux)){
            c_encolar(c, c_desencolar(c_aux));
        }
        pos_c = 0;
        p_apilar(p, x);
    }

    return final;
}


/**
7.	Un negocio tiene 3 ventanillas para atender a sus clientes. Los clientes forman cola en cada ventanilla.
	Un día, dos de los tres empleados que atienden las ventanillas no pueden asistir al trabajo,
	quedando uno solo para atender a las tres colas. Este empleado decide que, a medida que lleguen los clientes,
	atenderá por cierta cantidad de minutos (que denominaremos Q) a cada cola, paseándose por todas las colas equitativamente.
	Se pide que implemente un algoritmo que modele esta situación y dé como resultado el orden en que fueron atendidos los clientes.
 */
// retornar la cola con los resultados de la atenciones de los clientes.  Ver el ejemplo en el PDF del TP.
// retornar en la clave el nro de cola que lo atendio y en el void* de cada elemento los textos "Cliente 1 Cola 3", Cliente 1 Cola 2, etc.
// Segun el ejemplo el primer item de la cola seria clave: 3, void* "Cliente 1 Cola 3".
// Si las colas estan vacias, retornar cola vacia.
Cola c_ej7_atenderclientes(Cola c1, Cola c2, Cola c3, int tiempoatencion){
    Cola res = c_crear();
    TipoElemento x, y, z;
    int cont1 = 1, cont2 = 1, cont3 = 1;

    while(!c_es_vacia(c1) || !c_es_vacia(c2) || !c_es_vacia(c3)){
        if (!c_es_vacia(c1)) {
            x = c_desencolar(c1);
            x->clave -= tiempoatencion;

            if (x->clave <= 0) {
                char* texto1 = (char*) malloc(50 * sizeof(char));
                sprintf(texto1, "Cliente %d Cola 1", cont1++);

                TipoElemento x1 = te_crear_con_valor(1, texto1);
                c_encolar(res, x1);

                free(x);
            } else {
                c_encolar(c1, x);
            }
        }

        if (!c_es_vacia(c2)) {
            y = c_desencolar(c2);
            y->clave -= tiempoatencion;

            if (y->clave <= 0) {
                char* texto2 = (char*) malloc(50 * sizeof(char));
                sprintf(texto2, "Cliente %d Cola 2", cont2++);

                TipoElemento y1 = te_crear_con_valor(2, texto2);
                c_encolar(res, y1);

                free(y);
            } else {
                c_encolar(c2, y);
            }
        }

        if (!c_es_vacia(c3)) {
            z = c_desencolar(c3);
            z->clave -= tiempoatencion;

            if (z->clave <= 0) {
                char* texto3 = (char*) malloc(50 * sizeof(char));
                sprintf(texto3, "Cliente %d Cola 3", cont3++);

                TipoElemento z1 = te_crear_con_valor(3, texto3);
                c_encolar(res, z1);

                free(z);
            } else {
                c_encolar(c3, z);
            }
        }
    }
    return res;
}






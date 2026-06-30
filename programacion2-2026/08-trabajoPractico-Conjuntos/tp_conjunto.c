#include <stdio.h>
#include <stdlib.h>
#include "tp_conjunto.h"

/**
2.	Desarrollar un algoritmo que dado dos conjuntos de elementos tipo numérico (clave) 
	verifique las operaciones de Unión,  Intersección,  Diferencia y Pertenencia. 
*/
//A)
Conjunto c_ej2_union(Conjunto A, Conjunto B){
    Conjunto unir = cto_union(A, B);
    return unir;
}
//B)
Conjunto c_ej2_interseccion(Conjunto A, Conjunto B){
    Conjunto interseccion = cto_interseccion(A, B);
    return interseccion;
}
//C)
Conjunto c_ej2_diferencia(Conjunto A, Conjunto B){
    Conjunto diferencia = cto_diferencia(A, B);
    return diferencia;
}
//D
bool c_ej2_pertenece(Conjunto conjunto, int clave){
    return cto_pertenece(conjunto, clave);
}

/**
3.	Desarrollar un algoritmo que dada una colección de conjuntos de elementos tipo numérico (clave) 
	realice las operaciones de Unión e Intersección.
	La lista contendra la coleccion de conjuntos.  Cada campo void apunta a un conjunto.
*/
//A)
Conjunto c_ej3_uniones(Lista l_de_conjuntos){
    if(l_es_vacia(l_de_conjuntos)){
        return cto_crear();
    }
    Iterador it = iterador(l_de_conjuntos); //puedo recorrer toda la lista 
    Conjunto resultado = (Conjunto) siguiente(it)->valor; //almaceno el primer conjunto como inicio para el resultado. 
    while(hay_siguiente(it)){
        resultado = cto_union(resultado, (Conjunto) siguiente(it)->valor); //creo union entre el primer conjunto con el siguiente conjunto
    }
    return resultado; //devuelvo la union entre todos los conjuntos
}
//B)
Conjunto c_ej3_intersecciones(Lista l_de_conjuntos){
    if(l_es_vacia(l_de_conjuntos)){
        return cto_crear();
    }
    Iterador it = iterador(l_de_conjuntos); 
    Conjunto resultado = (Conjunto) siguiente(it)->valor; 
    while(hay_siguiente(it)){
        resultado = cto_interseccion(resultado, (Conjunto) siguiente(it)->valor); 
    }
    return resultado; 
}

/**
4.	Desarrollar un algoritmo que dado tres conjuntos puedan demostrar la propiedad de la transitividad:  
	“si A es subconjunto de B y B a su vez es subconjunto de C, entonces A es subconjunto de C”.
*/
bool subConjunto (Conjunto P, Conjunto Q){
    if(cto_cantidad_elementos(P)==0)                                    {return true;}
    if(cto_cantidad_elementos(P) > cto_cantidad_elementos(Q))           {return false;}
    int i = 1; 
    int tamanio = cto_cantidad_elementos(P);
    bool esta = true;
    while(i<=tamanio && esta){
        TipoElemento x = cto_recuperar(P, i);  
        esta = cto_pertenece(Q, x->clave);
        i++;
    }
    return esta; 
}
bool c_ej4_transitividad(Conjunto A, Conjunto B, Conjunto C){
    return subConjunto(A, B) && subConjunto(B, C) && subConjunto(A, C) ; 
}

/**
5.	Desarrollar un algoritmo capaz de resolver la diferencia simétrica (por la clave) entre dos conjuntos. 
	La diferencia simétrica es una operación entre dos conjuntos donde el conjunto resultante está conformado 
	por los elementos no comunes a los dos conjuntos.
*/
Conjunto c_ej5_dif_simetrica(Conjunto A, Conjunto B){
    Conjunto c1 = cto_diferencia(A, B);
    Conjunto c2 = cto_diferencia(B, A);
    return cto_union(c1, c2);
}

/**
6.	Dados dos conjuntos de números naturales se pide determinar si uno es subconjunto propio del otro.  
	Determinar la complejidad algorítmica
*/
bool esSubconjuntopropio(Conjunto P, Conjunto Q, int cp, int cq){
    if(cp >= cq)   
        return false;
    int i = 1;
    bool es_subconjunto = true;
    while(i<=cp && es_subconjunto){
        TipoElemento x = cto_recuperar(P, i);
        es_subconjunto = cto_pertenece(Q, x->clave);
        i++;
    }
    return es_subconjunto;
}
bool c_ej6_subconjuntopropio(Conjunto A, Conjunto B){
    int tamanio_A = cto_cantidad_elementos(A);
    int tamanio_B = cto_cantidad_elementos(B);
    bool AB = esSubconjuntopropio(A, B, tamanio_A, tamanio_B);
    bool BA = esSubconjuntopropio(B, A, tamanio_B, tamanio_A); 
    return (AB || BA) ;
}
//Complejidad Algoritmica: 2n --> O(n), sin tener en cuenta la TAD


/**
7.	Dados 3 conjuntos determinar si alguno es un subconjunto parcial o total del otro.  
	Se considera un subconjunto parcial cuando al menos la mitad de los elementos de uno están en el otro.  
	Determinar la complejidad algorítmica.
	Imprimir el resultado en la función.
*/
void c_ej7_subconjtotalparcial(Conjunto A, Conjunto B, Conjunto C);


/**
8.	Dados dos conjuntos de números naturales se pide determinar si son iguales sin importar la posición 
	de sus elementos.  
	Determinar la complejidad algorítmica.
*/
bool c_ej8_soniguales(Conjunto A, Conjunto B){
    if(cto_cantidad_elementos(A) != cto_cantidad_elementos(B)){
        return false;
    }
    bool son_iguales = true;
    int tamanio_A = cto_cantidad_elementos(A);
    int i = 1;
    while(i<=tamanio_A && son_iguales){
        TipoElemento x = cto_recuperar(A, i);
        son_iguales = cto_pertenece(B, x->clave);
        i++;
    }
    return son_iguales;
}
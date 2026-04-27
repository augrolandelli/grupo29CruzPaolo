#include "tp_2_listas.h"
#include "../libs/listas/headers/listas.h"
#include "stdlib.h"
#include "stdio.h"

Lista verElementosQueNoSeRepiten(Lista l1, Lista l2){
    Lista res = l_crear();
    int long1 = l_longitud(l1);
    int long2 = l_longitud(l2);

    for(int i = 1; i <= long1; i++){
        TipoElemento x = l_recuperar(l1, i);
        int aparecio = 0;

        for(int k = 1; k <= long2; k++){
            TipoElemento y = l_recuperar(l2, k);
            if(x->clave == y->clave){
                aparecio = 1;
            }
        }
        if(!aparecio){
             l_agregar(res,x);
        }
    }
    return res;
}
Lista verElementosRepetidos(Lista l1, Lista l2){
    Lista res = l_crear();
    int long1 = l_longitud(l1);
    int long2 = l_longitud(l2);

    for(int i = 1; i <= long1; i++){
        TipoElemento x = l_recuperar(l1, i);
        int aparecio = 0;

        for(int k = 1; k <= long2; k++){
            TipoElemento y = l_recuperar(l2, k);
            if(x->clave == y->clave){
                aparecio = 1;
            }
        }
        if(aparecio){
             l_agregar(res,x);
        }
    }
    return res;
}


float promedio(Lista l1){

    int longitud = l_longitud(l1);
    int suma = 0;
    for(int i = 1; i <= longitud; i++){
        TipoElemento x = l_recuperar(l1, i);
        suma += x->clave;
    }
    return ((float)suma/longitud);
}

/*

typedef struct resultadoStruct
{
    int pos;
    int valor;
    int pos_2;
    int valor_2;
} ResultadoValorMinimo;
*/

// Punto 2 E
ResultadoValorMinimo valorMinimo(Lista l1, Lista l2){
    ResultadoValorMinimo res;
    TipoElemento x;
    int long1 = l_longitud(l1);
    int long2 = l_longitud(l2);
    x = l_recuperar(l1,1);
    int minimo1 = x->clave;
    x = l_recuperar(l2,1);
    int minimo2 = x->clave;
    for(int i = 1; i<long1;i++){
        x = l_recuperar(l1,i);
        if(x->clave <= minimo1){
            minimo1 = x->clave;
            res.pos = i;
            res.valor = minimo1;
        }
    }

    for(int i = 1; i<=long2;i++){
        TipoElemento x = l_recuperar(l2,i);
        if(x->clave < minimo2){
            minimo2 = x->clave;
            res.pos_2 = i;
            res.valor_2 = minimo2;
        }
    }
    return res;
}


// P4 Retorna 1 si L1 > L2, 2 si L2 > L1, 0 si son iguales
int CompararListas(Lista l1, Lista L2){
    int res;
    Iterador it1 = iterador(l1);
    Iterador it2 = iterador(L2);
    int suma1=0,suma2=0;
    while(hay_siguiente(it1)){
        TipoElemento x = siguiente(it1);
        suma1 += x->clave;
    }
    while(hay_siguiente(it2)){
        TipoElemento y = siguiente(it2);
        suma2 += y->clave;
    }

    if(suma1>suma2){
        res = 1;
    }else if(suma1<suma2){
        res = 2;
    }else{
        res = 0;
    }
    return res;
}


// P6
bool esSublista(Lista l1, Lista l2){
    bool sublista, aparecio;
    Iterador it2 = iterador(l2);
    sublista = true;
    while(hay_siguiente(it2)){
        aparecio = false;
        TipoElemento x = siguiente(it2);
        Iterador it1 = iterador(l1);
        printf("l2:'%d'\n", x->clave);
        while(hay_siguiente(it1)){
            TipoElemento y = siguiente(it1);
            printf("l1:'%d'\n", y->clave);
            printf("\n\nl2:'%d' -  l1: '%d'\n\n", x->clave, y->clave);
            if(x->clave == y->clave){
                aparecio = true;
            }
        }
        if(!aparecio){
            sublista = false;
        }
    }
    return sublista;
}

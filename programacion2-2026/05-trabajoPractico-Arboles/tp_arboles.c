#include "tp_arboles.h"
/**
2.	Dado un árbol binario no vacío determinar:
 */

//  a.	Retornar una lista con todos los nodos terminales u hojas.
void verificarHoja(NodoArbol n, Lista res){
    if(n == NULL){
        return;
    }
    if(n_hijoizquierdo(n)==NULL && n_hijoderecho(n)==NULL){
        TipoElemento x = n_recuperar(n);
        l_agregar(res, x);
    }
    verificarHoja(n_hijoizquierdo(n),res);
    verificarHoja(n_hijoderecho(n),res);
}
Lista a_ej2_hojas(ArbolBinario A){
    Lista res = l_crear();
    verificarHoja(a_raiz(A), res);
    return res;
}


//  b.	Retornar en una estructura todos los nodos interiores (los que no son ni hojas ni raíz)
void verificarInteriores(NodoArbol n, Lista res){
    if(n == NULL){
        return;
    }
    TipoElemento x = n_recuperar(n);
    if(n_hijoizquierdo(n) != NULL || n_hijoderecho(n) != NULL){
        l_agregar(res,x);
    }
    verificarInteriores(n_hijoizquierdo(n),res);
    verificarInteriores(n_hijoderecho(n),res);
}
Lista a_ej2_interiores(ArbolBinario A){
    Lista res = l_crear();
    verificarInteriores(n_hijoizquierdo(a_raiz(A)), res);
    verificarInteriores(n_hijoderecho(a_raiz(A)), res);
    return res;
}

//  c.	Buscar todas las ocurrencias de una clave dentro del árbol. Retornar la posición de cada ocurrencia (puntero al nodo).
void aux_buscarclave(NodoArbol Q, Lista res, int clave){
    if(!a_es_rama_nula(Q)){
        if(n_recuperar(Q)->clave == clave){
            TipoElemento z = te_crear_con_valor(n_recuperar(Q)->clave, n_recuperar(Q)->valor);
            l_agregar(res, z);
        }
        aux_buscarclave(n_hijoizquierdo(Q), res, clave);
        aux_buscarclave(n_hijoderecho(Q), res, clave);
    }
}
Lista a_ej2_buscarclave(ArbolBinario A, int clave){
    if(a_es_vacio(A))
        return l_crear();
    Lista l_res = l_crear();
    aux_buscarclave(a_raiz(A), l_res, clave);
    return l_res;
}

// e.	Calcular la altura de su rama (Altura del Subárbol)
void aux_alturarama(NodoArbol Q, int clave, int contador, int* altura){
    if(!a_es_rama_nula(Q)){
        if(n_recuperar(Q)->clave == clave)
            *altura = contador;
        aux_alturarama(n_hijoizquierdo(Q), clave, contador+1, altura);
        aux_alturarama(n_hijoderecho(Q), clave, contador+1, altura);
    }
}
int a_ej3_alturarama(ArbolBinario A, int clave){
    if(a_es_vacio(A))
        return 0;
    int altura = 0;
    aux_alturarama(a_raiz(A), clave, 1, &altura);
    return altura;
}

// f.	Listar todos los nodos que están en el mismo nivel (solo la clave).
void aux_clavesmismonivel(NodoArbol Q, int nivel, Lista res, int nivel_actual){
    if(!a_es_rama_nula(Q)){
        if(nivel_actual == nivel)
            l_agregar(res, n_recuperar(Q));
        aux_clavesmismonivel(n_hijoizquierdo(Q), nivel, res, nivel_actual+1);
        aux_clavesmismonivel(n_hijoderecho(Q), nivel, res, nivel_actual+1);
    }
}
Lista a_ej3_clavesmismonivel(ArbolBinario A, int nivel){
    if(a_es_vacio(A))
        return l_crear();
    Lista l_resultado = l_crear();
    aux_clavesmismonivel(a_raiz(A), nivel, l_resultado, 0);
    return l_resultado;
}


/**
3.	Para un nodo del árbol binario determinado:
TRABAJAR SOBRE LA PRIMER OCURRECIA DE LA CLAVE
 */

// a.	Indicar el nombre del nodo padre (clave).
void padreRec(NodoArbol n, int clavehijo, int *padre){
    if(n==NULL){
        return;
    }
    if(n_hijoizquierdo(n) != NULL && n_recuperar(n_hijoizquierdo(n))->clave == clavehijo ){
        *padre = n_recuperar(n)->clave;
        return;
    }
    if(n_hijoderecho(n) != NULL && n_recuperar(n_hijoderecho(n))->clave == clavehijo ){
        *padre = n_recuperar(n)->clave;
        return;
    }
    padreRec(n_hijoizquierdo(n), clavehijo, padre);
    padreRec(n_hijoderecho(n), clavehijo, padre);
}
int a_ej3_clavepadre(ArbolBinario A, int clavehijo){
    int padre = -1;
    padreRec(a_raiz(A), clavehijo, &padre);
    return padre;
}

// b.	Listar los hijos (solo las clave/s).
void hijos(NodoArbol n, int clavepadre, Lista res){
    if(n==NULL){
        return;
    }
    TipoElemento x = n_recuperar(n);
    if(x->clave == clavepadre){
        NodoArbol hi = n_hijoizquierdo(n);
        NodoArbol hd = n_hijoderecho(n);

        if(hi != NULL){
            TipoElemento y = n_recuperar(hi);
            l_agregar(res, y);
        }
        if(hd != NULL){
            TipoElemento z = n_recuperar(hd);
            l_agregar(res, z);
        }
    }
    hijos(n_hijoizquierdo(n), clavepadre, res);
    hijos(n_hijoderecho(n), clavepadre, res);
}
Lista a_ej3_hijos(ArbolBinario A, int clavepadre){
    Lista res = l_crear();
    hijos(a_raiz(A), clavepadre, res);
    return res;
}

// c.	Listar el hermano (solo la clave).
void hermanoRec(NodoArbol n, int clave, int *hermano){
    if (n==NULL){
        return;
    }
    if(n_hijoizquierdo(n)!=NULL && n_hijoderecho(n) !=NULL && n_recuperar(n_hijoizquierdo(n))->clave == clave){
        *hermano = n_recuperar(n_hijoderecho(n))->clave;
        return;
    }
    if(n_hijoderecho(n)!=NULL && n_hijoizquierdo(n) !=NULL && n_recuperar(n_hijoderecho(n))->clave == clave ){
        *hermano = n_recuperar(n_hijoizquierdo(n))->clave;
        return;
    }
    hermanoRec(n_hijoizquierdo(n), clave, hermano);
    hermanoRec(n_hijoderecho(n), clave, hermano);

}
int a_ej3_hermano(ArbolBinario A, int clave){
    int hermano = -1;
    hermanoRec(a_raiz(A), clave, &hermano);
    return hermano;
}

// d.	Calcular el nivel en el que se encuentra.
void nivelRec(NodoArbol n, int clave, int contador, int *nivel){
    if(n==NULL){
        return;
    }
    if(n_recuperar(n) != NULL && n_recuperar(n)->clave == clave){
        *nivel = contador;
        return;
    }
    nivelRec(n_hijoizquierdo(n), clave, contador+1, nivel);
    nivelRec(n_hijoderecho(n), clave, contador+1, nivel);
}
int a_ej3_nivel(ArbolBinario A, int clave){
    int nivel = -1;
    nivelRec(a_raiz(A), clave, 0, &nivel);
    return nivel;
}
// e.	Calcular la altura de su rama (Altura del Subárbol)
int a_ej3_alturarama(ArbolBinario A, int clave);

// f.	Listar todos los nodos que están en el mismo nivel (solo la clave).
Lista a_ej3_clavesmismonivel(ArbolBinario A, int nivel);

/**
4.	Para Árboles “N-arios”:
 */
// a.	Dado un árbol n-ario, devolver en forma de lista el resultado del recorrido en anchura del árbol  (solo las claves).
Lista a_ej4_anchura(ArbolBinario A);

// b.	Escribir una función que, dado un árbol n-ario, devuelva el número (cantidad) de hojas de dicho árbol.
void hojasRec(NodoArbol n, int *hojas){
    if (n==NULL){
        return;
    }
    if(n_hijoizquierdo(n)==NULL){
        *hojas+=1;
    }
    hojasRec(n_hijoizquierdo(n), hojas);
    hojasRec(n_hijoderecho(n), hojas);
}


int a_ej4_q_hojas(ArbolBinario A){
    int hojas = 0;
    hojasRec(a_raiz(A), &hojas);
    return hojas;
}

// c.	Escribir una función booleana que dados dos árboles generales determine si tienen la misma estructura, sin importar los datos del mismo (árbol similar).
void similaresRec(NodoArbol na, NodoArbol nb, bool *res){
    if(na==NULL && nb==NULL){
        return;
    }
    if(na==NULL || nb==NULL){
        *res =false;
    }
    similaresRec(n_hijoizquierdo(na), n_hijoizquierdo(nb), res);
    similaresRec(n_hijoderecho(na), n_hijoderecho(nb), res);
}
bool a_ej4_similares(ArbolBinario A, ArbolBinario B){
    bool res = true;
    similaresRec(a_raiz(A), a_raiz(B),&res);
    return res;
}

// d.	Retornar el padre de un nodo del árbol (tipo_elemento).
bool padre(NodoArbol n, int clave, TipoElemento* p)
{
    if (!a_es_rama_nula(n)) {
        TipoElemento x = n_recuperar(n);
        if (x->clave == clave) {
            return true;
        } else {
            if (padre(n_hijoizquierdo(n), clave, p)) {
                TipoElemento x = n_recuperar(n);
                *p = x;
                return false;
            }
            return (padre(n_hijoderecho(n), clave, p));
        }
    }
    return false;
}
TipoElemento a_ej4_padre(ArbolBinario A, int clave)
{
    NodoArbol n = a_raiz(A);
    TipoElemento x = te_crear(-1);
    padre(n, clave, &x);
    return x;
}

// e.	Retornar los hermanos de un nodo del árbol (lista de hermanos).
void listarHermanoCompleto(NodoArbol n, int clave, Lista hermanos){
    if(n == NULL){
        return;
    }

    if(n_recuperar(n)->clave != clave){
        l_agregar(hermanos, n_recuperar(n));
    }

    listarHermanoCompleto(n_hijoderecho(n), clave, hermanos);
}

void hermanosRecCompleto(NodoArbol n, NodoArbol inicio_hermanos, int clave, Lista hermanos){
    if(n == NULL){
        return;
    }

    if(n_recuperar(n)->clave == clave){
        listarHermanoCompleto(inicio_hermanos, clave, hermanos);
        return;
    }

    hermanosRecCompleto(n_hijoizquierdo(n), n_hijoizquierdo(n), clave, hermanos);
    hermanosRecCompleto(n_hijoderecho(n), inicio_hermanos, clave, hermanos);
}

Lista a_ej4_hermanos(ArbolBinario A, int clave){
    Lista hermanos = l_crear();
    hermanosRecCompleto(a_raiz(A), a_raiz(A), clave, hermanos);
    return hermanos;
}

/**
7.	Determinar si dos árboles binarios son equivalentes.
 */
void equivalentesRec(NodoArbol na, NodoArbol nb, bool *equivalentes){
    if(na == NULL && nb == NULL){
        return;
    }
    if( (na == NULL && nb != NULL) || (na != NULL && nb == NULL)){
        *equivalentes = false;
        return;
    }

    if(n_recuperar(na)->clave != n_recuperar(nb)->clave){
        *equivalentes = false;
        return;
    }
    equivalentesRec(n_hijoizquierdo(na), n_hijoizquierdo(nb), equivalentes);
    equivalentesRec(n_hijoderecho(na), n_hijoderecho(nb), equivalentes);
}

bool a_ej7_equivalente(ArbolBinario A, ArbolBinario B){
    bool equivalentes = true;
    equivalentesRec(a_raiz(A), a_raiz(B), &equivalentes);
    return equivalentes;
}

/**
8.	Dado un árbol “n-ario” se pide:
 */
// a.	Determinar la altura del mismo.
void altura(NodoArbol n, int* h, int i)
{
    if (!a_es_rama_nula(n)) {
        if (i > *h) {
            *h = i;
        }
        altura(n_hijoizquierdo(n), h, i+1);
        altura(n_hijoderecho(n), h, i);
    }
}

int a_ej8_altura(ArbolBinario A)
{
    NodoArbol n = a_raiz(A);
    int h = -1;
    if (n != NULL) {
        h = 0;
    }
    altura(n, &h, 0);
    return h;
}

// b.	Determinar el nivel de un nodo.
void nivel(NodoArbol n, int clave, int* r, int h)
{
    if (!a_es_rama_nula(n) && *r == -1) {
        TipoElemento x = n_recuperar(n);
        if (clave == x->clave) {
            *r = h;
            return;
        }
        nivel(n_hijoizquierdo(n), clave, r, h + 1);
        nivel(n_hijoderecho(n), clave, r, h);
    }
}

int a_ej8_nivel(ArbolBinario A, int clave)
{
    NodoArbol n = a_raiz(A);
    int n_actual = -1;
    nivel(n, clave, &n_actual, 0);
    return n_actual;
}

// c.	Listar todos los nodos internos (solo las claves).
Lista a_ej8_internos(ArbolBinario A);
void internos(NodoArbol n, Lista l)
{
    if (!a_es_rama_nula(n)) {
        if (!a_es_rama_nula(n_hijoizquierdo(n))) {
            TipoElemento x = n_recuperar(n);
            l_agregar(l, x);
        }
        internos(n_hijoizquierdo(n), l);
        internos(n_hijoderecho(n), l);
    }
}

Lista a_ej8_internos(ArbolBinario A){
    NodoArbol n = a_raiz(A);
    Lista l = l_crear();
    internos(n_hijoizquierdo(n), l);
    return l;
}

// d.	Determinar si todas las hojas están al mismo nivel.
void mismonivel(NodoArbol n, bool* mismoniv, int* h, int n_actual)
{
    if (*mismoniv == false) return;

    if (!a_es_rama_nula(n)) {
        if (a_es_rama_nula(n_hijoizquierdo(n))) {
            if (*h == -1) {
                *h = n_actual;
            } else {
                if (*h != n_actual) {
                    *mismoniv = false;
                    return;
                }
            }
        }
        mismonivel(n_hijoizquierdo(n), mismoniv, h, n_actual + 1);
        mismonivel(n_hijoderecho(n), mismoniv, h, n_actual);
    }
}

bool a_ej8_hojasmismonivel(ArbolBinario A)
{
    NodoArbol n = a_raiz(A);
    bool mismoniv = true;
    int h = -1;
    mismonivel(n, &mismoniv, &h, 0);
    return mismoniv;
}


/**
9.	Generar un algoritmo, recursivo o no, que permita construir un árbol binario de búsqueda balanceado (AVL)
	a partir de un árbol binario sin un orden determinado.
	Comparar las alturas de ambos árboles. Determinar la complejidad algorítmica.
 */
// Primero llamamos para construir el AVL
void binario_a_avl(NodoArbol n, ArbolAVL AVL)
{
    if (!a_es_rama_nula(n)) {
        TipoElemento x = n_recuperar(n);
        avl_insertar(AVL, x);
        binario_a_avl(n_hijoizquierdo(n), AVL);
        binario_a_avl(n_hijoderecho(n), AVL);
    }
}

ArbolAVL a_ej9_construiravl(ArbolBinario A)
{
    ArbolAVL AVL = avl_crear();
    NodoArbol n = a_raiz(A);
    binario_a_avl(n, AVL);
    return AVL;
}

// Luego con el resultado de la funcion anterior llamamos a una funcion para que nos retorne la diferencia de las alturas
// comparadas como Altura(ArbolBinario) - Altura(ArbolAVL).
void calcularaltura(NodoArbol n, int* altura, int altura_actual)
{
    if (n != NULL) {
        if (altura_actual > *altura) {
            *altura = altura_actual;
        }
        calcularaltura(n_hijoizquierdo(n), altura, altura_actual+1);
        calcularaltura(n_hijoderecho(n), altura, altura_actual+1);
    }
}

int a_ej9_diferenciaalturas(ArbolBinario A, ArbolAVL AVL)
{
    NodoArbol n = a_raiz(A);
    NodoArbol m = avl_raiz(AVL);
    int h_b = -1, h_avl = -1;
    calcularaltura(n, &h_b, 0);
    calcularaltura(m, &h_avl, 0);
    return h_b - h_avl;
}

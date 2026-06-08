#include "../../listas/headers/listas.h"
#include "../../pilas/headers/pilas.h"
#include "../../colas/headers/colas.h"

int entero();
int enteroEnRango(int minimo, int maximo);
void sacarEspacios(char* frase);
char* fraseMinuscula(char* cadena);
int enteroPositivo();
int enteroMayorQue0();
char*pedirSenial();
void pedirConjunto(int conjunto[], int *tamano);
int pedirNumeroNatural(char *mensaje);
Lista cargarListaEnteros();
Lista cargarListaEnterosPositivos();

Pila cargarPilaEnteros();
int PilaLongitud(Pila p);
void p_mostrar_con_clave(Pila p);

Cola cargarColaEnteros();
int ColaLongitud(Cola c);
void c_mostrar_con_clave(Cola c);
bool validarColaEj5();

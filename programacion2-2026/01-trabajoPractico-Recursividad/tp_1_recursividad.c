#include "tp_1_recursividad.h"
#include "../libs/validaciones/headers/funciones.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Ejercicio 1
/*1.	Construir una funci�n recursiva que retorne verdadero si una cadena de caracteres pasada
como par�metro es un pal�ndromo.  Ej. �neuquen� ya que se lee igual de atr�s hacia adelante.*/
bool palindromo(char* cadena){
    int longitud = strlen(cadena);
    return palindromoRec(cadena, 0, longitud-1);
}

// Ejercicio 2
/*2.	Dados dos n�meros enteros m y n, construir una funci�n recursiva que devuelva
el producto de ambos, calculando el mismo como sumas sucesivas. Esto es: m*n=m+m+...+m, n veces. */

int producto (int m, int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return m;
    }
    if(n > 0){
        return m+producto(m , n-1);
    }
    return m;

}

//Ejercicio 3
/*3.	Generar un algoritmo recursivo que calcule el k-�simo n�mero de la serie de Fibonacci.*/

int terminoSeridFibonacci(int k){
    if(k==0){
        return 0;
    }
    if(k==1 || k==2){
        return 1;
    }
    return terminoSeridFibonacci(k-1) + terminoSeridFibonacci(k-2);

}

//Ejercicio 4
/*4.	Dados los números enteros m y n, construir una función recursiva que devuelva el
cociente de ambos, calculando el mismo mediante restas sucesivas. Se deberá tener en cuenta que en el caso
de que la división no sea exacta, se devolverán hasta d cifras decimales (si es necesario), donde d es un
valor de 1 a 10 a ingresar como precisión de la división. */

float division(int m, int n, int d){
    float res = 1;
    return res;
}

//Ejercicio 5
/*5.	Generar un algoritmo recursivo que le ponga los “.” de los miles a un String de números.*/

char * agregarSeparadorMiles(char numero[]){
    int longitud = strlen(numero);
    int puntos = ((longitud-1)/3);
    int longitudRes = (longitud + puntos);

    char * res = malloc(sizeof(numero)*100);
    agregarPuntos(numero, res, longitud-1, longitudRes-1, 0);

    return res;
}

//Ejercicio 6
/*6.	Se conoce que la mafia china es muy organizada y protege mucho a sus miembros, cuando deciden asistir
a una reunión se dispone de una cantidad de chinos que asisten, y ellos se ubican de forma que al mirarlos
frontalmente generan cierto respeto y temor. A continuación, se tiene una serie de posibles reuniones y su
nivel y la apariencia que se tiene del grupo que va a la reunión vistos frontalmente:

Nivel reunión	Vista frontal de la delegación
		1 	        (-.-)
		2 		 (-.(-.-).-)
		3 	  (-.(-.(-.-).-).-)
		4  (-.(-.(-.(-.-).-).-).-)

*/

char * reunionMafia(int nivel);

//ejercicio 7
/*8.	Se tiene una cadena que representa una onda digital de señales L (Low) y H (High). Se pide mostrar
la onda que representa utilizando “_” y “|”.

Ejemplo: Si se tiene la cadena HHHHLLLLHHHHHLLHHLL, su onda digital se puede ver algo así:
_ _ _ _            _ _ _ _ _      _ _
        | _ _ _ _ |         |_ _ |   | _ _

*/

char * ondaDigital(char seniales[]);

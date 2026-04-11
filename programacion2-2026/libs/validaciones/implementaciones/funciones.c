#include "../headers/funciones.h"
#include "../headers/validaciones.h"
#include "../../../01-trabajoPractico-Recursividad/tp_1_recursividad.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// TP_1_RECURSIVIDAD

void ejercicio1(){
    char *palabra = malloc(sizeof(char)*100);
    printf("\nBienvenido al ejercicio del palindromo.\n\nIngrese la palabra a verificar: ");
    scanf(" %[^\n]", palabra);

    sacarEspacios(palabra);
    palabra = fraseMinuscula(palabra);

    if(palindromo(palabra)){
        printf("\nLa palabra SI es un palindromo!\n");
    }else{
        printf("\nLa palabra NO es un palindromo!\n");
    }
    free(palabra);
}

bool palindromoRec(char* cadena, int inicio, int fin){
    if(inicio == fin){
        return true;
    }
    if(cadena[inicio] == cadena[fin]){
        return palindromoRec(cadena, inicio+1, fin-1);
    }
    return false;
}

void ejercicio2(){
    int m;
    int n;
    printf("\nBienvenido al ejercicio del producto mediante sumas sucesivas.\n\nIngrese el multiplicando: ");
    scanf(" %d", &m);
    printf("\nIngrese el multiplicador: ");
    scanf(" %d", &n);

    int signo = 1; //hay que inicializa sino suma el resultado mas el resultado si los dos son positivs
    //determinar signo del resultado
    if( (m < 0 && n>0) || (m>0 && n<0) ){
        signo = -1;
    }
    //hago los dos positivos
    if(m < 0){
        m = -m;
    }
    if(n < 0){
        n = -n;
    }
    int res = producto(m, n);
    res *= signo;
    printf("El resultado es: '%d'", res);
}

void ejercicio3(){
    int k;
    printf("\nBienvenido al ejercicio del k-esimo numero de la serie de fibonacci.\n\nIngrese el k-esimo termino a saber de la sere de fibonacci.\n");
    k = enteroPositivo();


    int res = terminoSeridFibonacci(k);
    printf("El resultado es: '%d'", res);
}

void ejercicio4(){
    int m,n,d;
    printf("\nBienvenido al ejercicio de calcular un cociente mediante restas sucesivas.\n");
    printf("Primero ingrese el dividendo. ");
    m = entero();
    printf("Segundo ingrese el divisor. ");
    n = entero();
    printf("Tercero ingrese la precision. ");
    d = enteroEnRango(1,10);
    float res = division(m,n,d);
    printf("El resultado es '%f'", res);
}

void ejercicio5(){
    printf("\nBienvenido al ejercicio de agregar el separador de miles a un numero.\n");
    int n;
    n = entero();
    char * strNum = malloc(sizeof(int) *100);

    sprintf(strNum, "%d", n);

    char * res = malloc(sizeof(int) *100);
    res = agregarSeparadorMiles(strNum);
    printf("\nResultado: '%s'\n", res);
    free(res);
    free(strNum);

}
void agregarPuntos(char* numero, char* res, int longitudOrig, int longitudRes, int contador){
    if(longitudRes < 0){
        return;
    }
    if(contador==3){
        res[longitudRes] = '.';
        agregarPuntos(numero, res, longitudOrig, longitudRes-1, 0);
    }else{
        res[longitudRes] = numero[longitudOrig];
        agregarPuntos(numero, res, longitudOrig-1, longitudRes-1, contador+1);

    }
}

void ejercicio6(){
    printf("\nBienvenido al ejercicio de las seniales.\n");
    printf("\nIngrese la cadena a repesentar la onda, unicamente 'L'(low = _) y 'H'(HIGH = ¯).\n");
    char * cadena = pedirSenial();
    char * res = ondaDigital(cadena);
    printf("%s", res);
    free(res);
    free(cadena);
}
char* ondaDigitalRec(char * cadena, char * resultado,int inicio, int longitud){
    if(inicio==longitud){
        return resultado;
    }
    if(cadena[inicio] == 'L'){
        strcat(resultado, "_");
        if(inicio + 1 < longitud && cadena[inicio+1] == 'H'){
            strcat(resultado, "|");
        }
    }else if(cadena[inicio] == 'H'){
        strcat(resultado, "-");
        if(inicio + 1 < longitud && cadena[inicio+1] == 'L'){
            strcat(resultado, "|");
        }
    }
    return ondaDigitalRec(cadena, resultado, inicio+1, longitud);
}

void ejercicio7(){
    printf("Bienvenido al ejercicio de la mafia china.\n Ingrese el nivel de la mafia para verla.\n");
    int nivel;
    nivel = enteroEnRango(1,100);
    char *vista = reunionMafia(nivel);
    printf("Nivel %d: %s\n\n", nivel, vista);
    free(vista);
}

void ejercicio8(){
    int conjunto[100];
    int tamano;
    int n;
    char *resultados[101];

    pedirConjunto(conjunto, &tamano);

    n = pedirNumeroNatural("Ingrese el valor objetivo(n): ");

    subconjuntosQueSumanN(conjunto, tamano, n, resultados);

    printf("Subconjuntos que suman %d:\n\n", n);
    for (int i = 0; resultados[i] != NULL; i++) {
        printf("%s\n", resultados[i]);
        free(resultados[i]);
    }
}
void encontrarSubconjuntos(int conjunto[], int tamano, int indiceActual, int sumaActual, int objetivo, int subconjuntoTemp[], int tamSub, char **output, int *contador) {
    if (sumaActual == objetivo) {
        char *resultado = (char *)malloc(100 * sizeof(char));
        resultado[0] = '\0';
        strcat(resultado, "{");
        for (int i = 0; i < tamSub; i++) {
            char buffer[10];
            sprintf(buffer, "%d", subconjuntoTemp[i]);
            strcat(resultado, buffer);
            if (i < tamSub - 1)
                strcat(resultado, ", ");
        }
        strcat(resultado, "}");
        output[(*contador)++] = resultado;
        return;
    }

    if (indiceActual == tamano || sumaActual > objetivo)
        return;

    subconjuntoTemp[tamSub] = conjunto[indiceActual];
    encontrarSubconjuntos(conjunto, tamano, indiceActual + 1, sumaActual + conjunto[indiceActual], objetivo, subconjuntoTemp, tamSub + 1, output, contador);
    encontrarSubconjuntos(conjunto, tamano, indiceActual + 1, sumaActual, objetivo, subconjuntoTemp, tamSub, output, contador);
}

//Ejercicio 9
void ejercicio9(){
    int n;
    printf("Bienvenido al ejercicio de divisible por 7!\n Ingrese el numero a saber si es divisible por 7.\n");
    n = entero();
    if(divisiblePor7(n)){
        printf("'%d' SI es divisible por 7\n\n", n);
    }else{
        printf("'%d' NO es divisible por 7\n\n", n);
    }
}


void ejercicio10(){
    printf("\nBienvenido al ejercicio numero 10.\n");
    printf("\nNot implemented.\n");
}

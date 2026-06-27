#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../libs/hash/headers/tabla_hash.h"
#include "../libs/arboles/headers/arbol_avl.h"
#include "../libs/listas/headers/listas.h"

#define TAM_TABLA 2000
#define PRIMO_HASH 1999

/** 
4. Desarrollar un algoritmo que dado un archivo que contendr� los datos de alumnos  (legajo, apellido, nombres, domicilio, TE)
   genere una tabla hash donde la clave ser� el legajo y se guardar� como dato la posici�n f�sica
   del registro para realizar accesos directos.
   Hacer un ABM para poder cargar manualmente el archivo.  El �legajo" es un valor de 6 d�gitos.
*/
typedef struct {
    int legajo;
    char apellido[50];
    char nombres[50];
    char domicilio[100];
    char te[20];
    bool activo;
} Alumno;
int hash_legajo(int clave) {
    return clave % PRIMO_HASH;
}
void alta_alumno(TablaHash tabla, FILE *archivo) {
    Alumno nuevo;
    printf("\n--- ALTA DE ALUMNO ---\n");
    printf("Legajo (6 digitos): ");
    scanf("%d", &nuevo.legajo);

    if (th_recuperar(tabla, nuevo.legajo) != NULL) {
        printf("Error: El legajo %d ya existe en el sistema.\n", nuevo.legajo);
        return;
    }

    while(getchar() != '\n');

    printf("Apellido: ");
    fgets(nuevo.apellido, sizeof(nuevo.apellido), stdin);
    nuevo.apellido[strcspn(nuevo.apellido, "\n")] = 0;

    printf("Nombres: ");
    fgets(nuevo.nombres, sizeof(nuevo.nombres), stdin);
    nuevo.nombres[strcspn(nuevo.nombres, "\n")] = 0;

    printf("Domicilio: ");
    fgets(nuevo.domicilio, sizeof(nuevo.domicilio), stdin);
    nuevo.domicilio[strcspn(nuevo.domicilio, "\n")] = 0;

    printf("Telefono: ");
    fgets(nuevo.te, sizeof(nuevo.te), stdin);
    nuevo.te[strcspn(nuevo.te, "\n")] = 0;

    nuevo.activo = true;

    fseek(archivo, 0, SEEK_END);

    int pos_fisica = ftell(archivo) / sizeof(Alumno);

    fwrite(&nuevo, sizeof(Alumno), 1, archivo);

    fflush(archivo);

    int *ptr_pos = (int *) malloc(sizeof(int));
    *ptr_pos = pos_fisica;
    TipoElemento te = te_crear_con_valor(nuevo.legajo, ptr_pos);
    th_insertar(tabla, te);

    printf("Alumno guardado con exito en el registro %d.\n", pos_fisica);
}

void baja_alumno(TablaHash tabla, FILE *archivo) {
    int legajo;

    printf("\n--- BAJA DE ALUMNO ---\n");
    printf("Ingrese el legajo: ");
    scanf("%d", &legajo);

    TipoElemento te = th_recuperar(tabla, legajo);

    if (te == NULL) {
        printf("No existe un alumno con ese legajo.\n");
        return;
    }

    int pos = *((int *) te->valor);

    Alumno alumno;

    fseek(archivo, pos * sizeof(Alumno), SEEK_SET);
    fread(&alumno, sizeof(Alumno), 1, archivo);

    if (!alumno.activo) {
        printf("El alumno ya estaba dado de baja.\n");
        return;
    }

    alumno.activo = false;

    fseek(archivo, pos * sizeof(Alumno), SEEK_SET);
    fwrite(&alumno, sizeof(Alumno), 1, archivo);
    fflush(archivo);

    th_eliminar(tabla, legajo);

    printf("Alumno dado de baja correctamente.\n");
}

void buscar_alumno(TablaHash tabla, FILE *archivo) {
    int legajo;

    printf("\n--- CONSULTA DE ALUMNO ---\n");
    printf("Ingrese el legajo: ");
    scanf("%d", &legajo);

    TipoElemento te = th_recuperar(tabla, legajo);

    if (te == NULL) {
        printf("No existe un alumno con ese legajo.\n");
        return;
    }

    int pos = *((int *) te->valor);

    Alumno alumno;

    fseek(archivo, pos * sizeof(Alumno), SEEK_SET);
    fread(&alumno, sizeof(Alumno), 1, archivo);

    if (!alumno.activo) {
        printf("El alumno se encuentra dado de baja.\n");
        return;
    }

    printf("\n===== DATOS DEL ALUMNO =====\n");
    printf("Legajo    : %d\n", alumno.legajo);
    printf("Apellido  : %s\n", alumno.apellido);
    printf("Nombres   : %s\n", alumno.nombres);
    printf("Domicilio : %s\n", alumno.domicilio);
    printf("Telefono  : %s\n", alumno.te);
}

void th_ej4_abm() {
    TablaHash tabla = th_crear(TAM_TABLA, hash_legajo);

    FILE *archivo = fopen("alumnos.dat", "rb+");
    if (archivo == NULL) {
        archivo = fopen("alumnos.dat", "wb+");
        if (archivo == NULL) {
            printf("Error:  se pudo crear el archivo alumnos.dat\n");
            return;
        }
    }

    Alumno a;
    int pos_fisica = 0;

    rewind(archivo);

    while (fread(&a, sizeof(Alumno), 1, archivo) == 1) {
        if (a.activo) {
            int *ptr_pos = (int *) malloc(sizeof(int));
            *ptr_pos = pos_fisica;

            TipoElemento te = te_crear_con_valor(a.legajo, ptr_pos);
            th_insertar(tabla, te);
        }
        pos_fisica++;
    }

    int opcion = 0;
    do {
        printf("\n=== GESTION DE ALUMNOS (ABM) ===\n");
        printf("1. Alta de Alumno\n");
        printf("2. Baja de Alumno\n");
        printf("3. Consultar Alumno\n");
        printf("4. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                alta_alumno(tabla, archivo);
                break;
            case 2:
                baja_alumno(tabla, archivo);
                break;
            case 3:
                buscar_alumno(tabla, archivo);
                break;
            case 4:
                printf("Guardando y cerrando el sistema...\n\n");
                break;
            default:
                printf("Opci�n inv�lida. Intente nuevamente.\n\n");
        }
    } while (opcion != 4);

    fclose(archivo);
}


/**
5. Realizar una comparaci�n de los tiempos de accesos a las claves entre un �rbol AVL y una Tabla Hash.
   El operador debe poder indicarle cuantas claves se deben generar (entre 1 y 2000), cuantas repeticiones
   se realizaran y cu�l es el rango de las claves a generar.
   Luego se tomar�n claves al azar dentro del mismo rango y se buscaran en ambas estructuras.
   El proceso se repetir� �n� veces (repeticiones a ingresar por el operador).
   Documentar la conclusi�n final respecto a los tiempos de accesos de ambas estructuras.
*/
int hash_ej5(int clave) {
    return abs(clave) % TAM_TABLA;
}

void th_ej5_comparacion(int q_claves, int q_repeticiones, int rango_desde, int rango_hasta) {
    TablaHash th = th_crear(TAM_TABLA, hash_ej5);
    ArbolAVL avl = avl_crear();

    int rango_total = rango_hasta - rango_desde + 1;
    int claves_insertadas = 0;

    srand(time(NULL));

    printf("\nGenerando e insertando %d claves unicas...\n", q_claves);
    while (claves_insertadas < q_claves) {
        int clave = rango_desde + rand() % rango_total;

        if (avl_buscar(avl, clave) == NULL) {
            TipoElemento te_hash = te_crear(clave);
            TipoElemento te_avl = te_crear(clave);

            avl_insertar(avl, te_avl);
            th_insertar(th, te_hash);
            claves_insertadas++;
        }
    }

    int *claves_a_buscar = (int *)malloc(q_repeticiones * sizeof(int));
    for (int i = 0; i < q_repeticiones; i++) {
        claves_a_buscar[i] = rango_desde + rand() % rango_total;
    }

    clock_t inicio_hash = clock();
    for (int i = 0; i < q_repeticiones; i++) {
        th_recuperar(th, claves_a_buscar[i]);
    }
    clock_t fin_hash = clock();
    double tiempo_hash = ((double)(fin_hash - inicio_hash)) / CLOCKS_PER_SEC;

    clock_t inicio_avl = clock();
    for (int i = 0; i < q_repeticiones; i++) {
        avl_buscar(avl, claves_a_buscar[i]);
    }
    clock_t fin_avl = clock();
    double tiempo_avl = ((double)(fin_avl - inicio_avl)) / CLOCKS_PER_SEC;

    printf("\n|=========================================|\n");
    printf("|       RESULTADOS DE LA COMPARACION      |\n");
    printf("|=========================================|\n");
    printf(" Claves almacenadas: %d\n", q_claves);
    printf(" Busquedas ejecutadas: %d\n", q_repeticiones);
    printf(" -----------------------------------------\n");
    printf(" Tiempo Tabla Hash: %f segundos\n", tiempo_hash);
    printf(" Tiempo Arbol AVL:  %f segundos\n", tiempo_avl);
    printf("|=========================================|\n");

    free(claves_a_buscar);
}

/**
6. Se desea poder implementar una soluci�n para encontrar de forma r�pida los datos de las personas que a una fecha
   determinada se presentaron a vacunar contra el COVID.
   Es decir dada una fecha determinada deber�a obtener quienes se vacunaron.
   De cada persona se guarda b�sicamente el DNI, Apellido y Nombre.
   Se debe adem�s hacer una pantalla de carga donde se pueda especificar la fecha y los datos de las personas
   que se vacunaron en esa fecha.
*/
typedef struct {
    int dni;
    char apellido[50];
    char nombre[50];
} PersonaVacunada;

int hash_fecha(int clave) {
    return clave % PRIMO_HASH;
}

int th_ej6_covid() {
    TablaHash tabla = th_crear(TAM_TABLA, hash_fecha);
    int opcion = 0;

    do {
        printf("\n|=========================================|\n");
        printf("|       REGISTRO DE VACUNACION COVID      |\n");
        printf("|=========================================|\n");
        printf(" 1. Cargar nueva persona vacunada\n");
        printf(" 2. Consultar vacunados por fecha\n");
        printf(" 3. Volver al menu principal\n");
        printf(" Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                int fecha;
                PersonaVacunada *nueva_persona = (PersonaVacunada *)malloc(sizeof(PersonaVacunada));

                printf("\nFecha de vacunacion (Formato AAAAMMDD, ej: 20240515): ");
                scanf("%d", &fecha);

                printf("DNI: ");
                scanf("%d", &nueva_persona->dni);

                while(getchar() != '\n');

                printf("Apellido: ");
                fgets(nueva_persona->apellido, sizeof(nueva_persona->apellido), stdin);
                nueva_persona->apellido[strcspn(nueva_persona->apellido, "\n")] = 0;

                printf("Nombre: ");
                fgets(nueva_persona->nombre, sizeof(nueva_persona->nombre), stdin);
                nueva_persona->nombre[strcspn(nueva_persona->nombre, "\n")] = 0;

                TipoElemento te_fecha = th_recuperar(tabla, fecha);
                Lista lista_vacunados;

                if (te_fecha == NULL) {
                    lista_vacunados = l_crear();
                    TipoElemento nuevo_te_fecha = te_crear_con_valor(fecha, lista_vacunados);
                    th_insertar(tabla, nuevo_te_fecha);
                } else {
                    lista_vacunados = (Lista)te_fecha->valor;
                }

                TipoElemento te_persona = te_crear_con_valor(nueva_persona->dni, nueva_persona);
                l_agregar(lista_vacunados, te_persona);

                printf(">>> Registro cargado con exito.\n");
                break;
            }
            case 2: {
                int fecha_consulta;
                printf("\nIngrese la fecha a consultar (Formato AAAAMMDD): ");
                scanf("%d", &fecha_consulta);

                TipoElemento te_resultado = th_recuperar(tabla, fecha_consulta);

                if (te_resultado == NULL) {
                    printf(">>> No hay registros de vacunacion para la fecha %d.\n", fecha_consulta);
                } else {
                    Lista lista_vacunados = (Lista)te_resultado->valor;

                    printf("\n--- Personas vacunadas el %d ---\n", fecha_consulta);
                    Iterador it = iterador(lista_vacunados);

                    while (hay_siguiente(it)) {
                        TipoElemento te_persona = siguiente(it);
                        PersonaVacunada *persona = (PersonaVacunada *)te_persona->valor;
                        printf("DNI: %d | Apellido y Nombre: %s, %s\n",
                               persona->dni, persona->apellido, persona->nombre);
                    }
                    free(it);
                }
                break;
            }
            case 3:
                printf("\nSaliendo del registro COVID...\n");
                break;
            default:
                printf("\nOpcion invalida.\n");
        }
    } while (opcion != 3);

    return 0;
}

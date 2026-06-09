#ifndef TIPO_ELEMENTO_H
#define TIPO_ELEMENTO_H

struct TipoElementoRep {
    int clave;
    void* valor;
};
typedef struct TipoElementoRep *TipoElemento;

TipoElemento te_crear(int clave);
TipoElemento te_crear_con_valor(int clave, void* valor);

static const unsigned int TAMANIO_MAXIMO = 100;

#endif // TIPO_ELEMENTO_H


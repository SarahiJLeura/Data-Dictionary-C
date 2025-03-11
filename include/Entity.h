#include "Resources.h"

#ifndef ENTITY_H
#define ENTITY_H

typedef struct entidad{
    char nombre[MAX];
    long ptr_sig_entidad;
    long ptr_atributos;
    long ptr_datos;
}TEntidad;

#endif

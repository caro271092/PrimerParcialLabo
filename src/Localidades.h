/* Localidades.h */
#ifndef LOCALIDADES_H_
#define LOCALIDADES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "InputOutput.h"
#define EMPTY 1
#define FULL 0

typedef struct{
		int idLocalidad;
		char descripcion[30];
		int isEmpty;
	}eLocalidad;

/// \fn void IniciarEstructuraLocalidades(eLocalidad[], int)
/// \brief  otorga el valor vacío al campo isEmpty para luego identificarlo y poder completarlo (en este caso está hardcodeado)
/// \param lista array de localidades
/// \param tam tamaño del array
void IniciarEstructuraLocalidades(eLocalidad lista[], int tam);

#endif /* LOCALIDADES_H_ */

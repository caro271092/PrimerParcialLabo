/* Localidades.c */
#include "Localidades.h"

void IniciarEstructuraLocalidades(eLocalidad lista[], int tam){
	for(int i=0; i<tam; i++){
		lista[0].idLocalidad = 1;
		strcpy(lista[0].descripcion, "Caballito");
		lista[0].isEmpty = FULL;
		lista[1].idLocalidad = 2;
		strcpy(lista[1].descripcion, "Flores");
		lista[1].isEmpty = FULL;
		lista[2].idLocalidad = 3;
		strcpy(lista[2].descripcion, "Barracas");
		lista[2].isEmpty = FULL;
	}
}

/*InputOutput.c */
#include "InputOutput.h"

int IngresarEntero(char mensaje[]){
	int numeroIngresado;
	printf(mensaje);
	fflush(stdin);
	scanf("%d", &numeroIngresado);
	return numeroIngresado;
}

int ValidacionIngresoDeUnFlotantePositivo(char ingreso[]){
	int i;
	int retorno = -1;
	int longitud;
	longitud = strlen(ingreso);
	int contadorDePuntos = 0;
		for(i=0; i<longitud; i++){
			if(isdigit(ingreso[i]) == 0){
				if(ingreso[i] == '.'){
					contadorDePuntos++;
				}
				if(ingreso[i] != '.' || contadorDePuntos > 1){
					retorno = -1;
					break;
				}
		}
		retorno =0;
	}
	return retorno;
}

int ValidacionIngresoDeUnEnteroPositivo(char ingreso[]){
	int i;
	int retorno = -1;
	int longitud;
	longitud = strlen(ingreso);
		for(i=0; i< longitud; i++){
			if(isdigit(ingreso[i]) != 0){
				retorno = 0;
				break;
			}
		}
	return retorno;
}

int PedirNumeroEntero(int* ingresoValidado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos){
	int retorno = -1;
	char ingreso[50];
	int buffer;
	if(ingresoValidado!=NULL && mensaje!=NULL && mensajeError != NULL && minimo<=maximo && reintentos >= 0){
		do{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%[^\n]", ingreso);
			if(ValidacionIngresoDeUnEnteroPositivo(ingreso)==0){
				buffer = atoi(ingreso);
			}if(buffer>=minimo && buffer<=maximo){
					*ingresoValidado = buffer;
					retorno = 0;
					break;
			}else{
				printf("%s", mensajeError);
				}
		reintentos--;
		}while(reintentos>=0);
	}
	return retorno;
}

int PedirNumeroFlotante(float* ingresoValidado, char mensaje[], char mensajeError[], float minimo, float maximo, int reintentos){
	int retorno = -1;
	char ingreso[50];
	float buffer;
	if(ingresoValidado!=NULL && mensaje!=NULL && mensajeError != NULL && minimo<=maximo && reintentos >= 0){
		do{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%[^\n]", ingreso);
			if(ValidacionIngresoDeUnFlotantePositivo(ingreso)!=-1){
			buffer = atof(ingreso);
			}if(buffer>=minimo && buffer<=maximo){
				*ingresoValidado = buffer;
				retorno = 0;
				break;
				}else{
					printf("%s", mensajeError);
					}
			reintentos--;
		}while(reintentos>=0);
	}
	return retorno;
}

int GetString(char string[], char message[], int len){
	char auxiliarString[len];
	int retorno = -1;
	if(string != NULL && message != NULL){
		printf(message);
		fflush(stdin);
		scanf("%[^\n]", auxiliarString);
		while(strlen(auxiliarString) > len){
			printf("Reingrese: ");
			fflush(stdin);
			scanf("%[^\n]", auxiliarString);
		}
		strcpy(string, auxiliarString);
		retorno =0;
	}
	return retorno;
}

char* ToUpperFirstLetter(char cadena[]){
	int tamanio;
	tamanio= strlen(cadena);
	for(int i = 0; i < tamanio; i++){
		cadena[0]=towupper(cadena[0]);
		}
return cadena;
}

int ValidacionEnteroDentroDeUnRango(int ingreso,int minimo,int maximo){
	while(ingreso<minimo||ingreso>maximo){
		printf("Ingrese una opción válida: ");
		fflush(stdin);
		scanf("%d", &ingreso);
	}
	return ingreso;
}

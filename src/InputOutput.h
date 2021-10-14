/*InputOutput.h
 */

#ifndef INPUTOUTPUT_H_
#define INPUTOUTPUT_H_

	int IngresarEntero(char mensaje[]);
	int ValidacionIngresoDeUnFlotantePositivo(char ingreso[]);
	int ValidacionIngresoDeUnEnteroPositivo(char ingreso[]);
	int PedirNumeroEntero(int* ingresoValidado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);
	int PedirNumeroFlotante(float *ingresoValidado, char mensaje[], char mensajeError[], float minimo, float maximo, int reintentos);
	int GetString(char string[], char message[], int len);
	char* ToUpperFirstLetter(char cadena[]);
	int ValidacionEnteroDentroDeUnRango(int ingreso,int minimo,int maximo);

#endif /* INPUTOUTPUT_H_ */

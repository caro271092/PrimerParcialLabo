/*InputOutput.h */
#ifndef INPUTOUTPUT_H_
#define INPUTOUTPUT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#define EMPTY 1
#define FULL 0

/// \fn int IngresarEntero(char[])
/// \brief pide al usuario el ingreso de un entero
/// \param mensaje mensaje para pedir el ingreso
/// \return número ingresado
int IngresarEntero(char mensaje[]);

/// \fn int ValidacionIngresoDeUnFlotantePositivo(char[])
/// \brief valida que el ingreso que recibe por parámetro sea un flotante positivo
/// \param ingreso ingreso a validar
/// \return retorna -1 si el ingreso no es un flotante positivo, 0 si lo es
int ValidacionIngresoDeUnFlotantePositivo(char ingreso[]);

/// \fn int ValidacionIngresoDeUnEnteroPositivo(char[])
/// \brief valida que el ingreso que recibe por parámetro sea un entero positivo
/// \param ingreso ingreso a validar
/// \return retorna -1 si el ingreso no es un entero positivo, 0 si lo es
int ValidacionIngresoDeUnEnteroPositivo(char ingreso[]);

/// \fn int PedirNumeroEntero(int*, char[], char[], int, int, int)
/// \brief pide al usuario el ingreso de un entero y valida que éste sea un entero positivo y esté dentro de determinado rango
/// dándole la posibilidad de reingresar, de ser necesario
/// \param ingresoValidado si el ingreso es un entero positivo y está dentro del rango lo devuelve a través de este puntero
/// \param mensaje mensaje para pedir el ingreso
/// \param mensajeError mensaje para informar que el ingreso no corresponde
/// \param minimo valor mínimo que puede tener el ingreso
/// \param maximo valor máximo que puede tener el ingreso
/// \param reintentos cantidad de veces que puede reingresar en caso de ser necesario
/// \return -1 si luego de los reintentos el ingreso sigue siendo incorrecto, 0 si se validó correctamente el ingreso
int PedirNumeroEntero(int* ingresoValidado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);

/// \fn int PedirNumeroFlotante(float*, char[], char[], float, float, int)
/// \brief pide al usuario el ingreso de un flotante y valida que éste sea positivo y esté dentro de determinado rango
/// dándole la posibilidad de reingresar, de ser necesario
/// \param ingresoValidado si el ingreso es un flotante positivo y está dentro del rango lo devuelve a través de este puntero
/// \param mensaje mensaje para pedir el ingreso
/// \param mensajeError mensaje para informar que el ingreso no corresponde
/// \param minimo valor mínimo que puede tener el ingreso
/// \param maximo valor máximo que puede tener el ingreso
/// \param reintentos cantidad de veces que puede reingresar en caso de ser necesario
/// \return -1 si luego de los reintentos el ingreso sigue siendo incorrecto, 0 si se validó correctamente el ingreso
int PedirNumeroFlotante(float *ingresoValidado, char mensaje[], char mensajeError[], float minimo, float maximo, int reintentos);

/// \fn int GetString(char[], char[], int)
/// \brief solicita el ingreso de una cadena de caracteres, de determinado máximo de caracteres
/// \param string ingreso validado
/// \param message mensaje para solicitar el ingreso
/// \param len tamaño máximo del string
/// \return -1 si no se pudo guardar el string, 0 si se pudo
int GetString(char string[], char message[], int len);

/// \fn char ToUpperFirstLetter*(char[])
/// \brief recibe una cadena de caracteres y coloca en mayúscula el caracter de la posición 0
/// \param cadena cadena a modificar
/// \return cadena con el caracter en la posición 0 en mayúscula
char* ToUpperFirstLetter(char cadena[]);

/// \fn int ValidacionEnteroDentroDeUnRango(int, int, int)
/// \brief valida que el entero ingresado esté dentro de un rango determinado
/// \param ingreso ingreso a validar
/// \param minimo valor mínimo que puede tomar el ingreso
/// \param maximo valor máximo que puede tomar el ingreso
/// \return ingreso validado
int ValidacionEnteroDentroDeUnRango(int ingreso,int minimo,int maximo);

#endif /* INPUTOUTPUT_H_ */

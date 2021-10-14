/* Clientes.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "Clientes.h"
#include "InputOutput.h"
#define EMPTY 1
#define FULL 0


int IniciarEstructura(eCliente lista[], int tam){
	for(int i=0; i<tam; i++){
	        lista[i].isEmpty = EMPTY;
	    }
	return 0;
}


int BuscarPrimerEspacioLibre(eCliente lista[], int tam){
	int i;
	int index = -1;
	for(i=0; i<tam;i++){
		if(lista[i].isEmpty == EMPTY){
			index = i;
			break;
		}
	}
	return index;
}

int BuscarPrimerEspacioOcupado(eCliente lista[], int tam){
	int i;
	int index = -1;
	for(i=0; i<tam;i++){
		if(lista[i].isEmpty == FULL){
			index = i;
			break;
		}
	}
	return index;
}


int AgregarCliente(eCliente lista[], int tam, int idCliente, char nombreEmpresa[], int cuit, char direccion[], int localidad){
	int retorno = -1;
	int index;
	index = BuscarPrimerEspacioLibre(lista, tam);
	if(lista != NULL && index != -1){
	lista[index].idCliente = idCliente;
	strcpy(lista[index].nombreEmpresa, nombreEmpresa);
	lista[index].cuit = cuit;
	strcpy(lista[index].direccion, direccion);
	lista[index].localidad = localidad;
	/*switch(localidad){
	case 1:
		strcpy(lista[index].localidad.CABA, "CABA");
	break;
	case 2:
		strcpy(lista[index].localidad.GBA, "Gran Buenos Aires");
		break;
	case 3:
		strcpy(lista[index].localidad.IDP, "Interior del País");
		break;
	}*/
	lista[index].isEmpty = FULL;
	retorno = 0;
	}
	return retorno;
}

int PedirCliente(eCliente lista[], int tam, int *idCliente){
	char nombreEmpresa[51];
	int cuit;
	char direccion[51];
	int localidad;
	int retorno;
	if(lista != NULL){
	GetString(nombreEmpresa, ">> Nombre de la empresa: ", 51);
	ToUpperFirstLetter(nombreEmpresa);
	PedirNumeroEntero(&cuit, ">> CUIT (solo números): ", "-->Error.", 1, INT_MAX, 2);
	GetString(direccion, ">> Direccion: ", 51);
	ToUpperFirstLetter(direccion);
	PedirNumeroEntero(&localidad, ">> Localidad (1.CABA/2.Gran Buenos Aires/3.Interior del país): ", "-->Error.", 1, 3, 2);
	}
	*idCliente += 1;
	retorno = AgregarCliente(lista, tam, *idCliente, nombreEmpresa, cuit, direccion, localidad);
	return retorno;
}

int EncontrarClientePorId(eCliente lista[], int tam, int idIngresado){
	int retorno = -1;
	int i;
	for(i=0;i<tam;i++){
		if(lista != NULL && lista[i].isEmpty == FULL && lista[i].idCliente == idIngresado){
			retorno = i;
			break;
		}
	}
	return retorno;
}

int ModificarDireccion(eCliente lista[], int tam, int id){
	int retorno = -1;
	char newDireccion[51];
	int newLocalidad;
	int idAModificar;
	idAModificar = EncontrarClientePorId(lista, tam, id);
	if((EncontrarClientePorId(lista, tam, id))!=-1){
		GetString(newDireccion, ">> Ingrese nueva dirección: ", 51);
		ToUpperFirstLetter(newDireccion);
		strcpy(lista[idAModificar].direccion, newDireccion);
		PedirNumeroEntero(&newLocalidad, ">> Ingrese nueva localidad (1.CABA/2.Gran Buenos Aires/3.Interior del país): ", "-->Error.", 1, 3, 2);
		lista[idAModificar].localidad = newLocalidad;
		/*switch(newLocalidad){
			case 1:
				strcpy(lista[idAModificar].localidad.CABA, "CABA");
			break;
			case 2:
				strcpy(lista[idAModificar].localidad.GBA, "Gran Buenos Aires");
				break;
			case 3:
				strcpy(lista[idAModificar].localidad.IDP, "Interior del País");
				break;
			}*/
		retorno = 0;
		}
	 return retorno;
}

int ImprimirListadoClientes(eCliente lista[], int tam){
	printf("%-10s%-20s%-20s%-20s%s","ID","Empresa", "CUIT", "Dirección", "Localidad\n");
	for(int i = 0; i < tam; i++) {
		if(lista[i].isEmpty == FULL){
			printf("%-10d", lista[i].idCliente);
			printf("%-20s", lista[i].nombreEmpresa);
			printf("%-20d", lista[i].cuit);
			printf("%-20s", lista[i].direccion);
			//printf("%-20s", lista[i].localidad);
			switch(lista[i].localidad){
				case 1: printf("CABA\n");
						break;
				case 2: printf("Gran Buenos Aires\n");
						break;
				case 3: printf("Interior del país\n");
						break;
			}
		}
	}
	return 0;
}

int BajaCliente(eCliente lista[], int tam, int idBaja){
	int retorno = -1;
	int idBajaConfirmado;
	idBajaConfirmado = EncontrarClientePorId(lista, tam, idBaja);
	if((EncontrarClientePorId(lista, tam, idBaja))!=-1){
		lista[idBajaConfirmado].isEmpty = EMPTY;
		retorno = 0;
	}
	return retorno;
}







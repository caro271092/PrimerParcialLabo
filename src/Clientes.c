/* Clientes.c */
#include "Clientes.h"

void IniciarEstructura(eCliente lista[], int tam){
	for(int i=0; i<tam; i++){
	        lista[i].isEmpty = EMPTY;
	    }
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

int AgregarCliente(eCliente lista[], int tam, int idCliente, char nombreEmpresa[], int cuit, char direccion[], int idLocalidad){
	int retorno = -1;
	int index;
	index = BuscarPrimerEspacioLibre(lista, tam);
	if(lista != NULL && index != -1){
	lista[index].idCliente = idCliente;
	strcpy(lista[index].nombreEmpresa, nombreEmpresa);
	lista[index].cuit = cuit;
	strcpy(lista[index].direccion, direccion);
	lista[index].idLocalidad = idLocalidad;
	lista[index].isEmpty = FULL;
	retorno = 0;
	}
	return retorno;
}

int PedirCliente(eCliente lista[], int tam, int* idCliente){
	int retorno = -1;
	char nombreEmpresa[51];
	int cuit;
	char direccion[51];
	int idLocalidad;
	if(lista != NULL){
	GetString(nombreEmpresa, ">> Nombre de la empresa: ", 51);
	ToUpperFirstLetter(nombreEmpresa);
	PedirNumeroEntero(&cuit, ">> CUIT (solo números): ", "-->Error.", 1, INT_MAX, 2);
	GetString(direccion, ">> Direccion: ", 51);
	ToUpperFirstLetter(direccion);
	PedirNumeroEntero(&idLocalidad, ">> Localidad (1.Caballito/2.Flores/3.Barracas): ", "-->Error.", 1, 3, 2);
	}
	*idCliente += 1;
	retorno = AgregarCliente(lista, tam, *idCliente, nombreEmpresa, cuit, direccion, idLocalidad);
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
		PedirNumeroEntero(&newLocalidad, ">> Ingrese nueva localidad (1.Caballito/2.Flores/3.Barracas): ", "-->Error.", 1, 3, 2);
		lista[idAModificar].idLocalidad = newLocalidad;
		retorno = 0;
		}
	 return retorno;
}

int ImprimirListadoClientes(eCliente lista[], int tam){
	int retorno = -1;
	printf("%-10s%-20s%-20s%-20s%s","ID","Empresa", "CUIT", "Dirección", "Localidad\n");
	for(int i = 0; i < tam; i++) {
		if(lista[i].isEmpty == FULL){
			printf("%-10d", lista[i].idCliente);
			printf("%-20s", lista[i].nombreEmpresa);
			printf("%-20d", lista[i].cuit);
			printf("%-20s", lista[i].direccion);
			switch(lista[i].idLocalidad){
				case 1: printf("%s", "Caballito\n");
						break;
				case 2: printf("%s", "Flores\n");
						break;
				case 3: printf("%s", "Barracas\n");
						break;
			}
		}
	retorno =0;
	}
	return retorno;
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

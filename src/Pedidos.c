/* Pedidos.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "Pedidos.h"
#include "InputOutput.h"
#define EMPTY 1
#define FULL 0


int IniciarEstructuraPedido(eCliente lista[], int tam){
	for(int i=0; i<tam; i++){
	        lista[i].pedido.isEmpty = EMPTY;
	    }
	return 0;
}



int BuscarPrimerEspacioLibrePedidos(eCliente lista[], int tam){
	int i;
	int index = -1;
	for(i=0; i<tam;i++){
		if(lista[i].pedido.isEmpty == EMPTY){
			index = i;
			break;
		}
	}
	return index;
}

int AgregarPedido(eCliente lista[], int tam, int idPedido, float cantidadKilosARecolectar, float kilosHDPE, float kilosLDPE, float kilosPP, int indexClienteIngresado){
	int retorno = -1;
	if(lista != NULL){
	lista[indexClienteIngresado].pedido.idPedido = idPedido;
	lista[indexClienteIngresado].pedido.cantidadKilosARecolectar = cantidadKilosARecolectar;
	lista[indexClienteIngresado].pedido.kilosHDPE = kilosHDPE;
	lista[indexClienteIngresado].pedido.kilosLDPE = kilosHDPE;
	lista[indexClienteIngresado].pedido.kilosPP = kilosHDPE;
	strcpy(lista[indexClienteIngresado].pedido.estado, "Pendiente");
	lista[indexClienteIngresado].pedido.isEmpty = FULL;
	retorno = 0;
	}
	return retorno;
}

int IngresarDatosDePedido(eCliente lista[], int tam, int *idPedido, int indexClienteIngresado){
	float cantidadKilosARecolectar = 0;
	float kilosHDPE;
	float kilosLDPE;
	float kilosPP;
	int retorno = -1;
	if(lista != NULL){
	PedirNumeroFlotante(&cantidadKilosARecolectar, ">>Cantidad de kilos a recolectar: ","-->Error.", 1, 500, 2);
	kilosHDPE= 0;
	kilosLDPE = 0;
	kilosPP = 0;
	}
	*idPedido += 1;
	retorno = AgregarPedido(lista, tam, *idPedido, cantidadKilosARecolectar,kilosHDPE, kilosLDPE,kilosPP, indexClienteIngresado);
	return retorno;
}


int ImprimirListadoPedidos(eCliente lista[], int tam){
	printf("%-15s%-15s%-15s%-15s%-15s%-15s%s","ID Pedido","ID Cliente", "Kg totales", "Estado", "Kg HDPE","Kg LDPE","Kg PP\n");
	for(int i = 0; i < tam; i++) {
		if(lista[i].pedido.isEmpty == FULL){
			printf("%-15d", lista[i].pedido.idPedido);
			printf("%-15d", lista[i].idCliente);
			printf("%-15.1f", lista[i].pedido.cantidadKilosARecolectar);
			printf("%-15s", lista[i].pedido.estado);
			printf("%-15.1f", lista[i].pedido.kilosHDPE);
			printf("%-15.1f", lista[i].pedido.kilosLDPE);
			printf("%-15.1f\n", lista[i].pedido.kilosPP);
		}
	}
	return 0;
}

int BuscarPrimerEspacioOcupadoPedidos(eCliente lista[], int tam){
	int i;
	int index = -1;
	for(i=0; i<tam;i++){
		if(lista[i].pedido.isEmpty == FULL){
			index = i;
			break;
		}
	}
	return index;
}

int EncontrarPedidoPorId(eCliente lista[], int tam, int idPedidoIngresado){
	int retorno = -1;
	int i;
	for(i=0;i<tam;i++){
		if(lista != NULL && lista[i].isEmpty == FULL && lista[i].pedido.idPedido == idPedidoIngresado){
			retorno = i;
			break;
		}
	}
	return retorno;
}

int ClasificarPlastico(eCliente lista[], int tam, int id){
	int retorno = -1;
	float newKilosHDPE;
	float newKilosLDPE;
	float newKilosPP;
	int idAModificar;
	idAModificar = EncontrarPedidoPorId(lista, tam, id);
	if((EncontrarPedidoPorId(lista, tam, id))!=-1){
		PedirNumeroFlotante(&newKilosHDPE, "Kilos de HDPE obtenidos: ","Error. Reingrese: ", 1, 400,2);
		lista[idAModificar].pedido.kilosHDPE = newKilosHDPE;
		PedirNumeroFlotante(&newKilosLDPE, "Kilos de LDPE obtenidos: ","Error. Reingrese: ", 1, 400,2);
		lista[idAModificar].pedido.kilosLDPE = newKilosLDPE;
		PedirNumeroFlotante(&newKilosPP, "Kilos de PP obtenidos: ","Error. Reingrese: ", 1, 400,2);
		lista[idAModificar].pedido.kilosPP = newKilosPP;
		strcpy(lista[idAModificar].pedido.estado, "Completado");
		retorno = 0;
		}
	 return retorno;
}


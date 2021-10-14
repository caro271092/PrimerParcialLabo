/* Informes.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "Informes.h"

#define EMPTY 1
#define FULL 0

void MostrarCliente(eCliente cliente){
  printf("%-10d %-20s %-20d %-20s",
		  cliente.idCliente,
		  cliente.nombreEmpresa,
		  cliente.cuit,
		  cliente.direccion);
		  //cliente.localidad);
		  switch(cliente.localidad){
  				case 1: printf("CABA\n");
  						break;
  				case 2: printf("Gran Buenos Aires\n");
  						break;
  				case 3: printf("Interior del país\n");
  						break;
  			}
}

int ContadorEstadoPedidoCliente(eCliente listaClientes[], int tamClientes, char estadoRequerido[], int idAchequear){
	int contador = 0;
	int i = 0;
	for(i = 0; i<tamClientes; i++){
			if(listaClientes[i].pedido.isEmpty == FULL && listaClientes[i].pedido.estado == estadoRequerido && listaClientes[i].idCliente == idAchequear){
				contador++;
			}
	}
	return contador;
}

void MostrarCantidadDePedidosPendientesPorCliente(eCliente listaClientes[], int tamClientes){
	int i;
	int cantidadPedidosPendientes;
	printf("%-10s%-20s%-20s%-20s%s","ID","Empresa", "CUIT", "Dirección", "Localidad\n");
	for(i=0; i<tamClientes; i++){
		cantidadPedidosPendientes = ContadorEstadoPedidoCliente(listaClientes, tamClientes, "Pendiente", listaClientes[i].idCliente);
		MostrarCliente(listaClientes[i]);
		printf("%d", cantidadPedidosPendientes);
	    }
}

void MostrarClientePedidosPendientes(eCliente cliente){
  printf("%-10d %-20d %-20s %-20.1f",
		  cliente.pedido.idPedido,
		  cliente.cuit,
		  cliente.direccion,
  	  	  cliente.pedido.cantidadKilosARecolectar);
  			}


void DetallePedidosPendientes(eCliente listaClientes[], int tamClientes){
	int i;
	printf("%-10s%-20s%-20s%s","ID Pedido", "CUIT", "Dirección", "Kilos a recolectar\n");
	for(i=0; i<tamClientes; i++){
	if(listaClientes[i].isEmpty == FULL && (strcmp(listaClientes[i].pedido.estado, "Pendiente") == 0)){
		MostrarClientePedidosPendientes(listaClientes[i]);
	}
	}
}

void MostrarClientePedidosProcesados(eCliente cliente){
  printf("%-10d %-20s %-20.1f %-20.1f %-20.1f",
		  cliente.cuit,
		  cliente.direccion,
  	  	  cliente.pedido.kilosHDPE,
		  cliente.pedido.kilosLDPE,
		  cliente.pedido.kilosPP);
  			}

void DetallePedidosProcesados(eCliente listaClientes[], int tamClientes){
	int i;
	printf("%-15s %-15s %-15s %-15s %s","CUIT", "Direccion","Kg HDPE","Kg LDPE","Kg PP\n");
	for(i=0; i<tamClientes; i++){
	if(listaClientes[i].isEmpty == FULL && (strcmp(listaClientes[i].pedido.estado, "Completado") == 0)){
		MostrarClientePedidosProcesados(listaClientes[i]);
	}
	}
}




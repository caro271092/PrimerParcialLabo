/* Pedidos.c */
#include "Pedidos.h"

void IniciarEstructuraPedido(ePedido lista[], int tam){
	for(int i=0; i<tam; i++){
	        lista[i].isEmpty = EMPTY;
	    }
}

int BuscarPrimerEspacioLibrePedidos(ePedido lista[], int tam){
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

int AgregarPedido(ePedido lista[], int tam, int idPedido, float cantidadKilosARecolectar, float kilosHDPE, float kilosLDPE, float kilosPP, int idClienteIngresado){
	int retorno = -1;
	int index;
	index = BuscarPrimerEspacioLibrePedidos(lista, tam);
	if(lista != NULL){
	lista[index].idPedido = idPedido;
	lista[index].idCliente = idClienteIngresado;
	lista[index].cantidadKilosARecolectar = cantidadKilosARecolectar;
	lista[index].kilosHDPE = kilosHDPE;
	lista[index].kilosLDPE = kilosHDPE;
	lista[index].kilosPP = kilosHDPE;
	strcpy(lista[index].estado, "Pendiente");
	lista[index].isEmpty = FULL;
	retorno = 0;
	}
	return retorno;
}

int IngresarDatosDePedido(ePedido lista[], int tam, int *idPedido, int idClienteIngresado){
	int retorno = -1;
	float cantidadKilosARecolectar = 0;
	float kilosHDPE;
	float kilosLDPE;
	float kilosPP;
	if(lista != NULL){
	PedirNumeroFlotante(&cantidadKilosARecolectar, ">>Cantidad de kilos a recolectar: ","-->Error.", 1, 500, 2);
	kilosHDPE= 0;
	kilosLDPE = 0;
	kilosPP = 0;
	}
	*idPedido += 1;
	retorno = AgregarPedido(lista, tam, *idPedido, cantidadKilosARecolectar,kilosHDPE, kilosLDPE,kilosPP, idClienteIngresado);
	return retorno;
}

int ImprimirListadoPedidos(ePedido lista[], int tam){
	int retorno = -1;
	printf("%-15s%-15s%-15s%-15s%-15s%-15s%s","ID Pedido","ID Cliente", "Kg totales", "Estado", "Kg HDPE","Kg LDPE","Kg PP\n");
	for(int i = 0; i < tam; i++) {
		if(lista[i].isEmpty == FULL){
			printf("%-15d", lista[i].idPedido);
			printf("%-15d", lista[i].idCliente);
			printf("%-15.1f", lista[i].cantidadKilosARecolectar);
			printf("%-15s", lista[i].estado);
			printf("%-15.1f", lista[i].kilosHDPE);
			printf("%-15.1f", lista[i].kilosLDPE);
			printf("%-15.1f\n", lista[i].kilosPP);
			retorno =0;
		}
	}
	return retorno;
}

int BuscarPrimerEspacioOcupadoPedidos(ePedido lista[], int tam){
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

int EncontrarPedidoPorId(ePedido lista[], int tam, int idPedidoIngresado){
	int retorno = -1;
	int i;
	for(i=0;i<tam;i++){
		if(lista != NULL && lista[i].isEmpty == FULL && lista[i].idPedido == idPedidoIngresado){
			retorno = i;
			break;
		}
	}
	return retorno;
}

int ClasificarPlastico(ePedido lista[], int tam, int id){
	int retorno = -1;
	float newKilosHDPE;
	float newKilosLDPE;
	float newKilosPP;
	int idAModificar;
	idAModificar = EncontrarPedidoPorId(lista, tam, id);
	if((EncontrarPedidoPorId(lista, tam, id))!=-1){
		PedirNumeroFlotante(&newKilosHDPE, "Kilos de HDPE obtenidos: ","Error. Reingrese: ", 1, 400,2);
		lista[idAModificar].kilosHDPE = newKilosHDPE;
		PedirNumeroFlotante(&newKilosLDPE, "Kilos de LDPE obtenidos: ","Error. Reingrese: ", 1, 400,2);
		lista[idAModificar].kilosLDPE = newKilosLDPE;
		PedirNumeroFlotante(&newKilosPP, "Kilos de PP obtenidos: ","Error. Reingrese: ", 1, 400,2);
		lista[idAModificar].kilosPP = newKilosPP;
		strcpy(lista[idAModificar].estado, "Completado");
		retorno = 0;
		}
	 return retorno;
}

float KilosTotalesDePPObtenidos(ePedido listaPedidos[], int tamPedidos){
	int i;
	float acumuladorPP =0;
	for(i=0; i<tamPedidos;i++){
		 if(listaPedidos!=NULL && (listaPedidos[i].isEmpty == FULL) && (strcmp(listaPedidos[i].estado,"Completado")==0)){
			 acumuladorPP = acumuladorPP + listaPedidos[i].kilosPP;
		 }
	}
	return acumuladorPP;
}




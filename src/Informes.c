/* Informes.c */
#include "Informes.h"

void MostrarCliente(eCliente cliente){
  printf("%-10d%-20s%-20d%-20s",
		  cliente.idCliente,
		  cliente.nombreEmpresa,
		  cliente.cuit,
		  cliente.direccion);
  	  	  switch(cliente.idLocalidad){
  	  	  	  case 1: printf("%-20s", "Caballito");
  	  			break;
  	  	  	  case 2: printf("%-20s", "Flores");
  	  			break;
  	  	  	  case 3: printf("%-20s", "Barracas");
  	  			break;
  	  	  }
}

void MostrarCuitYDireccionCliente(eCliente listaClientes[], int tamClientes, int idClienteRecibido){
	int idAMostrar;
	idAMostrar = EncontrarClientePorId(listaClientes, tamClientes, idClienteRecibido);
	printf("%-10d%-20s",
		listaClientes[idAMostrar].cuit,
		listaClientes[idAMostrar].direccion);
}

void DetallePedidosPendientes(ePedido listaPedidos[], int tamPedidos, eCliente listaClientes[], int tamClientes){
	int i;
	int idClienteRecibido;
	printf("%-10s%-20s%s", "CUIT", "Dirección", "Kilos a recolectar\n");
	for(i=0; i<tamPedidos; i++){
		if(listaPedidos!=NULL && (strcmp(listaPedidos[i].estado, "Pendiente") == 0)){
			idClienteRecibido = listaPedidos[i].idCliente;
			MostrarCuitYDireccionCliente(listaClientes, tamClientes, idClienteRecibido);
			printf("%.1f\n", listaPedidos[i].cantidadKilosARecolectar);
		}
	}
}

void DetallePedidosProcesados(ePedido listaPedidos[], int tamPedidos, eCliente listaClientes[], int tamClientes){
	int i;
	int idClienteRecibido;
	printf("%-10s%-20s%-10s%-10s%s","CUIT", "Direccion","Kg HDPE","Kg LDPE","Kg PP\n");
	for(i=0; i<tamPedidos; i++){
		if(listaPedidos!=NULL && (strcmp(listaPedidos[i].estado, "Completado") == 0)){
			idClienteRecibido = listaPedidos[i].idCliente;
			MostrarCuitYDireccionCliente(listaClientes, tamClientes, idClienteRecibido);
			printf("%-10.1f%-10.1f%.1f\n", listaPedidos[i].kilosHDPE,
					listaPedidos[i].kilosLDPE,
					listaPedidos[i].kilosPP);
		}
	}
}

int ContadorEstadoPedidoCliente(ePedido listaPedidos[], int tam, char estadoRequerido[], int idAchequear){
	int i;
	int contador = 0;
	for(i=0; i<tam; i++){
		if(listaPedidos!= NULL && (strcmp(listaPedidos[i].estado, estadoRequerido) == 0) && (listaPedidos[i].idCliente == idAchequear)){
			contador++;
		}
	}
	return contador;
}

void MostrarCantidadDePedidosPendientesPorCliente(ePedido listaPedidos[], int tamPedidos, eCliente listaClientes[], int tamClientes){
	int i;
	int cantidadPedidosPendientes;
	printf("%-10s%-20s%-20s%-20s%-20s%s","ID","Empresa","CUIT","Dirección","Localidad","Pedidos Pendientes\n");
	for(i=0; i<tamClientes; i++){
		if(listaClientes!=NULL && listaClientes[i].isEmpty == FULL){
			cantidadPedidosPendientes = ContadorEstadoPedidoCliente(listaPedidos, tamPedidos,"Pendiente", listaClientes[i].idCliente);
			MostrarCliente(listaClientes[i]);
			printf("%d\n", cantidadPedidosPendientes);
			}
		}
}

int CantidadPedidosPendientesPorLocalidad(ePedido listaPedidos[], int tamPedidos, eCliente listaClientes[], int tamClientes, int* idLocalidad){
	int i;
	int idAchequear;
	int indexClienteConPedidoPendiente;
	int contadorPedidosPorLocalidad =0;
	int idLocalidadIngresada;
	PedirNumeroEntero(&idLocalidadIngresada, ">>Ingrese la localidad que desea consultar (1.Caballito/2.Flores/3.Barracas): ","-->Error.", 1, 3, 2);
	for(i=0; i<tamPedidos;i++){
	 if(listaPedidos!=NULL && (listaPedidos[i].isEmpty == FULL) && (strcmp(listaPedidos[i].estado,"Pendiente")==0)){
		idAchequear = listaPedidos[i].idCliente;
		indexClienteConPedidoPendiente = EncontrarClientePorId(listaClientes, tamClientes, idAchequear);
		if(listaClientes[indexClienteConPedidoPendiente].idLocalidad == idLocalidadIngresada){
						contadorPedidosPorLocalidad++;
					}
	 }
	}
	*idLocalidad = idLocalidadIngresada;
return contadorPedidosPorLocalidad;
}

int ContadorPedidosPorCliente(ePedido listaPedidos[], int tam, int idAchequear){
	int i;
	int contador = 0;
	for(i=0; i<tam; i++){
		if(listaPedidos!= NULL && (listaPedidos[i].idCliente == idAchequear)){
			contador++;
		}
	}
	return contador;
}

int ClienteConMasPedidos(ePedido listaPedidos[], int tamPedidos){
	int i;
	int idAchequear;
	int auxMayorCantidadPedidos;
	int mayorCantidadPedidos;
	int idClienteConMasPedidos;
	int flagPrimeraIteracion =1;
	  for(i=0; i<tamPedidos; i++){
	   if(listaPedidos!=NULL && (listaPedidos[i].isEmpty == FULL)){
		   idAchequear = listaPedidos[i].idCliente;
		   auxMayorCantidadPedidos = ContadorPedidosPorCliente(listaPedidos, tamPedidos, idAchequear);
		   if(auxMayorCantidadPedidos>mayorCantidadPedidos || flagPrimeraIteracion ==1){
			   idClienteConMasPedidos = idAchequear;
			   mayorCantidadPedidos = auxMayorCantidadPedidos;
			   flagPrimeraIteracion =0;
		   }
	   }
	}
	  return idClienteConMasPedidos;
}

int ClienteConMasPedidosEstado(ePedido listaPedidos[], int tamPedidos, char estadoDeseado[]){
	int i;
	int idAchequear;
	int auxMayorCantidadPedidos;
	int mayorCantidadPedidos;
	int idClienteConMasPedidosEstado;
	int flagPrimeraIteracion =1;
	  for(i=0; i<tamPedidos; i++){
	   if(listaPedidos!=NULL && (listaPedidos[i].isEmpty == FULL)){
		   idAchequear = listaPedidos[i].idCliente;
		   auxMayorCantidadPedidos = ContadorEstadoPedidoCliente(listaPedidos, tamPedidos, estadoDeseado, idAchequear);
		   if(auxMayorCantidadPedidos>mayorCantidadPedidos || flagPrimeraIteracion ==1){
			   idClienteConMasPedidosEstado = idAchequear;
			   mayorCantidadPedidos = auxMayorCantidadPedidos;
			   flagPrimeraIteracion =0;
		   }
	   }
	}
	  return idClienteConMasPedidosEstado;
}

/*
int ClienteConMasPedidosCompletados(ePedido listaPedidos[], int tamPedidos){
	int i;
	int idAchequear;
	int auxMayorCantidadPedidos;
	int mayorCantidadPedidos;
	int idClienteConMasPedidosCompletados;
	int flagPrimeraIteracion =1;
	  for(i=0; i<tamPedidos; i++){
	   if(listaPedidos!=NULL && (listaPedidos[i].isEmpty == FULL)){
		   idAchequear = listaPedidos[i].idCliente;
		   auxMayorCantidadPedidos = ContadorEstadoPedidoCliente(listaPedidos, tamPedidos, "Completado", idAchequear);
		   if(auxMayorCantidadPedidos>mayorCantidadPedidos || flagPrimeraIteracion ==1){
			   idClienteConMasPedidosCompletados = idAchequear;
			   mayorCantidadPedidos = auxMayorCantidadPedidos;
			   flagPrimeraIteracion =0;
		   }
	   }
	}
	  return idClienteConMasPedidosCompletados;
}*/


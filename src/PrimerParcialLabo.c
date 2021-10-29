/*Name: PrimerParcialLabo.c
 Author: Carolina Alvarez, 1E */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "Clientes.h"
#include "Pedidos.h"
#include "Informes.h"
#include "InputOutput.h"
#include "Localidades.h"
#define T_CLIENTES 100
#define T_PEDIDOS 1000
#define T_LOCALIDADES 3

int main(void) {
  setbuf(stdout, NULL);
  int opcionIngresada = 0;
  int opcionIngresadaInformes;
  eCliente listaClientes[T_CLIENTES];
  ePedido listaPedidos[T_PEDIDOS];
  eLocalidad listaLocalidades[T_LOCALIDADES];
  int retornoFuncion;
  int idCliente= 1000;
  int idPedido= 2000;
  int idIngresado;
  int idPedidoIngresado;
  int hayClientesCargados;
  int hayPedidosCargados;
  char respuestaConfirmacion;
  int pedidosPendientesPorLocalidad;
  int contadorClientes =0;
  float kgPPPromedioPorCliente;
  float kgPPTotales;
  int idClienteConMasPedidos;
  int idClienteConMasPedidosPendientes;
  int idClienteConMasPedidosCompletados;
  int tienePedidosPendientes;
  int indexPedido;
  int idLocalidadIngresada;
	IniciarEstructuraLocalidades(listaLocalidades, T_LOCALIDADES);
	IniciarEstructura(listaClientes, T_CLIENTES);
	IniciarEstructuraPedido(listaPedidos, T_PEDIDOS);
		do{
		printf("\n 1. Alta cliente "
			   "\n 2. Modificar dirección de cliente "
			   "\n 3. Baja de cliente "
			   "\n 4. Crear pedido de recolección "
			   "\n 5. Procesar residuos "
			   "\n 6. Informes "
			   "\n 7. Finalizar "
				);
		PedirNumeroEntero(&opcionIngresada, "\n >>Ingrese la opción que desea ejecutar: " , "---> ERROR. Ingrese una opción válida.", 1, 7, 2);
		switch(opcionIngresada){
		case 1:
		   retornoFuncion = PedirCliente(listaClientes,T_CLIENTES, &idCliente);
		   if(retornoFuncion != -1){
			   contadorClientes++;
				printf("\n--->El cliente se dió de alta exitosamente. Id: %d\n", idCliente);
				}else{
					printf("\n--->ERROR. El cliente no se pudo cargar.\n");
				}
		break;
		case 2:
			hayClientesCargados = BuscarPrimerEspacioOcupado(listaClientes, T_CLIENTES);
			if(hayClientesCargados==-1){
				printf("\n--->No hay clientes dados de alta aún.\n");
			}else{
			ImprimirListadoClientes(listaClientes, T_CLIENTES);
			PedirNumeroEntero(&idIngresado, "\n--->Ingrese el Id. del cliente que desea modificar: ", "--->ERROR.", 1, INT_MAX,3);
			retornoFuncion = ModificarDireccion(listaClientes,T_CLIENTES, idIngresado);
				if(retornoFuncion==-1){
					idIngresado = IngresarEntero("--->El Id. ingresado no es válido. Intente nuevamente: ");
					retornoFuncion = ModificarDireccion(listaClientes,T_CLIENTES, idIngresado);
				}
				if(retornoFuncion==0){
					printf("\n--->La dirección del cliente se modificó exitosamente.");
					}else{
						printf("\n--->No se pudo modificar la dirección del cliente.");
				}
			}
		break;
		case 3:
			hayClientesCargados = BuscarPrimerEspacioOcupado(listaClientes, T_CLIENTES);
			if(hayClientesCargados==-1){
				printf("\n--->No hay clientes dados de alta aún.\n");
			}else{
				ImprimirListadoClientes(listaClientes, T_CLIENTES);
				PedirNumeroEntero(&idIngresado, "\n--->Ingrese el Id. del cliente que desea dar de baja: ", "--->ERROR.", 1, INT_MAX,3);
				if((EncontrarClientePorId(listaClientes, T_CLIENTES, idIngresado)==-1)){
					idIngresado = IngresarEntero("--->El Id. ingresado no es válido. Intente nuevamente: ");
					if((EncontrarClientePorId(listaClientes, T_CLIENTES, idIngresado)==-1)){
						printf("\n--->El Id. ingresado no existe en la base de datos.\n");
					}
				}
				if((EncontrarClientePorId(listaClientes, T_CLIENTES, idIngresado)!=-1)){
					tienePedidosPendientes = ContadorEstadoPedidoCliente(listaPedidos, T_PEDIDOS, "Pendiente", idIngresado);
					if(tienePedidosPendientes == 0){
						printf("\n--->Si desea confirmar la baja presione s: ");
						fflush(stdin);
						scanf("%s", &respuestaConfirmacion);
							if(respuestaConfirmacion=='s'||respuestaConfirmacion=='S'){
								retornoFuncion = BajaCliente(listaClientes, T_CLIENTES, idIngresado);
								if(retornoFuncion==0){
									contadorClientes--;
								printf("\n--->El cliente se dió de baja exitosamente.");
								}else{
									printf("\n--->No se pudo dar de baja el cliente.");
								}
							}else{
								printf("\n--->Se canceló la baja.\n");
							}
					}else{
						printf("\n--->No se pudo dar de baja el cliente ya que tiene pedidos pendientes.");
					}
				}
			}
		break;
		case 4:
			hayClientesCargados = BuscarPrimerEspacioOcupado(listaClientes, T_CLIENTES);
			if(hayClientesCargados==-1){
				printf("\n--->No hay clientes dados de alta aún.\n");
			}else{
				ImprimirListadoClientes(listaClientes, T_CLIENTES);
				PedirNumeroEntero(&idIngresado, "\n--->Ingrese el Id. del cliente a cargar pedido de recolección: ", "--->ERROR.", 1, INT_MAX,3);
				if((EncontrarClientePorId(listaClientes, T_CLIENTES, idIngresado))==-1){
					printf("\n--->El Id. ingresado no existe en la base de datos.\n");
					}else{
						retornoFuncion = IngresarDatosDePedido(listaPedidos, T_PEDIDOS, &idPedido, idIngresado);
						if(retornoFuncion != -1){
							printf("\n--->El pedido se dió de alta exitosamente.\n");
						}else{
							printf("\n--->ERROR. El pedido no se pudo cargar.\n");
						}
					}
				}
		break;
		case 5:
			hayPedidosCargados = BuscarPrimerEspacioOcupadoPedidos(listaPedidos, T_PEDIDOS);
			if(hayPedidosCargados==-1){
				printf("\n--->No hay pedidos cargados aún.\n");
			}else{
			ImprimirListadoPedidos(listaPedidos, T_PEDIDOS);
			PedirNumeroEntero(&idPedidoIngresado, "--->Ingrese el Id. del pedido: ", "--->ERROR.", 1, INT_MAX,3);
			if((EncontrarPedidoPorId(listaPedidos, T_PEDIDOS, idPedidoIngresado))==-1){
				printf("\n--->El Id. ingresado no existe en la base de datos.\n");
			}else{
				indexPedido = EncontrarPedidoPorId(listaPedidos, T_PEDIDOS, idPedidoIngresado);
				if(strcmp(listaPedidos[indexPedido].estado,"Pendiente")==0){
					retornoFuncion = ClasificarPlastico(listaPedidos, T_PEDIDOS, idPedidoIngresado);
					if(retornoFuncion != -1){
						printf("\n--->Los residuos del pedido se procesaron exitosamente.\n");
					}else{
						printf("\n--->ERROR. El pedido no se pudo procesar.\n");
					}
				}else{
					printf("\n--->El pedido seleccionado ya fue procesado.\n");
				}
			}
			}
		break;
		case 6:
			hayPedidosCargados = BuscarPrimerEspacioOcupadoPedidos(listaPedidos, T_PEDIDOS);
			if(hayPedidosCargados==-1){
				printf("\n--->No hay pedidos cargados aún.\n");
			}else{
				printf("\n \t1. Pedidos pendientes"
					   "\n \t2. Pedidos procesados"
					   "\n \t3. Cantidad de pedidos pendientes por cliente"
					   "\n \t4. Cantidad de pedidos pendientes por localidad"
					   "\n \t5. Kilos de polipropileno reciclado promedio por cliente"
					   "\n \t6. ID Cliente con mayor cantidad de pedidos"
						"\n --->Seleccione la opción que desea informar: ");
				fflush(stdin);
				scanf("%d", &opcionIngresadaInformes);
				opcionIngresadaInformes = ValidacionEnteroDentroDeUnRango(opcionIngresadaInformes, 1, 6);
				switch(opcionIngresadaInformes){
					case 1:
						DetallePedidosPendientes(listaPedidos, T_PEDIDOS, listaClientes, T_CLIENTES);
					break;
					case 2:
						DetallePedidosProcesados(listaPedidos, T_PEDIDOS, listaClientes, T_CLIENTES);
					break;
					case 3:
						MostrarCantidadDePedidosPendientesPorCliente(listaPedidos, T_PEDIDOS, listaClientes, T_CLIENTES);
					break;
					case 4:
						pedidosPendientesPorLocalidad = CantidadPedidosPendientesPorLocalidad(listaPedidos, T_PEDIDOS, listaClientes, T_CLIENTES, &idLocalidadIngresada);
						switch(idLocalidadIngresada){
										case 1: printf("\n--->La cantidad de pedidos pendientes en Caballito es: %d\n", pedidosPendientesPorLocalidad);
												break;
										case 2: printf("\n--->La cantidad de pedidos pendientes en Flores es: %d\n", pedidosPendientesPorLocalidad);
												break;
										case 3: printf("\n--->La cantidad de pedidos pendientes en Barracas es: %d\n", pedidosPendientesPorLocalidad);
												break;
									}
						//printf("\n--->La cantidad de pedidos pendientes en esta localidad es: %d\n", pedidosPendientesPorLocalidad);
					break;
					case 5:
						kgPPTotales = KilosTotalesDePPObtenidos(listaPedidos, T_PEDIDOS);
						kgPPPromedioPorCliente = kgPPTotales/contadorClientes;
						printf("\n--->La cantidad de kilos de polipropileno reciclado promedio por cliente es: %.1f\n", kgPPPromedioPorCliente);
					break;
					case 6:
						idClienteConMasPedidos = ClienteConMasPedidos(listaPedidos, T_PEDIDOS);
						idClienteConMasPedidosPendientes = ClienteConMasPedidosEstado(listaPedidos, T_PEDIDOS, "Pendiente");
						idClienteConMasPedidosCompletados = ClienteConMasPedidosEstado(listaPedidos, T_PEDIDOS, "Completado");
						printf("\n--->ID Cliente con mayor cantidad de pedidos: %d\n", idClienteConMasPedidos);
						printf("--->ID Cliente con mayor cantidad de pedidos pendientes: %d\n", idClienteConMasPedidosPendientes);
						printf("--->ID Cliente con mayor cantidad de pedidos completados: %d\n", idClienteConMasPedidosCompletados);
					break;
				}
			}
		}
		}while(opcionIngresada!=7);
		printf("--->Ha finalizado el programa.");
	return EXIT_SUCCESS;
}

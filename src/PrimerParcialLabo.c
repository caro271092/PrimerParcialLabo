/*Name: PrimerParcialLabo.c
 Author: Carolina Alvarez, 1E
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "Clientes.h"
#include "Pedidos.h"
#include "Informes.h"
#include "InputOutput.h"
#define T_CLIENTES 6
#define T_PEDIDOS 10

int main(void) {
	setbuf(stdout, NULL);
	int opcionIngresada = 0;
	int opcionIngresadaInformes;
	eCliente listaClientes[T_CLIENTES]; //= {{001,"carolina", "alvarez", 1234.23,2},{11,"pepe","polinas",32.4,1},{231,"marcos","juarez",555,4},{777,"sofia","vieyra",43.3,1},{8,"sonia","alvarez",345.134,3}};
	//ePedido listaPedidos[T_PEDIDOS];
	//eCliente cadaCliente;
	int retornoFuncion;
	int idCliente= 1000;
	int idPedido= 2000;
	int idIngresado;
	int idPedidoIngresado;
	int hayClientesCargados;
	int hayPedidosCargados;
	char respuestaConfirmacion;
	int indexClienteIngresado;

	IniciarEstructura(listaClientes, T_CLIENTES);
	IniciarEstructuraPedido(listaClientes, T_CLIENTES);
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
							printf("\n--->Si desea confirmar la baja presione s: ");
							fflush(stdin);
							scanf("%s", &respuestaConfirmacion);
								if(respuestaConfirmacion=='s'||respuestaConfirmacion=='S'){
									retornoFuncion = BajaCliente(listaClientes, T_CLIENTES, idIngresado);
									if(retornoFuncion==0){
									printf("\n--->El cliente se dió de baja exitosamente.");
									}else{
										printf("\n--->No se pudo dar de baja el cliente.");
										}
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
			indexClienteIngresado = EncontrarClientePorId(listaClientes, T_CLIENTES, idIngresado);
			retornoFuncion = IngresarDatosDePedido(listaClientes, T_CLIENTES, &idPedido, indexClienteIngresado);
			if(retornoFuncion != -1){
				printf("\n--->El pedido se dió de alta exitosamente.\n");
				}else{
					printf("\n--->ERROR. El pedido no se pudo cargar.\n");
					}
				}
				}
			break;
		case 5:
			hayPedidosCargados = BuscarPrimerEspacioOcupadoPedidos(listaClientes, T_CLIENTES);
			if(hayPedidosCargados==-1){
				printf("\n--->No hay pedidos cargados aún.\n");
			}else{
			ImprimirListadoPedidos(listaClientes, T_CLIENTES);
			PedirNumeroEntero(&idPedidoIngresado, "--->Ingrese el Id. del pedido: ", "--->ERROR.", 1, INT_MAX,3);
			if((EncontrarPedidoPorId(listaClientes, T_CLIENTES, idPedidoIngresado))==-1){
				printf("\n--->El Id. ingresado no existe en la base de datos.\n");
				}else{
				retornoFuncion = ClasificarPlastico(listaClientes, T_CLIENTES, idPedidoIngresado);
					if(retornoFuncion != -1){
						printf("\n--->Los residuos del pedido se procesaron exitosamente.\n");
						}else{
							printf("\n--->ERROR. El pedido no se pudo procesar.\n");
						}
				}
			}
			break;
		case 6:
			hayPedidosCargados = BuscarPrimerEspacioOcupadoPedidos(listaClientes, T_CLIENTES);
			if(hayPedidosCargados==-1){
				printf("\n--->No hay pedidos cargados aún.\n");
			}else{
				printf("\n \t1. Pedidos pendientes"
					   "\n \t2. Pedidos procesados"
					   "\n \t3. Cantidad de pedidos pendientes por cliente"
					   "\n \t4. Cantidad de pedidos pendientes por localidad"
					   "\n \t5. Kilos de polipropileno reciclado promedio por cliente"
						"\n --->Seleccione la opción que desea informar: ");
				fflush(stdin);
				scanf("%d", &opcionIngresadaInformes);
				opcionIngresadaInformes = ValidacionEnteroDentroDeUnRango(opcionIngresadaInformes, 1, 5);
				switch(opcionIngresadaInformes){
				case 1:
					DetallePedidosPendientes(listaClientes, T_CLIENTES);
					break;
				case 2:
					DetallePedidosProcesados(listaClientes, T_CLIENTES);
					break;
				case 3:
					MostrarCantidadDePedidosPendientesPorCliente(listaClientes, T_CLIENTES);
					break;
				 	 }
					/*
					printf("--->Ingrese 1 para ordenar ascendentemente o 0 para ordenar descendentemente: ");
					fflush(stdin);
					scanf("%d", &orden);
					orden = ValidacionEnteroDentroDeUnRango(orden, 0,1);
					retornoFuncion = sortEmployees(listaEmpleados,T, orden);
					if(retornoFuncion==0){
						printEmployees(listaEmpleados,T);
					}else{
						printf("\n--->No se pudieron ordenar los datos.");
					}
					break;
				case 2:
					retornoFuncion = PromedioSalarios(listaEmpleados, T, &totalSalarios,  &contadorCantidadEmpleados, &promedioSalarios, &contadorEmpleadosQueSuperanSalarioPromedio);
					if(retornoFuncion==0){
						printf("--->El total de los salarios es %.2f, su promedio %.2f y la cantidad de empleados que superan el salario promedio es %d.", totalSalarios, promedioSalarios, contadorEmpleadosQueSuperanSalarioPromedio);
						}else{
						printf("\n--->No se pudo realizar el informe.");
					}
					break;
				 }
*/

		}
		}
		}while(opcionIngresada!=7);
		printf("--->Ha finalizado el programa.");
	return EXIT_SUCCESS;
}

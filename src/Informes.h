/* Informes.h
 */
#ifndef INFORMES_H_
#define INFORMES_H_
#include "Pedidos.h"
#include "Clientes.h"
void MostrarCliente(eCliente cliente);
int ContadorEstadoPedidoCliente(eCliente listaClientes[], int tamClientes, char estadoRequerido[], int idAchequear);
void MostrarCantidadDePedidosPendientesPorCliente(eCliente listaClientes[], int tamClientes);
void MostrarClientePedidosPendientes(eCliente cliente);
void DetallePedidosPendientes(eCliente listaClientes[], int tamClientes);
void MostrarClientePedidosProcesados(eCliente cliente);
void DetallePedidosProcesados(eCliente listaClientes[], int tamClientes);

#endif /* INFORMES_H_ */

/*Pedidos.h
 */
#ifndef PEDIDOS_H_
#define PEDIDOS_H_
#include "Clientes.h"
/*typedef struct{
		int idPedido;
		float cantidadKilosARecolectar;
		char estado[30];
		float kilosHDPE;
		float kilosLDPE;
		float kilosPP;
		int isEmpty;
	}ePedido;*/

	int BuscarPrimerEspacioLibrePedidos(eCliente lista[], int tam);
	int AgregarPedido(eCliente lista[], int tam, int idPedido, float cantidadKilosARecolectar, float kilosHDPE, float kilosLDPE, float kilosPP, int idClienteIngresado);
	int IngresarDatosDePedido(eCliente lista[], int tam, int *idPedido, int idClienteIngresado);
	int ImprimirListadoPedidos(eCliente lista[], int tam);
	int BuscarPrimerEspacioOcupadoPedidos(eCliente lista[], int tam);
	int EncontrarPedidoPorId(eCliente lista[], int tam, int idPedidoIngresado);
	int ClasificarPlastico(eCliente lista[], int tam, int id);
	int IniciarEstructuraPedido(eCliente lista[], int tam);

#endif /* PEDIDOS_H_ */

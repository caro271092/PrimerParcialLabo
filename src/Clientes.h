/*Clientes.h
 */
#ifndef CLIENTES_H_
#define CLIENTES_H_

typedef struct{
		int idPedido;
		float cantidadKilosARecolectar;
		char estado[30];
		float kilosHDPE;
		float kilosLDPE;
		float kilosPP;
		int isEmpty;
	}ePedido;

/*typedef struct{
		char CABA[51];
		char GBA[51];
		char IDP[51];
		int isEmpty;
	}eLocalidad;*/


typedef struct{
		int idCliente;
		ePedido pedido;
		char nombreEmpresa[51];
		int cuit;
		char direccion[51];
		//eLocalidad localidad;
		int localidad;
		int isEmpty;
	}eCliente;

	int IniciarEstructura(eCliente lista[], int tam);
	int BuscarPrimerEspacioLibre(eCliente lista[], int tam);
	int BuscarPrimerEspacioOcupado(eCliente lista[], int tam);
	int AgregarCliente(eCliente lista[], int tam, int idCliente, char nombreEmpresa[], int cuit, char direccion[], int localidad);
	int PedirCliente(eCliente lista[], int tam, int *idCliente);
	int EncontrarClientePorId(eCliente lista[], int tam, int idIngresado);
	int ModificarDireccion(eCliente lista[], int tam, int id);
	int ImprimirListadoClientes(eCliente lista[], int tam);
	int BajaCliente(eCliente lista[], int tam, int idBaja);


#endif /* CLIENTES_H_ */

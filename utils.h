#ifndef __UTILS_H__
#define __UTILS_H__

/*-----------------------------------------------------------------------------
|   Includes
+----------------------------------------------------------------------------*/
#include "global.h"

/*-----------------------------------------------------------------------------
|   Portotipos
+----------------------------------------------------------------------------*/

RET existe(int x);
RET existePedido(int x, PEDIDOS *raizPedEx);
int cantidadpro(void);
void codNombreProduct(int cod, char *nombre);
float precioProduct(int cod);
RET existeUsu(int x);
RET vaciausu(void);
int cantidadusu(void);
RET vaciaped(PEDIDOS *raizPedEx);
int cantidadPed(PEDIDOS *raizPedCa);
RET descontarProducto(int codi, int cant);
RET validarCantidad(int cant, int codi);

#endif // __UTILS_H__

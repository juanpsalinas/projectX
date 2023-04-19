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
int cantidadpro();
void codNombreProduct(int cod, char* nombre);
float precioProduct(int cod);
RET existeUsu(int x);
RET vaciausu();
int cantidadusu();
RET vaciaped(PEDIDOS *raizPedEx);
int cantidadPed(PEDIDOS *raizPedCa);
RET descontarProducto(int codi, int cant);

#endif // __UTILS_H__

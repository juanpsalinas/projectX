#ifndef __UTILS_H__
#define __UTILS_H__

#include "global.h"


RET existe(int x);
RET existePedido(int x, PEDIDOS *raizPedEx);
int cantidadpro();
const char *codNombreProduct(int cod);
int precioProduct(int cod);
RET existeUsu(int x);
RET vaciausu();
int cantidadusu();
RET vaciaped(PEDIDOS *raizPedEx);
int cantidadPed(PEDIDOS *raizPedCa);
RET descontarProducto(int codi, int cant);

#endif
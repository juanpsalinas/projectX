#ifndef __REGISTRO__
#define __REGISTRO__

#include "global.h"

void insertarusu( char nombreusu[15], char cedula[15] );
void insertarpro( char nombrep[15], int cantidadp, float preciop);
void insertarPedido(int cant, int pos , char nombreProd[15] , int cantProd, float valor, PEDIDOS *vect);
void datosUser();
void registrarVenta();
void NuevoProducto();
#endif
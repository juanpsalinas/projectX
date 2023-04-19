#ifndef __REGISTRO__
#define __REGISTRO__

/*-----------------------------------------------------------------------------
|   Includes
+----------------------------------------------------------------------------*/
#include "global.h"

/*-----------------------------------------------------------------------------
|   Prototipos
+----------------------------------------------------------------------------*/

void insertarusu(char *nombreusu, char *cedula);
void insertarpro(char *nombrep, int cantidadp, float preciop);
void insertarPedido(int cant, char *nombreProd, int cantProd, float valor);
void datosUser(void);
void registrarVenta(void);
void NuevoProducto(void);

#endif // __REGISTRO__

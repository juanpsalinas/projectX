#ifndef __IMPRIMIR__
#define __IMPRIMIR__

/*-----------------------------------------------------------------------------
|   Includes
+----------------------------------------------------------------------------*/
#include "global.h"

/*-----------------------------------------------------------------------------
|   Prototipos
+----------------------------------------------------------------------------*/
void imprimirpro(void);
void imprimirUsu();
void imprimirUsuespe(USUARIOS *usuarioProd);
void imprimirPedi(PEDIDOS *vectP[TAMANO]);
void imprimirPediEspes(PEDIDOS *vectEsps, int codigoPedido);

#endif // __IMPRIMIR__

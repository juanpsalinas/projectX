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
void imprimirUsu(void);
void imprimirUsuespe(USUARIOS *usuarioProd);
void imprimirPedi(PEDIDOS *vectP);
void imprimirPediEspes(PEDIDOS *vectEsps, int codigoPedido);

#endif // __IMPRIMIR__

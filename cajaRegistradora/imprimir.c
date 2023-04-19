/*-----------------------------------------------------------------------------
|   Includes
+----------------------------------------------------------------------------*/
#include "imprimir.h"

/*-----------------------------------------------------------------------------
|   Funciones
+----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
| Function Name: imprimirpro
| Description: Imprime la lista de productos.
| Parameters:
| - Nada (void).
| Returns:
| - Nada (void).
+---------------------------------------------------------------------------*/
void imprimirpro(void)
{
    PRODUCTOS *reco = raiz;
    printf("___   LISTA DE PRODUCTOS   ___ \n");
    while (reco != NULL)
    {
        printf("\n<<<<<<<<<<  %s  >>>>>>>>>>>\n", reco->nombre);
        printf(" Codigo | Cantidad | Precio \n");
        printf("   %d\t     %d\t     %0.0f \n", reco->codigo, reco->cantidad, reco->precio);
        reco = reco->sig;
    }
    printf("\n");
}

/*----------------------------------------------------------------------------
| Function Name: imprimirUsu
| Description: Imprime la información de los usuarios almacenados en una lista enlazada.
| Parameters: Ninguno.
| Returns: Ninguno.
+---------------------------------------------------------------------------*/
void imprimirUsu(void)
{
    USUARIOS *recous = raizUsu;
    while (recous != NULL)
    {
        printf("\n\n************************************\n");
        printf("<<<<<<<<<<  %s  >>>>>>>>>>>\n", recous->nombreUs);
        printf("\t<> Cedula : %s \n", recous->cedulaUs);
        printf("\t<> Codigo : %d \n", recous->codigoUsu);
        recous = (USUARIOS *)recous->sig;
    }
    printf("\n");
}

/*-----------------------------------------------------------------------------
| Nombre de la función: imprimirUsuespe
| Descripción: Imprime la información de un usuario dado
| Parámetros:
| - usuarioProd: puntero a una estructura USUARIOS que representa al usuario a imprimir
| Devoluciones: nulo
+---------------------------------------------------------------------------*/
void imprimirUsuespe(USUARIOS *usuarioProd)
{
    printf(" _____________________________________\n");
    printf("|  Nombre  |  |  Cedula   |  | Codigo|\n");
    printf("|  %s    \t%s  \t  %d _|\n", usuarioProd->nombreUs, usuarioProd->cedulaUs, usuarioProd->codigoUsu);
    printf("\n");
}

/*----------------------------------------------------------------------------
| Function Name: imprimirPedi
| Description: Imprime los pedidos almacenados en un arreglo de PEDIDOS
| Parameters: vectP: arreglo de PEDIDOS
| Returns: void
+---------------------------------------------------------------------------*/
void imprimirPedi(PEDIDOS *vectP)
{
    CLEAN
    PEDIDOS *reco = vectP;
    float total = 0;

    RET band = RET_FAIL;

    while (reco != NULL)
    {
        if (band == RET_FAIL)
        {
            total = 0;
            printf("\n*************************************2\n");
            printf(" xxxxxxxxxxx  Pedido N*:%d  xxxxxxxxxx\n", reco->codigoPedido);
            printf("   --Fecha: %s--\n", reco->fecha);
            imprimirUsuespe(reco->usuarioP);
            band = RET_OK;
        }
        while (1)
        {
            printf("->\t%s ............%0.2f\n", reco->nombreP, reco->valorC);
            total += reco->valorC;
            if (reco->sig != NULL && reco->codigoPedido == reco->sig->codigoPedido)
                reco = reco->sig;
            else
            {
                band = RET_FAIL;
                break;
            }
        }
        printf("\t\t  ____________________\n");
        printf("\t\t\tTOTAL: %.2f\n", total);
        reco = reco->sig;
        printf("**************************************\n");
    }
}

/*------------------------------------------------ ----------------------------
| Nombre de la función: imprimirPediEspes
| Descripción: imprime un informe de pedido detallado para un pedido específico
| Parámetros: PEDIDOS *vectEsps - puntero al primer nodo de la orden
| Returns: void
+------------------------------------------------- --------------------------*/
void imprimirPediEspes(PEDIDOS *vectEsps, int codigoPedido)
{
    // CLEAN//
    PEDIDOS *reco = vectEsps;
    float total = 0;
    RET band = RET_FAIL;

    while (reco != NULL)
    {
        if (codigoPedido == reco->codigoPedido)
        {
            if (band == RET_FAIL)
            {
                printf("\n*************************************\n");
                printf(" xxxxxxxxxxx  Pedido N*:%d  xxxxxxxxxx\n", reco->codigoPedido);
                printf("   --Fecha: %s--\n", reco->fecha);
                imprimirUsuespe(reco->usuarioP);
                band = RET_OK;
            }
            printf("->\t%s ............%0.2f\n", reco->nombreP, reco->valorC);
            total += reco->valorC;
        }
        reco = reco->sig;
    }
    printf("_____________________________________\n");
    printf(" \tTOTAL: .............%0.2f\n\n", total);
}

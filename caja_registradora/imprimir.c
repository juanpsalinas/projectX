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
    printf("\t___   LISTA DE PRODUCTOS   ___");
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
void imprimirUsu()
{
    USUARIOS *recous = raizUsu;
    while (recous != NULL)
    {
        printf("\n\n************************************\n");
        printf("<<<<<<<<<<  %s  >>>>>>>>>>>\n", recous->nombreUs);
        printf("\t<> Cedula : %s \n", recous->cedulaUs);
        printf("\t<> Codigo : %d \n\n", recous->codigoUsu);
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
    printf("|  Nombre  |  |  Cedula  |   | Codigo|\n");
    printf("|  %s    \t%s  \t  %d _|\n", usuarioProd->nombreUs, usuarioProd->cedulaUs, usuarioProd->codigoUsu);
    printf("\n");
}

/*----------------------------------------------------------------------------
| Function Name: imprimirPedi
| Description: Imprime los pedidos almacenados en un arreglo de PEDIDOS
| Parameters: vectP: arreglo de PEDIDOS
| Returns: void
+---------------------------------------------------------------------------*/
void imprimirPedi(PEDIDOS *vectP[TAMANO])
{
    CLEAN
    int i = 0;
    PEDIDOS *reco = vectP[i];
    PEDIDOS *reco2 = vectP[i];
    float total = 0;

    while (vectP[i] != NULL)
    {
        reco = vectP[i];
        printf("\n*************************************\n");
        printf("  xxxxxxxxx  Pedido N*:%d  xxxxxxxxx\n", reco->codigoPedido);
        printf("   --Fecha: %s--\n", reco->fecha);
        imprimirUsuespe(reco->usuarioP);

        total = 0;
        while (reco != NULL)
        {
            printf("-> %s ..................%0.2f\n", reco->nombreP, reco->valorC);
            total += reco->valorC;
            reco = (PEDIDOS *)reco->sig;
        }

        printf("                  ____________________\n");
        printf("\t\t\tTOTAL: %.2f\n", total);
        printf("**************************************\n");
        i++;
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
    int i = 0;
    PEDIDOS *reco = vectEsps;
    float total = 0;

    while (reco != NULL)
    {
        if(codigoPedido == reco->codigoPedido)
            break;
        reco = reco->sig;
    }

    printf("\n*************************************\n");
    printf(" xxxxxxxxxxx  Pedido N*:%d  xxxxxxxxxx\n", reco->codigoPedido);
    printf("   --Fecha: %s--\n", reco->fecha);
    imprimirUsuespe(reco->usuarioP);

    printf("->\t%s ............%0.2f\n", reco->nombreP, reco->valorC);
    total += reco->valorC;

    printf("_____________________________________\n");
    printf(" \tTOTAL: ..............%0.2f\n\n", total);
    i++;
}

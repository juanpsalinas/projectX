/*-----------------------------------------------------------------------------
|   Includes
+----------------------------------------------------------------------------*/
#include "global.h"
#include "utils.h"
#include "registro.h"
#include "imprimir.h"

/*-----------------------------------------------------------------------------
|   Globales
+----------------------------------------------------------------------------*/
int cantUs = -1;
PRODUCTOS *raiz = NULL;
USUARIOS *raizUsu = NULL;
USUARIOS *nombreClienActu = NULL;
PEDIDOS *raizPed = NULL;
PEDIDOS *vectorPedidos = NULL;

/*-----------------------------------------------------------------------------
|   Prototipos
+----------------------------------------------------------------------------*/
static void inventario();
static void menuPrincipal();

/*-----------------------------------------------------------------------------
|   Funciones
+----------------------------------------------------------------------------*/

//TODO: Cabecera
static void inventario()
{
    int opcion;
    do
    {
        printf("\nSub-menu de inventario\n");
        printf(" ¿¿¿¿¿¿¿¿¿¿¿\n");
        printf(" ''''''''''''''''''''''\n");
        printf("|>  1-Agregar productos.\n");
        printf("|>  2-Listado de productos.\n");
        printf("|>  3-Salir.\n\n");
        printf("Elija su opcion: ->");
        scanf("%i", &opcion);
        CLEAN
        switch (opcion)
        {
        case 1:
            NuevoProducto();
            break;
        case 2:
            imprimirpro();
            break;
        default:
            printf("\n");
        }
    } while (opcion != 3);
}

//TODO: Cabecera
static void menuPrincipal()
{
    int opcion;
    do
    {
        printf("\n***  MINI CAJA REGISTRADORA ***\n");
        printf("   -------------------------\n");
        printf("[]  1-Registrar venta.\n");
        printf("[]  2-Inventario.\n");
        printf("[]  3-Lista de ventas.\n");
        printf("[]  4-Salir.\n");
        printf("[]  5-Imprimir usuarios.\n");
        printf("Elija su opcion: ->");
        scanf("%i", &opcion);
        CLEAN
        switch (opcion)
        {
        case 1:
            registrarVenta();
            break;
        case 2:
            inventario();
            break;
        case 3:
            imprimirPedi(&vectorPedidos);
            break;
        case 4: // Salir
            printf("Gracias por utilizar nuestra caja registradora!\n\n");
            break;
        case 5:
            imprimirUsu();
            break;
        default:
            printf("La opcion no es valida.\n");
        }
    } while (opcion != 4);
}

int main()
{
    // CLEAN
    /* for (int i = 0; i < TAMANO; i++)
        vectorPedidos->sig = raizPed; */

    insertarpro("CARNE", 15, 1500.0);
    insertarpro("PAPA", 20, 1350.0);
    insertarpro("LECHE", 30, 2000.0);

    insertarusu("JUAN P", "12546322");
    insertarusu("PABLO S", "24545444");
    insertarusu("SLINAS J", "32565655");
    insertarusu("J LOPEZ", "32121515");

    menuPrincipal();

    return 0;
}

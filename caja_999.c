
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura que representa un producto
typedef struct Producto
{
    int id;
    char nombre[50];
    double precio;
    int cantidad;
    struct Producto *siguiente;
} Producto;

// Estructura que representa una venta
typedef struct Venta
{
    int idProducto;
    char nombreProducto[50];
    double precioProducto;
    int cantidadProducto;
    double total;
    struct Venta *siguiente;
} Venta;

// Función que muestra el menú principal
int mostrarMenuPrincipal()
{
    int opcion;
    printf("===== MENU PRINCIPAL =====\n");
    printf("1. Registrar venta\n");
    printf("2. Inventario\n");
    printf("3. Listar ventas\n");
    printf("4. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

// Función que muestra el menú del inventario
int mostrarMenuInventario()
{
    int opcion;
    printf("===== INVENTARIO =====\n");
    printf("1. Crear producto\n");
    printf("2. Listar productos\n");
    printf("3. Regresar\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

// Función que crea un nuevo producto
Producto *crearProducto(int id, char nombre[], double precio, int cantidad)
{
    Producto *producto = (Producto *)malloc(sizeof(Producto));
    producto->id = id;
    strcpy(producto->nombre, nombre);
    producto->precio = precio;
    producto->cantidad = cantidad;
    producto->siguiente = NULL;
    return producto;
}

// Función que agrega un producto a la lista enlazada
void agregarProducto(Producto **listaProductos, Producto *producto)
{
    if (*listaProductos == NULL)
    {
        *listaProductos = producto;
    }
    else
    {
        Producto *actual = *listaProductos;
        while (actual->siguiente != NULL)
        {
            actual = actual->siguiente;
        }
        actual->siguiente = producto;
    }
}

// Función que muestra los productos del inventario
void mostrarProductos(Producto *listaProductos)
{
    printf("===== INVENTARIO =====\n");
    printf("ID\tNOMBRE\t\tPRECIO\tCANTIDAD\n");
    while (listaProductos != NULL)
    {
        printf("%d\t%s\t\t%.2f\t%d\n", listaProductos->id, listaProductos->nombre, listaProductos->precio, listaProductos->cantidad);
        listaProductos = listaProductos->siguiente;
    }
}

// Función que realiza una venta
void realizarVenta(Producto **listaProductos, Venta **pilaVentas)
{
    int idProducto, cantidadProducto;
    Producto *producto = NULL;
    printf("Ingrese el ID del producto: ");
    scanf("%d", &idProducto);
    printf("Ingrese la cantidad del producto: ");
    scanf("%d", &cantidadProducto);

    // Buscar el producto en el inventario
    Producto *actual = *listaProductos;
    while (actual != NULL)
    {
        if (actual->id == idProducto)
        {
            producto = actual;
            break;
        }
        actual = actual->siguiente;
    }

    // Verificar que se haya encontrado el producto y haya suficiente cantidad
    if (producto == NULL)
    {
        printf("ERROR: Producto no encontrado en el inventario.\n");
    }
    else if (cantidadProducto > producto->cantidad)
    {
        printf("ERROR: No hay suficiente cantidad del producto en el inventario.\n");
    }
    else
    {
        // Actualizar el inventario
        producto->cantidad -= cantidadProducto;

        // Calcular el total de la venta y crear la venta
        double totalVenta = cantidadProducto * producto->precio;
        Venta *venta = (Venta *)malloc(sizeof(Venta));
        venta->idProducto = producto->id;
        strcpy(venta->nombreProducto, producto->nombre);
        venta->precioProducto = producto->precio;
        venta->cantidadProducto = cantidadProducto;
        venta->total = totalVenta;
        venta->siguiente = *pilaVentas;
        *pilaVentas = venta;

        printf("Venta realizada con exito. Total: %.2f\n", totalVenta);
    }
}

// Función que muestra las ventas realizadas
void mostrarVentas(Venta *pilaVentas)
{
    printf("===== VENTAS =====\n");
    printf("ID\tNOMBRE\t\tPRECIO\tCANTIDAD\tTOTAL\n");
    while (pilaVentas != NULL)
    {
        printf("%d\t%s\t\t%.2f\t%d\t\t%.2f\n", pilaVentas->idProducto, pilaVentas->nombreProducto, pilaVentas->precioProducto, pilaVentas->cantidadProducto, pilaVentas->total);
        pilaVentas = pilaVentas->siguiente;
    }
}

int main()
{
    Producto *listaProductos = NULL;
    Venta *pilaVentas = NULL;
    int opcion;
    do
    {
        opcion = mostrarMenuPrincipal();
        switch (opcion)
        {
        case 1:
            realizarVenta(&listaProductos, &pilaVentas);
            break;
        case 2:
            opcion = mostrarMenuInventario();
            switch (opcion)
            {
            case 1:
            {
                int id;
                char nombre[50];
                double precio;
                int cantidad;
                printf("Ingrese el ID del producto: ");
                scanf("%d", &id);
                printf("Ingrese el nombre del producto: ");
                scanf("%s", nombre);
                printf("Ingrese el precio del producto: ");
                scanf("%lf", &precio);
                printf("Ingrese la cantidad del producto: ");
                scanf("%d", &cantidad);
                Producto *producto = crearProducto(id, nombre, precio, cantidad);
                agregarProducto(&listaProductos, producto);
                printf("Producto creado con exito.\n");
                break;
            }
            case 2:
                mostrarProductos(listaProductos);
                break;
            case 3:
                break;
            default:
                printf("ERROR: Opcion invalida.\n");
                break;
            }
            break;
        case 3:
            mostrarVentas(pilaVentas);
            break;
        case 4:
            printf("Adios!\n");
            break;
        default:
            printf("ERROR: Opcion invalida.\n");
            break;
        }
    } while (opcion != 4);

            // Liberar memoria
            Producto *actualProducto = listaProductos;
    while (actualProducto != NULL)
    {
        Producto *siguienteProducto = actualProducto->siguiente;
        free(actualProducto);
        actualProducto = siguienteProducto;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PRODUCTOS 50
#define MAX_VENTAS 100

typedef struct
{
    char nombre[50];
    int cantidad;
    float precio;
} Producto;

typedef struct
{
    char nombre[50];
    int cantidad;
    float precio;
    char nombreComprador[50];
} Venta;

void menuInventario()
{
    int subopcion;
    Producto inventario[MAX_PRODUCTOS];
    int n_productos = 0;

    do
    {
        printf("\n*** Inventario ***\n");
        printf("1. Crear producto\n");
        printf("2. Listar productos\n");
        printf("3. Regresar\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &subopcion);

        switch (subopcion)
        {
        case 1:
            crearProducto(inventario, &n_productos);
            break;
        case 2:
            listarProductos(inventario, n_productos);
            break;
        case 3:
            break;
        default:
            printf("Opción inválida. Por favor seleccione una opción del 1 al 3.\n");
            break;
        }
    } while (subopcion != 3);
}

// Función para mostrar el menú principaL
int main()
{
    Producto inventario[MAX_PRODUCTOS];
    int n_productos = 0;
    Venta ventas[MAX_VENTAS];
    int n_ventas = 0;

    int opcion = 0;
    do
    {
        // Menú principal
        printf("\n*** MINI CAJA REGISTRADORA ***\n");
        printf("   -------------------------\n");
        printf("Menu Principal: \n");
        printf("1. Registrar venta\n");
        printf("2. Inventario\n");
        printf("3. Listar ventas\n");
        printf("4. Guardar los datos del inventario y las ventas en un archivo.\n");
        printf("5. Cargar los datos del inventario y las ventas desde un archivo.\n");
        printf("6. Salir del programa\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            registrarVenta(inventario, n_productos, ventas, &n_ventas);
            break;
        case 2:
            menuInventario();
            break;
        case 3:
            listarVentas(ventas, n_ventas);
            break;
        case 4:
            guardarDatos(inventario, n_productos, ventas, n_ventas);
            break;
        case 5:
            cargarDatos(inventario, &n_productos, ventas, &n_ventas);
            break;
        case 6:
            printf("Gracias por utilizar nuestra caja registradora!\n");
            break;
        default:
            printf("Opción inválida. Por favor seleccione una opción del 1 al 6.\n");
            break;
        }
    } while (opcion != 6);

    return 0;
}


// Función para crear un nuevo producto en el inventario
void crearProducto(Producto *inventario, int *n_productos)
{

    if (*n_productos == MAX_PRODUCTOS)
    {
        printf("No se pueden agregar más productos al inventario.\n");
        return;
    }
    Producto nuevoProducto;
    printf("Ingrese el nombre del producto: ");
    scanf("%s", nuevoProducto.nombre);
    printf("Ingrese la cantidad del producto: ");
    scanf("%d", &nuevoProducto.cantidad);
    printf("Ingrese el precio del producto: ");
    scanf("%f", &nuevoProducto.precio);
    
    inventario[*n_productos] = nuevoProducto;
    (*n_productos)++;
    printf("El producto ha sido agregado al inventario.\n");
}

// Función para listar los productos del inventario
void listarProductos(Producto *inventario, int n_productos)
{
    printf("Inventario:\n");
    for (int i = 0; i < n_productos; i++)
    {
        printf("%d. %s, Cantidad: %d, Precio: %.2f\n", i + 1, inventario[i].nombre, inventario[i].cantidad, inventario[i].precio);
    }
}

// Función para registrar una venta
void registrarVenta(Producto *inventario, int n_productos, Venta *ventas, int *n_ventas)
{
    char nombreProducto[50];
    int cantidad = 0;
    char nombreComprador[50];

    printf("Ingrese el nombre del comprador: ");
    scanf("%s", nombreComprador);

    printf("Ingrese el nombre del producto vendido: ");
    scanf("%s", nombreProducto);
    for (int i = 0; i < n_productos; i++)
    {
        if (strcmp(nombreProducto, inventario[i].nombre) == 0) // comparar el nombre del producto ingresado con el nombre de los productos en el inventario
        {
            printf("Ingrese la cantidad vendida: ");
            scanf("%d", &cantidad);
            if (cantidad <= inventario[i].cantidad) // verificar si hay suficiente cantidad de producto en el inventario
            {
                Venta nuevaVenta;
                strcpy(nuevaVenta.nombre, nombreProducto);
                nuevaVenta.cantidad = cantidad;
                nuevaVenta.precio = inventario[i].precio;
                ventas[*n_ventas] = nuevaVenta;
                (*n_ventas)++;
                inventario[i].cantidad -= cantidad;
                printf("La venta ha sido registrada.\n");
                return;
            }
            else
            {
                printf("No hay suficiente cantidad de %s en el inventario.\n", inventario[i].nombre);
                return;
            }
        }
    }
    printf("El producto ingresado no se encuentra en el inventario.\n");
}

// Función para listar las ventas realizadas
void listarVentas(Venta ventas[], int n_ventas){

    printf("Ventas realizadas:\n");
    for (int i = 0; i < n_ventas; i++)
    {
        printf("%d. %s, Cantidad: %d, Precio total: %.2f, comprado por:%s\n", i + 1, ventas[i].nombre, ventas[i].cantidad, ventas[i].precio, ventas[i].nombreComprador);
    }
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char fecha[30];
    sprintf(fecha, "%d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("Fecha y hora actual:: %s\n", fecha); // Se agrega esta línea para imprimir la variable "fecha".
}
// Función para guardar los datos del inventario y las ventas en un archivo
void guardarDatos(Producto *inventario, int n_productos, Venta *ventas, int n_ventas)
{
    FILE *archivo;
    archivo = fopen("datos.txt", "w");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }
    fprintf(archivo, "Inventario:\n");
    for (int i = 0; i < n_productos; i++)
    {
        fprintf(archivo, "%s %d %.2f\n", inventario[i].nombre, inventario[i].cantidad, inventario[i].precio);
    }
    fprintf(archivo, "\nVentas:\n");
    for (int i = 0; i < n_ventas; i++)
    {
        fprintf(archivo, "%s %d %.2f\n", ventas[i].nombre, ventas[i].cantidad, ventas[i].precio);
    }
    printf("Los datos han sido guardados en el archivo datos.txt\n");
    fclose(archivo);
}

// Función para cargar los datos del inventario y las ventas desde un archivo
void cargarDatos(Producto *inventario, int *n_productos, Venta *ventas, int *n_ventas)
{
    FILE *archivo;
    archivo = fopen("datos.txt", "r");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }
    
    char linea[100];
    fgets(linea, 100, archivo);
    if (strcmp(linea, "Inventario:\n") == 0)
    {
        while (fgets(linea, 100, archivo) != NULL && *n_productos < MAX_PRODUCTOS)
        {
            char *nombre = strtok(linea, " ");
            char *cantidad_str = strtok(NULL, " ");
            char *precio_str = strtok(NULL, " ");
            int cantidad = atoi(cantidad_str);
            float precio = atof(precio_str);
            Producto nuevoProducto;
            strcpy(nuevoProducto.nombre, nombre);
            nuevoProducto.cantidad = cantidad;
            nuevoProducto.precio = precio;
            inventario[*n_productos] = nuevoProducto;
            (*n_productos)++;
        }
    }
    fgets(linea, 100, archivo);
    if (strcmp(linea, "\nVentas:\n") == 0)
    {
        while (fgets(linea, 100, archivo) != NULL && *n_ventas < MAX_VENTAS)
        {
            char *nombre = strtok(linea, " ");
            char *cantidad_str = strtok(NULL, " ");
            char *precio_str = strtok(NULL, " ");
            int cantidad = atoi(cantidad_str);
            float precio = atof(precio_str);
            Venta nuevaVenta;
            strcpy(nuevaVenta.nombre, nombre);
            nuevaVenta.cantidad = cantidad;
            nuevaVenta.precio = precio;
            ventas[*n_ventas] = nuevaVenta;
            (*n_ventas)++;
        }
    }
    printf("Los datos han sido cargados desde el archivo datos.txt\n");
    fclose(archivo);
}


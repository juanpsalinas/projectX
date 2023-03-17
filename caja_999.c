
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definición de estructuras
struct Producto {
    int id;
    char nombre[20];
    int cantidad;
};

struct Venta {
    int id;
    char nombreComprador[50];
    int idProducto;
    int cantidad;
    char fecha[30];
};

// Declaración de variables globales
struct Producto inventario[3] = {{1, "Carne", 10}, {2, "Leche", 20}, {3, "Arroz", 30}};
struct Venta ventas[100];
int numVentas = 0;

// Declaración de funciones
void registrarVenta();
void mostrarInventario();
void crearProducto();
void listarProductos();
void listarVentas();
void menuInventario();

void menuInventario()
{
    int subopcion;
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
            crearProducto();
            break;
        case 2:
            listarProductos();
            break;
        case 3:
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }
    } while (subopcion != 3);
}

// Función principal
int main()
{
    int opcion;
    do
    {
        // Menú principal
        printf("\n*** Caja registradora ***\n");
        printf("1. Registrar venta\n");
        printf("2. Inventario\n");
        printf("3. Listar ventas\n");
        printf("4. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            registrarVenta();
            break;
        case 2:
            menuInventario();
            break;
        case 3:
            listarVentas();
            break;
        case 4:
            printf("Hasta luego!\n");
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }

    } while (opcion != 4);

    return 0;
}

// Implementación de funciones
void registrarVenta() {
// Mostrar inventario
mostrarInventario();


// Obtener id del producto a vender
int idProducto;
printf("Ingrese el id del producto que desea vender: ");
scanf("%d", &idProducto);

// Obtener cantidad a vender
int cantidad;
printf("Ingrese la cantidad que desea vender: ");
scanf("%d", &cantidad);

// Verificar si hay suficiente cantidad en inventario
int i;
for (i = 0; i < 3; i++) {
    if (inventario[i].id == idProducto) {
        if (inventario[i].cantidad < cantidad) {
            printf("No hay suficiente cantidad en inventario\n");
            return;
        }
        else {
            inventario[i].cantidad -= cantidad;
            break;
        }
    }
}

// Si el producto no se encontró en el inventario
if (i == 3) {
    printf("El producto no se encuentra en inventario\n");
    return;
}

// Obtener el nombre del comprador
char nombreComprador[50];
printf("Ingrese el nombre del comprador: ");
scanf("%s", nombreComprador);

// Obtener la fecha actual
time_t t = time(NULL);
struct tm tm = *localtime(&t);
char fecha[30];
sprintf(fecha, "%d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

// Crear registro de venta
ventas[numVentas].id = numVentas + 1;
ventas[numVentas].idProducto = idProducto;
ventas[numVentas].cantidad = cantidad;
strcpy(ventas[numVentas].nombreComprador, nombreComprador);
strcpy(ventas[numVentas].fecha, fecha);
numVentas++;

printf("Venta registrada exitosamente\n");
}

void mostrarInventario() {
printf("\nInventario:\n");
printf("ID\tNombre\tCantidad\n");
int i;
for (i = 0; i < 3; i++) {
printf("%d\t%s\t%d\n", inventario[i].id, inventario[i].nombre, inventario[i].cantidad);
}
}

void crearProducto() {
// Obtener los datos del producto a crear
int id;
printf("Ingrese el id del producto: ");
scanf("%d", &id);


char nombre[20];
printf("Ingrese el nombre del producto: ");
scanf("%s", nombre);

int cantidad;
printf("Ingrese la cantidad del producto: ");
scanf("%d", &cantidad);

// Crear el producto
inventario[2].id = id;
strcpy(inventario[2].nombre, nombre);
inventario[2].cantidad = cantidad;

printf("Producto creado exitosamente\n");
}

void listarProductos() {
printf("\nProductos en inventario:\n");
printf("ID\tNombre\tCantidad\n");
int i;
for (i = 0; i < 3; i++) {
printf("%d\t%s\t%d\n", inventario[i].id, inventario[i].nombre, inventario[i].cantidad);
}
}

void listarVentas() {
printf("\nRegistro de ventas:\n");
printf("ID\tProducto\tComprador\tCantidad\tFecha\n");
int i;
for (i = 0; i < numVentas; i++) {
printf("%d\t%s\t%s\t%d\t%s\n", ventas[i].id, inventario[ventas[i].idProducto - 1].nombre, ventas[i].nombreComprador, ventas[i].cantidad, ventas[i].fecha);
}
}
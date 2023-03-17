#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTOS 3
#define LIMPIAR    \
    system("cls"); \
    system("pause");

typedef struct{
    char nombre[20];
    float precio;
    int cantidad;
} TPRODUCTO;

void agregar_producto(TPRODUCTO carrito[], int *cantidad_productos);
void eliminar_producto(TPRODUCTO carrito[], int *cantidad_productos);
void mostrar_carrito(TPRODUCTO carrito[], int cantidad_productos);
void mostrar_total(TPRODUCTO carrito[], int cantidad_productos);

int main(){ 
    TPRODUCTO carrito[MAX_PRODUCTOS];
    int cantidad_productos = 0;
    int opcion;

    do{
        do{
        printf("\n\n");
        printf("\n--- MINI CAJA REGISTADORA ---\n");
        printf("\n  -------------------------\n");
        printf("Menu Principal: \n");
        printf("(1) Resgistrar Venta.\n");
        printf("(2) Inventario.\n");
        printf("(3) Listar ventas.\n");
        printf("(4) Salir.\n");
        printf("(5) jhchiu.\n");

        printf("\nEscoja la opcion:");
        scanf("%d", &opcion);
        }while (opcion < 1 || opcion>5);


        switch (opcion) {
            case 1:
                agregar_producto(carrito, &cantidad_productos);
                break;
            case 2:
                eliminar_producto(carrito, &cantidad_productos);
                break;
            case 3:
                mostrar_carrito(carrito, cantidad_productos);
                break;
            case 4:
                mostrar_total(carrito, cantidad_productos);
                break;
            case 5:
                printf("\nHasta luego!\n");
                return 0;
            default:
                printf("\nOpcion invalida. Intente nuevamente.\n");
        }
    }
    
}










void agregar_producto(TPRODUCTO carrito[], int *cantidad_productos)
{
    int i;
    char nombre[20];
    float precio;
    int cantidad;

    if (*cantidad_productos >= MAX_PRODUCTOS)
    {
        printf("\nEl carrito esta lleno.\n");
        return;
    }

    printf("\n--- Agregar producto ---\n");

    FILE *identificador = fopen("TPRODUCTO.txt", "a");
    if (identificador == NULL)
    {
        printf("NO SE HA PODIDO ABRIR EL FICHERO.\n ");
        return;
    }
    fprintf(identificador, "10202121");
    
    fclose(identificador);

    printf("Ingrese el nombre del producto: ");
    scanf("%s", nombre);

    printf("Ingrese el precio del producto: ");
    scanf("%f", &precio);

    printf("Ingrese la cantidad del producto: ");
    scanf("%d", &cantidad);


    for (i = 0; i < MAX_PRODUCTOS; i++){
        if (strcmp(carrito[i].nombre, "") == 0){
            strcpy(carrito[i].nombre, nombre);
            carrito[i].precio = precio;
            carrito[i].cantidad = cantidad;
            *cantidad_productos += 1;
            printf("\nProducto agregado exitosamente.\n");
            return;
        }
    }
}

void mostrar_carrito(TPRODUCTO carrito[], int cantidad_productos) {
int i;


printf("\n--- Carrito ---\n");

if (cantidad_productos == 0) {
    printf("\nEl carrito esta vacio.\n");
    return;
}

for (i = 0; i < MAX_PRODUCTOS; i++) {
    if (strcmp(carrito[i].nombre, "") != 0) {
        printf("%d. %s\t%.2f\t%d\n", i+1, carrito[i].nombre, carrito[i].precio,  carrito[i].cantidad);
    }
}
}

void mostrar_total(TPRODUCTO carrito[], int cantidad_productos) {
int i;
float total = 0.0;

printf("\n--- Total ---\n");

if (cantidad_productos == 0) {
    printf("\nEl carrito esta vacio.\n");
    return;
}

for (i = 0; i < MAX_PRODUCTOS; i++) {
    if (strcmp(carrito[i].nombre, "") != 0) {
        total += carrito[i].precio * carrito[i].cantidad;
    }
}

printf("\nEl total es: $%.2f\n", total);
}
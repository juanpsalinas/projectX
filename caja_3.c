
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTOS 3

struct producto {
    char nombre[20];
    int id;
    float precio;
    int cantidad;
};

struct compra {
    char fecha[20];
    char nombre_comprador[50];
    int cantidad_productos;
    struct producto productos[MAX_PRODUCTOS];
};

void agregar_producto(struct compra *c) {
    int id, cantidad;
    struct producto p;

    printf("\n--- Agregar Producto ---\n");

    printf("\nID del producto: ");
    scanf("%d", &id);
    fflush(stdin);

    switch (id) {
        case 1:
            strcpy(p.nombre, "Carne");
            p.id = 1;
            p.precio = 100.0;
            break;
        case 2:
            strcpy(p.nombre, "Leche");
            p.id = 2;
            p.precio = 50.0;
            break;
        case 3:
            strcpy(p.nombre, "Arroz");
            p.id = 3;
            p.precio = 30.0;
            break;
        default:
            printf("\nProducto no encontrado.\n");
            return;
    }

    printf("\nCantidad: ");
    scanf("%d", &cantidad);
    fflush(stdin);

    if (c->cantidad_productos == MAX_PRODUCTOS) {
        printf("\nNo se pueden agregar mas productos.\n");
        return;
    }

    p.cantidad = cantidad;
    p.precio *= cantidad;

    c->productos[c->cantidad_productos] = p;
    c->cantidad_productos++;

    printf("\nProducto agregado al carrito.\n");
}

void eliminar_producto(struct compra *c) {
    int i, id;

    printf("\n--- Eliminar Producto ---\n");

    printf("\nID del producto: ");
    scanf("%d", &id);
    fflush(stdin);

    for (i = 0; i < c->cantidad_productos; i++) {
        if (c->productos[i].id == id) {
            printf("\nCantidad a eliminar: ");
            int cantidad;
            scanf("%d", &cantidad);
            fflush(stdin);

            if (cantidad >= c->productos[i].cantidad) {
                c->productos[i] = c->productos[c->cantidad_productos - 1];
                c->cantidad_productos--;
            } else {
                c->productos[i].cantidad -= cantidad;
                c->productos[i].precio -= cantidad * (c->productos[i].precio / c->productos[i].cantidad);
            }

            printf("\nProducto eliminado del carrito.\n");
            return;
        }
    }

    printf("\nEl producto no se encuentra en el carrito.\n");
}

void mostrar_carrito(struct compra c) {
    int i;

    printf("\n--- Carrito ---\n");

    printf("\nFecha: %s\n", c.fecha);
    printf("Comprador: %s\n", c.nombre_comprador);

    if (c.cantidad_productos == 0) {
        printf("\nNo hay productos en el carrito.\n");
        return;
    }

    printf("\nID | Nombre | Cantidad | Precio\n");

    for (i = 0; i <c.cantidad_productos; i++) {
    printf("%d | %s | %d | %.2f\n", c.productos[i].id, c.productos[i].nombre, c.productos[i].cantidad, c.productos[i].precio);
}



}

float calcular_total(struct compra c) {
int i;
float total = 0.0;


for (i = 0; i < c.cantidad_productos; i++) {
    total += c.productos[i].precio;
}

return total;
}

int main() {
struct compra c;
int opcion;


c.cantidad_productos = 0;

printf("Fecha: ");
fgets(c.fecha, 20, stdin);
fflush(stdin);

printf("Nombre del comprador: ");
fgets(c.nombre_comprador, 50, stdin);
fflush(stdin);

while (1) {
    printf("\n\n");
    printf("\n--- MINI CAJA REGISTADORA ---\n");
    printf("\n  -------------------------\n");
    printf("Menu Principal: \n");
    printf("\n1. Agregar producto");
    printf("\n2. Eliminar producto");
    printf("\n3. Mostrar carrito");
    printf("\n4. Calcular total");
    printf("\n5. Salir");
    printf("\n\nEscoja laOpcion: ");
    scanf("%d", &opcion);
    fflush(stdin);

    switch (opcion) {
        case 1:
            agregar_producto(&c);
            break;
        case 2:
            eliminar_producto(&c);
            break;
        case 3:
            mostrar_carrito(c);
            break;
        case 4:
            printf("\nTotal: %.2f\n", calcular_total(c));
            break;
        case 5:
            printf("\nGracias por usar la caja registradora. Hasta luego!\n");
            exit(0);
        default:
            printf("\nOpcion no valida.\n");
            break;
    }
}

return 0;
}
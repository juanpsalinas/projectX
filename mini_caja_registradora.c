#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PRODUCTOS 3

typedef struct
{
    int id;
    char nombre[20];
    float precio;
    int cantidad;
   //char nombreComprador[50];
} producto;

typedef struct nodo
{
    producto p;
    struct nodo *sig;
} nodo;

typedef struct
{
    nodo *inicio;
    nodo *fin;
    int tam;
} cola;

void inicializar_cola(cola *c)
{
    c->inicio = NULL;
    c->fin = NULL;
    c->tam = 0;
}

int cola_vacia(cola *c)
{
    return c->tam == 0;
}

void encolar(cola *c, producto p)
{
    nodo *nuevo = (nodo *)malloc(sizeof(nodo));
    nuevo->p = p;
    nuevo->sig = NULL;
    if (cola_vacia(c))
    {
        c->inicio = nuevo;
        c->fin = nuevo;
    }
    else
    {
        c->fin->sig = nuevo;
        c->fin = nuevo;
    }
    c->tam++;
}

void desencolar(cola *c)
{
    if (!cola_vacia(c))
    {
        nodo *aux = c->inicio;
        c->inicio = c->inicio->sig;
        free(aux);
        c->tam--;
    }
}

void listar_cola(cola *c)
{
    if (!cola_vacia(c))
    {
        nodo *aux = c->inicio;
        while (aux != NULL)
        {
            printf("Id: %d\n", aux->p.id);
            printf("Nombre: %s\n", aux->p.nombre);
            printf("Precio: %.2f\n", aux->p.precio);
            printf("Cantidad: %d\n", aux->p.cantidad);
            //printf("Nombre del comprador: %s\n", aux->p.nombreComprador);
            aux = aux->sig;
        }
    }
    else
    {
        printf("La cola esta vacia.\n");
    }
}

void crear_productos(cola *inventario)
{
    producto p;
    printf("Ingrese el id del producto: ");
    scanf("%d", &p.id);
    printf("Ingrese el nombre del producto: ");
    scanf("%s", p.nombre);
    printf("Ingrese el precio del producto: ");
    scanf("%f", &p.precio);
    printf("Ingrese la cantidad del producto: ");
    scanf("%d", &p.cantidad);
    encolar(inventario, p);
    printf("El producto ha sido creado exitosamente.\n");
}

void listar_productos(cola *inventario)
{
    printf("Inventario:\n");
    listar_cola(inventario);
}

void registrar_venta(cola *inventario, cola *ventas)
{
    if (!cola_vacia(inventario)){
        producto p;

        printf("Ingrese el nombre del producto: ");
        scanf("%s", p.nombre);
        nodo *aux = inventario->inicio;
        while (aux != NULL)
        {
            if (strcmp(aux->p.nombre, p.nombre) == 0)
            {
                printf("Ingrese la cantidad del producto: ");
                scanf("%d", &p.cantidad);

                // Obtener el nombre del comprador
                //printf("Ingrese el nombre del comprador: ");
                //scanf("%s", p.nombreComprador);

                if (aux->p.cantidad >= p.cantidad)
                {
                    aux->p.cantidad -= p.cantidad;
                    p.precio = aux->p.precio;
                    p.id= aux->p.id;
                    //p.nombreComprador= aux->p.nombreComprador;
                    encolar(ventas, p);
                    printf("La venta numero 001 ha sido registrada exitosamente.\n");
                }
                else
                {
                    printf("No hay suficientes unidades del producto en el inventario.\n");
                }
                break;
            }
            aux = aux->sig;
        }
        if (aux == NULL)
        {
            printf("No se encontro el producto en el inventario.\n");
        }
    }
    else
    {
        printf("El inventario esta vacio.\n");
    }
}

void listar_ventas(cola *ventas)
{
    printf("Ventas realizadas:\n");
    printf("Id de venta:\n");
                    // Obtener la fecha actual
                time_t t = time(NULL);
                struct tm tm = *localtime(&t);
                char fecha[30];
                sprintf(fecha, "%d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
                printf("Fecha y hora actual:: %s\n", fecha);
            
    listar_cola(ventas);
}

int main()
{
    // Inicializar productos quemados
    producto productos_quemados[MAX_PRODUCTOS] = {
        {1, "Carne", 10.50, 20},
        {2, "Leche", 2.50, 50},
        {3, "Arroz", 1.20, 100}};
    // Inicializar inventario con productos quemados
    cola inventario;
    inicializar_cola(&inventario);
    for (int i = 0; i < MAX_PRODUCTOS; i++)
    {
        encolar(&inventario, productos_quemados[i]);
    }
    // Inicializar cola de ventas
    cola ventas;
    inicializar_cola(&ventas);
    // Mostrar menu principal
    int opcion = 0;
    int subopcion = 0;
    do
    {
        printf("\nMenu principal\n");
        printf("1. Registrar venta\n");
        printf("2. Inventario\n");
        printf("3. Listar ventas\n");
        printf("4. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            registrar_venta(&inventario, &ventas);
            break;
        case 2:
            // Mostrar sub-menu de inventario
            do
            {
                printf("\nSub-menu de inventario\n");
                printf("1. Crear producto\n");
                printf("2. Listar productos\n");
                printf("3. Regresar\n");
                printf("Ingrese una opcion: ");
                scanf("%d", &subopcion);
                switch (subopcion)
                {
                case 1:
                    crear_productos(&inventario);
                    break;
                case 2:
                    listar_productos(&inventario);
                    break;
                case 3:
                    break;
                default:
                    printf("Opcion invalida.\n");
                }
            } while (subopcion != 3);
            break;
        case 3:
            listar_ventas(&ventas);
            break;
        case 4:
            printf("Gracias por utilizar nuestra caja registradora!\n");
            break;
        default:
            printf("Opcion invalida.\n");
        }
    } while (opcion != 4);
    return 0;
}
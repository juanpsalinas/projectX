#ifndef __GLOBAL_H__
#define __GLOBAL_H__

/*-----------------------------------------------------------------------------
|   Includes
+----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*-----------------------------------------------------------------------------
|   Structs
+----------------------------------------------------------------------------*/
typedef struct USUARIOS
{
    int codigoUsu;
    char nombreUs[15];
    char cedulaUs[15];
    struct USUARIOS *sig;
} USUARIOS;

typedef struct PEDIDOS
{
    int codigoPedido;
    USUARIOS *usuarioP;
    char nombreP[15];
    int cantidadproducts;
    char fecha[70];
    float valorC;
    struct PEDIDOS *sig;
} PEDIDOS;

typedef struct PRODUCTOS
{
    int codigo;
    char nombre[15];
    int cantidad;
    float precio;
    struct PRODUCTOS *sig;
} PRODUCTOS;

/*-----------------------------------------------------------------------------
|   Enums
+----------------------------------------------------------------------------*/
typedef enum RET
{
    RET_OK,
    RET_FAIL
} RET;

/*-----------------------------------------------------------------------------
|   GLOBALES
+----------------------------------------------------------------------------*/
#define TAMANO 50
#define CLEAN system("cls");
extern PRODUCTOS *raiz;
extern USUARIOS *raizUsu;
extern USUARIOS *nombreClienActu;
extern PEDIDOS *raizPed;
extern PEDIDOS *vectorPedidos;

#endif // __GLOBAL_H__

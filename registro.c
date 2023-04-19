/*-----------------------------------------------------------------------------
|   Includes
+----------------------------------------------------------------------------*/
#include "global.h"
#include "registro.h"
#include "utils.h"
#include "imprimir.h"

/*-----------------------------------------------------------------------------
|   Funciones
+----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
|   Function Name: insertarusu
|   Description: Inserta un nuevo usuario en la lista enlazada de usuarios
|   Parameters:
|       - nombreusu: nombre del usuario a insertar
|       - cedula: cédula del usuario a insertar
|   Returns: void
+---------------------------------------------------------------------------*/
void insertarusu(char *nombreusu, char *cedula)
{
    static int codigo = 0;
    codigo++;
    int pos = cantidadusu() + 1;
    if (existeUsu(codigo) == RET_FAIL)
    {
        USUARIOS *nuevo;
        nuevo = malloc(sizeof(USUARIOS));
        nuevo->codigoUsu = codigo;
        strcpy(nuevo->nombreUs, nombreusu);
        strcpy(nuevo->cedulaUs, cedula);
        nuevo->sig = NULL;

        if (pos == 1)
        {
            nuevo->sig = (struct USUARIOS *)raizUsu;
            raizUsu = nuevo;
        }
        else
        {
            USUARIOS *reco = raizUsu;
            while (reco->sig != NULL)
            {
                reco = (USUARIOS *)reco->sig;
            }
            reco->sig = nuevo;
            nombreClienActu = reco->sig;
        }
    }
}

/*----------------------------------------------------------------------------
| Function Name: insertarpro
| Description: Inserta un nuevo producto en la lista de productos.
| Parameters:
| - nombrep: nombre del nuevo producto.
| - cantidadp: cantidad del nuevo producto.
| - preciop: precio del nuevo producto.
| Returns: (void).
+---------------------------------------------------------------------------*/
void insertarpro(char *nombrep, int cantidadp, float preciop)
{
    static int x = 0;
    ++x;
    int pos = cantidadpro() + 1;
    PRODUCTOS *nuevo;
    nuevo = malloc(sizeof(PRODUCTOS));
    nuevo->codigo = x;
    strcpy(nuevo->nombre, nombrep);
    nuevo->cantidad = cantidadp;
    nuevo->precio = preciop;
    nuevo->sig = NULL;

    if (pos == 1)
    {
        nuevo->sig = raiz;
        raiz = nuevo;
    }
    else
    {
        PRODUCTOS *reco = raiz;
        while (reco->sig != NULL)
        {
            reco = reco->sig;
        }
        reco->sig = nuevo;
    }
}

/*------------------------------------------------ ----------------------------
| Function Name: insertarPedido
| Description: Inserta un nuevo pedido en la posición especificada de la matriz de pedidos
| Parameters:
| cant (int) - Código de pedido
| pos (int) - Posición en la matriz de órdenes
| nombreProd (char[15]) - Nombre del producto
| cantProd (int) - Cantidad de productos
| valor (float) - Valor total del pedido
| vect (PEDIDOS []) - Matriz de pedidos
| Returns: void
+------------------------------------------------- --------------------------*/
void insertarPedido(int cant, char *nombreProd, int cantProd, float valor)
{
    time_t t = time(NULL);
    struct tm tiempoLocal = *localtime(&t);
    char fechaHora[70];
    char *formato = "%Y-%m-%d %H:%M:%S";
    int bytesEscritos = strftime(fechaHora, sizeof fechaHora, formato, &tiempoLocal);
    char fecha[10];
    memset(fecha, 0x00, sizeof(fecha));
    sprintf(fecha, "%d", bytesEscritos);

    int posi = cantidadPed(vectorPedidos) + 1;
    PEDIDOS *nuevo_Pedido = NULL;
    nuevo_Pedido = malloc(sizeof(PEDIDOS));
    nuevo_Pedido->codigoPedido = cant;
    nuevo_Pedido->usuarioP = nombreClienActu;
    strcpy(nuevo_Pedido->nombreP, nombreProd);
    nuevo_Pedido->cantidadproducts = cantProd;
    strcpy((char *)nuevo_Pedido->fecha, (const char *)fecha);
    nuevo_Pedido->valorC = valor;
    strcpy(nuevo_Pedido->fecha, fechaHora);
    nuevo_Pedido->sig = NULL;

    if (posi == 1)
    {
        nuevo_Pedido->sig = vectorPedidos;
        vectorPedidos = nuevo_Pedido;
    }
    else
    {
        PEDIDOS *reco = vectorPedidos;
        while (reco->sig != NULL)
            reco = reco->sig;
        reco->sig = nuevo_Pedido;
    }
}

/*-------------------------------------------------- ---------------------------
| Function Name: datosUser
| Description Solicita al usuario que ingrese su nombre y número de cédula, y almacena la información en el sistema.
| Parameters: void
| Returns: void
+------------------------------------------------- --------------------------*/
void datosUser(void)
{
    CLEAN

    char nombreUs[15];
    char cedula[15];

    static int contUsers = 0;
    contUsers++;

    fflush(stdin);
    printf("Ingrese su nombre: ");
    gets(nombreUs);

    fflush(stdin);
    printf("Ingrese su cedula: ");
    gets(cedula);

    insertarusu(nombreUs, cedula);
}

/*----------------------------------------------------------------------------
| Function Name: registrarVenta
| Description: Permite registrar la venta de productos
| Parameters: void
| Returns: void
+---------------------------------------------------------------------------*/
void registrarVenta(void)
{
    int codigoVenta;
    int cantidadp;
    char opcion;

    datosUser();
    imprimirpro();
    char nombre[15];
    char auxNombre[15];
    static int i = 1;

    do
    {
        fflush(stdin);
        printf("-->Ingrese el codigo del producto: ");
        scanf("%d", &codigoVenta);
        if (existe(codigoVenta) == RET_FAIL)
        {
            printf("No existe el producto\n");
            continue;
        }
        fflush(stdin);
        printf("-->Ingrese el cantidad del producto: ");
        scanf("%d", &cantidadp);
        if(validarCantidad(cantidadp,codigoVenta) == RET_FAIL){
            printf("No hay suficiente cantidad en el Stock\n");
            continue;
        }

        float valor = (float)cantidadp * precioProduct(codigoVenta);
        memset(nombre, 0x00, sizeof(nombre));
        codNombreProduct(codigoVenta, auxNombre);
        strcpy(nombre, auxNombre);

        printf(" Cod: %d, Cant :%d  ", codigoVenta, cantidadp);
        if (descontarProducto(codigoVenta, cantidadp) == RET_OK)
        {
            insertarPedido(i, nombre, cantidadp, valor);
        }

        fflush(stdin);
        printf("  Desea adquirir otro producto ? 's/n' \n");
        scanf("%c", &opcion);
    } while (opcion != 'n');
    if (opcion == 'n')
        imprimirPediEspes(vectorPedidos, i);
    i++;
}

/*----------------------------------------------------------------------------
| Function Name: NuevoProducto
| Description: Permite ingresar los datos de un nuevo producto y lo agrega a la lista de productos.
| Parameters: void
| Returns: void
+---------------------------------------------------------------------------*/
void NuevoProducto(void)
{
    char nombrep[15];
    int cantidadp;
    float preciop;
    char opcion;

    do
    {
        printf("-->Ingrese el nombre del producto: ");
        fflush(stdin);
        gets(nombrep);
        printf("-->Ingrese el cantidad del producto: ");
        fflush(stdin);
        scanf("%d", &cantidadp);
        printf("-->Ingrese el precio del producto: ");
        fflush(stdin);
        scanf("%f", &preciop);
        CLEAN

        insertarpro(nombrep, cantidadp, preciop);

        fflush(stdin);
        printf("- Desea continuar ? 's/n' \n");
        scanf("%c", &opcion);
        CLEAN

    } while (opcion != 'n');
}

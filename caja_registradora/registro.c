/*-----------------------------------------------------------------------------
|   Includes
+----------------------------------------------------------------------------*/
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
void insertarusu(char nombreusu[15], char cedula[15])
{
    static int codigo = 0;
    codigo++;
    int pos = cantidadusu() + 1;
    if (!existeUsu(codigo))
    {
        if (pos <= cantidadusu() + 1)
        {
            USUARIOS *nuevo;
            nuevo = malloc(sizeof(USUARIOS));
            nuevo->codigoUsu = codigo;
            strcpy(nuevo->nombreUs, nombreusu);
            strcpy(nuevo->cedulaUs, cedula);
            nuevo->ant = NULL;
            nuevo->sig = NULL;

            if (pos == 1)
            {
                nuevo->sig = (struct USUARIOS *)raizUsu;
                if (raizUsu != NULL)
                    raizUsu->ant = (struct USUARIOS *)nuevo;
                raizUsu = nuevo;
            }
            else
            {
                if (pos == cantidadusu() + 1)
                {
                    USUARIOS *reco = raizUsu;
                    while (reco->sig != NULL)
                    {
                        reco = (USUARIOS *)reco->sig;
                    }
                    reco->sig = (struct USUARIOS *)nuevo;
                    nombreClienActu = (USUARIOS *)reco->sig;
                    nuevo->ant = (struct USUARIOS *)reco;
                }
                else
                {
                    USUARIOS *reco = raizUsu;
                    int f;
                    for (f = 1; f <= pos - 2; f++)
                        reco = (USUARIOS *)reco->sig;
                    USUARIOS *siguiente = (USUARIOS *)reco->sig;
                    reco->sig = (struct USUARIOS *)nuevo;
                    nuevo->ant = (struct USUARIOS *)reco;
                    nuevo->sig = (struct USUARIOS *)siguiente;
                    siguiente->ant = (struct USUARIOS *)nuevo;
                }
            }
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
void insertarpro(char nombrep[15], int cantidadp, float preciop)
{
    static int x = 0;
    x++;
    int pos = cantidadpro() + 1;
    if (!existe(x) == RET_OK)
    {
        if (pos <= cantidadpro() + 1)
        {
            PRODUCTOS *nuevo;
            nuevo = malloc(sizeof(PRODUCTOS));
            nuevo->codigo = x;
            strcpy(nuevo->nombre, nombrep);
            nuevo->cantidad = cantidadp;
            nuevo->precio = preciop;
            nuevo->ant = NULL;
            nuevo->sig = NULL;

            if (pos == 1)
            {
                nuevo->sig = (struct PRODUCTOS *)raiz;
                if (raiz != NULL)
                    raiz->ant = (struct PRODUCTOS *)nuevo;
                raiz = nuevo;
            }
            else
            {
                if (pos == cantidadpro() + 1)
                {
                    PRODUCTOS *reco = raiz;
                    while (reco->sig != NULL)
                    {
                        reco = (PRODUCTOS *)reco->sig;
                    }
                    reco->sig = (struct PRODUCTOS *)nuevo;
                    nuevo->ant = (struct PRODUCTOS *)reco;
                }
                else
                {
                    PRODUCTOS *reco = raiz;
                    int f;
                    for (f = 1; f <= pos - 2; f++)
                        reco = (PRODUCTOS *)reco->sig;
                    PRODUCTOS *siguiente = (PRODUCTOS *)reco->sig;
                    reco->sig = (struct PRODUCTOS *)nuevo;
                    nuevo->ant = (struct PRODUCTOS *)reco;
                    nuevo->sig = (struct PRODUCTOS *)siguiente;
                    siguiente->ant = (struct PRODUCTOS *)nuevo;
                }
            }
        }
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
void insertarPedido(int cant, int pos, char nombreProd[15], int cantProd, float valor, PEDIDOS *vect)
{

    time_t t = time(NULL);
    struct tm tiempoLocal = *localtime(&t);
    char fechaHora[70];
    char *formato = "%Y-%m-%d %H:%M:%S";
    int bytesEscritos = strftime(fechaHora, sizeof fechaHora, formato, &tiempoLocal);
    char fecha[10];
    memset(fecha, 0x00, sizeof(fecha));
    sprintf(fecha, "%d", bytesEscritos);

    int posi = cantidadPed(vect) + 1;
    if (!existePedido(cant, vect))
    {
        if (posi <= cantidadPed(vect) + 1)
        {
            PEDIDOS *nuevo;
            nuevo = malloc(sizeof(PEDIDOS));
            nuevo->codigoPedido = cant;
            nuevo->usuarioP = nombreClienActu;
            strcpy(nuevo->nombreP, nombreProd);
            nuevo->cantidadproducts = cantProd;
            strcpy((char *)nuevo->fecha, (const char *)fecha);
            nuevo->valorC = valor;
            strcpy(nuevo->fecha, fechaHora);
            nuevo->ant = NULL;
            nuevo->sig = NULL;

            if (posi == 1)
            {
                nuevo->sig = (struct PEDIDOS *)vect;
                if (vect != NULL)
                    vect->ant = (struct PEDIDOS *)nuevo;
                vect = nuevo;
            }
            else
            {
                if (posi == cantidadPed(vect) + 1)
                {
                    PEDIDOS *reco = vect;
                    while (reco->sig != NULL)
                        reco = (PEDIDOS *)reco->sig;
                    reco->sig = (struct PEDIDOS *)nuevo;
                    nuevo->ant = (struct PEDIDOS *)reco;
                }
                else
                {
                    PEDIDOS *reco = (PEDIDOS *)vect;
                    int f;
                    for (f = 1; f <= posi - 2; f++)
                        reco = (PEDIDOS *)reco->sig;
                    PEDIDOS *siguiente = (PEDIDOS *)reco->sig;
                    reco->sig = (struct PEDIDOS *)nuevo;
                    nuevo->ant = (struct PEDIDOS *)reco;
                    nuevo->sig = (struct PEDIDOS *)siguiente;
                    siguiente->ant = (struct PEDIDOS *)nuevo;
                }
            }
        }
    }
    printf("vect = %s", vect->nombreP);
}

/*-------------------------------------------------- ---------------------------
| Function Name: datosUser
| Description Solicita al usuario que ingrese su nombre y número de ID, y almacena la información en el sistema.
| Parameters: void
| Returns: void
+------------------------------------------------- --------------------------*/
void datosUser()
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
    scanf("%s", &cedula);

    insertarusu(nombreUs, cedula);
    cantUs++;
}

/*----------------------------------------------------------------------------
| Function Name: registrarVenta
| Description: Permite registrar la venta de productos
| Parameters: void
| Returns: void
+---------------------------------------------------------------------------*/
void registrarVenta()
{
    int codigo;
    int cantidadp;
    char opcion;
    fflush(stdin);
    printf("-----  DESEA COMPRAR ? ('s/n') -----  \n\n");
    scanf("%c", &opcion);

    if (opcion != 'n')
    {
        datosUser();
        printf("\t___   LISTA DE PRODUCTOS   ___");
        imprimirpro();
    }

    static int i = 1;

    do
    {
        printf("-->Ingrese el codigo del producto: ");
        scanf("%i", &codigo);
        fflush(stdin);
        printf("-->Ingrese el cantidad del producto: ");
        scanf("%i", &cantidadp);

        float valor = (float)cantidadp * precioProduct(codigo);
        char nombre[15];
        strcpy(nombre, codNombreProduct(codigo));

        printf(" Cod: %i, Cant :%i  ", codigo, cantidadp);
        if (descontarProducto(codigo, cantidadp))
            insertarPedido(i, cantUs, nombre, cantidadp, valor, vectorPedidos);

        fflush(stdin);
        printf("  Desea adquirir otro producto ? 's/n' \n");
        scanf("%c", &opcion);
    } while (opcion != 'n');
    i++;
    printf("vectorPedidos[%d] = %s", i, vectorPedidos->nombreP);
    if (opcion == 'n')
        imprimirPediEspes(vectorPedidos);
}

/*----------------------------------------------------------------------------
| Function Name: NuevoProducto
| Description: Permite ingresar los datos de un nuevo producto y lo agrega a la lista de productos.
| Parameters: void
| Returns: void
+---------------------------------------------------------------------------*/
void NuevoProducto()
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
        scanf("%i", &cantidadp);
        printf("-->Ingrese el precio del producto: ");
        fflush(stdin);
        scanf("%f", &preciop);
        CLEAN

        insertarpro(nombrep, cantidadp, preciop);

        fflush(stdin);
        printf("¿ Desea continuar ? 's/n' \n");
        scanf("%c", &opcion);
        CLEAN

    } while (opcion != 'n');
}

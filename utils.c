/*-----------------------------------------------------------------------------
|   Includes
+----------------------------------------------------------------------------*/
#include "utils.h"

/*-----------------------------------------------------------------------------
|   Funciones
+----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
| Function Name: existe
| Description: Verifica si un elemento con el código dado existe en la lista.
| Parameters: x: código del elemento a buscar
| Returns:
| RET_OK si el elemento existe en la lista.
| RET_FAIL si el elemento no existe en la lista.
+---------------------------------------------------------------------------*/
RET existe(int x)
{
    PRODUCTOS *reco = raiz;
    while (reco != NULL)
    {
        if (reco->codigo == x)
            return RET_OK;
        reco = reco->sig;
    }
    return RET_FAIL;
}

/*----------------------------------------------------------------------------
| Function Name: existePedido
| Description: Verifica si un pedido existe en la lista de pedidos
| Parameters: int x (codigo del pedido a buscar), PEDIDOS raizPedEx (puntero a la raíz de la lista de pedidos)
| Returns: RET_OK si el pedido existe, RET_FAIL si no existe
+---------------------------------------------------------------------------*/
RET existePedido(int x, PEDIDOS *raizPedEx)
{
    PEDIDOS *recoped = raizPedEx;
    while (recoped != NULL)
    {
        if (recoped->codigoPedido == x)
            return RET_OK;
        recoped = recoped->sig;
    }
    return RET_FAIL;
}

/*----------------------------------------------------------------------------
| Function Name: cantidadpro
| Description: Devuelve la cantidad de elementos en la lista  PRODUCTOS.
| Parameters:void
| Returns: La cantidad de elementos en la lista.
+---------------------------------------------------------------------------*/
int cantidadpro(void)
{
    PRODUCTOS *reco = raiz;
    int cant = 0;
    while (reco != NULL)
    {
        cant++;
        reco = reco->sig;
    }
    return cant;
}

/*-------------------------------------------------- ---------------------------
| Function Name: codNombreProducto
| Description: dado un código, busca el nombre del producto correspondiente en la lista vinculada
| Parameters: int cod - el código de producto a buscar
| Returns: const char - el nombre del producto correspondiente, o NULL si no se encuentra
+------------------------------------------------- --------------------------*/
void codNombreProduct(int cod, char *nombre)
{
    PRODUCTOS *reco = raiz;
    while (reco != NULL)
    {
        if (reco->codigo == cod)
            strcpy(nombre, reco->nombre);
        reco = reco->sig;
    }
}

/*----------------------------------------------------------------------------
| Function Name: precioProduct
| Description: Retorna el precio de un producto dado su código
| Parameters:
| int cod: código del producto
| Returns:
| int: precio del producto
+---------------------------------------------------------------------------*/
float precioProduct(int cod)
{
    PRODUCTOS *reco = raiz;
    while (reco != NULL)
    {
        if (reco->codigo == cod)
            return reco->precio;
        else
            reco = reco->sig;
    }
    return 0;
}

/*----------------------------------------------------------------------------
| Function Name: existeUsu
| Description: Verifica si un usuario con el código dado existe en la lista de usuarios.
| Parameters:
|  x: código del usuario a buscar
| Returns:
|  RET_OK (valor definido en otra parte del código) si el usuario existe en la lista.
|  RET_FAIL (valor definido en otra parte del código) si el usuario no existe en la lista.
+---------------------------------------------------------------------------*/
RET existeUsu(int x)
{
    USUARIOS *recousu = raizUsu;
    while (recousu != NULL)
    {
        if (recousu->codigoUsu == x)
            return RET_OK;
        recousu = (USUARIOS *)recousu->sig;
    }
    return RET_FAIL;
}

/*----------------------------------------------------------------------------
| Function Name: vaciausu
| Description: Verifica si la lista de usuarios está vacía
| Parameters: None
| Returns: RET_OK si la lista está vacía, RET_FAIL en caso contrario
+---------------------------------------------------------------------------*/
RET vaciausu(void)
{
    return (raizUsu == NULL) ? RET_OK : RET_FAIL;
}

/*----------------------------------------------------------------------------
| Function Name: cantidadusu
| Description: Cuenta la cantidad de usuarios registrados en la lista de usuarios
| Parameters: void
| Returns: int - la cantidad de usuarios registrados
+---------------------------------------------------------------------------*/
int cantidadusu(void)
{
    int cant = 0;
    USUARIOS *recousu = raizUsu;
    while (recousu != NULL)
    {
        cant++;
        recousu = recousu->sig;
    }
    return cant;
}

/*----------------------------------------------------------------------------
| Function Name: vaciaped
| Description: Verifica si la lista de pedidos está vacía
| Parameters: PEDIDOS raizPedEx (puntero a la raíz de la lista de pedidos)
| Returns: RET_OK si la lista está vacía, RET_FAIL si no lo está
+---------------------------------------------------------------------------*/
RET vaciaped(PEDIDOS *raizPedEx)
{
    return (raizPedEx == NULL) ? RET_OK : RET_FAIL;
}

/*----------------------------------------------------------------------------
| Function Name: cantidadPed
| Description: Retorna la cantidad de pedidos
| Parameters: PEDIDOS raizPedCa (puntero a la raíz de la lista de pedidos)
| Returns: La cantidad de nodos en la lista de pedidos
+---------------------------------------------------------------------------*/
int cantidadPed(PEDIDOS *raizPedCa)
{
    int cantd = 0;
    PEDIDOS *recoped = raizPedCa;
    while (recoped != NULL)
    {
        recoped = recoped->sig;
        cantd++;
    }
    return cantd;
}

/*----------------------------------------------------------------------------
| Function Name: validarCantidad
| Description:Valida si la cantidad de un producto con el código dado está disponible en el inventario.
| Parameters: cant - la cantidad a validar; codi 
- el código de producto a buscar.
| Returns: RET_OK si la cantidad esta disponible, RET_FAIL de lo contrario
+---------------------------------------------------------------------------*/
RET validarCantidad(int cant, int codi)
{
    PRODUCTOS *reco = raiz;
    while (reco != NULL)
    {
        if (reco->codigo == codi)
        {
            if (reco->cantidad <= cant)
            {
                return RET_FAIL;
            }
        }
        reco = reco->sig;
    }
    return RET_OK;
}

/*----------------------------------------------------------------------------
| Function Name: descontarProducto
| Description: Descuenta una cantidad de productos del stock.
| Parameters:
| - codi: Código del producto a descontar.
| - cant: Cantidad de productos a descontar.
| Returns:
| - RET_OK si se pudo descontar la cantidad de productos especificada.
| - RET_FAIL si no se encontró el producto o la cantidad a descontar excede el stock.
+---------------------------------------------------------------------------*/
RET descontarProducto(int codi, int cant)
{
    PRODUCTOS *reco = raiz;
    while (reco != NULL)
    {
        if (reco->codigo == codi)
        {
            reco->cantidad -= cant;
            printf("->Se ha descontado\n");
            return RET_OK;
        }
        reco = reco->sig;
    }
    return RET_FAIL;
}

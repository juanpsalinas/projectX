#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * 
 *      LAS GLOVALES
 * 
 */

#define TAMANO 50
int cantUs = -1;


/**

 *      FUNCIONES DE PRODUCTOS

*/

typedef struct{             // PRODUCTOS
    int codigo;
    char nombre[15];
    int cantidad;
    float precio;
    struct nodo *sig;
    struct nodo *ant;
} nodo;

nodo *raiz = NULL;

int existe(int x)
{
     nodo *reco = raiz;
    while (reco != NULL)
    {
        if (reco->codigo == x)
            return 1;
        reco = reco->sig;
    }
    return 0;
}

int cantidadpro()
{
    nodo *reco = raiz;
    int cant = 0;
    while (reco != NULL)
    {
        cant++;
        reco = reco->sig;
    }
    return cant;
}

void insertarpro( char nombrep[15], int cantidadp, float preciop ) 
{
    static int x = 0;
    x++;
    int pos = cantidadpro()+1;
    if(!existe(x)){
        if (pos <= cantidadpro() + 1)
        {
            nodo *nuevo;
            nuevo=malloc(sizeof(nodo));
            nuevo->codigo = x;
            strcpy(nuevo->nombre, nombrep);
            nuevo->cantidad = cantidadp;
            nuevo->precio = preciop;
            nuevo->ant=NULL;
            nuevo->sig=NULL;

            if (pos == 1)
            {
                nuevo->sig = raiz;
                if (raiz != NULL)
                    raiz->ant = nuevo;
                raiz = nuevo;
            }
            else
            {
                if (pos == cantidadpro() + 1)
                {
                    nodo *reco = raiz;
                    while (reco->sig != NULL)
                    {
                        reco = reco->sig;
                    }
                    reco->sig = nuevo;
                    nuevo->ant = reco;
                }
                else
                {
                    nodo *reco = raiz;
                    int f;
                    for (f = 1; f <= pos - 2; f++)
                        reco = reco->sig;
                    nodo *siguiente = reco->sig;
                    reco->sig = nuevo;
                    nuevo->ant = reco;

                    nuevo->sig = siguiente;
                    siguiente->ant = nuevo;
                }
            }
        }
    }
}

void imprimirpro()
{
    nodo *reco=raiz;
    while (reco!=NULL)
    {
        printf("\n<<<<<<<<<<  %s  >>>>>>>>>>>\n",reco->nombre);
        printf(" cod: %i | cant: %i | precio : %0.0f \n", reco->codigo , reco->cantidad , reco->precio);
        reco=reco->sig;
    }
    printf("\n");
}

int descontarProducto(int codip, int cant)
{
    nodo *reco = raiz;
    while (reco != NULL)
    {
        if (reco->codigo == codip)
        {
            if(reco->cantidad >= cant) {
                reco->cantidad -= cant;
                printf("se desconto\n");
                return 1;
            }else
                printf(">>>>>La cantidad excede el stock.<<<<<\n");
                return 0;
        }
        reco = reco->sig;
    }
    return 0;
}

const char* codNombreProduct(int cod)
{
    nodo *reco = raiz;
    while (reco != NULL)
    {
        if (reco->codigo == cod)
            return reco->nombre;
        else
            reco = reco->sig;
    }
    return 0;
}

int precioProduct(int cod)
{
     nodo *reco = raiz;
    while (reco != NULL)
    {
        if (reco->codigo == cod)
            return reco->precio;
        else
            reco = reco->sig;
    }
    return 0;
}


/**
 *
 *      FUNCIONES DE USUARIO
 *
 */

typedef struct{             // USUARIOS
    int codigoUsu;            
    char nombreUs[15];
    char cedulaUs[15];
    struct usuarios *sig;
    struct usuarios *ant;
}usuarios;

usuarios *raizUsu = NULL;
usuarios *nombreClienActu = NULL;


int existeUsu(int x){
    usuarios *recousu = raizUsu;
    while (recousu != NULL)
    {
        if (recousu->codigoUsu == x)
            return 1;
        recousu = recousu->sig;
    }
    return 0;
}

int vaciausu(){
    if (raizUsu == NULL)
        return 1;
    else
        return 0;
}

int cantidadusu()
{
    usuarios *recousu = raizUsu;
    int cant = 0;
    while (recousu != NULL)
    {
        cant++;
        recousu = recousu->sig;
    }
    return cant;
}

void insertarusu( char nombreusu[15], char cedula[15] )
{
    static int codigo = 0;
    codigo++;
    int pos = cantidadusu()+1;
    if(!existeUsu(codigo)){
        if (pos <= cantidadusu() + 1)
        {
            usuarios *nuevo;
            nuevo=malloc(sizeof(usuarios));
            nuevo->codigoUsu = codigo;
            strcpy(nuevo->nombreUs, nombreusu);
            strcpy(nuevo->cedulaUs, cedula);
            nuevo->ant=NULL;
            nuevo->sig=NULL;

            

            if (pos == 1)
            {
                nuevo->sig = raizUsu;
                if (raizUsu != NULL)
                    raizUsu->ant = nuevo;
                raizUsu = nuevo;
            }
            else
            {
                if (pos == cantidadusu() + 1)
                {
                    usuarios *reco = raizUsu;
                    while (reco->sig != NULL)
                    {
                        reco = reco->sig;
                    }
                    reco->sig = nuevo;
                    nombreClienActu = reco->sig;
                    nuevo->ant = reco;
                }
                else
                {
                    usuarios *reco = raizUsu;
                    int f;
                    for (f = 1; f <= pos - 2; f++)
                        reco = reco->sig;
                    usuarios *siguiente = reco->sig;
                    reco->sig = nuevo;
                    nuevo->ant = reco;
                    nuevo->sig = siguiente;
                    siguiente->ant = nuevo;
                }
            }
        }
    }
}

void imprimirUsu()
{
    usuarios *recous=raizUsu;
    while (recous!=NULL)
    {
        printf("\n\n************************************\n");
        printf("<<<<<<<<<<  %s  >>>>>>>>>>>\n",recous->nombreUs);
        printf("\t cedula : %s \n",recous->cedulaUs);
        printf("\t cod : %i \n\n",recous->codigoUsu);
        recous=recous->sig;
    }
    printf("\n");
}

void imprimirUsuespe(usuarios *usuarioProd)
{
        printf("*************************************\n");
        printf(" nombre \tcedula\t codigo\n");
        printf(" %s  \t%s  \t%i\n",usuarioProd->nombreUs ,usuarioProd->cedulaUs ,usuarioProd->codigoUsu);
}


/**
 *             
 *      FUNCIONES DE PEDIDO
 *
 */

typedef struct{             // STRUCT PEDIDOS
    int codigoPedido; 
    usuarios *usuarioP;
    char nombreP[15];
    int cantidadproducts;
    char fecha[70];
    float valorC;
    struct pedidos *sig;
    struct pedidos *ant;
}pedidos;

pedidos *raizPed = NULL;
pedidos *vectorPedidos[TAMANO]; 


int existePedido(int x, pedidos *raizPedEx)
{
    pedidos *recoped = raizPedEx;
    while (recoped != NULL)
    {
        if (recoped->codigoPedido == x)
            return 1;
        recoped = recoped->sig;
    }
    return 0;
}

int vaciaped(pedidos *raizPedEx)
{
    if (raizPedEx == NULL)
        return 1;
    else
        return 0;
}

int cantidadPed(pedidos *raizPedCa)
{
    int cantd = 0;
    pedidos *recoped = raizPedCa;
    while (recoped != NULL)
    {
        recoped = recoped->sig;
        cantd++;
    }
    return cantd;
}

void insertarPedido( int pos , char nombreProd[15] , int cantProd, float valor, pedidos *vect[TAMANO])
{

    time_t t = time(NULL);
    struct tm tiempoLocal = *localtime(&t);
    char fechaHora[70];
    char *formato = "%Y-%m-%d %H:%M:%S";
    int bytesEscritos = strftime(fechaHora, sizeof fechaHora, formato, &tiempoLocal);

    static int codigo = 0;
    codigo++;
    int posi = cantidadPed(vect[pos])+1;
    if(!existePedido(codigo, vect[pos])){
        if (posi <= cantidadPed(vect[pos])+1 ){
            pedidos *nuevo;
            nuevo=malloc(sizeof(pedidos));
            nuevo->codigoPedido = codigo;
            nuevo->usuarioP = nombreClienActu;
            strcpy(nuevo->nombreP , nombreProd);
            nuevo->cantidadproducts = cantProd;
            nuevo->valorC = valor;
            strcpy(nuevo->fecha, fechaHora);
            nuevo->ant=NULL;
            nuevo->sig=NULL;

            if (posi == 1)
            {
                nuevo->sig = vect[pos];
                if (vect[pos] != NULL) vect[pos]->ant = nuevo;
                vect[pos] = nuevo;
            }
            else
            {
                if (posi == cantidadPed(vect[pos]) + 1)
                {
                    pedidos *reco = vect[pos];
                    while (reco->sig != NULL)reco = reco->sig;
                    reco->sig = nuevo;
                    nuevo->ant = reco;
                }
                else
                {
                    pedidos *reco = vect[pos];
                    int f;
                    for (f = 1; f <= posi - 2; f++)reco = reco->sig;

                    pedidos *siguiente = reco->sig;
                    reco->sig = nuevo;
                    nuevo->ant = reco;
                    nuevo->sig = siguiente;
                    siguiente->ant = nuevo;
                }
            }
        }
    }
}

void imprimirPedi(pedidos *vectP[TAMANO])
{
    system("cls");
    int i = 0;
    pedidos *reco = vectP[i];
    pedidos *reco2 = vectP[i];
    while(vectP[i] != NULL)
    {
        reco = vectP[i];
        printf("\n*************************************\n");
        printf("<<<<<<<<<<  pedido N:%i  >>>>>>>>>>>\n", vectP[i]->codigoPedido);
        printf("fecha: %s\n", vectP[i]->fecha );
        imprimirUsuespe(reco->usuarioP);
        
        while (reco!=NULL){
            printf("->%s\t\t..........%0.2f\n", reco->nombreP, reco->valorC);
            reco=reco->sig;
        }

        float total= 0;

        while (reco2!=NULL){
            total += reco2->valorC;
            reco2=reco2->sig;
        }
        printf("\tTOTAL %f\n", total);
        i++;
    }
}

void imprimirPediEspes(pedidos *vectEsps)
{
    int i = 0;
    pedidos *reco = vectEsps;
    pedidos *reco2 = vectEsps;

    printf("\n*************************************\n");
    printf("<<<<<<<<<<  pedido N:%i  >>>>>>>>>>>\n", reco->codigoPedido);
    imprimirUsuespe(reco->usuarioP);
    
    while (reco!=NULL){
        printf("->\t%s\t.....%0.2f\n", reco->nombreP, reco->valorC);
        reco=reco->sig;
    }

    float total= 0;

    while (reco2!=NULL){
        total += reco2->valorC;
        reco2=reco2->sig;
    }
    printf("\tTOTAL %0.2f\n\n\n", total);
    i++;
}



/**
 *
 *      FUNCIONES DE MAIN
 *
 */

const char* fecha(){
    time_t t = time(NULL);
    struct tm tiempoLocal = *localtime(&t);
    char fechaHora[70];
    char *formato = "%Y-%m-%d %H:%M:%S";
    int bytesEscritos = strftime(fechaHora, sizeof fechaHora, formato, &tiempoLocal);
    if (bytesEscritos != 0) {
        printf("Fecha y hora: %s", fechaHora);
    } else {
        printf("Error formateando fecha");
    } 
    char fecha[70];
    strcpy(fecha, fechaHora);
    return fecha;
}

void datosUser(){
    system("cls");

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

static void registrarVenta()
{
    int codigo;
    int cantidadp;

    char opcion ;
    fflush(stdin);
    printf("----- DESEA COMPRAR? ('s/n') -----  \n\n");
    scanf("%c",&opcion);

    if(opcion!= 'n'){
        datosUser(); 
        printf("___   LISTA DE PRODUCTOS   ___");
        imprimirpro();
    } 
    
    while(opcion!= 'n')
    {
        printf("-->Ingrese el codigo del producto: ");
        scanf("%i", &codigo);
        fflush(stdin);
        printf("-->Ingrese el cantidad del producto: "); 
        scanf("%i", &cantidadp);

        float valor = (float) cantidadp * precioProduct(codigo);
        char nombre[15]; 
        strcpy(nombre, codNombreProduct(codigo));

        printf(" cod: %i, cant :%i",codigo, cantidadp );
        if (descontarProducto(codigo, cantidadp)) insertarPedido(cantUs, nombre , cantidadp, valor , &vectorPedidos); 
        
        fflush(stdin);
        printf(" Decea adquirir otro producto? 's/n' \n");
        scanf("%c",&opcion);
    }
    if(opcion == 'n')  imprimirPediEspes(vectorPedidos[cantUs]);
}

static void NuevoProducto()
{
    char nombrep[15];
    int cantidadp;
    float preciop;

    char opcion;
    do {
        printf("-->Ingrese el nombre del producto: ");
        fflush(stdin);
        gets(nombrep);
        printf("-->Ingrese el cantidad del producto: ");
        fflush(stdin);
        scanf("%i", &cantidadp);
        printf("-->Ingrese el precio del producto: ");
        fflush(stdin);
        scanf("%f", &preciop);
        system("cls");

        insertarpro( nombrep, cantidadp, preciop );

        fflush(stdin);
        printf("decea continuar? 's/n' \n");
        scanf("%c",&opcion);
        system("cls");

    } while(opcion!= 'n');
}

static void inventario()
{
    int opcion;
    do {
        printf("\n 1-Agregar producto.\n");
        printf(" 2-Listado de productos.\n");
        printf(" 3-Salir.\n\n");
        printf("Elija su opcion:");
        scanf("%i",&opcion);
        system("cls");
        switch (opcion) {
            case 1:NuevoProducto();
                break;
            case 2:imprimirpro();
                break; 
            default:
                printf("\n");
        }
    } while(opcion!=3);
}

static void menuPrincipal()
{
    int opcion;
    do {
        printf("1-Registrar venta.\n");
        printf("2-Inventario.\n");
        printf("3-Lista de ventas.\n");
        printf("4-Salir.\n\n");
        printf("Elija su opcion:");
        scanf("%i",&opcion);
        system("cls");
        switch (opcion) {
            case 1:registrarVenta();
                break;
            case 2:inventario();
                break;
            case 3:imprimirPedi(&vectorPedidos);
                break;
            case 5:imprimirUsu();
                break;
            default:
                printf("'nla opcion no es valida\n");
        }
    } while(opcion!=4);
}

int main()
{
    for (int i = 0 ; i< TAMANO ; i++) vectorPedidos[i]= raizPed;

    insertarpro( "MANZANA", 15, 1500.0 );
    insertarpro( "PERA", 15, 1350.0 );
    insertarpro( "ZANAHORIA", 15, 2000.0 );


    insertarusu("YHON J", "13746153");
    insertarusu("YHON OCHOA", "2576873");
    insertarusu("MARIA J", "3278445");
    insertarusu("YJ OCHOA", "3749848");

    menuPrincipal();

    return 0;
}
/*-----------------------------------------------------------------------------
|   Includes
+----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*****************
*    Structs
******************/

typedef struct{             // USUARIOS
    int codigoUsu;            
    char nombreUs[15];
    char cedulaUs[15];
    struct usuarios *sig;
    struct usuarios *ant;
}usuarios;

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


typedef struct nodo{             // PRODUCTOS
    int codigo;
    char nombre[15];
    int cantidad;
    float precio;
    struct nodo *sig;
    struct nodo *ant;
} nodo;



/* 
    Prototipos
 */
void imprimirpro();
int existe(int x);
int cantidadpro();
void insertarpro( char nombrep[15], int cantidadp, float preciop);
void imprimirpro();
int descontarProducto(int codi, int cant);
const char* codNombreProduct(int cod);
int precioProduct(int cod);
int existeUsu(int x);
int vaciausu();
int cantidadusu();
void insertarusu( char nombreusu[15], char cedula[15] );
void imprimirUsu();
void imprimirUsuespe(usuarios *usuarioProd);
int existePedido(int x, pedidos *raizPedEx);


/*-----------------------------------------------------------------------------
|   GLOBALES
+----------------------------------------------------------------------------*/
#define TAMANO 50
int cantUs = -1;
nodo *raiz = NULL;
usuarios *raizUsu = NULL;
usuarios *nombreClienActu = NULL;
pedidos *raizPed = NULL;
pedidos *vectorPedidos[TAMANO]; 



int existe(int x){
    nodo *reco = raiz;
    while (reco != NULL)
    {
        if (reco->codigo == x)
            return 1;
        reco = reco->sig;
    }
    return 0;
}

int cantidadpro(){
    nodo *reco = raiz;
    int cant = 0;
    while (reco != NULL)
    {
        cant++;
        reco = reco->sig;
    }
    return cant;
}

void insertarpro( char nombrep[15], int cantidadp, float preciop){
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
            else{
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

void imprimirpro(){
    nodo *reco=raiz;
    while (reco!=NULL)
    {
        printf("\n<<<<<<<<<<  %s  >>>>>>>>>>>\n",reco->nombre);
        printf(" Codigo | Cantidad | Precio \n");
        printf("   %i\t     %i\t     %0.0f \n", reco->codigo , reco->cantidad , reco->precio);
        reco=reco->sig;
    }
    printf("\n");
}

int descontarProducto(int codi, int cant){
    nodo *reco = raiz;
    while (reco != NULL)
    {
        if (reco->codigo == codi)
        {
            if(reco->cantidad >= cant) {
                reco->cantidad -= cant;
                printf("->Se ha descontado\n");
                return 1;
            }else
                printf(">>>>>La cantidad excede el stock.<<<<<\n");
                return 0;
        }
        reco = reco->sig;
    }
    return 0;
}

const char* codNombreProduct(int cod){
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

int precioProduct(int cod){
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

int cantidadusu(){
    usuarios *recousu = raizUsu;
    int cant = 0;
    while (recousu != NULL)
    {
        cant++;
        recousu = recousu->sig;
    }
    return cant;
}

void insertarusu( char nombreusu[15], char cedula[15] ){
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

void imprimirUsu(){
    usuarios *recous=raizUsu;
    while (recous!=NULL)
    {
        printf("\n\n************************************\n");
        printf("<<<<<<<<<<  %s  >>>>>>>>>>>\n",recous->nombreUs);
        printf("\t<> Cedula : %s \n",recous->cedulaUs);
        printf("\t<> Codigo : %i \n\n",recous->codigoUsu);
        recous=recous->sig;
    }
    printf("\n");
}

void imprimirUsuespe(usuarios *usuarioProd){
        printf(" _____________________________________\n");
        printf("|  Nombre  |  |  Cedula  |   | Codigo|\n");
        printf("|  %s    \t%s  \t  %i _|\n",usuarioProd->nombreUs ,usuarioProd->cedulaUs ,usuarioProd->codigoUsu);
        printf("\n");
}
/**
 *             
 *      FUNCIONES DE PEDIDO
 *
 */




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

void insertarPedido(int cant, int pos , char nombreProd[15] , int cantProd, float valor, pedidos *vect[TAMANO]){

    time_t t = time(NULL);
    struct tm tiempoLocal = *localtime(&t);
    char fechaHora[70];
    char *formato = "%Y-%m-%d %H:%M:%S";
    int bytesEscritos = strftime(fechaHora, sizeof fechaHora, formato, &tiempoLocal);
    char fecha[10];
    memset(fecha,0x00,sizeof(fecha));
    sprintf(fecha,"%d",bytesEscritos);

    int posi = cantidadPed(vect[pos])+1;
    if(!existePedido(cant, vect[pos])){
        if (posi <= cantidadPed(vect[pos])+1){
            pedidos *nuevo;
            nuevo=malloc(sizeof(pedidos));
            nuevo->codigoPedido = cant;
            nuevo->usuarioP = nombreClienActu;
            strcpy(nuevo->nombreP , nombreProd);
            nuevo->cantidadproducts = cantProd;
            strcpy((char *)nuevo->fecha,(const char*)fecha);
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
                    for (f = 1; f <= posi - 2; f++)
                        reco = reco->sig;
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

void imprimirPedi(pedidos *vectP[TAMANO]){
    system("cls");
    int i = 0;
    pedidos *reco = vectP[i];
    pedidos *reco2 = vectP[i];
    float total= 0;

    while(vectP[i] != NULL)
    {
        reco = vectP[i];
        printf("\n*************************************\n");
        printf("  xxxxxxxxx  Pedido N*:%i  xxxxxxxxx\n", reco->codigoPedido);
        printf("   --Fecha: %s--\n", reco->fecha );
        imprimirUsuespe(reco->usuarioP);
        
        total = 0;
        while (reco!=NULL){
            printf("-> %s ..................%0.2f\n", reco->nombreP, reco->valorC);
            total += reco->valorC;
            reco=reco->sig;
        }

        printf("                  ____________________\n");
        printf("\t\t\tTOTAL: %.2f\n", total);
        printf("**************************************\n");
        i++;
    }
}

void imprimirPediEspes(pedidos *vectEsps){
    int i = 0;
    pedidos *reco = vectEsps;
    pedidos *reco2 = vectEsps;
    printf("prueba\n");

    printf("\n*************************************\n");
    printf(" xxxxxxxxxxx  Pedido N*:%i  xxxxxxxxxx\n", reco->codigoPedido);
    printf("   --Fecha: %s--\n", reco->fecha );
    imprimirUsuespe(reco->usuarioP);
    
    while (reco!=NULL){
        printf("->\t%s ............%0.2f\n", reco->nombreP, reco->valorC);
        reco=reco->sig;
    }

    float total= 0;

    while (reco2!=NULL){
        total += reco2->valorC;
        reco2=reco2->sig;
    }
    printf("_____________________________________\n");
    printf(" \tTOTAL: ..............%0.2f\n\n", total);
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

static void registrarVenta(){
    int codigo;
    int cantidadp;
    char opcion ;
    fflush(stdin);
    printf("-----  DESEA COMPRAR ? ('s/n') -----  \n\n");
    scanf("%c",&opcion);

    if(opcion!= 'n'){
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
        
        float valor = (float) cantidadp * precioProduct(codigo);
        char nombre[15]; 
        strcpy(nombre, codNombreProduct(codigo));

        printf(" Cod: %i, Cant :%i  ",codigo, cantidadp );
        if (descontarProducto(codigo, cantidadp)) 
            insertarPedido(i,cantUs, nombre , cantidadp, valor , &vectorPedidos); 
        
        fflush(stdin);
        printf("  Desea adquirir otro producto ? 's/n' \n");
        scanf("%c",&opcion);
    }while(opcion!= 'n');
    i++;
    if(opcion == 'n')  imprimirPediEspes(vectorPedidos[cantUs]);
}

static void NuevoProducto(){
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
        printf("¿ Desea continuar ? 's/n' \n");
        scanf("%c",&opcion);
        system("cls");

    } while(opcion!= 'n');
}

static void inventario(){
    int opcion;
    do {
        printf("\nSub-menu de inventario\n");
        printf(" ¿¿¿¿¿¿¿¿¿¿¿\n");
        printf(" ''''''''''''''''''''''\n");
        printf("|>  1-Agregar productos.\n");
        printf("|>  2-Listado de productos.\n");
        printf("|>  3-Salir.\n\n");
        printf("Elija su opcion: ->");
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
        printf("\n***  MINI CAJA REGISTRADORA ***\n");
        printf("   -------------------------\n");
        printf("[]  1-Registrar venta.\n");
        printf("[]  2-Inventario.\n");
        printf("[]  3-Lista de ventas.\n");
        printf("[]  4-Salir.\n");
        printf("[]  5-Imprimir usuarios.\n");
        printf("Elija su opcion: ->");
        scanf("%i",&opcion);
        system("cls");
        switch (opcion) {
            case 1:registrarVenta();
                break;
            case 2:inventario();
                break;
            case 3:imprimirPedi(&vectorPedidos);
                break;
            case 4: // Salir
            printf("Gracias por utilizar nuestra caja registradora!\n\n");
                break;
            case 5:imprimirUsu();
                break;
            default:
                printf("La opcion no es valida.\n");
        }
    } while(opcion!=4);
}

int main()
{
    for (int i = 0 ; i< TAMANO ; i++) vectorPedidos[i]= raizPed;

    insertarpro( "CARNE", 15, 1500.0 );
    insertarpro( "PAPA", 20, 1350.0 );
    insertarpro( "LECHE", 30, 2000.0 );


    insertarusu("JUAN P", "12546322");
    insertarusu("PABLO S", "24545444");
    insertarusu("SLINAS J", "32565655");
    insertarusu("J LOPEZ", "32121515");

    menuPrincipal();

    return 0;
    
}
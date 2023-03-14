#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N 50

typedef struct{
    char nombre_lib[N];
    char autor[N];
    int lleno_lib;
}libro;

typedef struct{
    char nombre_bi[N];
    libro lib[10];
    int lleno_bi;
}biblioteca;

biblioteca bi[3];

void vacio();
void cambio(char palabra[N]);
void anadebi();
void anadelib();
void consulta();


int main() {
    int op;
    char key;

    vacio();

    do{
        do{
            printf("Elige que deseas hacer: \n");
            printf("(1) Añadir una nueva biblioteca.\n");
            printf("(2) Añadir un libro biblioteca..\n");
            printf("(3) consultar un libro .\n");
            scanf("%i",&op);
        }while (op < 1 || op>3);

        switch (op){
        case 1:{
            anadebi();
            break;
        }    
        case 2:{
            anadelib();
            break;
        }
        case 3:{
            consulta();
            break;
        }
    }    
        printf("Introduce si deseas realizar otra operacion:  (S/N)");
        fflush(stdin);
        scanf("%c",&key);
    }while (key == 'S'||key=='s');

    system("pause");
    return 0;
}

void vacio(){
    int i,j;
    for ( i = 0; i < 3; i++){
        bi[i].lleno_bi = 0;
        for ( j = 0; j < 10; j++){
            bi[i].lib[j].lleno_lib = 0;
        }    
    }  
}

void cambio(char palabra[N]){
    int i;

    for ( i = 0; i < N; i++){
       if(palabra[i]== '\n'){
          palabra[i]= '\0';
       }
    }
}

void anadebi(){
    int i, aux;
    aux= 0;

    for ( i = 0; i < 3 && aux == 0; i++){
        if (bi[i].lleno_bi == 0){
                printf("Introduce un nombre para la biblioteca: ");
                fflush(stdin);
                fgets(bi[i]. nombre_bi,N,stdin);
                cambio(bi[i]. nombre_bi);

                bi[i]. lleno_bi=1;
                aux = 1;
        }
    }

    if (aux== 0){
    printf("no se pueden ingresar mas bibliotecas: \n");
    }   
}

void anadelib(){
    int i,op, aux;
    aux= 0;

    for ( i = 0; i < 3; i++){
        if (bi[i].lleno_bi== 1){
                printf("(%i) %s.\n", i, bi[i].nombre_bi);
        }
    }
    scanf("%i", &op);

    for ( i = 0; i < 10 && aux == 0; i++){
        if (bi[op].lib[i].lleno_lib == 0){
                printf("Introduce el nombre del libro: ");
                fflush(stdin);
                fgets(bi[op].lib[i].nombre_lib,N,stdin);
                cambio(bi[op].lib[i].nombre_lib);

                printf("Introduce el nombre del autor: ");
                fflush(stdin);
                fgets(bi[op].lib[i].autor,N,stdin);
                cambio(bi[op].lib[i].autor);

                bi[op].lib[i].lleno_lib =1;
                aux = 1;
        }
    }
}

void consulta(){
    int op,i,j,aux;
    char buscar[N];

    aux = 1;

    do{
            printf("Elige que deseas buscar: \n");
            printf("(1) Nombre ibro.\n");
            printf("(2) Nombre Autor.\n");
            scanf("%i",&op);
        }while (op < 1 || op>2);

        switch (op){
            case 1:{
                printf("Introduce el nombre del libro que deseas buscar: ");
                fflush(stdin);
                fgets(buscar,N,stdin);
                cambio(buscar);

                for ( i = 0; i < 3; i++){
                    aux = 1;
                    for ( j = 0; j < 10; j++){
                        aux= strcmp(buscar,bi[i].lib[j].nombre_lib);
                        if(aux == 0){
                            printf("El libro %s se encuentra en la biblioteca %s.\n", buscar,bi[i].nombre_bi);
                            printf("El autor es: %s.\n", bi[i].lib[j].autor);
                        }
                    }  
                }                   
                break;
            }
            case 2:{
                printf("Introduce el nombre del autor que deseas buscar: ");
                fflush(stdin);
                fgets(buscar,N,stdin);
                cambio(buscar);

                for ( i = 0; i < 3; i++){
                    aux = 1;
                    for ( j = 0; j < 10; j++){
                        aux= strcmp(buscar,bi[i].lib[j].autor);
                        if(aux == 0){
                            printf("El libro %s se encuentra en la biblioteca %s.\n", bi[i].lib[j].nombre_lib,bi[i].nombre_bi);
                        }
                    }  
                }                   
                break;
            }
        }
}


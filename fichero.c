#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct
{
    char *nombre;
    int edad;
}trabajadores;

trabajadores *trab;

void vaciar(char temp[]);
void copiar(char temp[], int i);

int main(){

    int i, j;
    char aux;
    char temp[50];
    int cont = 0;

    FILE *f;
    f = fopen("bloque.8.2.txt", "r");
    if (f == NULL){
        printf("NO SE HA PODIDO ABRIR EL FICHERO.\n ");
        exit(1);
    }

    while (!feof(f)){
        fgets(temp, 50, f);
        cont++;
    }

    rewind(f);

    trab = (trabajadores*)malloc(cont *sizeof(trabajadores));
    if (trab == NULL){
        printf("NO SE HA PODIDO RESERVAR MEMORIA.\n ");
        exit(1);
    }

    for ( i = 0; ! feof(f); i++){
        vaciar(temp);
        aux = '0';
        for ( j = 0; aux !='-'; j++){
           aux =fgetc(f);
           if (aux !='-'){
                 temp[j]= aux;
           }      
        }
        copiar(temp,i);

        fgets(temp,4,f);
        trab[i].edad=atoi(temp);
        printf("nombre: %s Edad: %i.\n",trab[i].nombre,trab[i].edad);
   }

    system ("pause");
    return 0;
}


void vaciar(char temp[]){
    int i;

    for ( i = 0; i < 50; i++){
        temp[i]='\0';
    }
}

void copiar(char temp[], int i){
    int N= strlen(temp)+ 1;
    trab[i].nombre =(char*)malloc(N*sizeof(char));
    if(trab[i].nombre == NULL){
        printf("no se ha podido reservar memo");
        exit(1);
    }
    strcpy(trab[i].nombre, temp);
}
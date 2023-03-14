#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void cambio(char aux[]);

int main(){

    char aux[50];

    FILE *f;

    f = fopen("bloque_8_3.txt", "w");
    if (f == NULL){
        printf("NO SE HA PODIDO ABRIR EL FICHERO.\n ");
        exit(1);
    }else printf("ta bien");

    printf("introduce una frase:  ");
    fgets(aux, 50, stdin);
    cambio(aux); 

    fprintf(f, "el string introducido es: %s", aux);

    fclose(f);

    system("pause");
    return 0;
}

void cambio(char aux[]){
    int i;

    for ( i = 0; i < 50; i++){
       if(aux[i]== '\n'){
          aux[i]= '\0';
       }
    }
}

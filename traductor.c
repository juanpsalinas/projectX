#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N 50

typedef struct{
    
    char nombre[N];
    char empleo[N];
    int edad;
}reg;

int main() {

    reg f1,f2;

    printf("Introduce valores para el fomulario 1; \n");
    printf("Introduce TU NOMBRE: ");
    fgets(f1.nombre,50,stdin);

    printf("Introduce TU empleo: ");
    fflush(stdin);
    fgets(f1.empleo,50,stdin);

    printf("Introduce TU edad: ");
    scanf("%i",&f1.edad);

    printf("Introduce valores para el fomulario 2; \n");
    printf("Introduce TU NOMBRE: ");
    fflush(stdin);
    fgets(f2.nombre,50,stdin);

    printf("Introduce TU empleo: ");
    fflush(stdin);
    fgets(f2.empleo,50,stdin);

    printf("Introduce TU edad: ");
    scanf("%i",&f2.edad);

    printf("los valores son: \n");
    printf("el NOMBRE de f1: %s", f1.nombre);
    printf("el NOMBRE de f2: %s", f2.nombre);

    printf("el empleo de f1: %s", f1.empleo);
    printf("el empleo de f2: %s", f2.empleo);

    printf("el NOMBRE de f1: %i\n", f1.edad);
    printf("el NOMBRE de f2: %i\n ", f2.edad);

    system("pause");
    
    return 0;
}

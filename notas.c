#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct{
    
    int mate;
    int ingles;
    int fisica;
}notas;


void darnotas(notas not[]);

int main() {
    notas not;
    darnotas(&not);

  
            printf("El nota de mate: %i.\n",not.mate);
            printf("El nota de ingles: %i.\n",not.ingles);
            printf("El nota de fisica: %i.\n",not.fisica);

    system("pause");
    return 0;
}

void darnotas(notas *not){
            printf(" introduzca El nota de mate: ");
            scanf("%i",&not->mate);

            printf(" introduzca El nota de ingles: ");
            scanf("%i",&not->ingles);

            printf(" introduzca El nota de fisica: ");
            scanf("%i",&not->fisica);
}
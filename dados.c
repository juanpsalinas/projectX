#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sorteo(int *vec);
void leer (int *vec);

int main() {

    int vec [] = {0,0,0,0,0,0};

    sorteo(vec);
    leer(vec);

    system("pause");
    
    return 0;
}

void sorteo (int *vec){
    srand(time(NULL));
    int i,aux;

    for  (i=0; i<10000 ; i++){
       aux=rand()%6;

       switch (aux) {
       case 0:{
             *(vec+aux) +=1;
              break;
       }
        case 1:{
             *(vec+aux) +=1;
              break;
       }
        case 2:{
             *(vec+aux) +=1;
              break;
       }
        case 3:{
             *(vec+aux) +=1;
              break;
       }
        case 4:{
             *(vec+aux) +=1;
              break;
       }
        case 5:{
             *(vec+aux) +=1;
              break;
       }
   }
}
}
void leer (int *vec) {
    int i;
    float x;

    for ( i=0; i<6; i++){
        x=(*(vec+i)*100)/10000.;
        printf("la probabilidad de que el numero %i salga es de: %f.\n ",i+1,x);
    }




}







#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int main() {

    char c1 [5] ;
    char c2 [5] ;

    printf("pon la 1 frase:  ");
    fgets(c1,5,stdin);
    
    printf("pon la 2 frase:  ");
    fflush(stdin);
    fgets(c2,5,stdin);

    if (strcmp(c1,c2) == 0){
        printf("ambas string son iguales.\n\n");
    }
    else{
        printf("ambas string NO on iguales.\n\n");
    }


    system("pause");
    
    return 0;
}

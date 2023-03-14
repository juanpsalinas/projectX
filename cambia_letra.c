#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void funcion(char c1[]);


int main() {

    char c1[] = "pepe. ";
    
    funcion (c1);

    printf("%s\n",c1);
    
    system("pause");
    
    return 0;
}

void funcion(char c1[]){
    int limite, i;

    limite= strlen(c1);

    for (i = 0; i < limite; i++){
        if (c1[i]== 'e'){
            c1[i] = 'a';
        }
    } 
    }
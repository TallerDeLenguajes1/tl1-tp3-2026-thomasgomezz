#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

    //---FUNCIONES---
    void mostrarPersonas(char *V[], int n);
    int buscarNombre(char *V[], int n, char *palabra);


int main(){

    char *V [N];
    char buffer[100];

    for (int i = 0; i < N; i++)
    {
        printf("Ingrese el nombre %d: ", i + 1);
        scanf("%s", buffer);

        //Reserva de memoria dinamica
        V[i] = (char *) malloc(strlen(buffer) + 1);
        //Copio en el buffer lo que va leyendo
        strcpy(V[i], buffer);
    }

    printf("\nLista de nombres: \n");
    mostrarPersonas(V, N);

    //LIBERO LA MEMORIA
    for (int i = 0; i < N; i++)
    {
        free(V[i]);
    }
    
    return 0;
}

//FUNCIONES
    void mostrarPersonas(char *V[], int n){
        for (int i = 0; i < N; i++)
        {
            printf("%s\n", V[i]);
        }
        

    }


    int buscarNombre(char *V[], int n, char *palabra){
    for (int i = 0; i < n; i++)
    {
        if (strstr(V[i], palabra) != NULL)
        {
            return i;
        }
    }
    return -1;
}
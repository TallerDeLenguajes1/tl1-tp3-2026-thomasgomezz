#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

    //---FUNCIONES---
    void mostrarPersonas(char *V[], int n);
    void buscarNombre(char *V[], int n, int id );


int main(){

    char *V [N];
    char buffer[100];
    int id;

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

    //BUSQUEDA POR ID
    printf("\Ningrese un ID (0 a %d)", N - 1);
    scanf("%d", &id);
    

    //LLAMO A LA FUNCION Y LE PASO LOS PARAMETROS
    buscarNombre(V, N, id);

    //LIBERO LA MEMORIA
    for (int i = 0; i < N; i++)
    {
        free(V[i]);
    }
    

    return 0;
}

//FUNCIONES
    void mostrarPersonas(char *V[], int n){
        for (int i = 0; i < n; i++)
        {
            printf("%s\n", V[i]);
        }
        

    }

    void buscarNombre(char *V[], int n, int id ){
        if (id >= 0 && id < n)
        {
            printf("Nombre buscado: %s\n", V[id]);
        }else{
            printf("No se encontro el valor buscado.\n");
        }
    }
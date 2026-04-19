#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

    //---FUNCIONES---
    void mostrarPersonas(char *V[], int n);
    void BuscaNombrePorId(char *V[], int n, int id);
    int BuscaNombrePorPalabra(char *V[], int n, char *palabra);


int main(){

    char *V [N];
    char buffer[100];
    int id;
    int opcion;

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

    //CREO UN MENU PARA BUSCAR NOMBRE 
    printf("\n1-Buscar por ID\n 2-Buscar por palabra\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    if (opcion == 1)
    {
        int id;
        printf("Ingrese un ID (0 a %d):", N - 1);
        scanf("%d", &id);
        BuscaNombrePorId(V, N , id);

    }else{ 
        if (opcion == 2)
        {
            char palabra[100];
            printf("Ingrese una palabra: ");
            scanf("%s", palabra);
            
            int pos = BuscaNombrePorPalabra(V, N ,palabra);
            if (pos != -1)
            {
                printf("Se encontro en la posicion %d\n", pos);
            }else{
                printf("No se encontró la palabra.\n");
            }
            
        }
        
    }
    


/*
//BOORAR ESTO??
    //BUSQUEDA POR ID
    printf("\ningrese un ID (0 a %d)", N - 1);
    scanf("%d", &id);
    

    //LLAMO A LA FUNCION Y LE PASO LOS PARAMETROS PARA BUSCAR NOMBRE POR ID
    buscarNombrePorId(V, N, id);


    //BUSCAR NOMBRE POR PALABRA
    BuscaNombrePorPalabra();

//HASTA ACA???
*/ 


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

    void BuscaNombrePorId(char *V[], int n, int id){
    if (id >= 0 && id < n)
    {
        printf("Nombre buscado: %s\n", V[id]);
    } else {
        printf("No se encontro el valor buscado\n");
    }
}

int BuscaNombrePorPalabra(char *V[], int n, char *palabra){
    for (int i = 0; i < n; i++)
    {
        if (strstr(V[i], palabra) != NULL)
        {
            return i;
        }
    }
    return -1;
}


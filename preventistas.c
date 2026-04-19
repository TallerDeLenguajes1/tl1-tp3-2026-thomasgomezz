#include<stdio.h>
#include<stdlib.h>

    #define MAX_CLIENTES 5


    int main(){
        int cantClientes;

        printf("Ingrese la cantidad de clientes(Maximo %d)", MAX_CLIENTES);

        //BUCLE PARA CONTROLAR QUE LA CANTIDAD NO SEA 0 NI EXCEDA DEL MAX
        while (cantClientes < 1 || cantClientes > MAX_CLIENTES)
        {
            printf("Cantidad invalida. Ingrese entre 1 y %d", MAX_CLIENTES);
            scanf("%d", &cantClientes);
        }

        //MUESTRO LA CANTIDAD DE CLIENTES INGRESADA
        printf("Cantidad de clientes ingresada: %d\n", cantClientes);

        return 0;
    }
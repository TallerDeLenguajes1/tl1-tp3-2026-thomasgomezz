#include<stdio.h>
#include<stdlib.h>
#include <string.h>

    //---ESTRUCUTURAS---
       typedef struct 
    {
        int clienteID; //Numerado en ciclo iterativo
        int cantidad;   //Entre 1 y 10
        char *tipoProducto; //Algun valor del arreglo tipoProdcutos
        float precioUnitario; //Entre 10 - 100
    }Producto;

    typedef struct 
    {
        int clienteID;  //Numerado en ciclo iterativo
        char *nombreCliente;    //Ingresado por usuario
        int cantProductosAPedir;    // Aleatorio (entre 1 a 5)
        Producto *productos;  //
    }Cliente;
    

    #define MAX_CLIENTES 5


    int main(){
        int cantClientes;

        printf("Ingrese la cantidad de clientes(Maximo %d):", MAX_CLIENTES);
        scanf("%d", &cantClientes);

        //BUCLE PARA CONTROLAR QUE LA CANTIDAD NO SEA 0 NI EXCEDA DEL MAX
        while (cantClientes < 1 || cantClientes > MAX_CLIENTES)
        {
            printf("Cantidad invalida. Ingrese entre 1 y %d", MAX_CLIENTES);
            scanf("%d", &cantClientes);
        }

        //MUESTRO LA CANTIDAD DE CLIENTES INGRESADA
        printf("Cantidad de clientes ingresada: %d\n", cantClientes);

        //SOLICITAR LA CARGA DE LOS CLIENTES CREADOS DINAMICAMENTE

        //HACER UNA RESERVA DE MEMORIA DINAMICA PARA LOS CLIENTES
        Cliente *clientes = (Cliente*)malloc(cantClientes * sizeof(Cliente));

        //CARGA DE CLIENTES(recorrer y cargar datos)
        for (int i = 0; i < cantClientes; i++)
        {
            clientes[i].clienteID = i + 1;      //asigna un ID a cada cliente

            char buffer[100];       //creo una variable para colocar el nombre
            printf("Ingrese el nombre del cliente %d:", i + 1);
            scanf("%s", buffer);

            //RESERVA DE MEMORIA DINAMICA PARA CADA NOMBRE DE UN CLIENTE
            clientes[i].nombreCliente = (char*)malloc(strlen(buffer) + 1);
            strcpy(clientes[i].nombreCliente, buffer);  //Copio el nombre en el buffer
        }
        
        //MOSTRAR PARA PROBAR
        printf("\nClientes cargados:\n");
        for (int i = 0; i < cantClientes; i++)
        {
            printf("ID: %d - Nombre: %s\n", clientes[i].clienteID, clientes[i].nombreCliente);
        }
        
        //LIBERAR MEMORIA PARA LOS NOMBRE DE LOS CLIENTES
        for (int i = 0; i < cantClientes; i++)
        {
            free(clientes[i].nombreCliente);
        }
        
        //LIBERO MEMORIA PARA LA RESERVA DE CLIENTES
        free(clientes);

        return 0;
    }
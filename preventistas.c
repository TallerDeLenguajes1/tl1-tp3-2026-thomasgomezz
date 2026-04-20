#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>


    //TIPO DE PRODUCTOS
    char *tipoProductos[]= {"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};


    //---ESTRUCUTURAS---
       typedef struct 
    {
        int productoID; //Numerado en ciclo iterativo
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

        //PARA GENERAR VALORES ALEATORIOS
        srand(time(NULL));

        //PUNTO i
        int cantClientes;

        printf("Ingrese la cantidad de clientes(Maximo %d):", MAX_CLIENTES);
        scanf("%d", &cantClientes);

        //BUCLE PARA CONTROLAR QUE LA CANTIDAD NO SEA 0 NI EXCEDA DEL MAX
        while (cantClientes < 1 || cantClientes > MAX_CLIENTES)
        {
            printf("Cantidad invalida. Ingrese entre 1 y %d\n", MAX_CLIENTES);
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

            //PARA PUNTO iii 
            //CANTIDAD DE PRODUCTOS (ALEATORIO)
            clientes[i].cantProductosAPedir = rand() % 5 + 1;

            //RESERVA DE MEMORIA DINAMICA PARA LA CANTIDAD DE PRODUCTOS
            clientes[i].productos = (Producto*)malloc(clientes[i].cantProductosAPedir * sizeof(Producto));

            //CARGA DE PRODUCTO
            for (int j = 0; j < clientes[i].cantProductosAPedir; j++)
            {
                clientes[i].productos[j].productoID = j + 1;
                clientes[i].productos[j].cantidad = rand() % 10 + 1;
                int tipo = rand() % 5;  //Me da un numero del 0 al 4 y lo agrego en el corchete
                clientes[i].productos[j].tipoProducto = tipoProductos[tipo];
                clientes[i].productos[j].precioUnitario = rand() % 91 + 10;
            }
            

        }
        
        //MOSTRAR PARA PROBAR
        printf("\n--- Clientes y productos cargados ---\n");
        for (int i = 0; i < cantClientes; i++)
        {
            printf("ID: %d - Nombre: %s\n", clientes[i].clienteID, clientes[i].nombreCliente);

            //AGREGADO PARA EL PUNTO iii

            printf("Cantidad de productos: %d\n", clientes[i].cantProductosAPedir);

            for (int j = 0; j < clientes[i].cantProductosAPedir; j++)
            {
                printf("Producto: %d | Cantidad: %d | Tipo: %s | Precio: %.2f\n", 
                    clientes[i].productos[j].productoID,
                    clientes[i].productos[j].cantidad,
                    clientes[i].productos[j].tipoProducto,
                    clientes[i].productos[j].precioUnitario
                    );
            }
            
        }
        
        //LIBERAR MEMORIA PARA LOS NOMBRE DE LOS CLIENTES
        for (int i = 0; i < cantClientes; i++)
        {
            free(clientes[i].nombreCliente);
            //para productos punto iii
            free(clientes[i].productos);
        }
        
        //LIBERO MEMORIA PARA LA RESERVA DE CLIENTES
        free(clientes);

        return 0;
    }
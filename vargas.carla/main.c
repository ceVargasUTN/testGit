#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"
#define cELEMENTOS 5
#define VACIO 0
#define OCUPADO 1
#define BORRADO -1
#define LLENO -1
int main()
{
    char auxNombre[50], auxApellido[50], auxDni[20], auxID[3], auxCliente[50], auxEquipo[50], auxOperador[50];
    int i, lugarLibre, lugarOcupado, genInt,  converDni, auxTime;
    int opcion = 0, ultimo_idC=0, ultimo_idA=0;

    eCliente clientes[cELEMENTOS];
    eAlquiler alquileres[cELEMENTOS];

    while (opcion != 7)
    {
        iniciarDatosArrayC( clientes, cELEMENTOS, VACIO );
        iniciarDatosArrayA(alquileres, cELEMENTOS, VACIO);

        opcion = getOpcion(opcion);
            switch (opcion)
            {

                case 1:
                    lugarLibre = buscarPrimerOcurrenciaC(clientes, cELEMENTOS, -1);
                    if (lugarLibre == LLENO)
                    {
                        printf("Lleno! ");
                        break;
                    }
                    if(!getStringValidado("Nombre: ", auxNombre))
                    {
                        printf("Solo debe contener letras...");
                        break;
                    }
                    if(!getStringValidado("Apellido: ", auxApellido))
                    {
                        printf("Solo debe contener letras...");
                        break;
                    }
                    if(!getNumerosString("DNI: ", auxDni))
                    {
                        printf("El DNI solo debe contener numeros...");
                    }

                    converDni = atoi(auxDni);
                    strcpy(clientes[lugarLibre].nombre, auxNombre);
                    strcpy(clientes[lugarLibre].apellido, auxApellido);
                    clientes[lugarLibre].dni = converDni;
                    clientes[lugarLibre].flag_estado = OCUPADO;
                    clientes[lugarLibre].id_cliente = ultimo_idC +1;


                    printf("%s\n",clientes[lugarLibre].nombre);
                    printf("%s\n", clientes[lugarLibre].apellido);
                    printf("%d\n", clientes[lugarLibre].dni);
                    printf("%d\n", clientes[lugarLibre].id_cliente);
                    printf("%d\n", clientes[lugarLibre].flag_estado);

                    ultimo_idC = ultimo_idC +1;
                    printf( "CARGADO CON EXITO!\n");
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    printf("MODIFICAR\n");
                    if (!getNumerosString("Ingrese el ID que desea modificar...", auxID))
                    {
                        printf("El id debe ser numerico!\n");
                        break;
                    }
                    genInt = atoi(auxID);
                    lugarOcupado = buscarPrimerOcurrenciaC(clientes, cELEMENTOS, genInt);//genInt en  este caso es el  id

                    if(lugarOcupado == LLENO)
                    {
                        printf("No se encuentra del  registro! \n");
                        break;
                    }
                    if(!getStringValidado("Nombre: ", auxNombre))
                    {
                        printf("Solo debe contener letras...");
                        break;
                    }
                    if(!getStringValidado("Apellido: ", auxApellido))
                    {
                        printf("Solo debe contener letras...");
                        break;
                    }

                    strcpy(clientes[lugarOcupado].nombre, auxNombre);
                    strcpy(clientes[lugarOcupado].apellido, auxApellido);
                    printf( "MODIFICACION EXITOSA!\n");
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    printf("Baja Cliente\n");
                    if (!getNumerosString("Ingrese el ID que desea eliminar...", auxID))
                {
                    printf("El id debe ser numerico!\n");
                    break;
                }
                genInt = atoi(auxID);
                lugarOcupado = buscarPrimerOcurrenciaC(clientes, cELEMENTOS, genInt);//genInt en  este caso es el  id
                printf("%d", lugarOcupado);
                if(lugarOcupado == LLENO)
                {
                    printf("No se encuentra del  registro! \n");
                    break;

                }
                clientes[lugarOcupado].flag_estado = BORRADO;
                printf( "BORRADO CON EXITO!\n");
                system("pause");
                system("cls");
                break;

                case 4:
                    printf("AGREGAR alquiler\n");
                lugarLibre = buscarPrimerOcurrenciaA(alquileres, cELEMENTOS, -1);
                if (lugarLibre == LLENO)
                {
                    printf("Lleno! ");
                    break;
                }
                if(!getStringValidado("Equipo: ", auxEquipo))
                {
                    printf("Solo debe contener letras...");
                    break;
                }
                if(!getStringValidado("Operador: ", auxOperador))
                {
                    printf("Solo debe contener letras...");
                    break;
                }
                if (!getNumerosString("Tiempo estimado: ", auxTime))
                {
                    printf("El id debe ser numerico!\n");
                    break;
                }
                if(!getStringValidado("Cliente: ", auxCliente))
                {
                    printf("Solo debe contener letras...");
                    break;
                }
                if (buscarCliente(clientes,cELEMENTOS, auxCliente)!= -1)//compara el auxCliente con el nombre del cliente en la estructura eClientes
                {
                    strcpy(alquileres[lugarLibre].cliente, auxCliente);
                    strcpy(alquileres[lugarLibre].equipo, auxEquipo);
                    strcpy(alquileres[lugarLibre].operador, auxOperador);
                    alquileres[lugarLibre].flag_estado = OCUPADO;
                    alquileres[lugarLibre].id_Alquiler = ultimo_idA +1;
                    ultimo_idA = ultimo_idA +1;
                    printf( "CARGADO CON EXITO!\n");
                    system("pause");
                    system("cls");
                    printf( "CARGA EXITOSA!\n");
                }else{
                    printf("No tiene registro de ese Cliente!");
                }

                system("pause");
                system("cls");
                    break;
                case 5:
                    break;
                case 6:
                    printf("Mostrar");
                    for(i=0;i < cELEMENTOS; i++)
                    {
                        if(clientes[i].flag_estado == OCUPADO)
                        {
                            printf("\n%s - %s - %d - %d \n",clientes[i].nombre,clientes[i].apellido, clientes[i].dni, clientes[i].id_cliente);
                        }
                    }
                    printf("Mostrar");
                    /*for(i=0;i < cELEMENTOS; i++)
                    {
                        if(alquileres[i].flag_estado == OCUPADO)
                        {
                            printf("\n%s - %s - %d - %d \n",alquileres[i].nombre,clientes[i].apellido, clientes[i].dni, clientes[i].id_cliente);
                        }
                    }*/
                    system("pause");
                    system("cls");
                    break;
                case 7:
                    break;

            }
    }
    return 0;
}

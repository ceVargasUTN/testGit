#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#define cELEMENTOS 5
#define VACIO 0
#define OCUPADO 1
#define BORRADO -1
#define LLENO -1

 int getOpcion(int opc)
    {
        int op;
        printf( "     MENU PRINCIPAL\nIngrese la opcion que desee: \n1. Altas clientes\n2. Modificar datos cliente\n3. Baja cliente\n4. Nuevo alquiler\n5. Fin alquiler\n6. Informar\n7. salir");
        scanf("%d", &op);
        return op;
    }

void obtenerDatosPorTeclado( char mensaje[], char input[])
{
    printf(mensaje);
    fflush(stdin);
    scanf("%s", input);
}

int validarSoloLetras(char soloString[])
{
    int i= 0;
    while (soloString[i] != '\0')
    {
        if ((soloString[i]!= ' ') && (soloString[i] < 'a' || soloString[i] > 'z') && (soloString[i]< 'A' || soloString[i]> 'Z'))
            return 0;
        i++;
    }
    return 1;
}


int getStringValidado(char mensaje[], char input[])
{
    char auxInput[50];
    obtenerDatosPorTeclado(mensaje, auxInput);
    if(validarSoloLetras(auxInput))
    {
        strcpy(input, auxInput);
        return 1;
    }
    return 0;
}

int esNumerico(char strInput[])
{
   int i=0;
   while(strInput[i] != '\0')
   {
       if(strInput[i] < '0' || strInput[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

int getNumerosString(char mensaje[],char input[])
{
    char aux[256];
    obtenerDatosPorTeclado(mensaje,aux);
    if(esNumerico(aux))//&& strlen(esNumerico(aux)) > 9
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


//verificar luego  el  dni
/*
char letraDNI(int dni)
{
  char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";

  return letra[dni%23];
}

short verificaDNI(char mensaje[], char inputDni)
{
    obtenerDatosPorTeclado(mensaje,aux);
  if (strlen(dni)!=9)
      return 0;
  else
    return (letraDNI(atoi(dni))==dni[8]);
}
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"
#define cELEMENTOS 5
#define VACIO 0
#define OCUPADO 1
#define BORRADO -1
#define LLENO -1
void iniciarDatosArrayA(eAlquiler arrayAlquilo[], int cantElementos, int valor)
{
    int i;
    for (i = 0 ; i< cantElementos ; i ++)
    {
        arrayAlquilo[i].flag_estado = valor;
    }
}

int buscarPrimerOcurrenciaA(eAlquiler arrayAlquilo[], int cantElementos, int valor)
{
    int i;
    for (i = 0 ; i< cantElementos ; i ++)
    {
        if ((arrayAlquilo[i].flag_estado == VACIO || arrayAlquilo[i].flag_estado == BORRADO)&& valor == -1)//si  el  estado  es vacio, o borrado, y  ademas el  valor es -1
        {
            return i;
        }
        else
        {
            if(valor == arrayAlquilo[i].id_Alquiler && arrayAlquilo[i].flag_estado == OCUPADO)//busco  que exista el id que le paso  por parametro (valor)
            {
                return i;
            }
        }
    }
    return LLENO;
}

int buscarCliente(eCliente client[], int cantElemetos, char val[])
{
    int i;
    for (i = 0; i< cantElemetos; i++)
    {
        if (client[i].flag_estado != BORRADO || client[i].flag_estado == 1)
        {
            if (strcmp(val, client[i].nombre)==0)
            {
                return val;
            }
        }
    }
    return -1;

}

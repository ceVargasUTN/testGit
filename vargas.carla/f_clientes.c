#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"
#define cELEMENTOS 5
#define VACIO 0
#define OCUPADO 1
#define BORRADO -1
#define LLENO -1
void iniciarDatosArrayC(eCliente arrayClient[], int cantElementos, int valor)
{
    int i;
    for (i = 0 ; i< cantElementos ; i ++)
    {
        arrayClient[i].flag_estado = valor;
    }
}

int buscarPrimerOcurrenciaC(eCliente arrayClient[], int cantElementos, int valor)
{
    int i;
    for (i = 0 ; i< cantElementos ; i ++)
    {
        if ((arrayClient[i].flag_estado == VACIO || arrayClient[i].flag_estado == BORRADO)&& valor == -1)//si  el  estado  es vacio, o borrado, y  ademas el  valor es -1
        {
            return i;
        }
        else
        {
            if(valor == arrayClient[i].id_cliente && arrayClient[i].flag_estado == OCUPADO)//busco  que exista el id que le paso  por parametro (valor)
            {
                return i;
            }
        }
    }
    return LLENO;
}


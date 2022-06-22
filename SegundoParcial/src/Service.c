/*
 * Service.c
 *
 *  Created on: 21 jun. 2022
 *      Author: Luis
 */

#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "Service.h"
#include "string.h"

/** \brief Modificar el ID del Servicio.
 *
 * \param id int
 * \param pArrayListService LinkedList*
 * \return int
 *
 */
int Service_setId(Service* this,int id)
{
	int retorno = 0;
	this->id = id;
	if(this->id != id)
	{
		retorno = 1;
	}
	return retorno;
}


/** \brief Obtiene el id del Servicio.
 *
 * \param id int*
 * \param pArrayListService LinkedList*
 * \return int
 *
 */
int Service_getId(Service* this,int* id)
{
	int retorno = 0;
	*id = this->id;
	if(*id != this->id)
	{
		retorno = 1;
	}
	return retorno;
}




/** \brief Modificar la cantidad del Servicio.
 *
 * \param id int
 * \param pArrayListService LinkedList*
 * \return int
 *
 */
int Service_setCant(Service* this,int cant)
{
	int retorno = 0;
	this->cantidad = cant;
	if(this->cantidad != cant)
	{
		retorno = 1;
	}
	return retorno;
}


/** \brief Obtiene la cantidad del Servicio.
 *
 * \param id int*
 * \param pArrayListService LinkedList*
 * \return int
 *
 */
int Service_getCant(Service* this,int* cant)
{
	int retorno = 0;
	*cant = this->cantidad;
	if(*cant != this->cantidad)
	{
		retorno = 1;
	}
	return retorno;
}

/** \brief Modificar la descripcion del Servicio.
 *
 * \param nombre char*
 * \param pArrayListService LinkedList*
 * \return int
 *
 */
int Service_setDesc(Service* this,char* desc)
{
	int retorno = 0;
	strcpy(this->descripcion, desc);
	if(strcmp(this->descripcion,desc) != 0)
	{
		retorno = 1;
	}

	return retorno;

}


/** \brief obtener la descripcion del Servicio.
 *
 * \param nombre char*
 * \param pArrayListService LinkedList*
 * \return int
 *
 */
int Service_getDesc(Service* this,char* desc)
{
	int retorno = 0;
	strcpy(desc, this->descripcion);
	if(strcmp(this->descripcion,desc) != 0)
	{
		retorno = 1;
	}

	return retorno;
}



/** \brief Modificar el tipo del Servicio.
 *
 * \param tipoServicio int
 * \param pArrayListService LinkedList*
 * \return int
 *
 */
int Service_setTipo(Service* this,int tipoServicio)
{
	int retorno = 0;
	this->tipo = tipoServicio;
	if(this->tipo != tipoServicio)
	{
		retorno = 1;
	}
	return retorno;


}
/** \brief Obtener el tipo del Servicio.
 *
 * \param tipoServicio int*
 * \param pArrayListService LinkedList*
 * \return int
 *
 */
int Service_getTipo(Service* this,int* tipoServicio)
{
	int retorno = 0;
	*tipoServicio = this->tipo;
	if(this->tipo != *tipoServicio)
	{
		retorno = 1;
	}
	return retorno;
}

/** \brief Modificar el precio del Servicio.
 *
 * \param precio float
 * \param pArrayListService LinkedList*
 * \return int
 *
 */
int Service_setPrecio(Service* this,float precio)
{
	int retorno = 0;
	this->precio = precio;
	if(this->precio != precio)
	{
		retorno = 1;
	}
	return retorno;
}

/** \brief Obtener el precio del Servicio.
 *
 * \param precio float*
 * \param pArrayListService LinkedList*
 * \return int
 *
 */
int Service_getPrecio(Service* this,float* precio)
{
	int retorno = 0;
	*precio = this->precio;
	if(this->precio != *precio)
	{
		retorno = 1;
	}
	return retorno;

}


/** \brief Modificar el precio total del Servicio.
 *
 * \param precio float
 * \param pArrayListService LinkedList*
 * \return int
 *
 */
int Service_setTotal(Service* this,float total)
{
	int retorno = 0;
	this->total = total;
	if(this->total != total)
	{
		retorno = 1;
	}
	return retorno;
}

/** \brief Obtener el precio total del Servicio.
 *
 * \param precio float*
 * \param pArrayListService LinkedList*
 * \return int
 *
 */
int Service_getTotal(Service* this,float* total)
{
	int retorno = 0;
	*total = this->total;
	if(this->total != *total)
	{
		retorno = 1;
	}
	return retorno;

}


/** \brief Inicializa al Servicio.
 *
 * \return Service*
 *
 */
Service* Service_new()
{
	Service* nuevoServicio = NULL;
    nuevoServicio= (Service*) malloc(sizeof(Service));

    if(nuevoServicio != NULL)
    {
		nuevoServicio->id = 0;
    	strcpy(nuevoServicio->descripcion, "");
		nuevoServicio->tipo = 0;
		nuevoServicio->precio = 0;
		nuevoServicio->cantidad = 0;
		nuevoServicio->total = 0;

    }

    return nuevoServicio;

}

/** \brief Rellena el Servicio.
 * \param idStr char*
 * \param nombreStr char*
 * \param apellidoStr char*
 * \param tipoServicioStr char*
 * \param precioStr char*
 * \param flycodeStr char*
 * \param estadoStr char*
 * \return Service*
 *
 */

Service* Service_newParametros(char* idStr,char* cantStr, char* tipoStr, char* precioStr, char* descStr, char* totalStr)
{
	Service* nuevoServicio = Service_new();
	int idAux;
	int tipoAux;
	float precioAux;
	int cantAux;
	float totalAux;

	idAux = atoi(idStr);
	precioAux = atof(precioStr);
	cantAux = atoi(cantStr);
	totalAux = atof(totalStr);
	tipoAux = atoi(tipoStr);

	int validacion = 0;

    if(nuevoServicio != NULL)
    {

    	if(Service_setId(nuevoServicio, idAux) == 0)
    	{
    		validacion ++;
    		if(Service_setDesc(nuevoServicio, descStr)==0)
    		{
    			validacion ++;
    			if(Service_setTipo(nuevoServicio, tipoAux) == 0)
    			{
    				validacion++;
    				if(Service_setPrecio(nuevoServicio, precioAux) == 0)
    				{
    					validacion++;
    					if(Service_setCant(nuevoServicio, cantAux) == 0)
    					{
    						validacion++;
    						if(Service_setTotal(nuevoServicio, totalAux) == 0)
    						{
    							validacion ++;
    						}
    					}
    				}
    			}
    		}
    	}

        if(validacion != 6)
        {
            free(nuevoServicio);
            nuevoServicio=NULL;
        }
    }

    return nuevoServicio;

}

//-----------------------------------------------------//

/** \brief Printea la lista completa.
 * \param pArrayListService LinkedList*
 *
 */
void Service_list(LinkedList* pArrayListService)
{
	Node* indice = pArrayListService->pFirstNode;
	Service* leer;

	printf("\nID  | Descripcion |   tipo     |      Precio  | Cantidad | Total\n");
	for(; indice != NULL; indice = indice->pNextNode)
	{
		leer = indice->pElement;
		Service_print(leer);
	}
}

/** \brief Printea un Servicio.
 * \param this Service*
 *
 */
void Service_print(Service* this)
{

	if(this != NULL)
	{
		printf("%d   |   ", this->id);
		printf(this->descripcion);
		printf("   |   ");
		printf("%d", this->tipo);
		printf("   |   ");
		printf("%.2f", this->precio);
		printf("   |   ");
		printf("%d", this->cantidad);
		printf("   |   ");
		printf("%.2f", this->total);
		printf("\n-------------------------------\n");
	}
}



void calcularTotal(void* servicio)
{
	Service* calculando;
	calculando = servicio;
	float resultado = calculando->precio * calculando->cantidad;
	Service_setTotal(calculando, resultado);
}


int compararDesc(void* ServicioUno, void* ServicioDos)
{
	Service* primerServicio = ServicioUno;
	Service* segundoServicio = ServicioDos;
	int comparacion;
	comparacion = strcmp(primerServicio->descripcion, segundoServicio->descripcion);
	return comparacion;
}

int filtroTipoUno(void* servicio)
{
	int retorno = 0;
	Service* filtrando = servicio;

	if( filtrando->tipo == 1)
	{
		retorno =1;
	}
	return retorno;
}

int filtroTipoDos(void* servicio)
{
	int retorno = 0;
	Service* filtrando = servicio;

	if( filtrando->tipo == 2)
	{
		retorno =1;
	}
	return retorno;
}

int filtroTipoTres(void* servicio)
{
	int retorno = 0;
	Service* filtrando = servicio;

	if( filtrando->tipo == 3)
	{
		retorno =1;
	}
	return retorno;
}



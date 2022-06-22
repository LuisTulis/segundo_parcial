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
int Service_setId(eServicio* this,int id)
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
int Service_getId(eServicio* this,int* id)
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
int Service_setCant(eServicio* this,int cant)
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
int Service_getCant(eServicio* this,int* cant)
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
int Service_setDesc(eServicio* this,char* desc)
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
int Service_getDesc(eServicio* this,char* desc)
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
int Service_setTipo(eServicio* this,int tipoServicio)
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
int Service_getTipo(eServicio* this,int* tipoServicio)
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
int Service_setPrecio(eServicio* this,float precio)
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
int Service_getPrecio(eServicio* this,float* precio)
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
int Service_setTotal(eServicio* this,float total)
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
int Service_getTotal(eServicio* this,float* total)
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
 * \return eServicio*
 *
 */
eServicio* Service_new()
{
	eServicio* nuevoServicio = NULL;
    nuevoServicio= (eServicio*) malloc(sizeof(eServicio));

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
 * \return eServicio*
 *
 */

eServicio* Service_newParametros(char* idStr,char* cantStr, char* tipoStr, char* precioStr, char* descStr, char* totalStr)
{
	eServicio* nuevoServicio = Service_new();
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
	eServicio* leer;

	printf("\nID  | Descripcion |   tipo     |      Precio  | Cantidad | Total\n");
	for(; indice != NULL; indice = indice->pNextNode)
	{
		leer = indice->pElement;
		Service_print(leer);
	}
}

/** \brief Printea un Servicio.
 * \param this eServicio*
 *
 */
void Service_print(eServicio* this)
{

	if(this != NULL)
	{

		char tipoAux[20];
		switch(this->tipo)
		{
			case 1:
				strcpy(tipoAux, "MINORISTA");
				break;
			case 2:
				strcpy(tipoAux, "MAYORISTA");
				break;
			case 3:
				strcpy(tipoAux, "EXPORTAR");
				break;
		}


		printf("%d   |   ", this->id);
		printf(this->descripcion);
		printf("   |   ");
		printf(tipoAux);
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
	eServicio* calculando;
	calculando = servicio;
	float resultado = calculando->precio * calculando->cantidad;
	Service_setTotal(calculando, resultado);
}


int compararDesc(void* ServicioUno, void* ServicioDos)
{
	eServicio* primerServicio = ServicioUno;
	eServicio* segundoServicio = ServicioDos;
	int comparacion;
	comparacion = strcmp(primerServicio->descripcion, segundoServicio->descripcion);
	return comparacion;
}

int filtroTipoUno(void* servicio)
{
	int retorno = 0;
	eServicio* filtrando = servicio;

	if( filtrando->tipo == 1)
	{
		retorno =1;
	}
	return retorno;
}

int filtroTipoDos(void* servicio)
{
	int retorno = 0;
	eServicio* filtrando = servicio;

	if( filtrando->tipo == 2)
	{
		retorno =1;
	}
	return retorno;
}

int filtroTipoTres(void* servicio)
{
	int retorno = 0;
	eServicio* filtrando = servicio;

	if( filtrando->tipo == 3)
	{
		retorno =1;
	}
	return retorno;
}



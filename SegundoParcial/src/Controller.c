/*
 * Controller.c
 *
 *  Created on: 21 jun. 2022
 *      Author: Luis
 */

#include "Controller.h"
#include <stdio.h>
#include <stdlib.h>

#include "../inc/LinkedList.h"

#include "parser.h"
#include "ctype.h"
#include "string.h"
#include "utn.h"
#include "Service.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListService LinkedList*
 * \return int
 *
 */
int controller_loadFromText(LinkedList* pArrayListService)
{
	FILE* pFile;
	int validarParseo = 0;
	char path[30];

	fflush(stdin);
	utn_getCadena(path, "Ingrese el nombre que desea abrir (csv) ('data' predeterminado)");
	strcat(path,".csv");

	pFile = fopen(path, "r");
	if(pFile != NULL)
	{
		validarParseo = parser_Service(pFile, pArrayListService);
	}
	fclose(pFile);

    return validarParseo;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListService LinkedList*
 * \return int
 *
 */
int controller_ListService(LinkedList* pArrayListService)
{
	if(pArrayListService != NULL)
	{
		Service_list(pArrayListService);
	}
    return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListService LinkedList*
 * \return int
 *
 */
int controller_sortService(LinkedList* pArrayListService)
{

	int retorno;

	retorno = ll_sort(pArrayListService, compararDesc, 1);

    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListService LinkedList*
 * \return int
 *
 */
int controller_saveAsText(LinkedList* pArrayListService)
{
	FILE* pFile;

	int retorno = 1;
	char path[30];
	fflush(stdin);
	utn_getCadena(path, "Que nombre desea ponerle al archivo?");
	strcat(path, ".csv");
	pFile = fopen(path, "w");
	if(pFile == NULL)
	{
		printf("\nError al abrir el archivo.\n");
		retorno = 0;
	}
	else
	{
		int id;
		char desc[50];
		int tipo;
		float precio;
		int cantidad;
		float total;
		Node* indice = pArrayListService->pFirstNode;

		fprintf(pFile,"%s,%s,%s,%s,%s,%s\n", "id", "descripcion", "tipo", "precio", "cantidad", "total");
		for(; indice != NULL; indice = indice->pNextNode)
		{

			Service_getId(indice->pElement, &id);
			Service_getDesc(indice->pElement, desc);
			Service_getTipo(indice->pElement, &tipo);
			Service_getPrecio(indice->pElement, &precio);
			Service_getCant(indice->pElement, &cantidad);
			Service_getTotal(indice->pElement, &total);

			fprintf(pFile,"%d,%s,%d,%f,%d,%f\n", id, desc, tipo, precio, cantidad, total);
		}
		printf("\nDatos guardados con exito.\n");
	}
	fclose(pFile);

	return retorno;
}

int controller_TotalPrice(LinkedList* pArrayListService)
{
	int retorno = 0;
	if(pArrayListService != NULL)
	{
		retorno = 1;
		ll_map(pArrayListService, calcularTotal);
	}
	return retorno;

}

void controller_Filter(LinkedList* pArrayListService)
{

	int tipoSeleccionado;
	utn_getNumeroEntero(&tipoSeleccionado,"\nPor que tipo desea filtrar?\n"
												"1-2-3", "Opcion no valida", 1, 3, 3);

	LinkedList* NuevaLista = ll_newLinkedList();
	switch(tipoSeleccionado)
	{
		case 1:
			NuevaLista = ll_filter(pArrayListService, filtroTipoUno);
			break;
		case 2:
			NuevaLista = ll_filter(pArrayListService, filtroTipoDos);
			break;
		case 3:
			NuevaLista = ll_filter(pArrayListService, filtroTipoTres);
			break;
	}

	controller_saveAsText(NuevaLista);

	int subOption;
	do
	{
		utn_getNumeroEntero(&subOption,"\nQue opcion desea realizar?\n"
										"\n1. Imprimir sub lista."
										"\n2. Asignar totales."
										"\n3. Mostrar servicios"
										"\n4. Guardar servicios" "\n5. Volver al menu principal", "Opcion no valida", 1, 5, 3);


		switch(subOption)
		{
			case 1:
				controller_ListService(NuevaLista);
				break;
			case 2:
				controller_TotalPrice(NuevaLista);
				break;
			case 3:
				controller_sortService(NuevaLista);
				controller_ListService(NuevaLista);
				break;
			case 4:
				controller_saveAsText(NuevaLista);
				break;
			case 5:
				printf("\nVolviendo al menu. . .\n");
				break;
		}

	}while(subOption != 5);



}


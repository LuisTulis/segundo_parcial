#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "Service.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListService LinkedList*
 * \return int
 *
 */
int parser_Service(FILE* pFile, LinkedList* pArrayListService)
{

	eServicio* nuevo;

	char idAux[50];
	char descAux[50];
	char tipoAux[50];
	char precioAux[50];
	char cantAux[50];
	char totalAux[50];

	int r;
	int flagDatos = 0;

	if(pFile == NULL)
	{
		printf("El archivo no existe");
		exit(EXIT_FAILURE);
	}
	do
	{
		r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idAux,descAux,tipoAux,precioAux,cantAux,totalAux);
		if(r==6)
		{
			{
				if(flagDatos != 0)
				{
						nuevo = Service_newParametros(idAux,cantAux,tipoAux,precioAux,descAux,totalAux);

						if(nuevo != NULL)
						{
							ll_add(pArrayListService, nuevo);
						}
				}
			}
			flagDatos = 1;
		}

	}while(!feof(pFile));

	fclose(pFile);



    return 1;
}


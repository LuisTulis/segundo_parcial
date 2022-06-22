/*
 ============================================================================
 Name        : SegundoParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "Controller.h"
#include "utn.h"

/*
 * 1) Cargar archivo: Se pedirá el nombre del archivo y se cargará en un linkedlist los elementos
del mismo.
2) Imprimir lista: Se imprimirá por pantalla la tabla con los datos de los servicios.
3) Asignar totales: Se deberá hacer uso de la función map la cual recibirá el linkedlist y una
función que asignará a cada servicio el total calculado de la siguiente forma: cantidad x
totalServicio.
4) Filtrar por tipo: Se deberá generar un archivo igual al original, pero donde solo aparezcan
servicios del tipo seleccionado.
5) Mostrar servicios: Se deberá mostrar por pantalla un listado de los servicios ordenados por
descripción de manera ascendente.
6) Guardar servicios:*/

int main(void) {
	setbuf(stdout,NULL);

	LinkedList* lista = ll_newLinkedList();


	if(lista != NULL)
	{
		int flagCaseUno = 1;
		int option;
		int datosGuardados = 1;
		do
		{
			utn_getNumeroEntero(&option,"\nQue opcion desea realizar?\n"
											"\n1. Cargar archivo."
											"\n2. Imprimir lista."
											"\n3. Asignar totales."
											"\n4. Filtrar por tipo"
											"\n5. Mostrar servicios"
											"\n6. Guardar servicios" "\n7. Salir", "Opcion no valida", 1, 7, 3);


			switch(option)
			{
				case 1:
					if(controller_loadFromText(lista) == 0)
					{
						printf("Hubo un error al cargar el archivo.");
					}
					else
					{
						printf("Archivo cargado con exito.");
						datosGuardados = 0;
						flagCaseUno = 0;
					}
					break;
				case 2:
					if(flagCaseUno == 0)
					{
						controller_ListService(lista);
					}
					else
					{
						printf("Carge un archivo antes de realizar el resto de acciones.");
					}
					break;
				case 3:
					if(flagCaseUno == 0)
					{
						if(controller_TotalPrice(lista))
						{
							printf("Precio total establecido.");
							datosGuardados = 0;
						}
						else
						{
							printf("Hubo un error al cargar los totales.");
						}
					}
					else
					{
						printf("Carge un archivo antes de realizar el resto de acciones.");
					}
					break;
				case 4:
					if(flagCaseUno == 0)
					{
						controller_Filter(lista);
					}
					else
					{
						printf("Carge un archivo antes de realizar el resto de acciones.");
					}
					break;
				case 5:
					if(flagCaseUno == 0)
					{
						controller_sortService(lista);
						controller_ListService(lista);
						datosGuardados = 0;
					}
					else
					{
						printf("Carge un archivo antes de realizar el resto de acciones.");
					}
					break;
				case 6:
					if(flagCaseUno == 0)
					{
						controller_saveAsText(lista);
						datosGuardados = 1;
					}
					else
					{
						printf("Carge un archivo antes de realizar el resto de acciones.");
					}
					break;
				case 7:
					if(datosGuardados != 1)
					{
						printf("\nGuarde los datos antes de salir.\n");
					}
					else
					{
						printf("\nSaliendo del sistema.\n");
					}
					break;
			}

		}while(datosGuardados != 1 || option != 7);

	}
	else
	{
		printf("ERROR, no hay espacio en la memoria.");
	}
	return EXIT_SUCCESS;
}

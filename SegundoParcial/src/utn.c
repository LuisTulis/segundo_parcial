/*
 * utn.c
 *
 *  Created on: 22 may. 2022
 *      Author: Luis
 */

#include <stdio.h>
#include <ctype.h>

int utn_getNumeroEntero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos)
{
	int num = 0;
	int ret = 0;

	while (reintentos > 0)
	{
		printf(mensaje);
		fflush(stdin);
		scanf("%d", &num);

		if(num <= maximo && num >= minimo)
		{
			break;
		}

		reintentos--;
		printf(mensajeError);
	}


	if (reintentos == 0)
	{
		printf("\nUsted gastó todos los intentos posibles.\n");
		ret = -1;
	} else
	{
		*pResultado = num;
		ret = 0;
	}
	return ret;
}
int utn_getNumeroFlotante(float *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos)
{
	float num;
	int ret;
	while (reintentos > 0)
	{
		printf(mensaje);
		scanf("%f", &num);
		fflush(stdin);
		if (num <= maximo && num >= minimo)
			break;
		reintentos--;
		printf(mensajeError);
	}
	if (reintentos == 0) {
		printf("\nusted gastó todos los intentos\n"
				"\nvolviendo al menu.\n");
		ret = -1;
	} else {
		*pResultado = num;
		ret = 0;
	}
	return ret;
}
int utn_getCadena(char arrayRecibido[], char textoAMostrar[])
{
	int ret;
	ret = 0;
	printf(textoAMostrar);
	gets(arrayRecibido);
	fflush(stdin);

	return ret;
}


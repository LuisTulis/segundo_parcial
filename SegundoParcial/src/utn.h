/*
 * utn.h
 *
 *  Created on: 22 may. 2022
 *      Author: Luis
 */

#ifndef UTN_H_
#define UTN_H_



#endif /* UTN_H_ */

/** \brief  * Ingresa un numero entero a la variable
* \param pResultado int* Variable en la que se almacena el numero ingreasdo
* \param mensaje char* Mensaje a mostrar
* \param mensajeError char* Mensaje en caso de que haya un error
* \param minimo int Valor minimo que se permite
* \param maximo int Valor maximo que se permite
* \param reintentos int Cantidad de veces que se permite ingresar numeros en caso de error
*
* \return int Return devuelve 0 si se pudo, -1 si hubo un error.
*
*/
int utn_getNumeroEntero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);

/** \brief  * Ingresa un numero flotante a la variable
* \param pResultado float* Variable en la que se almacena el numero ingreasdo
* \param mensaje char* Mensaje a mostrar
* \param mensajeError char* Mensaje en caso de que haya un error
* \param minimo int Valor minimo que se permite
* \param maximo int Valor maximo que se permite
* \param reintentos int Cantidad de veces que se permite ingresar numeros en caso de error
*
* \return int Return devuelve 0 si se pudo, -1 si hubo un error.
*
*/
int utn_getNumeroFlotante(float *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);

/** \brief  * Ingresa un numero entero a la variable
* \param arrayRecibido char [] Variable en la que se almacena el texto ingreasdo
* \param textoAMostrar char[] Mensaje a mostrar
*
* \return int Return devuelve 0 si se pudo, -1 si hubo un error.
*
*/
int utn_getCadena(char arrayRecibido[], char textoAMostrar[]);

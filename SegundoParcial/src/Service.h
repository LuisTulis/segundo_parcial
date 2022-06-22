/*
 * Service.h
 *
 *  Created on: 21 jun. 2022
 *      Author: Luis
 */

#ifndef SERVICE_H_
#define SERVICE_H_

struct{
	int id;
	char descripcion[50];
	int tipo;
	float precio;
	int cantidad;
	float total;
}typedef Service;

#endif /* SERVICE_H_ */

Service* Service_new();
Service*Service_newParametros(char* idStr,char* cantStr, char* tipoStr, char* precioStr, char* descStr, char* totalStr);
void Service_delete();

int Service_setId(Service* this,int id);
int Service_getId(Service* this,int* id);

int Service_setDesc(Service* this,char* desc);
int Service_getDesc(Service* this,char* desc);

int Service_setPrecio(Service* this,float precio);
int Service_getPrecio(Service* this,float* precio);

int Service_setCant(Service* this,int cant);
int Service_getCant(Service* this,int* cant);

int Service_setTipo(Service* this,int tipo);
int Service_getTipo(Service* this,int* tipo);

int Service_setTotal(Service* this,float total);
int Service_getTotal(Service* this,float* total);

//------------------------------------------------------------------//

void Service_list(LinkedList* pArrayListService);

void Service_print(Service* this);

int Service_idDisponible(LinkedList* pArrayListService);

void* Service_busqueda(LinkedList* pArrayListService, int idABuscar);

int Service_sort(LinkedList* pArrayListService, int *indexUno, int *indexDos);

void calcularTotal(void* servicio);

int compararDesc(void* ServicioUno, void* ServicioDos);

int filtroTipoUno(void* servicio);
int filtroTipoDos(void* servicio);
int filtroTipoTres(void* servicio);



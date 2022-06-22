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
}typedef eServicio;

#endif /* SERVICE_H_ */

eServicio* Service_new();
eServicio*Service_newParametros(char* idStr,char* cantStr, char* tipoStr, char* precioStr, char* descStr, char* totalStr);
void Service_delete();

int Service_setId(eServicio* this,int id);
int Service_getId(eServicio* this,int* id);

int Service_setDesc(eServicio* this,char* desc);
int Service_getDesc(eServicio* this,char* desc);

int Service_setPrecio(eServicio* this,float precio);
int Service_getPrecio(eServicio* this,float* precio);

int Service_setCant(eServicio* this,int cant);
int Service_getCant(eServicio* this,int* cant);

int Service_setTipo(eServicio* this,int tipo);
int Service_getTipo(eServicio* this,int* tipo);

int Service_setTotal(eServicio* this,float total);
int Service_getTotal(eServicio* this,float* total);

//------------------------------------------------------------------//

void Service_list(LinkedList* pArrayListService);

void Service_print(eServicio* this);

int Service_sort(LinkedList* pArrayListService, int *indexUno, int *indexDos);

void calcularTotal(void* servicio);

int compararDesc(void* ServicioUno, void* ServicioDos);

int filtroTipoUno(void* servicio);
int filtroTipoDos(void* servicio);
int filtroTipoTres(void* servicio);



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	LinkedList* this = (LinkedList*) malloc(sizeof(LinkedList));

	if(this != NULL)
	{
		this->size = 0;
		this->pFirstNode = NULL;
	}

	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	int size = -1;
	if(this != NULL)
	{
		size = this->size;
	}
	return size;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* buscar = NULL;
	int len = ll_len(this);
	if(this != NULL)
	{
		buscar = this->pFirstNode;

		if(nodeIndex >= 0 && nodeIndex < len)
		{
			int i;

			for(i = 0; i < nodeIndex; i++)
			{
				buscar = buscar->pNextNode;
			}
		}
		else
		{
			buscar = NULL;
		}
	}

    return buscar;

}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int retorno = -1;
	Node* nuevo;

	if(this != NULL)
	{
		int largo = ll_len(this);

		if(nodeIndex >= 0 && nodeIndex <= largo)
		{
			nuevo = (Node*) malloc(sizeof(Node));
			nuevo->pElement = pElement;
			nuevo->pNextNode = NULL;
			if(nuevo != NULL)
			{
				if(nodeIndex == 0)
				{
					nuevo->pNextNode = this->pFirstNode;
					this->pFirstNode = nuevo;
				}
				else
				{
					Node* anterior = getNode(this, nodeIndex-1);
					nuevo->pNextNode = anterior->pNextNode;
					anterior->pNextNode = nuevo;
				}
				this->size = largo+1;
				retorno = 0;
			}
		}
	}
	return retorno;

}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
	int retorno = -1;

	if(this!= NULL)
	{
		retorno = 0;
		int largo = ll_len(this);
		addNode(this, largo, pElement);
	}


    return retorno;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
	void* pElement = NULL;
	Node* nodeAux = NULL;

	if(this != NULL)
	{

		int largo = ll_len(this);
		if(index >= 0 && index < largo)
		{
			nodeAux = getNode(this, index);
			if(nodeAux != NULL)
			{
				pElement = nodeAux->pElement;
			}
		}
	}

    return pElement;

}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    int largo = ll_len(this);
    if(this != NULL && index >= 0 && index <= largo)
	{
		Node* cambio = getNode(this, index);
		if(cambio != NULL)
		{
			cambio->pElement = pElement;
			returnAux = 0;
		}
	}

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	int largo = ll_len(this);
    	Node* recibido;
    	Node* siguiente;
    	Node* anterior;

		if(index >= 0 && index < largo)
		{
			recibido = getNode(this, index);
			if(recibido != NULL)
			{
				siguiente = getNode(this, index+1);
				if(index == 0)
				{
					this->pFirstNode = siguiente;
				}
				else
				{
					anterior = getNode(this, index-1);
					if(anterior != NULL)
					{
						anterior->pNextNode = siguiente;
					}
				}
				this->size = largo -1;
				free(recibido);
				returnAux = 0;
			}
    	}

    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{

	int returnAux = -1;
	int flagReturn = -1;
	if(this != NULL)
	{
		flagReturn = 0;
		int largo = ll_len(this);
		for(int i = 0 ; i < largo ; i++)
		{
			returnAux = ll_remove(this, i);
			if(returnAux != 0)
			{
				flagReturn = -1;
			}
		}
	}


    return flagReturn;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	ll_clear(this);
    	this = NULL;

    	free(this);
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	Node* comparacion;
    	int largo = ll_len(this);
    	for(int i = 0; i < largo; i ++)
    	{
    		comparacion = getNode(this, i);
    		if(comparacion->pElement == pElement)
    		{
    			returnAux = i;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this!= NULL)
    {
    	int valor = ll_len(this);
    	if(valor == 0)
    	{
    		returnAux = 1;
    	}
    	else
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
	return addNode(this, index, pElement);
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
	int largo = ll_len(this);
	if(this != NULL && index >= 0 && index <= largo+1)
	{
		returnAux = ll_get(this, index);
		ll_remove(this, index);
	}

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = 0;

    	int comparar = ll_indexOf(this,pElement);

    	if(comparar != -1)
    	{
    		returnAux = 1;
    	}

    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int flag = 0;

    if(this != NULL && this2 != NULL)
    {
    	returnAux = 1;

    	int largo = ll_len(this2);
    	for(int i = 0; i < largo; i ++)
    	{
    		void* comparacion = ll_get(this2, i);
    		int comparar = ll_contains(this, comparacion);
    		if(comparar == 0)
    		{
    			flag = 1;
    		}

    	}
    	if(flag == 1)
    	{
    		returnAux = 0;
    	}

    }


    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;


    if(this!= NULL)
    {

    	int largo = ll_len(this);

    	if(from < largo && from >= 0 && to <= largo && from < to)
    	{
    		cloneArray = ll_newLinkedList();
    		for(; from < to; from++)
    		{
    			void* clon = ll_get(this, from);
    			ll_add(cloneArray, clon);
    		}
    	}

    }


    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this != NULL)
    {
    	cloneArray = ll_newLinkedList();
    	int total = ll_len(this);
    	cloneArray = ll_subList(this, 0, total);
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{

    int returnAux = -1;
    void* pElementUno;
    void* pElementDos;

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
    {
    	int largo = ll_len(this);
    	returnAux = 1;
    	for(int i = 0; i < largo -1; i ++)
    	{
    		for(int j = i+1; j < largo; j++)
    		{
    			pElementUno = ll_get(this, i);
    			pElementDos = ll_get(this, j);

    			int comparacion = pFunc(pElementUno, pElementDos);
    			if( (comparacion == 1 && order == 1) || (comparacion == -1 && order == 0))
    			{
    				ll_set(this, i, pElementDos);
    				ll_set(this, j, pElementUno);
    			}

    		}

    	}

    }

    return returnAux;
}

LinkedList* ll_map(LinkedList* this, void (*fn)(void* element))
{
    if( this != NULL && fn != NULL)
    {
    	int largo = ll_len(this);
        for(int i=0; i< largo ; i++)
        {
           fn(ll_get(this,i));
        }
    }
    return this;
}

LinkedList* ll_filter(LinkedList* this, int(*fn)(void*))
{

	LinkedList* listaFiltrada = NULL;
	int i, tam;
	void* eElemento=NULL;

	if(this!=NULL && fn !=NULL)
	{
		listaFiltrada= ll_newLinkedList();
		if(listaFiltrada != NULL)
		{
			tam = ll_len(this);
			for(i=0; i<tam;i++)
			{
				eElemento= ll_get(this,i);
				if(fn(eElemento))
				{
					ll_add(listaFiltrada, eElemento);
				}
			}
		}
	}

	return listaFiltrada;
}

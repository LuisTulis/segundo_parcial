/*
 *
 * Controller.h
 *
 *  Created on: 21 jun. 2022
 *      Author: Luis
 */


#include "../inc/LinkedList.h"

#ifndef CONTROLLER_H_


#define CONTROLLER_H_



#endif /* CONTROLLER_H_ */


int controller_loadFromText(LinkedList* pArrayListPassenger);
int controller_ListService(LinkedList* pArrayListPassenger);
int controller_sortService(LinkedList* pArrayListPassenger);
int controller_saveAsText(LinkedList* pArrayListPassenger);
int controller_TotalPrice(LinkedList* pArrayListService);
void controller_Filter(LinkedList* pArrayListService);

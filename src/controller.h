/*
 * controller.h
 *
 *  Created on: 23 jun. 2022
 *      Author: ungim
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadFromText(char *path, LinkedList *pArrayServicios);
int controller_ListServicio(LinkedList *pArrayServicios);
int controller_precioFinal(LinkedList *pArrayServicios);
int controller_filter(LinkedList *pArrayServicios);
int controller_sortdescripcion(LinkedList *pArrayServicios);
int controller_saveAsText(char *path, LinkedList *pArrayServicios);


#endif /* CONTROLLER_H_ */

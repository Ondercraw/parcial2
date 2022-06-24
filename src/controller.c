/*
 * controller.c
 *
 *  Created on: 23 jun. 2022
 *      Author: ungim
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "servicios.h"
#include "parser.h"
#include "inputs.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param pArrayServiciosLinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayServicios)
{
	int ret;

	FILE* pFile;

	if(path == NULL && pArrayServicios == NULL){

		ret = 0;
		return ret;
	}


	pFile = fopen(path, "r");

	ret = parser_ServicioFromText(pFile, pArrayServicios);


	fclose(pFile);

    return ret;
}


/** \brief Listar pasajeros
 *
 * \param pArrayServicios LinkedList*
 * \return int
 *
 */
int controller_ListServicio(LinkedList* pArrayServicios)
{
	Node* indice = pArrayServicios->pFirstNode;
	eServicio* leer;

	printf("\n ID: descripcion:  tipo:  precioUnitario: cantidad: totalServicio:\n");
	for (; indice != NULL; indice = indice->pNextNode) {
		leer = indice->pElement;
		listServicio(leer);
	}

	return 1;
}

int controller_precioFinal(LinkedList *pArrayServicios) {

	ll_map(pArrayServicios, Servicio_precioFinal);

	return 0;
}

int controller_saveAsText(char *path, LinkedList *pArraylistaServicios) {
	FILE *pFile;

	int retorno = 1;
	pFile = fopen(path, "w");
	if (pFile == NULL) {
		retorno = 0;
	}

	int id;
	char descripcion[30];
	char tipo[30];
	float precio;
	int cantidad;
	float precioTotal;

	Node *indice = pArraylistaServicios->pFirstNode;
	fprintf(pFile, "%s,%s,%s,%s,%s,%s\n", "id", "descripcion", "tipo", "precio",
			"cantidad", "precioTotal");

	for (; indice != NULL; indice = indice->pNextNode) {

		Servicio_getId(indice->pElement, &id);
		Servicio_getDescripcion(indice->pElement, descripcion);
		Servicio_getTipo(indice->pElement, tipo);
		Servicio_getPrecioUnitario(indice->pElement, &precio);
		Servicio_getCantidad(indice->pElement, &cantidad);
		Servicio_getTotalServicio(indice->pElement, &precioTotal);

		fprintf(pFile, "%d,%s,%s,%f,%d,%f\n", id, descripcion, tipo, precio,
				cantidad, precioTotal);

	}

	fclose(pFile);

	return retorno;

}


int controller_filter(LinkedList *pArrayServicios) {

	LinkedList *listaNueva;
	char path[30];
	int order;

	printf("Ingrese el tipo por el cual desea filtrar (1 (Minorista), 2 (Mayorista) o 3(Exportador) )\n");
	scanf("%d", &order);

	switch (order) {
		case 1:
			listaNueva = ll_filter(pArrayServicios, primerFilter);
			break;
		case 2:
			listaNueva = ll_filter(pArrayServicios, segundoFilter);
			break;
		case 3:
			listaNueva = ll_filter(pArrayServicios, tercerFilter);
			break;
	}

	controller_ListServicio(listaNueva);

	printf("Como desea llamar el archivo filtrado? (Recomendado: Especificar filtro usado)\n");
	fflush(stdin);
	gets(path);
	controller_saveAsText(path, listaNueva);

	return 0;
}

int controller_sortdescripcion(LinkedList *pArrayServicios) {
	int order;
	printf("ingrese un orden 0 - ascendente o 1 descendente");
	scanf("%d", &order);
	ll_sort(pArrayServicios, Servicio_descripcionComparados, order);

	return 0;
}



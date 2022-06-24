/*
 * parser.c
 *
 *  Created on: 23 jun. 2022
 *      Author: ungim
 */
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ctype.h"
#include "LinkedList.h"
#include "parser.h"
#include "servicios.h"


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_ServicioFromText(FILE* pFile , LinkedList* pArrayServicios)
{
	int r;
	int ret = 0;
	char id[50];
	char descripcion[50];
	char tipo[50];
	char precioUnitario[50];
	char cantidad[50];
	char totalServicio[50];

	eServicio* this;

	if(pFile == NULL){
		printf("El archivo no existe");
		exit(EXIT_FAILURE);
		}

	r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",id,descripcion,tipo,precioUnitario,cantidad,totalServicio);

	do{

	r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",id,descripcion,tipo,precioUnitario,cantidad,totalServicio);

		if(r==6){
			this = Servicio_newParametros(id,descripcion,tipo,precioUnitario,cantidad,totalServicio);
			ll_add(pArrayServicios, this);

			ret = 1;
		}

	}while(!feof(pFile));
	fclose(pFile);

    return ret;

}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

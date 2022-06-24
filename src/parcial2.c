/*
 ============================================================================
 Name        : parcial2.c
 Author      : thomas velazco
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================


se deberá realizar un programa que permita el análisis de dicho archivo y sea capaz de generar
nuevos archivos de salida de formato similar filtrados por varios criterios:
El programa contará con el siguiente menú:
	1) Cargar archivo: Se pedirá el nombre del archivo y se cargará en un linkedlist los elementos
	del mismo.
	2) Imprimir lista: Se imprimirá por pantalla la tabla con los datos de los servicios.
	3) Asignar totales: Se deberá hacer uso de la función map la cual recibirá el linkedlist y una
	función que asignará a cada servicio el total calculado de la siguiente forma: cantidad x
	totalServicio.
	4) Filtrar por tipo: Se deberá generar un archivo igual al original, pero donde solo aparezcan
	servicios del tipo seleccionado.
	5) Mostrar servicios: Se deberá mostrar por pantalla un listado de los servicios ordenados por
	descripción de manera ascendente.
	6) Guardar servicios: Se deberá guardar el listado del punto anterior en un archivo de texto.
	7) Salir.
Requerimientos del desarrollo. • Se deberá crear la entidad “eServicios” con todos sus
campos correspondientes. • se deberá utilizar la biblioteca linkedlist para almacenar los
servicios leídos del archivo. • se deberá agregar a la biblioteca la función “ll_filter ()” la cual
devolverá una nueva linkedlist que contenga alguno de los elementos de la lista original, según
algún criterio.

Detalle de la función “ll_filter ()” prototipo de la función:

linkedlist* ll_filter (linkedlist* this, int (*pFunc) (void* element))

la función “ll_filter” recibirá una lista y una función “pFunc”. se deberá iterar todos los
elementos de la lista y pasárselos a la función “pFunc”. la función “pFunc” devolverá 1 si ese
ítem se debe agregar a la lista resultado o 0 si no debe agregarse. la función “ll_filter” generará
la nueva lista resultado, agregará a la misma los ítems correspondientes y la devolverá.

Detalle de la función “ll_map ()” prototipo de la función:

linkedlist* ll_map (linkedlist* this, void*(*pFunc) (void* element))

la función “ll_map” recibirá una lista y una función “pFunc”. se deberán iterar todos los
elementos de la lista y pasárselos a la función “pFunc” que recibirá el elemento y le calculará el
campo totalServicio, el retorno de “pFunc” se agregará a la lista resultado. esta nueva lista será
devuelta por ll_map.
nota: el código deberá tener comentarios con la documentación de cada una de las funciones y
respetar las reglas de estilo de la cátedra.
nota bis: separar en distintas bibliotecas las entidades, parser y generador de informes.
Para la aprobación, se deberá realizar como mínimo el parseo del archivo, imprimir la lista, la
función ll_map o ll_filter y el guardado en el archivo de texto.

*/


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"


int main(void) {
	setbuf(stdout, NULL);

	int opcion = 0;
	int banderaTex = 0;
	int banderaGuaTex = 0;
	char path[20];

		LinkedList *listaServicio = ll_newLinkedList();

		do {
			printf("1. Cargar archivo\n"
					"2. Imprimir lista\n"
					"3. Asignar totales\n"
					"4. Filtrar por tipo\n"
					"5. Mostrar servicios\n"
					"6. Guardar servicios\n"
					"7. Salir\n\n"
					"Ingrese la opcion deseada: ");
			fflush(stdin);
			scanf("%d", &opcion);

			switch (opcion) {


			case 1:

				if (banderaGuaTex == 0) {
				banderaGuaTex = 1;

				printf("\n¿Que archivo desea abrir? \n"
						"Ingrese el nombre del archivo: \n");
				fflush(stdin);
				gets(path);
				controller_loadFromText(path, listaServicio);


				banderaTex = 1;
				}else{
					printf("los datos solo pueden ser cargados una vez\n");
				}

				break;

			case 2:
				if(banderaTex == 0){
					printf("Primero debe ingresar un archivo (opcion 1)");

				}else{

				controller_ListServicio(listaServicio);

				}
				break;

			case 3:

				if (banderaTex == 0) {

						printf("Primero debe ingresar un archivo (opcion 1)");

				} else {

				controller_precioFinal(listaServicio);

				}

				break;
			case 4:

				if (banderaTex == 0) {
					printf("Primero debe ingresar un archivo (opcion 1)");
				} else {
					controller_filter(listaServicio);
				}
				break;

			case 5:
				if (banderaTex == 0) {
					printf("Primero debe ingresar un archivo (opcion 1)");
				} else {
					controller_sortdescripcion(listaServicio);
					controller_ListServicio(listaServicio);
				}
				break;

			case 6:

				if (banderaTex == 0) {
					printf("Primero debe ingresar un archivo (opcion 1)");
				} else {
					printf("¿Que archivo desea Guardar? \n"
							"\n Ingrese el nombre del archivo: \n");
					fflush(stdin);
					gets(path);
					controller_saveAsText(path, listaServicio);
					banderaGuaTex = 1;
				}
				break;

			case 7:
				if (banderaGuaTex == 0) {

					printf("\n Guarde los datos antes de cerrar el programa \n");

				} else {
					printf("\nSaliendo del menu.\n");
				}
				break;

			default:
				printf("Opcion no valida\n");
				break;

			}


		}while (opcion != 7);

	return 0;
}

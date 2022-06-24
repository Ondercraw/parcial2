/*
 ============================================================================
 Name        : parcial2.c
 Author      : thomas velazco
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================


se deber� realizar un programa que permita el an�lisis de dicho archivo y sea capaz de generar
nuevos archivos de salida de formato similar filtrados por varios criterios:
El programa contar� con el siguiente men�:
	1) Cargar archivo: Se pedir� el nombre del archivo y se cargar� en un linkedlist los elementos
	del mismo.
	2) Imprimir lista: Se imprimir� por pantalla la tabla con los datos de los servicios.
	3) Asignar totales: Se deber� hacer uso de la funci�n map la cual recibir� el linkedlist y una
	funci�n que asignar� a cada servicio el total calculado de la siguiente forma: cantidad x
	totalServicio.
	4) Filtrar por tipo: Se deber� generar un archivo igual al original, pero donde solo aparezcan
	servicios del tipo seleccionado.
	5) Mostrar servicios: Se deber� mostrar por pantalla un listado de los servicios ordenados por
	descripci�n de manera ascendente.
	6) Guardar servicios: Se deber� guardar el listado del punto anterior en un archivo de texto.
	7) Salir.
Requerimientos del desarrollo. � Se deber� crear la entidad �eServicios� con todos sus
campos correspondientes. � se deber� utilizar la biblioteca linkedlist para almacenar los
servicios le�dos del archivo. � se deber� agregar a la biblioteca la funci�n �ll_filter ()� la cual
devolver� una nueva linkedlist que contenga alguno de los elementos de la lista original, seg�n
alg�n criterio.

Detalle de la funci�n �ll_filter ()� prototipo de la funci�n:

linkedlist* ll_filter (linkedlist* this, int (*pFunc) (void* element))

la funci�n �ll_filter� recibir� una lista y una funci�n �pFunc�. se deber� iterar todos los
elementos de la lista y pas�rselos a la funci�n �pFunc�. la funci�n �pFunc� devolver� 1 si ese
�tem se debe agregar a la lista resultado o 0 si no debe agregarse. la funci�n �ll_filter� generar�
la nueva lista resultado, agregar� a la misma los �tems correspondientes y la devolver�.

Detalle de la funci�n �ll_map ()� prototipo de la funci�n:

linkedlist* ll_map (linkedlist* this, void*(*pFunc) (void* element))

la funci�n �ll_map� recibir� una lista y una funci�n �pFunc�. se deber�n iterar todos los
elementos de la lista y pas�rselos a la funci�n �pFunc� que recibir� el elemento y le calcular� el
campo totalServicio, el retorno de �pFunc� se agregar� a la lista resultado. esta nueva lista ser�
devuelta por ll_map.
nota: el c�digo deber� tener comentarios con la documentaci�n de cada una de las funciones y
respetar las reglas de estilo de la c�tedra.
nota bis: separar en distintas bibliotecas las entidades, parser y generador de informes.
Para la aprobaci�n, se deber� realizar como m�nimo el parseo del archivo, imprimir la lista, la
funci�n ll_map o ll_filter y el guardado en el archivo de texto.

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

				printf("\n�Que archivo desea abrir? \n"
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
					printf("�Que archivo desea Guardar? \n"
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

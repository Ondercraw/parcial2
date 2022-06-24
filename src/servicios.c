/*
 * servicios.c
 *
 *  Created on: 23 jun. 2022
 *      Author: ungim
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "controller.h"
#include "servicios.h"

eServicio* Servicio_new()
{
	eServicio* nuevoServicio = NULL;
    nuevoServicio= (eServicio*) malloc(sizeof(eServicio));

    if(nuevoServicio != NULL)
    {
        nuevoServicio->id=0;
        strcpy(nuevoServicio->descripcion, " ");
        strcpy(nuevoServicio->tipo, " ");
        nuevoServicio->precioUnitario = 0;
        nuevoServicio->cantidad = 0;
        nuevoServicio->totalServicio=0;
    }

    return nuevoServicio;

}

eServicio* Servicio_newParametros(char* idStr,char* descripcionStr,char* tipoStr,char* precioUnitarioStr,char* cantidadStr,char* totalServicioStr){

	eServicio* this;

	int id;
	int tipo;
	float precioUnitario;
	int cantidad;
	float totalServicio;

	char tipoAux[50];


	this = Servicio_new();

	id = atoi(idStr);

	tipo = atoi(tipoStr);

	precioUnitario = atof(precioUnitarioStr);

	cantidad = atoi(cantidadStr);

	totalServicio = atof(totalServicioStr);

	switch(tipo){

	case 1:

		strcpy(tipoAux, "Minorista");

		break;

	case 2:

		strcpy(tipoAux, "Mayorista");
		break;
	case 3:

		strcpy(tipoAux, "Exportador");
	}

	if(this != NULL){

		Servicio_setId(this, id);
		Servicio_setDescripcion(this, descripcionStr);
		Servicio_setTipo(this, tipoAux);
		Servicio_setPrecioUnitario(this, precioUnitario);
		Servicio_setCantidad(this, cantidad);
		Servicio_setTotalServicio(this, totalServicio);



		}else{

			free(this);
			this = NULL;
		}
	return this;
}

int Servicio_setId(eServicio* this,int id){

	int retorno = 0;
	this->id = id;

		if (this->id != id) {

			retorno = 1;
		}

	return retorno;
}

int Servicio_getId(eServicio* this,int* id){

	int ret = -1;

	if(this != NULL && id != NULL){

	*id = this->id;

	ret = 1;
	}


	return ret;

}

int Servicio_setDescripcion(eServicio* this,char* descripcion){

	int ret = 0;

	if(this != NULL && descripcion != NULL){

	strcpy(this->descripcion, descripcion);

	ret = 1;
	}
	return ret;
}

int Servicio_getDescripcion(eServicio* this,char* descripcion){

	int ret = -1;

	if(this != NULL && descripcion != NULL){

	strcpy(descripcion,this->descripcion);

	ret = 1;
	}
	return ret;
}

int Servicio_setTipo(eServicio* this,char* tipo){

	int ret = 0;

	if(this != NULL && tipo != NULL){

	strcpy(this->tipo, tipo);

	ret = 1;
	}
	return ret;

}

int Servicio_getTipo(eServicio* this,char* tipo){

	int ret = -1;

	if(this != NULL && tipo != NULL){

	strcpy(tipo,this->tipo);

	ret = 1;
	}
	return ret;
}

int Servicio_setPrecioUnitario(eServicio* this,float precioUnitario){

	int retorno = 0;

	    this->precioUnitario= precioUnitario;
	    if (this->precioUnitario != precioUnitario) {

	        retorno = 1;
	    }
	    return retorno;
}

int Servicio_getPrecioUnitario(eServicio* this,float* precioUnitario){

	int ret = 0;

	if(this != NULL && precioUnitario != NULL){

	*precioUnitario = this->precioUnitario;

	ret = 1;
	}


	return ret;

}

int Servicio_setCantidad(eServicio* this,int cantidad){

	int retorno = 0;
	    this->cantidad = cantidad;
	    if (this->cantidad != cantidad) {

	        retorno = 1;
	    }
	    return retorno;
}

int Servicio_getCantidad(eServicio* this,int* cantidad){

	int ret = -1;

	if(this != NULL && cantidad != NULL){

	*cantidad = this->cantidad;

	ret = 1;
	}


	return ret;

}

int Servicio_setTotalServicio(eServicio* this,float totalServicio){

	int retorno = 0;
	    this->totalServicio = totalServicio;
	    if (this->totalServicio != totalServicio) {

	        retorno = 1;
	    }
	    return retorno;
}

int Servicio_getTotalServicio(eServicio* this,float* totalServicio){

	int ret = -1;

	if(this != NULL && totalServicio != NULL){

		*totalServicio = this->totalServicio;

		ret = 1;
	}
	return ret;
}



void listServicio(eServicio* this){

	printf("\n  %d   %s   %s   %.2f  %d  %.2f \n",this->id,this->descripcion,this->tipo,this->precioUnitario,this->cantidad,this->totalServicio);

}

int Servicio_precioFinal(void* Element) {

	eServicio *precioFinal;

	precioFinal = Element;

	float precioAPasar;


	precioAPasar = precioFinal->precioUnitario * precioFinal->cantidad;

	Servicio_setTotalServicio(precioFinal, precioAPasar);

	return 0;

}

int primerFilter(void *servicio) {
	int ret = 0;
	eServicio* filtrando = servicio;

	if(strcmp(filtrando->tipo, "Minorista") == 0) {
		ret = 1;
	}
	return ret;
}

int segundoFilter(void *servicio) {
	int ret = 0;
	eServicio* filtrando = servicio;

	if(strcmp(filtrando->tipo, "Mayorista") == 0) {
		ret = 1;
	}
	return ret;
}
int tercerFilter(void *servicio) {
	int ret = 0;
	eServicio* filtrando = servicio;

	if(strcmp(filtrando->tipo, "Exportador") == 0) {
		ret = 1;
	}
	return ret;
}

int Servicio_descripcionComparados(void *descripcionA, void *descripcionB) {
	int ret;
	char descripcionAuxA[50];
	char descripcionAuxB[50];

	eServicio *a;
	eServicio *b;

	a = (eServicio*) descripcionA;
	b = (eServicio*) descripcionB;

	Servicio_getDescripcion(a, descripcionAuxA);
	Servicio_getDescripcion(b, descripcionAuxB);

	if (strcmp(descripcionAuxA, descripcionAuxB) == 0) {
		ret = 0;
	} else {
		if (strcmp(descripcionAuxA, descripcionAuxB) > 0) {
			ret = 1;
		} else {
			ret = -1;
		}
	}
	return ret;
}

/*
 * servicios.h
 *
 *  Created on: 23 jun. 2022
 *      Author: ungim
 */

#ifndef SERVICIOS_H_
#define SERVICIOS_H_

struct
{
	int id;
	char descripcion[50];
	char tipo[50];
	float precioUnitario;
	int cantidad;
	float totalServicio;

}typedef eServicio;

eServicio* Servicio_new();
eServicio* Servicio_newParametros(char* idStr,char* descripcionStr,char* tipoStr,char* precioUnitarioStr,char* cantidadStr,char* totalServicioStr);

int Servicio_setId(eServicio* this,int id);
int Servicio_getId(eServicio* this,int* id);

int Servicio_setDescripcion(eServicio* this,char* descripcion);
int Servicio_getDescripcion(eServicio* this,char* descripcion);

int Servicio_setTipo(eServicio* this,char* tipo);
int Servicio_getTipo(eServicio* this,char* tipo);

int Servicio_setPrecioUnitario(eServicio* this,float precioUnitario);
int Servicio_getPrecioUnitario(eServicio* this,float* precioUnitario);

int Servicio_setCantidad(eServicio* this,int cantidad);
int Servicio_getCantidad(eServicio* this,int* cantidad);

int Servicio_setTotalServicio(eServicio* this,float totalServicio);
int Servicio_getTotalServicio(eServicio* this,float* totalServicio);

int Servicio_compareByDescripcion(void* p1, void* p2);

void listServicio(eServicio* this);

int Servicio_precioFinal(void* Element);

int primerFilter(void *servicio);
int segundoFilter(void *servicio);
int tercerFilter(void *servicio);

int Servicio_descripcionComparados(void *descripcionA, void *descripcionB);




#endif /* SERVICIOS_H_ */

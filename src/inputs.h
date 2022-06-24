/*
 * inputs.h
 *
 *  Created on: 23 jun. 2022
 *      Author: ungim
 */

#ifndef INPUTS_H_
#define INPUTS_H_

void pedirEntero(int* variableRecibida, char textoAMostrar[]);
void pedirFlotante(float* variableRecibida, char textoAMostrar[]);
void pedirCadena(char arrayRecibido[], char textoAMostrar[]);
int utn_getNumeroEntero(int *pResultado, char *mensaje, char *mensajeError,
int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float *pResultado, char *mensaje, char *mensajeError,
int minimo, int maximo, int reintentos);
int cadenaValidada(char arrayRecibido[], char textoAMostrar[]);

#endif /* INPUTS_H_ */

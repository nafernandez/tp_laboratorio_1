/*
 ============================================================================
 Name        : tp1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"


int main(void) {

	int opcion;
	int numero1;
	int numero2;
	int suma;
	int resta;
	long long factorial;
	int multiplicacion;
	int division;
	int flagNumero1=0;
	int flagNumero2=0;

	do {
		printf(
				"\nElija una opcion:\n1.Elegir un numero.\n2.Elegir otro numero\n3.Calcular todas las operaciones.\n4.Informe de resultados.\n5. Salir\n");
		__fpurge(stdin);
		scanf("\n%d", &opcion);

		switch (opcion) {
		case 1:
			numero1 = utn_getNumero();
			flagNumero1=1;
			break;
		case 2:
			numero2 = utn_getNumero();
			flagNumero2=1;
			break;
		case 3:
				if(flagNumero1&&flagNumero2)
				{
					suma= utn_sumarNumeros(numero1, numero2);
					resta= utn_restarNumeros(numero1, numero2);
					multiplicacion= utn_multiplicacionNumeros(numero1, numero2);
					division= utn_divisionNumeros(numero1, numero2);
					factorial=utn_factorial(numero1, numero2);

				}else
				{
					printf("\nError, tiene que ingresar dos numeros\n");
				}

			break;
		case 4:
				printf("\n%d",suma);
				printf("\n%d",resta);
				printf("\n%d",multiplicacion);
				printf("\n%d",division);
				printf("\n%d", factorial);
				break;
		case 5:
			break;

		}

	} while (opcion != 5);

	return 0;
}

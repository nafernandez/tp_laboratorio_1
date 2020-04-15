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

#include "Biblioteca.h"


int main(void)

{
	setbuf(stdout, NULL);

	int opcion;
	int numero1;
	int numero2;
	int suma;
	int resta;
	int factorialNumero1;
	int factorialNumero2;
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
					division=utn_divisionNumeros(numero1, numero2);
					factorialNumero1=utn_factorial(numero1);
					factorialNumero2=utn_factorial(numero2);

				}else
				{
					printf("\nError, tiene que ingresar dos numeros\n");
				}

				printf("\nLa operacion ha sido completada con exito.");
			break;
		case 4:
				printf("\nEl resultado de A+B es: %d", suma);
				printf("\nEl resultado de A-B es: %d",resta);
				printf("\nEl resultado de A*B es: %d",multiplicacion);
				printf("\nEl resultado del factorial de A es: %d", factorialNumero1);
				printf("\nEl resultado del factorial de B es: %d", factorialNumero2);

				if(numero2==0)
				{
					printf("\nEl resultado de la division no pudo realizarse ya que no se puede dividir por 0");
				}else
				{
					printf("\nE resultado de A/B es: %d",division);
				}
				break;
		case 5:
			break;

		}

	} while (opcion != 5);

	return 0;
}

/*
 * utn.c
 *
 *  Created on: 11 abr. 2020
 *      Author: natalia
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int utn_getNumero(void)
{
	int numero;

	printf("Ingrese un numero");
	scanf("%d", &numero);

	return numero;
}

int utn_sumarNumeros(int numero1,int numero2)
{
	int suma;

	suma=numero1+numero2;

	return suma;
}

int utn_restarNumeros(int numero1, int numero2)
{
	int resta;

	resta= numero1-numero2;

	return resta;
}

int utn_multiplicacionNumeros(int numero1, int numero2)
{
	int multiplicacion;

	multiplicacion= numero1*numero2;

	return multiplicacion;
}

int utn_divisionNumeros(int numero1, int numero2)
{
	int division;

	division= numero1/numero2;

	return division;
}

long long utn_factorial(int numero1, int numero2)
{
	long long factorial=1;                             //// utilizo long long ya que el numero que ingresen puede ser muy grande para guardarlo en int


	for(int i=0;i>0;i--)                              ////la variable i la tomo como el numero que se ingresara en el main, por cada vuelta decrece i.
	{
		factorial=factorial*i;						 ////Se multiplica el factorial hasta que llegue a 1.
	}
	return factorial;								//// devuelve factorial cuando termina.
}

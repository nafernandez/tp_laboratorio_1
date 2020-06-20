/*
 ============================================================================
 Name        : FernandezHerenda-NataliaTp2.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Una empresa requiere un sistema para administrar su nómina de empleados. Se sabe que
dicha nómina bajo ninguna circunstancia superara los 1000 empleados.
Datos:
El sistema deberá tener el siguiente menú de opciones:
1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.

NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de algún empleado.

 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "arrayEmployees.h"
#include "utn.h"
#define QTY_EMPLOYEES 50
#define QTY_LETTERS 50


int main(void) {
	setbuf(stdin,NULL);

	Employee arrayEmployees[QTY_EMPLOYEES];
	int auxiliarIndice;
	int auxId;
	int inicializacionId=0;
	float auxSalary;
	int auxSector;
	int opcion=0;
	char auxName[QTY_LETTERS];
	char auxLastName[QTY_LETTERS];
	int flagDatos=0;
	int opcionInformes=0;
	int opcionSortEmployee=0;

	if(initEmployees(arrayEmployees, QTY_EMPLOYEES)==0)
		{
			printf("El sistema esta listo para ingresar nuevos empleados.\n");
		}
	do{
		if(!utn_getNumero(&opcion, "Ingrese la opcion a elegir:\n"
									"1. Alta de empleados\n"
									"2. Modificar datos de un empleado.\n"
									"3. Baja de empleado\n"
									"4. Para informes\n"
									"5. Para salir", "La opcion ingresada es incorrecta\n", 1, 5, 2))
		{
			switch(opcion)
			{
			case 1:
				printf("ALTA DE EMPLEADOS\n");
				flagDatos=1;
				auxiliarIndice=buscarPrimerPosicionVacia(arrayEmployees, QTY_EMPLOYEES);
				if(auxiliarIndice>=0)
				{
					if((utn_getNombre(auxName, QTY_LETTERS, "Ingrese el nombre", "Error, reingrese el nombre", 2)==0 &&
					   utn_getNombre(auxLastName, QTY_LETTERS, "Ingrese el apellido", "Error, reingrese el apellido", 2)==0) &&
					   (utn_getNumero(&auxSector, "Ingrese el numero de sector", "Error, reingrese el numero", 1, 20, 2)==0 &&
					   utn_getNumeroFlotante(&auxSalary, "Ingrese el salario","Reingrese el salario", 1000, 100000, 2)==0 ))
					{
						if(addEmployee(arrayEmployees, QTY_EMPLOYEES,auxiliarIndice, &inicializacionId, auxName, auxLastName, auxSalary, auxSector)==0)
						{
								printf("\nCarga realizada con exito\n");
						}
						else
						{
							printf("\nNO HAY MAS LUGAR");
						}
					break;
					}else
					{
						printf("No se puede ingresar a esta opcion sin antes haber cargado datos del empleado\n");
					}
			case 2:
				if (flagDatos)
				{
					printf("Ha elegido modificar datos de un empleado\n");
					showArrayEmployees(arrayEmployees,QTY_EMPLOYEES);
					if(utn_getNumero(&auxId, "\nIndique el ID a modificar: \n", "Error, reingrese el ID\n",0, QTY_EMPLOYEES, 2)==0)
					{
						auxiliarIndice=findEmployeeIndexById(arrayEmployees, QTY_EMPLOYEES, auxId);
					}
					if(	auxiliarIndice >-1 && modifyEmployee(arrayEmployees, QTY_EMPLOYEES, auxiliarIndice) == 0)
						{
							printf("\nModificacion realizada con exito\n");
						}
				}else
				{
					printf("No se puede ingresar a esta opcion sin antes haber cargado datos del empleado\n");
				}
				break;
			case 3:
				if (flagDatos)
				{
					printf("Ha elegido eliminar un empleado de la lista.\n");
					showArrayEmployees(arrayEmployees,QTY_EMPLOYEES);
					if(utn_getNumero(&auxId, "\nIndique el ID a eliminar: \n", "Error, reingrese el ID\n",0, QTY_EMPLOYEES, 2)==0)
					{
						auxiliarIndice=findEmployeeIndexById(arrayEmployees, QTY_EMPLOYEES, auxId);
					}
					if(	auxiliarIndice >-1 && deleteEmployee(arrayEmployees, QTY_EMPLOYEES, auxiliarIndice)==0)
					{
						printf("La eliminacion se ha realizado con exito.\n");
					}
				}else
				{
					printf("No se puede ingresar a esta opcion sin antes haber cargado datos del empleado\n");
				}
				break;
			case 4:
				//1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
				//2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.

				if(flagDatos)
					{
						if(!utn_getNumero(&opcionInformes, "Ingrese la opcion a elegir:\n"
															"1. Listado de empleados ordenados alfabeticamente por apellido y sector\n"
															"2. Total y promedio de los salarios(especificando cuantos empleados superan el salario promedio).\n", "La opcion ingresada es incorrecta\n", 1, 2, 2))
						{
							switch(opcionInformes)
							{
								case 1:
									printf("Ha elegido mostrar los empleados\n");
									if(!utn_getNumero(&opcionSortEmployee, "Ingrese la opcion a elegir:\n"
																		""
																		"0.Ordenados de forma descendente\n"
																		"1. Ordenados de forma ascendente", "La opcion ingresada es incorrecta\n", 0, 1, 2))
									{
										sortEmployees(arrayEmployees,QTY_EMPLOYEES, opcionSortEmployee);
										showArrayEmployees(arrayEmployees,QTY_EMPLOYEES);
									}
									break;
								case 2:
									printf("Ha elegido mostrar el total y promedio de salarios\n");
									showAverageSalaryAndAboveAverage(arrayEmployees,QTY_EMPLOYEES);
									break;
							}
						}
					}else
					{
						printf("No se puede ingresar a esta opcion sin antes haber cargado datos del empleado\n");
					}
				break;

			}
			}
		}


		}while(opcion!=5);
}









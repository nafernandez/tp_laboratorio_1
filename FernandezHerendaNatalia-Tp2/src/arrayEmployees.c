/*
 * arrayEmployees.c
 *
 *  Created on: 10 may. 2020
 *      Author: natalia
 */

#define QTY_EMPLOYEES 1000
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "arrayEmployees.h"
#include "utn.h"

int initEmployees(Employee* aEmployee, int len)
{
	int retorno= -1;
	int i;
	if(aEmployee!= NULL && len> 0)
	{
		retorno=0;
	}
	for(i=0; i < len; i++)
	{
		aEmployee[i].isEmpty= 1;
	}
	return retorno;
}

int findFirstPositionEmpty(Employee* aEmployee, int len)
{
	int respuesta= -1;
	int i;
	if(aEmployee!=NULL && len > 0)
		{
			respuesta=0;
		}
		for (i=0; i<len; i++)
		{
			if(aEmployee[i].isEmpty== 1)
			{
				respuesta=i;
				break;
			}
		}
	return respuesta;
}

int addEmployee(Employee* aEmployee, int len,int indice, int* id, char name [], char lastName[], float salary, int sector)
{
	Employee bufferEmployee;
	int respuesta=-1;

	if(aEmployee!=NULL&& len>0 && indice<len && id!=NULL && aEmployee[indice].isEmpty==1)
	{
		respuesta=0;

		{
			strcpy(bufferEmployee.lastName, lastName);
			strcpy(bufferEmployee.name, name);
			bufferEmployee.salary=salary;
			bufferEmployee.sector=sector;
			bufferEmployee.id=(*id)+1;
			bufferEmployee.isEmpty=0;
			aEmployee[indice]= bufferEmployee;
			(*id)++;
			respuesta = 0;

		}
	}
	return respuesta;
}

int modifyEmployee(Employee* aEmployee, int len, int indice)
{
		int respuesta = -1;
		Employee bufferEmployee;
		int opcion=0;
		showEmployee(aEmployee);
		if((aEmployee != NULL && len > 0) && (indice < len) && (indice >= 0) && (aEmployee[indice].isEmpty == 0))
		{
			respuesta = 0;
			bufferEmployee = aEmployee[indice];
			do{
				if(!utn_getNumero(&opcion, "Ingrese la opcion a elegir:\n"
												"1. Nombre\n"
												"2. Apellido\n"
												"3. Salario\n"
												"4. Sector\n"
												"5. Para salir", "La opcion ingresada es incorrecta\n", 1, 5, 2))
				{
					switch(opcion)
					{
						case 1:
							if(utn_getNombre(bufferEmployee.name,50,"\nNombre?\n","\nERROR\n",2) == 0)
							{
								printf("Nombre modificado con exito\n");
							}else
							{
								printf("No se ha podido modificar el nombre, intente nuevamente\n");
							}
						break;
						case 2:
							if(utn_getNombre(bufferEmployee.lastName,50,"\nApellido?\n","\nERROR\n",2) == 0)
								{
									printf("Apellido modificado con exito\n");
								}else
								{
									printf("No se ha podido modificar el apellido, intente nuevamente\n");
								}
							break;
						case 3:
							if(utn_getNumero(&bufferEmployee.sector, "Numero de sector?", "Error, reingrese el numero", 1, 20, 2)==0)
							{
								printf("Sector modificado con exito\n");
							}else
							{
								printf("No se ha podido modificar el sector\n");
							}
						break;
						case 4:
							if(utn_getNumeroFlotante(&bufferEmployee.salary, "Ingrese el nuevo salario","Reingrese el salario", 1000, 100000, 2)==0)
							{
								printf("Salario modificado con exito\n");
							}else
							{
								printf("No se ha podido modificar el Salario\n");
							}
						break;
					}
				}
			}while(opcion!=5);
			aEmployee[indice] = bufferEmployee;
		}
		return respuesta;
}

int showEmployee(Employee* aEmployee)
{
	int retorno=-1;

		if(aEmployee != NULL && aEmployee->isEmpty == 0)
		{
			retorno=0;
			printf("\nID: %d\nNombre: %s\nApellido: %s\nSalario: %.2f\n Sector: %d\n",aEmployee->id, aEmployee->name, aEmployee->lastName,aEmployee->salary, aEmployee->sector);
		}
		return retorno;

}

int showArrayEmployees(Employee* aEmployee,int len)
{
	int respuesta = -1;
	int i;
	if(aEmployee != NULL && len > 0)
	{
		respuesta = 0;
		for(i=0;i<len;i++)
		{
			if(aEmployee[i].isEmpty==0)
			{
				showEmployee(&aEmployee[i]);
			}
		}
	}
	return respuesta;
}
int findEmployeeIndexById(Employee* aEmployee, int len, int id)
{
	int respuesta = -1;
	int i;
	if(aEmployee != NULL && len >= 0 && id >= 0)
	{
		respuesta = 0;
		for(i=0;i<len;i++)
		{
			if(aEmployee[i].id == id)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

int deleteEmployee(Employee* aEmployee, int len, int indice)
{
	int respuesta=-1;
	if(aEmployee != NULL && len > 0 && indice < len && indice >= 0 && aEmployee[indice].isEmpty == 0)
	{
		aEmployee[indice].isEmpty=1;
		respuesta=0;
	}
	return respuesta;
}

int sortEmployees(Employee* aEmployee,int len, int order)
{
	int respuesta = -1;
	int flagSwap;
	int i;
	Employee bufferEmployee;
	int auxiliarComparacion;
	if(aEmployee != NULL && len > 0)
	{
		if(order==0)
		{
			do
			{
				flagSwap = 0;
				for(i=0;i<len-1;i++)
				{
					if(aEmployee[i].isEmpty || aEmployee[i+1].isEmpty)
					{
						continue;
					}
					auxiliarComparacion = strncmp(aEmployee[i].lastName,aEmployee[i+1].lastName, 51);
					if(	 auxiliarComparacion > 0 ||
						(auxiliarComparacion == 0 && aEmployee[i].sector < aEmployee[i+1].sector) )
					{
						flagSwap = 1;
						bufferEmployee = aEmployee[i];
						aEmployee[i] = aEmployee[i+1];
						aEmployee[i+1]=bufferEmployee;
					}
				}
				len--;
			}while(flagSwap);
		}else
		{
			if(order==1)
			{
				for(i=0;i<len-1;i++)
				{
					if(aEmployee[i].isEmpty==0 || aEmployee[i+1].isEmpty==0)
					{
						continue;
					}
					auxiliarComparacion = strncmp(aEmployee[i].name,aEmployee[i+1].name, 51);
					if(	 auxiliarComparacion < 0 ||
						(auxiliarComparacion == 0 && aEmployee[i].sector > aEmployee[i+1].sector) )
					{
						flagSwap = 1;
						bufferEmployee = aEmployee[i];
						aEmployee[i] = aEmployee[i+1];
						aEmployee[i+1]=bufferEmployee;
					}
				}
				len--;
			}
		}
	}
	return respuesta;
}

int showAverageSalaryAndAboveAverage(Employee* aEmployee, int len)
{
	int respuesta=-1;
	float promedio;
	int acumuladorSalarios=0;
	int i;
	int contadorMayoresDelPromedio=0;

	if(aEmployee != NULL && len>=0)
	{
		for(i=0;i<len &&  aEmployee[i].isEmpty==0; i++)
		{
			acumuladorSalarios=acumuladorSalarios+aEmployee[i].salary;
		}
		promedio=acumuladorSalarios/i;
		printf("\nMonto total de los sueldos: %d\n", acumuladorSalarios);
		printf("\nPromedio total de los sueldos: %.2f\n", promedio);
		respuesta=0;
		for(i=0;i<len &&  aEmployee[i].isEmpty==0; i++)
		{
			if(promedio<aEmployee[i].salary)
			{
				contadorMayoresDelPromedio++;
			}
		}

		printf("\nLa cantidad de empleados que superan el salario promedio es de: %d\n", contadorMayoresDelPromedio);
	}
	return respuesta;
}

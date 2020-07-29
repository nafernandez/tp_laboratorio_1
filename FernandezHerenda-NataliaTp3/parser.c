#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee)
{
	int ret = -1;
	char nombre[128];
	char horasTrabajadas[128];
	char id[128];
	char sueldo[128];
	int i = 0;
	Employee *pEmpleado;

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas,sueldo);
	do
	{
		if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo)==4) /// probar si hay q sacar comas o what
		{
			pEmpleado = employee_newParametros(id,nombre,horasTrabajadas, sueldo);
			i++;
			if(pEmpleado!=NULL && i !=0)
			{
				ll_add(pArrayListEmployee, (Employee*)pEmpleado);
				ret=0;
			}
		}
		else
		{
			break;
		}

	}while(feof(pFile)==0);
return ret;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee)
{
	int retorno=-1;
	Employee pEmpleado;
	Employee* auxiliarEmpleado;
	int empty=1;
	do{
		empty= fread(&pEmpleado,sizeof(Employee),1,pFile);
		if(empty==1)
		{
			auxiliarEmpleado= employee_newParametrosBinario(pEmpleado.id,pEmpleado.nombre,pEmpleado.horasTrabajadas, pEmpleado.sueldo);
			ll_add(pArrayListEmployee, (Employee*)auxiliarEmpleado);
			retorno=0;
		}

	}while(feof(pFile)==0);


	return retorno;
}

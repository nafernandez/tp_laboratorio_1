


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Employee.h"
#define NOMBRE_LEN 50

static int isValidNombre(char* cadena,int longitud);

static int isValidNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 *
 */


Employee* employee_new(void)
{
	Employee* auxiliarPuntero = NULL;
	auxiliarPuntero = (Employee*) malloc(sizeof(Employee));
	return auxiliarPuntero;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* this = NULL;
	this = employee_new();
	if(this!=NULL)
	{
		this->horasTrabajadas=atoi(horasTrabajadasStr);
		this->id=atoi(idStr);
		strncpy(this->nombre,nombreStr,128);
		this->sueldo=atof(sueldoStr);
	}else
	{
		employee_delete(this);
		this=NULL;
	}
	return this;
}


void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		if(isValidNombre(nombre,NOMBRE_LEN))
		{
			retorno = 0;
			strncpy(this->nombre,nombre,NOMBRE_LEN);
		}
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strncpy(nombre,this->nombre,NOMBRE_LEN);
	}
	return retorno;
}



int employee_setId(Employee* this,int id)
{
	int retorno = -1;
	if(this != NULL && id > 0)
	{
		retorno = 0;
		this->id = id;
	}
	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = 0;
		*horasTrabajadas = this->horasTrabajadas;
	}
	return retorno;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas > 0)
	{
		retorno = 0;
		this->horasTrabajadas = horasTrabajadas;
	}
	return retorno;
}

float employee_setSueldo(Employee* this,float sueldo)
{
	float retorno = -1;
	if(this != NULL && sueldo >= 0)
	{
		retorno = 0;
		this->sueldo = sueldo;
	}
	return retorno;
}
float employee_getSueldo(Employee* this,float* sueldo)
{
	float retorno = -1;
	if(this != NULL)
	{
		retorno = 0;
		*sueldo = this->sueldo;
	}
	return retorno;
}

Employee* employee_newParametrosBinario(int id,char* nombreStr,int horasTrabajadas, float sueldo)
{
	Employee* this = NULL;
	this = employee_new();
	if(this!=NULL)
	{
		this->id=id;
		strncpy(this->nombre,nombreStr,128);
		this->horasTrabajadas=horasTrabajadas;
		this->sueldo=sueldo;

	}else
	{
		employee_delete(this);
		this=NULL;
	}
	return this;
}
int imprimirEmpleado(Employee* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		printf("%d %s %d $%.2f\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
		retorno = 0;
	}
	return retorno;
}

int employee_OrdenamientoPorNombre(void* this1, void* this2)
{
	char nombre1[123];
	char nombre2[123];
	employee_getNombre((Employee*)this1, nombre1);
	employee_getNombre((Employee*)this2, nombre2);
	if(this1!=NULL && this2!=NULL)
	{
		return strcmp(nombre1, nombre2);
	}
	return 0;
}

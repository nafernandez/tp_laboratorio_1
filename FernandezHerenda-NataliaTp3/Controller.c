#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "utn.h"
#define CANT_NOMBRE 50


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	fflush(stdin);
	int retorno= 0;
	FILE* pFile=NULL;
	if(pArrayListEmployee!=NULL && path!=NULL)
	{
		pFile = fopen(path,"r");
		if(pFile !=NULL)
		{
			retorno= parser_EmployeeFromText(pFile,pArrayListEmployee);

			if(retorno==0)
			{
				printf("Se leyo\n");
			}else
			{
				printf("Error, no se llego a leer completo\n");
				fclose(pFile);
			}
		}else
		{
			printf("el archivo no pudo ser leido.\n");
		}

	}
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	fflush(stdin);
		int retorno= 0;
		FILE* pFile=NULL;
		if(pArrayListEmployee!=NULL && path!=NULL)
		{
			pFile = fopen(path,"rb");
			if(pFile !=NULL)
			{
				retorno= parser_EmployeeFromBinary(pFile,pArrayListEmployee);

				if(retorno==0)
				{
					printf("Se leyo\n");
				}else
				{
					printf("Error, no se llego a leer completo\n");
				}
			}else
			{
				printf("el archivo no pudo ser leido.\n");
			}

		}
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno= -1;
	char auxNombre[128];
	int auxHoras;
	int auxSalario;
	int auxId=ll_len(pArrayListEmployee)+1;
	Employee* auxEmpleado= employee_new();
	if(!ll_len(pArrayListEmployee))
	{
		printf("No hay datos todavia cargados\n");
	}else if(pArrayListEmployee!=NULL)
	{
		if(auxEmpleado!=NULL)
		{
			if(!utn_getNombre(auxNombre, CANT_NOMBRE,"Ingrese el nombre", "Error, reingrese", 2) &&
			   !utn_getNumero(&auxHoras, "Ingrese la cant de horas\n", "Error", 1, 300, 2)&&
			   !utn_getNumero(&auxSalario,"Ingrese el salario\n", "Error, reingrese", 500, 100000, 2))
			{
				if(!employee_setId(auxEmpleado,auxId) &&
				   !employee_setNombre(auxEmpleado,auxNombre) &&
				   !employee_setHorasTrabajadas(auxEmpleado,auxHoras) &&
				   !employee_setSueldo(auxEmpleado,auxSalario))
				{
					ll_add(pArrayListEmployee,auxEmpleado);
					retorno=0;
				}
			}
		}
	}
		return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int id;
	int opcion;
	char nombre[128];
	int horas;
	int salario;
	int i;
	Employee* auxEmployee;

	if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0)
	{
		if(!utn_getNumero(&id, "Ingrese el ID a modificar\n", "Error", 1, 5000, 2) && id<=ll_len(pArrayListEmployee))
		{
			for(i=0;id<ll_len(pArrayListEmployee); i++)
			{
				auxEmployee= (Employee*)ll_get(pArrayListEmployee,i);
				if(auxEmployee->id==id)
				{
					imprimirEmpleado(auxEmployee);
					break;
				}
			}

				while(opcion!=4)
				{
					if(!utn_getNumero(&opcion, "que desea modificar?\n"
															"1. Nombre\n"
															"2. Salario\n"
															"3. Horas\n"
															"4. Salir \n", "Error", 1, 4, 2))
					{
						switch(opcion)
						{
							case 1:
								if(!utn_getNombre(nombre, CANT_NOMBRE,"Ingrese el nombre", "Error, reingrese", 2))
								{
									employee_setNombre(auxEmployee,nombre);
									printf("Se ha cambiado el nombre con exito\n");
								}
								break;
							case 2:
								if(!utn_getNumero(&horas, "Ingrese la cant de horas\n", "Error", 1, 300, 2))
								{
									employee_setHorasTrabajadas(auxEmployee,horas);
									printf("Se ha modificado la cantidad de horas con exito\n");
								}
								break;
							case 3:
								if(!utn_getNumero(&salario,"Ingrese el salario\n", "Error, reingrese", 500, 100000, 2))
								{
									employee_setSueldo(auxEmployee,salario);
									printf("Se ha modificado el salario\n");
								}
								break;
							}
					}
					retorno=0;
				}
			}

		}
	    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int id;
	Employee* auxEmployee;
	int i;
	if(pArrayListEmployee!=NULL)
	{
		if(!utn_getNumero(&id, "Ingrese el ID a eliminar\n", "Error", 1, 3000, 2)&& id <=ll_len(pArrayListEmployee) )
		{
			for(i = 0; i< ll_len(pArrayListEmployee);i++)
			{
				auxEmployee = (Employee*)ll_get(pArrayListEmployee,i);
				if(auxEmployee->id == id)
				{
					ll_remove(pArrayListEmployee,i);
					retorno = 0;
				}else
				{
					printf("No se ha encontrado el ID\n");
				}
			}
		}
	}
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	Employee* auxiliarEmployee;
	int i;
	int retorno = -1;
	printf("ID-NOMBRE-HORAS TRABAJADAS-SUELDO\n");
	for(i = 0; i< ll_len(pArrayListEmployee);i++)
	{
		auxiliarEmployee = (Employee*)ll_get(pArrayListEmployee,i);
		if(auxiliarEmployee != NULL)
		{
			imprimirEmpleado(auxiliarEmployee);
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int OpcionOrdenamiento=0;
	if(pArrayListEmployee!=NULL)
	{
			if(!utn_getNumero(&OpcionOrdenamiento, "Ingrese la opcion de ordenamiento\n"
													"1. Ascendente\n"
													"2.Descendente\n"
													"3.Salir.\n", "Error opcion incorrecta", 1, 3, 2))
			{
				switch(OpcionOrdenamiento)
				{
					case 1:
						ll_sort(pArrayListEmployee,employee_OrdenamientoPorNombre,1);
						break;
					case 2:
						ll_sort(pArrayListEmployee,employee_OrdenamientoPorNombre,0);
						break;
				}
			}
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE* nuevoArchivo;
	int i;
	Employee* auxiliarEmployee;
	char nombre[128];
	float salario;
	int horas;
	int id;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		nuevoArchivo = fopen(path,"w+");
		for(i=0; i<ll_len(pArrayListEmployee); i++)
		{
			auxiliarEmployee=(Employee*)ll_get(pArrayListEmployee,i);
			employee_getId(auxiliarEmployee,&id);
			employee_getNombre(auxiliarEmployee,nombre);
			employee_getHorasTrabajadas(auxiliarEmployee,&horas);
			employee_getSueldo(auxiliarEmployee,&salario);
			fprintf(nuevoArchivo,"%d,%s,%d,%.2f\n",id,nombre,horas,salario);
			retorno =0;
		}
		fclose(nuevoArchivo);
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int i;
    Employee* auxiliarEmployee;
    FILE* nuevoArchivo;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
    	nuevoArchivo=fopen(path, "w+b");
    	for(i=0; i<ll_len(pArrayListEmployee); i++)
    	{
    		auxiliarEmployee=(Employee*)ll_get(pArrayListEmployee,i);
    		fwrite(auxiliarEmployee,sizeof(Employee),1,nuevoArchivo);
    		retorno=0;
    	}
    	fclose(nuevoArchivo);
    }
    return retorno;
}


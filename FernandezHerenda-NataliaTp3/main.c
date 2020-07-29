#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
	int opcion=0;

	LinkedList* listaEmpleados = ll_newLinkedList();
	do
		{
			if(!utn_getNumero(&opcion,  "Ingrese la opcion a elegir:\n"
										"1. Carga de datos de empleados en modo texto.\n"
										"2. Carga de datos de empleados en modo binario.\n"
										"3. Alta de empleado.\n"
										"4. Modificar datos de empleado.\n"
										"5. Baja de empleado.\n"
										"6. Listar empleados. \n"
										"7. Ordenar empleados.\n"
										"8. Guardar los datos en modo texto.\n"
										"9. Guardar los datos en modo binario.\n"
										"10. Salir\n", "La opcion ingresada es incorrecta\n", 1, 10, 2))
			switch(opcion)
			{
				case 1:
					controller_loadFromText("data.csv",listaEmpleados);
					break;
				case 2:
					controller_loadFromBinary("data.csv",listaEmpleados);
					break;
				case 3:
					if(!controller_addEmployee(listaEmpleados))
					{
						printf("Se ha dado de alta al empleado\n");
					}
					break;
				case 4:
					if(!controller_editEmployee(listaEmpleados))
					{
						printf("Modificacion realizada con exito\n");
					}
					break;
				case 5:
					if(!controller_removeEmployee(listaEmpleados))
					{
						printf("Se removio con exito\n");
					}
					break;
				case 6:
					if(controller_ListEmployee(listaEmpleados)!=0)
					{
						printf("No se pudieron imprimir los empleados\n");
					}
					break;
				case 7:
					controller_sortEmployee(listaEmpleados);
					break;
				case 8:
					if(controller_saveAsText("archivoText.csv" , listaEmpleados)==0)
					{
						printf("Se ha guardado con exito\n");
					}else
					{
						printf("No se pudo guardar\n");
					}
					break;
				case 9:
					if(controller_saveAsBinary("archivo.bin",listaEmpleados)==0)
					{
						printf("se ha guardado con exito\n");
					}else
					{
						printf("No se pudo guardar\n");
					}
					break;
		}
		}while(opcion!=10);
		return 0;
}


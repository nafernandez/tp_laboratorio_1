/*
 * arrayEmployees.h
 *
 *  Created on: 10 may. 2020
 *      Author: natalia
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;

int initEmployees(Employee* list, int len);
int addEmployee(Employee* aEmployee, int len,int indice, int* id, char name [], char lastName[], float salary, int sector);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);
int findEmployeeIndexById(Employee* aEmployee, int len, int id);
int showArrayEmployees(Employee* aEmployee,int len);
int showEmployee(Employee* aEmployee);
int deleteEmployee(Employee* aEmployee, int len, int indice);
int sortEmployees(Employee* aEmployee,int len, int order);
int buscarPrimerPosicionVacia(Employee* aEmployee, int len);
int modifyEmployee(Employee* aEmployee, int len, int indice);
int showAverageSalaryAndAboveAverage(Employee* aEmployee, int len);

#endif /* ARRAYEMPLOYEES_H_ */

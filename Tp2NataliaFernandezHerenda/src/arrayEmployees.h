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
/** \brief To indicate that all position in the array are empty,
*
this function put the flag (isEmpty) in TRUE in all
*
position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

int addEmployee(Employee* aEmployee, int len,int indice, int* id, char name [], char lastName[], float salary, int sector);
/** \brief add in a existing list of employees the values received as parameters
*
in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int findEmployeeIndexById(Employee* aEmployee, int len, int id);
/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int deleteEmployee(Employee* list, int len, int id);
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int showArrayEmployees(Employee* aEmployee,int len);
/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int showEmployee(Employee* aEmployee);
/** \brief print the content of employee
*
* \param list Employee*
* \return int
*
*/
int sortEmployees(Employee* aEmployee,int len, int order);
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int findFirstPositionEmpty(Employee* aEmployee, int len);
/** \brief Find first position empty in the array Employee
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

int modifyEmployee(Employee* aEmployee, int len, int indice);
/** \brief Modify data of an Employee
*
* \param list Employee*
* \param len int
* \param indice int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/

int showAverageSalaryAndAboveAverage(Employee* aEmployee, int len);

/** \brief prints average wages and employees above average
*
* \param list Employee*
* \param len int
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/

#endif /* UTN_H_ */

/*
 * utn.h
 *
 *  Created on: 11 abr. 2020
 *      Author: natalia
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(void);
/* @brief	Pide al usuario ingresar numeros.
* @param	De parametro ingreso un void ya que no le estoy dando ningun parametro, sino que estoy pidiendo un dato.
* @return	Retorna un numero entero.*/

int utn_sumarNumeros(int numero1,int numero2);
/* @brief	Suma los numeros ingresados por el usuario.
* @param	En el primer parametro ingreso el numero correspondiente a "A".
* @param	En el segundo parametro ingreso el numero correspondiente a "B".
* @return	Retorna la suma de ambos numeros.*/

int utn_restarNumeros(int numero1, int numero2);
/* @brief	Resta los numeros ingresados por el usuario.
* @param	En el primer parametro ingreso el numero correspondiente a "A".
* @param	En el segundo parametro ingreso el numero correspondiente a "B".
* @return	Retorna el resultado de la resta.*/

int utn_multiplicacionNumeros(int numero1, int numero2);
/* @brief	Multiplica los numeros ingresados por el usuario.
* @param	En el primer parametro ingreso el numero correspondiente a "A".
* @param	En el segundo parametro ingreso el numero correspondiente a "B".
* @return	Retorna el resultado de la multiplicacion.*/

int utn_divisionNumeros(int numero1, int numero2);
/* @brief	Divide los numeros ingresados por el usuario, coloco un if para que cuando el numero2 sea 0 no haga la division.
* @param	En el primer parametro ingreso el numero correspondiente a "A".
* @param	En el segundo parametro ingreso el numero correspondiente a "B".
* @return	Retorna el resultado de la division..*/

int utn_factorial(int numeroIngresado);
/* @brief	Nos permite obtener el resultado del factorial de un numero, utilizo for para igualar el contador al numero asi se cuantas veces tiene que dar
   la vuelta la iteracion, luego si el numero es mas grande que el contador aun, sigo y a medida que da vueltas, va decrementandose el contador.
* @param	En numeroIngresado, se completa con el numero que ingreso el usuario sea en el caso A o B.
* @return	Retorna el resultado del factorial de CADA numero.*/

#endif /* UTN_H_ */

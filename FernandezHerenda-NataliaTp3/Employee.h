#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

float employee_setSueldo(Employee* this,float sueldo);
float employee_getSueldo(Employee* this,float* sueldo);

Employee* employee_newParametrosBinario(int id,char* nombreStr,int horasTrabajadas, float sueldo);
int imprimirEmpleado(Employee* this);
int employee_OrdenamientoPorNombre(void* this1, void* this2);
#endif // employee_H_INCLUDED

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Cliente;

Cliente* employee_new();
Cliente* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);
void employee_delete(Cliente*);

int employee_setId(Cliente* this,int id);
int employee_getId(Cliente* this,int* id);

int employee_setNombre(Cliente* this,char* nombre);
int employee_getNombre(Cliente* this,char* nombre);

int employee_setHorasTrabajadas(Cliente* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Cliente* this,int* horasTrabajadas);

int employee_setSueldo(Cliente* this,int sueldo);
int employee_getSueldo(Cliente* this,int* sueldo);

#endif // employee_H_INCLUDED

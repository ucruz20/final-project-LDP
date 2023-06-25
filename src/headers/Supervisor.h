#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include "Empleado.h"

class Supervisor : public Empleado
{
public:
    Supervisor(const string &nombre, const string &apellido, const string &direccion,
               const string &fechaNacimiento, const string &sexo)
        : Empleado(nombre, apellido, direccion, fechaNacimiento, sexo)  {
        sueldo = 750.0;
        rol="Supervisor";
    }
    double calcularSalario() override;

    double calcularSalarioNeto(double salarioBruto);
};

#endif

#ifndef TECNICO_H
#define TECNICO_H

#include "Empleado.h"

class Tecnico : public Empleado
{
public:
    Tecnico(const string &nombre, const string &apellido, const string &direccion,
            const string &fechaNacimiento, const string &sexo)
        : Empleado(nombre, apellido, direccion, fechaNacimiento, sexo)  {
        sueldo = 350.0;
        rol="Tecnico";
    }

    double calcularSalario() override;

    double calcularSalarioNeto(double salarioBruto);
};

#endif

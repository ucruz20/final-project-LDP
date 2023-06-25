#ifndef GERENTE_H
#define GERENTE_H

#include "Empleado.h"

class Gerente : public Empleado
{
public:
    Gerente(const string &nombre, const string &apellido, const string &direccion,
            const string &fechaNacimiento, const string &sexo)
        : Empleado(nombre, apellido, direccion, fechaNacimiento, sexo)
    {
        sueldo = 5000;
        rol="Gerente";
    }

    double calcularSalario() override;

    double calcularSalarioNeto(double salarioBruto);
};

#endif

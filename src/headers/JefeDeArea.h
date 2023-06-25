#ifndef JEFEDEAREA_H
#define JEFEDEAREA_H

#include "Empleado.h"

class JefeDeArea : public Empleado
{
public:
    JefeDeArea(const string &nombre, const string &apellido, const string &direccion,
               const string &fechaNacimiento, const string &sexo)
        : Empleado(nombre, apellido, direccion, fechaNacimiento, sexo)
    {
        sueldo = 1500;
        rol = "Jefe de Area";
    }

    double calcularSalario() override;

    double calcularSalarioNeto(double salarioBruto);
};

#endif

#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
#include <string>

using namespace std;

class Empleado
{
protected:
    string nombre;
    string apellido;
    string direccion;
    string fechaNacimiento;
    string sexo;
    double sueldo;
    string rol;

public:
    Empleado(const string &nombre, const string &apellido, const string &direccion,
             const string &fechaNacimiento, const string &sexo, const int sueldo = 0.0, const string rol = "Empleado")
        : nombre(nombre), apellido(apellido), direccion(direccion),
          fechaNacimiento(fechaNacimiento), sexo(sexo), sueldo(sueldo), rol(rol) {}

    virtual double calcularSalario() = 0;
     double calcularSalarioNeto(double salario) const;

    string getNombre() const { return nombre; }
    string getApellido() const { return apellido; }
    string getDireccion() const { return direccion; }
    string getFechaNacimiento() const { return fechaNacimiento; }
    string getSexo() const { return sexo; }
    double getSueldo() const {return sueldo;}
    string getRol()const {return rol;}

    virtual ~Empleado() {}
};

#endif

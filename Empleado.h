#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
#include <string>

using namespace std;

class Empleado
{
protected:
    string nombre;
    string direccion;
    string fechaNacimiento;
    string sexo;
    string apellido;
    double salario;
    string rol;

public:
    Empleado(string &nombre, string &direccion, string &fechaNacimiento, string &sexo, string &apellido, double salario=0.0, string rol="")
        : nombre(nombre), direccion(direccion), fechaNacimiento(fechaNacimiento), sexo(sexo), apellido(apellido), salario(salario), rol(rol) {}

    virtual ~Empleado() {}

    virtual double calcularSalario();

    virtual string getJerarquia() = 0;

    string getNombre() const {
        return nombre;
    }

    string getDireccion() const {
        return direccion;
    }

    string getFechaNacimiento() const {
        return fechaNacimiento;
    }

    string getSexo() const {
        return sexo;
    }
    string getApellido() const{
        return apellido;
    }

    double getSueldo()const{
        return salario;
    }
    string getRol() const{
        return rol;
    }

};

class Gerente : public Empleado
{

public:
    Gerente(string &nombre, string &direccion, string &fechaNacimiento, string &sexo, string &apellido)
        : Empleado(nombre, direccion, fechaNacimiento, sexo, apellido) {
            salario = 500;
            rol="Gerente";
        }

    string getJerarquia() override {
        return "Gerente";
    }
};

class Tecnico : public Empleado
{
private:
    double sueldo;

public:
    Tecnico(string &nombre, string &direccion, string &fechaNacimiento, string &sexo, string &apellido)
        : Empleado(nombre, direccion, fechaNacimiento, sexo, apellido), sueldo(350.0) {}

    string getJerarquia() override {
        return "Técnico";
    }

};

class JefeDeArea : public Empleado
{
private:
    double sueldo;

public:
    JefeDeArea(string &nombre, string &direccion, string &fechaNacimiento, string &sexo, string &apellido)
        : Empleado(nombre, direccion, fechaNacimiento, sexo, apellido), sueldo(1500.0) {}

    string getJerarquia() override {
        return "Jefe de Área";
    }

};

class Supervisor : public Empleado
{
private:
    double sueldo;

public:
    Supervisor(string &nombre, string &direccion, string &fechaNacimiento, string &sexo, string &apellido)
        : Empleado(nombre, direccion, fechaNacimiento, sexo, apellido),  sueldo(750.0) {}

    string getJerarquia() override {
        return "Supervisor";
    }

};

#endif

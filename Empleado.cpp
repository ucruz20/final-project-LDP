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

public:
    Empleado(string &nombre, string &direccion, string &fechaNacimiento, string &sexo)
        : nombre(nombre), direccion(direccion), fechaNacimiento(fechaNacimiento), sexo(sexo) {}

    virtual ~Empleado() {}

    virtual double calcularSalario() = 0;

    virtual string getJerarquia() = 0;

};

class Gerente : public Empleado
{
private:
    double sueldo;

public:
    Gerente(string &nombre, string &direccion, string &fechaNacimiento, string &sexo)
        : Empleado(nombre, direccion, fechaNacimiento, sexo), sueldo(5000.0) {}

    double calcularSalario() override
    {
        // Realizar cálculos para el salario del gerente con descuentos
        return sueldo - (sueldo * 0.075) - (sueldo * 0.0775);
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
    Tecnico(string &nombre, string &direccion, string &fechaNacimiento, string &sexo)
        : Empleado(nombre, direccion, fechaNacimiento, sexo), sueldo(350.0) {}

    double calcularSalario() override
    {
        // Realizar cálculos para el salario del técnico con descuentos
        return sueldo - (sueldo * 0.075) - (sueldo * 0.0775);
    }


};

class JefeDeArea : public Empleado
{
private:
    double sueldo;

public:
    JefeDeArea(string &nombre, string &direccion, string &fechaNacimiento, string &sexo)
        : Empleado(nombre, direccion, fechaNacimiento, sexo), sueldo(1500.0) {}

    double calcularSalario() override
    {
        // Realizar cálculos para el salario del jefe de área con descuentos
        return sueldo - (sueldo * 0.075) - (sueldo * 0.0775);
    }

};

class Supervisor : public Empleado
{
private:
    double sueldo;

public:
    Supervisor(string &nombre, string &direccion, string &fechaNacimiento, string &sexo)
        : Empleado(nombre, direccion, fechaNacimiento, sexo), sueldo(750.0) {}

    double calcularSalario() override
    {
        // Realizar cálculos para el salario del supervisor con descuentos
        return sueldo - (sueldo * 0.075) - (sueldo * 0.0775);
    }

};

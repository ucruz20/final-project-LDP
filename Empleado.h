#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
#include <string>

class Empleado {
protected:
    std::string nombre;
    std::string direccion;
    std::string fechaNacimiento;
    std::string sexo;

public:
    Empleado(const std::string& nombre, const std::string& direccion, const std::string& fechaNacimiento, const std::string& sexo)
        : nombre(nombre), direccion(direccion), fechaNacimiento(fechaNacimiento), sexo(sexo) {}

    virtual ~Empleado() {}

    virtual double calcularSalario() const = 0;

};

class Gerente : public Empleado {
private:
    double sueldo;

public:
    Gerente(const std::string& nombre, const std::string& direccion, const std::string& fechaNacimiento, const std::string& sexo)
        : Empleado(nombre, direccion, fechaNacimiento, sexo), sueldo(5000.0) {}

    double calcularSalario() const {
        // Realizar cálculos para el salario del gerente con descuentos
        return sueldo - (sueldo * 0.075) - (sueldo * 0.0775);
    }

};

class Tecnico : public Empleado {
private:
    double sueldo;

public:
    Tecnico(const std::string& nombre, const std::string& direccion, const std::string& fechaNacimiento, const std::string& sexo)
        : Empleado(nombre, direccion, fechaNacimiento, sexo), sueldo(350.0) {}

    double calcularSalario() const {
        // Realizar cálculos para el salario del técnico con descuentos
        return sueldo - (sueldo * 0.075) - (sueldo * 0.0775);
    }


};

class JefeDeArea : public Empleado {
private:
    double sueldo;

public:
    JefeDeArea(const std::string& nombre, const std::string& direccion, const std::string& fechaNacimiento, const std::string& sexo)
        : Empleado(nombre, direccion, fechaNacimiento, sexo), sueldo(1500.0) {}

    double calcularSalario() const {
        // Realizar cálculos para el salario del jefe de área con descuentos
        return sueldo - (sueldo * 0.075) - (sueldo * 0.0775);
    }

};

class Supervisor : public Empleado {
private:
    double sueldo;

public:
    Supervisor(const std::string& nombre, const std::string& direccion, const std::string& fechaNacimiento, const std::string& sexo)
        : Empleado(nombre, direccion, fechaNacimiento, sexo), sueldo(750.0) {}

    double calcularSalario() const {
        // Realizar cálculos para el salario del supervisor con descuentos
        return sueldo - (sueldo * 0.075) - (sueldo * 0.0775);
    }

};

#endif

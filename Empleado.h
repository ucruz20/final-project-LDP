#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>

class Empleado {
public:
    Empleado(const std::string& nombre, int edad);

    void saludar() const;
    void esMayorDeEdad() const;

private:
    std::string nombre_;
    int edad_;
};

#endif

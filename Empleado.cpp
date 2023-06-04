#include "Empleado.h"
#include <iostream>

Empleado::Empleado(const std::string& nombre, int edad)
    : nombre_(nombre), edad_(edad) {}

void Empleado::saludar() const {
    std::cout << "¡Hola! Mi nombre es " << nombre_ << std::endl;
}

void Empleado::esMayorDeEdad() const {
    if (edad_ >= 18) {
        std::cout << nombre_ << " es mayor de edad." << std::endl;
    } else {
        std::cout << nombre_ << " no es mayor de edad." << std::endl;
    }
}

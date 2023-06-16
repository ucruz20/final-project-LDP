#include "Empleado.h"
#include <iostream>

int main() {
    // Crear instancias de diferentes subclases de Empleado
    Empleado* empleado1 = new Gerente("John Doe", "123 Main St", "01/01/1990", "Masculino");
    Empleado* empleado2 = new Tecnico("Jane Smith", "456 Elm St", "02/02/1995", "Femenino");
    Empleado* empleado3 = new JefeDeArea("Mike Johnson", "789 Oak St", "03/03/1985", "Masculino");
    Empleado* empleado4 = new Supervisor("Amy Davis", "987 Pine St", "04/04/1992", "Femenino");

    // Calcular y mostrar el salario de cada empleado
    std::cout << "Salario del gerente: $" << empleado1->calcularSalario() << std::endl;
    std::cout << "Salario del técnico: $" << empleado2->calcularSalario() << std::endl;
    std::cout << "Salario del jefe de área: $" << empleado3->calcularSalario() << std::endl;
    std::cout << "Salario del supervisor: $" << empleado4->calcularSalario() << std::endl;

    // Liberar la memoria asignada a los objetos empleados
    delete empleado1;
    delete empleado2;
    delete empleado3;
    delete empleado4;

    return 0;
}

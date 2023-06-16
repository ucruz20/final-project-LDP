#include "Empleado.h"
#include <algorithm>

using namespace std;

int main() {
    
    int opcion;
    do {
        cout << "----- MENÚ -----" << endl;
        cout << "1. Ordenar empleados por nombre" << endl;
        cout << "2. Ordenar empleados por salario" << endl;
        cout << "3. Mostrar cantidad de empleados por rol" << endl;
        cout << "4. Agregar nuevo empleado" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                //ordenarEmpleadosPorNombre(empleados);
                cout << "Empleados ordenados por nombre." << endl;
                break;
            case 2:
                // ordenarEmpleadosPorSalario(empleados);
                cout << "Empleados ordenados por salario." << endl;
                break;
            case 3:
                // mostrarCantidadEmpleadosPorRol(empleados);
                cout << "Empleados ordenados por Rol." << endl;
                break;
            case 4:
                // agregar Nuevo Empleado
                cout << "nuevo empleado agregado." << endl;
                break;
            case 0:
                cout << "¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
                break;
        }
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

        cout << endl;
    } while (opcion != 0);
    return 0;
}

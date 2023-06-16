#include <iostream>
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

        cout << endl;
    } while (opcion != 0);
    return 0;
}

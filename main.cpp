#include "Empleado.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void agregarEmpleadoAArchivo(const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo, std::ios::app); // Abrir el archivo en modo de escritura y agregar al final

    if (archivo.is_open()) {
        std::string cargo, nombre, apellido, direccion, fecha, sexo;
        std::cin.ignore(); // Limpiar el búfer del teclado

        // Solicitar los datos del nuevo empleado al usuario
        std::cout << "Ingrese el cargo del empleado: ";
        std::getline(std::cin, cargo);
        std::cout << "Ingrese el nombre del empleado: ";
        std::getline(std::cin, nombre);
        std::cout << "Ingrese el apellido del empleado: ";
        std::getline(std::cin, apellido);
        std::cout << "Ingrese la dirección del empleado: ";
        std::getline(std::cin, direccion);
        std::cout << "Ingrese la fecha de nacimiento del empleado (MM/DD/AA): ";
        std::getline(std::cin, fecha);
        std::cout << "Ingrese el sexo del empleado: ";
        std::getline(std::cin, sexo);

        // Escribir los datos del nuevo empleado en el archivo
        archivo << cargo << "," << nombre << "," << apellido << "," << direccion << "," << fecha << "," << sexo << std::endl;

        std::cout << "Empleado agregado exitosamente." << std::endl;
    } else {
        std::cout << "No se pudo abrir el archivo." << std::endl;
    }

    archivo.close(); // Cerrar el archivo
}
void mostrarCantidadObjetosPorSubclase(const std::vector<Empleado*>& empleados) {
                    int cantidadGerentes = 0;
                    int cantidadTecnicos = 0;
                    int cantidadJefesDeArea = 0;
                    int cantidadSupervisores = 0;

                    for (const auto& empleado : empleados) {
                        if (dynamic_cast<Gerente*>(empleado) != nullptr) {
                            cantidadGerentes++;
                        } else if (dynamic_cast<Tecnico*>(empleado) != nullptr) {
                            cantidadTecnicos++;
                        } else if (dynamic_cast<JefeDeArea*>(empleado) != nullptr) {
                            cantidadJefesDeArea++;
                        } else if (dynamic_cast<Supervisor*>(empleado) != nullptr) {
                            cantidadSupervisores++;
                        }
                    }

                    std::cout << "Cantidad de Gerentes: " << cantidadGerentes << std::endl;
                    std::cout << "Cantidad de Técnicos: " << cantidadTecnicos << std::endl;
                    std::cout << "Cantidad de Jefes de Área: " << cantidadJefesDeArea << std::endl;
                    std::cout << "Cantidad de Supervisores: " << cantidadSupervisores << std::endl;
                }

// Comparador para ordenar los empleados alfabéticamente por nombre
bool compararPorNombre(const Empleado* emp1, const Empleado* emp2) {
    return emp1->apellido < emp2->apellido;
}

// Función para crear objetos de empleados a partir de un archivo
std::vector<Empleado*> crearEmpleadosDesdeArchivo(const std::string& nombreArchivo) {
    std::vector<Empleado*> empleados;
    std::ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::istringstream iss(linea);
            std::string tipoEmpleado, nombre, apellido, direccion, fechaNacimiento, genero;
            if (std::getline(iss, tipoEmpleado, ',') && std::getline(iss, nombre, ',') && std::getline(iss, apellido, ',') && std::getline(iss, direccion, ',') &&
                std::getline(iss, fechaNacimiento, ',') && std::getline(iss, genero, ',')) {
                if (tipoEmpleado == "Gerente") {
                    empleados.push_back(new Gerente(nombre, apellido, direccion, fechaNacimiento, genero));
                } else if (tipoEmpleado == "Tecnico") {
                    empleados.push_back(new Tecnico(nombre, apellido, direccion, fechaNacimiento, genero));
                } else if (tipoEmpleado == "JefeDeArea") {
                    empleados.push_back(new JefeDeArea(nombre, apellido, direccion, fechaNacimiento, genero));
                } else if (tipoEmpleado == "Supervisor") {
                    empleados.push_back(new Supervisor(nombre, apellido, direccion, fechaNacimiento, genero));
                }
            }
        }
        archivo.close();

  // Ordenar los empleados alfabéticamente por nombre
        std::sort(empleados.begin(), empleados.end(), compararPorNombre);
    } else {
        std::cout << "No se pudo abrir el archivo." << std::endl;
    }
    return empleados;
}

int main() {
    int opcion,opcion2;
    
    // Crear objetos de empleados a partir del archivo "empleados.txt"
    std::vector<Empleado*> empleados = crearEmpleadosDesdeArchivo("empleados.txt");
   
    do {
        cout << "----- MENÚ -----" << endl;
        cout << "1. Ordenar empleados por nombre" << endl;
        cout << "2. Ordenar empleados por salario" << endl;
        cout << "3. Mostrar de empleados por rol" << endl;
        cout << "4. Agregar nuevo empleado" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: 
                // Imprimir los empleados ordenados alfabéticamente por nombre
                for (const auto& empleado : empleados) {
                std::cout << "Apellido: " << empleado->apellido << std::endl;
                std::cout << "Nombre: " << empleado->nombre << std::endl;
                std::cout << "Dirección: " << empleado->direccion << std::endl;
                std::cout << "Fecha de nacimiento: " << empleado->fechaNacimiento << std::endl;
                std::cout << "Género: " << empleado->sexo << std::endl;
                std::cout << std::endl;
                }
                break;
            case 2:
                // ordenarEmpleadosPorSalario(empleados);
                cout << "Empleados ordenados por salario." << endl;
                break;
            case 3:
                //Mostrar la cantidad de objetos por subclase
                mostrarCantidadObjetosPorSubclase(empleados);
                break;
            case 4:      
                agregarEmpleadoAArchivo("empleados.txt");
                cout << "Nuevo empleado agregado." << endl;
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

     // Liberar la memoria asignada a los objetos empleados
    for (const auto& empleado : empleados) {
        delete empleado;
    }

    return 0;
}

        //Empleado* empleado1 = new Gerente("John Doe", "123 Main St", "01/01/1990", "Masculino");
        //Empleado* empleado1 = new Gerente("John Doe", "123 Main St", "01/01/1990", "Masculino");
        //Empleado* empleado3 = new JefeDeArea("Mike Johnson", "789 Oak St", "03/03/1985", "Masculino");
        //Empleado* empleado4 = new Supervisor("Amy Davis", "987 Pine St", "04/04/1992", "Femenino");

        // Crear instancias de diferentes subclases de Empleado
       
        // Calcular y mostrar el salario de cada empleado
        //std::cout << "Salario del gerente: $" << empleado1->calcularSalario() << std::endl;
        //std::cout << "Salario del técnico: $" << empleado2->calcularSalario() << std::endl;
        //std::cout << "Salario del jefe de área: $" << empleado3->calcularSalario() << std::endl;
        //std::cout << "Salario del supervisor: $" << empleado4->calcularSalario() << std::endl;

        // Liberar la memoria asignada a los objetos empleados
        //delete empleado1;
        //delete empleado2;
        //delete empleado3;
        //delete empleado4;
        /*for (const auto& empleado : empleados) {
        if (auto gerente = dynamic_cast<Gerente*>(empleado)) {
        std::cout << "Gerente:" << std::endl;
        std::cout << "Nombre: " << gerente->nombre << std::endl;
        std::cout << "Apellido: " << gerente->apellido << std::endl;
        std::cout << "Dirección: " << gerente->direccion << std::endl;
        std::cout << "Fecha de nacimiento: " << gerente->fechaNacimiento << std::endl;
        std::cout << "Género: " << gerente->sexo << std::endl;
        std::cout << "--------------------------------" << std::endl;
        } else if (auto jefeDeArea = dynamic_cast<JefeDeArea*>(empleado)) {
        std::cout << "Jefe de Área:" << std::endl;
        std::cout << "Nombre: " << jefeDeArea->nombre << std::endl;
        std::cout << "Apellido: " << jefeDeArea->apellido << std::endl;
        std::cout << "Dirección: " << jefeDeArea->direccion << std::endl;
        std::cout << "Fecha de nacimiento: " << jefeDeArea->fechaNacimiento << std::endl;
        std::cout << "Género: " << jefeDeArea->sexo << std::endl;
        std::cout << "--------------------------------" << std::endl;
        } else if (auto tecnico = dynamic_cast<Tecnico*>(empleado)) {
        std::cout << "Técnico:" << std::endl;
        std::cout << "Nombre: " << tecnico->nombre << std::endl;
        std::cout << "Nombre: " << tecnico->apellido << std::endl;
        std::cout << "Dirección: " << tecnico->direccion << std::endl;
        std::cout << "Fecha de nacimiento: " << tecnico->fechaNacimiento << std::endl;
        std::cout << "Género: " << tecnico->sexo << std::endl;
        std::cout << "--------------------------------" << std::endl;
        } else if (auto supervisor = dynamic_cast<Supervisor*>(empleado)) {
        std::cout << "Supervisor:" << std::endl;
        std::cout << "Nombre: " << supervisor->nombre << std::endl;
        std::cout << "Nombre: " << supervisor->apellido << std::endl;
        std::cout << "Dirección: " << supervisor->direccion << std::endl;
        std::cout << "Fecha de nacimiento: " << supervisor->fechaNacimiento << std::endl;
        std::cout << "Género: " << supervisor->sexo << std::endl;
        std::cout << "--------------------------------" << std::endl;
        }
        }
        */
                
                

#include "src/headers/Empleado.h"
#include "src/headers/JefeDeArea.h"
#include "src/headers/Tecnico.h"
#include "src/headers/Supervisor.h"
#include "src/headers/Gerente.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void agregarEmpleadoAArchivo(const string &nombreArchivo)
{
    ofstream archivo(nombreArchivo, ios::app); // Abrir el archivo en modo de escritura y agregar al final

    if (archivo.is_open())
    {
        string cargo, nombre, apellido, direccion, fecha, sexo;
        cin.ignore(); // Limpiar el búfer del teclado

        // Solicitar los datos del nuevo empleado al usuario
        cout << "Ingrese el cargo del empleado: ";
        getline(cin, cargo);
        cout << "Ingrese el nombre del empleado: ";
        getline(cin, nombre);
        cout << "Ingrese el apellido del empleado: ";
        getline(cin, apellido);
        cout << "Ingrese la dirección del empleado: ";
        getline(cin, direccion);
        cout << "Ingrese la fecha de nacimiento del empleado (MM/DD/AA): ";
        getline(cin, fecha);
        cout << "Ingrese el sexo del empleado: ";
        getline(cin, sexo);

        // Escribir los datos del nuevo empleado en el archivo
        archivo << cargo << "," << nombre << "," << apellido << "," << direccion << "," << fecha << "," << sexo << endl;

        cout << "Empleado agregado exitosamente." << endl;
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }

    archivo.close(); // Cerrar el archivo
}
void mostrarCantidadObjetosPorSubclase(const vector<Empleado *> &empleados)
{
    int cantidadGerentes = 0;
    int cantidadTecnicos = 0;
    int cantidadJefesDeArea = 0;
    int cantidadSupervisores = 0;

    for (const auto &empleado : empleados)
    {
        if (dynamic_cast<Gerente *>(empleado) != nullptr)
        {
            cantidadGerentes++;
        }
        else if (dynamic_cast<Tecnico *>(empleado) != nullptr)
        {
            cantidadTecnicos++;
        }
        else if (dynamic_cast<JefeDeArea *>(empleado) != nullptr)
        {
            cantidadJefesDeArea++;
        }
        else if (dynamic_cast<Supervisor *>(empleado) != nullptr)
        {
            cantidadSupervisores++;
        }
    }

    cout << "Cantidad de Gerentes: " << cantidadGerentes << endl;
    cout << "Cantidad de Técnicos: " << cantidadTecnicos << endl;
    cout << "Cantidad de Jefes de Área: " << cantidadJefesDeArea << endl;
    cout << "Cantidad de Supervisores: " << cantidadSupervisores << endl;
    cout << "total de empleados: " << empleados.size(); 
}

// Comparador para ordenar los empleados alfabéticamente por nombre
bool compararPorNombre(const Empleado *emp1, const Empleado *emp2)
{
    return emp1->getApellido() < emp2->getApellido();
}

// Comparador para ordenar los empleados de mayor a menor por salario
bool compararPorSalario(Empleado *emp1, Empleado *emp2)
{
    return emp1->calcularSalario() > emp2->calcularSalario();
}
bool compararPorSalarioMenor(Empleado *emp1, Empleado *emp2)
{
    return emp1->calcularSalario() < emp2->calcularSalario();
}

// Función para ordenar los empleados por salario
void ordenarEmpleadosPorSalario(vector<Empleado *> &empleados)
{
    std::sort(empleados.begin(), empleados.end(), compararPorSalario);
}
void ordenarEmpleadosPorSalarioMenor(vector<Empleado *> &empleados)
{
    std::sort(empleados.begin(), empleados.end(), compararPorSalarioMenor);
}

// Función para crear objetos de empleados a partir de un archivo
vector<Empleado *> crearEmpleadosDesdeArchivo(const string &nombreArchivo)
{
    vector<Empleado *> empleados;
    ifstream archivo(nombreArchivo);
    if (archivo.is_open())
    {
        string linea;
        while (getline(archivo, linea))
        {
            istringstream iss(linea);
            string tipoEmpleado, nombre, apellido, direccion, fechaNacimiento, genero;
            if (getline(iss, tipoEmpleado, ',') && getline(iss, nombre, ',') && getline(iss, apellido, ',') && getline(iss, direccion, ',') &&
                getline(iss, fechaNacimiento, ',') && getline(iss, genero, ','))
            {
                if (tipoEmpleado == "Gerente")
                {
                    empleados.push_back(new Gerente(nombre, apellido, direccion, fechaNacimiento, genero));
                }
                else if (tipoEmpleado == "Tecnico")
                {
                    empleados.push_back(new Tecnico(nombre, apellido, direccion, fechaNacimiento, genero));
                }
                else if (tipoEmpleado == "JefeDeArea")
                {
                    empleados.push_back(new JefeDeArea(nombre, apellido, direccion, fechaNacimiento, genero));
                }
                else if (tipoEmpleado == "Supervisor")
                {
                    empleados.push_back(new Supervisor(nombre, apellido, direccion, fechaNacimiento, genero));
                }
            }
        }
        archivo.close();

        // Ordenar los empleados alfabéticamente por nombre
        sort(empleados.begin(), empleados.end(), compararPorNombre);
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
    return empleados;
}

int main()
{
    vector<Empleado *> empleados;
    int opcion;

    // Crear objetos de empleados a partir del archivo "empleados.txt"

    do
    {
        empleados = crearEmpleadosDesdeArchivo("empleados.txt");
        cout << "----- MENÚ -----" << endl;
        cout << "1. Ordenar empleados por primer apellido" << endl;
        cout << "2. Ordenar empleados por salario (mayor a menor)" << endl;
        cout << "3. Ordenar empleados por salario (menor a mayor)" << endl;
        cout << "4. Mostrar de empleados por rol" << endl;
        cout << "5. Agregar nuevo empleado" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            // Imprimir los empleados ordenados alfabéticamente por nombre
            for (const auto &empleado : empleados)
            {
                cout << "Apellido: " << empleado->getApellido() << endl;
                cout << "Nombre: " << empleado->getNombre() << endl;
                cout << "Dirección: " << empleado->getDireccion() << endl;
                cout << "Fecha de nacimiento: " << empleado->getFechaNacimiento() << endl;
                cout << "Género: " << empleado->getSexo() << endl;
                cout << "Salario base: " << empleado->getSueldo() << endl;
                cout << "Jerarquia: " << empleado->getRol() << endl;
                cout << endl;
            }
            break;
        case 2:
            // ordenarEmpleadosPorSalario(empleados);
            ordenarEmpleadosPorSalario(empleados);
            cout << "Empleados ordenados por salario:" << endl;
            for (const auto &empleado : empleados)
            {
                cout << "Apellido: " << empleado->getApellido() << endl;
                cout << "Nombre: " << empleado->getNombre() << endl;
                cout << "Dirección: " << empleado->getDireccion() << endl;
                cout << "Fecha de nacimiento: " << empleado->getFechaNacimiento() << endl;
                cout << "Género: " << empleado->getSexo() << endl;
                cout << "Salario base: " << empleado->getSueldo() << endl;
                cout << "Jerarquia: " << empleado->getRol() << endl;
                cout << "Salario neto: " << empleado->calcularSalario() << endl;
                cout << endl;
            }
            break;

        case 3:
            ordenarEmpleadosPorSalarioMenor(empleados);
            cout << "Empleados ordenados por salario:" << endl;
            for (const auto &empleado : empleados)
            {
                cout << "Apellido: " << empleado->getApellido() << endl;
                cout << "Nombre: " << empleado->getNombre() << endl;
                cout << "Dirección: " << empleado->getDireccion() << endl;
                cout << "Fecha de nacimiento: " << empleado->getFechaNacimiento() << endl;
                cout << "Género: " << empleado->getSexo() << endl;
                cout << "Salario base: " << empleado->getSueldo() << endl;
                cout << "Jerarquia: " << empleado->getRol() << endl;
                cout << "Salario neto: " << empleado->calcularSalario() << endl;
                cout << endl;
            }
            break;
        case 4:
            // Mostrar la cantidad de objetos por subclase
            mostrarCantidadObjetosPorSubclase(empleados);
            break;
        case 5:
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

    for (const auto &empleado : empleados)
    {
        delete empleado;
    }

    return 0;
}

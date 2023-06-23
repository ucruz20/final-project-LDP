#include "Empleado.h"
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
}

// Comparador para ordenar los empleados alfabéticamente por nombre
bool compararPorNombre(const Empleado *emp1, const Empleado *emp2)
{
    return emp1->getApellido() < emp2->getApellido();
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
    int opcion, opcion2;

    // Crear objetos de empleados a partir del archivo "empleados.txt"

    do
    {
        empleados = crearEmpleadosDesdeArchivo("empleados.txt");
        cout << "----- MENÚ -----" << endl;
        cout << "1. Ordenar empleados por nombre" << endl;
        cout << "2. Ordenar empleados por salario" << endl;
        cout << "3. Mostrar de empleados por rol" << endl;
        cout << "4. Agregar nuevo empleado" << endl;
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
            cout << "Empleados ordenados por salario." << endl;
            break;
        case 3:
            // Mostrar la cantidad de objetos por subclase
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
    
    for (const auto &empleado : empleados)
    {
        delete empleado;
    }

    return 0;
}

// Empleado* empleado1 = new Gerente("John Doe", "123 Main St", "01/01/1990", "Masculino");
// Empleado* empleado1 = new Gerente("John Doe", "123 Main St", "01/01/1990", "Masculino");
// Empleado* empleado3 = new JefeDeArea("Mike Johnson", "789 Oak St", "03/03/1985", "Masculino");
// Empleado* empleado4 = new Supervisor("Amy Davis", "987 Pine St", "04/04/1992", "Femenino");

// Crear instancias de diferentes subclases de Empleado

// Calcular y mostrar el salario de cada empleado
// cout << "Salario del gerente: $" << empleado1->calcularSalario() << endl;
// cout << "Salario del técnico: $" << empleado2->calcularSalario() << endl;
// cout << "Salario del jefe de área: $" << empleado3->calcularSalario() << endl;
// cout << "Salario del supervisor: $" << empleado4->calcularSalario() << endl;

// Liberar la memoria asignada a los objetos empleados
// delete empleado1;
// delete empleado2;
// delete empleado3;
// delete empleado4;
/*for (const auto& empleado : empleados) {
if (auto gerente = dynamic_cast<Gerente*>(empleado)) {
cout << "Gerente:" << endl;
cout << "Nombre: " << gerente->nombre << endl;
cout << "Apellido: " << gerente->apellido << endl;
cout << "Dirección: " << gerente->direccion << endl;
cout << "Fecha de nacimiento: " << gerente->fechaNacimiento << endl;
cout << "Género: " << gerente->sexo << endl;
cout << "--------------------------------" << endl;
} else if (auto jefeDeArea = dynamic_cast<JefeDeArea*>(empleado)) {
cout << "Jefe de Área:" << endl;
cout << "Nombre: " << jefeDeArea->nombre << endl;
cout << "Apellido: " << jefeDeArea->apellido << endl;
cout << "Dirección: " << jefeDeArea->direccion << endl;
cout << "Fecha de nacimiento: " << jefeDeArea->fechaNacimiento << endl;
cout << "Género: " << jefeDeArea->sexo << endl;
cout << "--------------------------------" << endl;
} else if (auto tecnico = dynamic_cast<Tecnico*>(empleado)) {
cout << "Técnico:" << endl;
cout << "Nombre: " << tecnico->nombre << endl;
cout << "Nombre: " << tecnico->apellido << endl;
cout << "Dirección: " << tecnico->direccion << endl;
cout << "Fecha de nacimiento: " << tecnico->fechaNacimiento << endl;
cout << "Género: " << tecnico->sexo << endl;
cout << "--------------------------------" << endl;
} else if (auto supervisor = dynamic_cast<Supervisor*>(empleado)) {
cout << "Supervisor:" << endl;
cout << "Nombre: " << supervisor->nombre << endl;
cout << "Nombre: " << supervisor->apellido << endl;
cout << "Dirección: " << supervisor->direccion << endl;
cout << "Fecha de nacimiento: " << supervisor->fechaNacimiento << endl;
cout << "Género: " << supervisor->sexo << endl;
cout << "--------------------------------" << endl;
}
}
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Empleado {
protected:
    string nombre;
    string apellido;
    string direccion;
    string fechaNacimiento;
    string sexo;

public:
    Empleado(const string& nombre, const string& apellido, const string& direccion,
             const string& fechaNacimiento, const string& sexo)
        : nombre(nombre), apellido(apellido), direccion(direccion),
          fechaNacimiento(fechaNacimiento), sexo(sexo) {}

    virtual double calcularSalario() = 0;

    string getNombre() const { return nombre; }
    string getApellido() const { return apellido; }
    string getDireccion() const { return direccion; }
    string getFechaNacimiento() const { return fechaNacimiento; }
    string getSexo() const { return sexo; }

    virtual string getJerarquia() = 0;

    virtual ~Empleado() {}
};

class Gerente : public Empleado {
public:
    Gerente(const string& nombre, const string& apellido, const string& direccion,
            const string& fechaNacimiento, const string& sexo)
        : Empleado(nombre, apellido, direccion, fechaNacimiento, sexo) {}

    double calcularSalario() override {
        // Realizar cálculos para el salario del gerente con descuentos
        double sueldo = 5000.0; // Ejemplo de sueldo base para un gerente
        double salarioBruto = sueldo;
        double salarioNeto = calcularSalarioNeto(salarioBruto);
        return salarioNeto;
    }

    string getJerarquia() override {
        return "Gerente";
    }

    double calcularSalarioNeto(double salarioBruto) {
        // Cálculos de descuentos, base imponible, impuesto sobre la renta, etc.
        // Aquí se deben realizar los cálculos reales para el salario neto del gerente.
        // Se incluye un ejemplo básico:
        double descuentoISSS = salarioBruto * 0.075;
        double descuentoAFP = salarioBruto * 0.0775;
        double salarioNeto = salarioBruto - descuentoISSS - descuentoAFP;
        return salarioNeto;
    }
};

class Tecnico : public Empleado {
public:
    Tecnico(const string& nombre, const string& apellido, const string& direccion,
            const string& fechaNacimiento, const string& sexo)
        : Empleado(nombre, apellido, direccion, fechaNacimiento, sexo) {}

    double calcularSalario() override {
        // Realizar cálculos para el salario del técnico con descuentos
        double sueldo = 2500.0; // Ejemplo de sueldo base para un técnico
        double salarioBruto = sueldo;
        double salarioNeto = calcularSalarioNeto(salarioBruto);
        return salarioNeto;
    }

    string getJerarquia() override {
        return "Técnico";
    }

    double calcularSalarioNeto(double salarioBruto) {
        // Cálculos de descuentos, base imponible, impuesto sobre la renta, etc.
        // Aquí se deben realizar los cálculos reales para el salario neto del técnico.
        // Se incluye un ejemplo básico:
        double descuentoISSS = salarioBruto * 0.075;
        double descuentoAFP = salarioBruto * 0.0775;
        double salarioNeto = salarioBruto - descuentoISSS - descuentoAFP;
        return salarioNeto;
    }
};

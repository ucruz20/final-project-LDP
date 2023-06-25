#include "../headers/Supervisor.h"

double Supervisor::calcularSalario() {
    double salarioBruto = sueldo;
    double salarioNeto = calcularSalarioNeto(salarioBruto);
    return salarioNeto;
}


double Supervisor::calcularSalarioNeto(double salarioBruto) {
    double descuentoISSS = salarioBruto * 0.075;
    double descuentoAFP = salarioBruto * 0.0775;
    double renta = 0.0;
    
    // Cálculo del descuento de renta según la tabla de tramos de renta en El Salvador
    if (salarioBruto >= 0.01 && salarioBruto <= 472.00) {
        renta = 0.0;
    } else if (salarioBruto >= 472.01 && salarioBruto <= 895.24) {
        renta = (salarioBruto - 472.00) * 0.10 + 17.67;
    } else if (salarioBruto >= 895.25 && salarioBruto <= 2038.10) {
        renta = (salarioBruto - 895.24) * 0.20 + 60.00;
    } else if (salarioBruto >= 2038.11) {
        renta = (salarioBruto - 2038.10) * 0.30 + 288.57;
    }
    
    double salarioNeto = salarioBruto - descuentoISSS - descuentoAFP - renta;
    return salarioNeto;
}

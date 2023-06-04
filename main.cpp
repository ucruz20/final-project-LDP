#include <iostream>
#include "Empleado.h"

using namespace std;

int main() {
    Empleado empleado("Juan", 25);

    empleado.saludar();
    empleado.esMayorDeEdad();

    return 0;
}

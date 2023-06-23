# final-project-LDP
# pasos para ejecutar el proyecto
1- Clonar el repositorio
# Ejecutar el siguiente comando para poder compilar el proyecto:
2-Ejecutar comando:
g++ -o proyectoEjecutable main.cpp src/class/JefeDeArea.cpp src/class/Supervisor.cpp src/class/Gerente.cpp src/class/Tecnico.cpp

3- en consola ejcutar el archivo ./ProyectoEjecutable

# si desea usar cmake seguir los siguientes pasos:
2- crear una carpeta llamada build en la carpeta raiz de este proyecto
3-Crear una copia del archivo empleados.txt y pegarla dentro de la carpeta build
3-dentro de la carpeta build ejecutar el siguiente comando: cmake ..
4- dentro de la misma carpeta ejecutar cmake --build .
5- Para ejecutar el archivo resultante, ./ProyectoEjecutable.

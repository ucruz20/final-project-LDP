# final-project-LDP

# Ejecutar el siguiente comando para poder compilar el proyecto:

g++ -o programa main.cpp src/class/JefeDeArea.cpp src/class/Supervisor.cpp src/class/Gerente.cpp src/class/Tecnico.cpp

# si desea usar cmake seguir los siguientes pasos:
1- Clonar el repositorio
2- crear una carpeta llamada build en la carpeta raiz de este proyecto
3-Crear una copia del archivo empleados.txt y pegarla dentro de la carpeta build
3-dentro de la carpeta build ejecutar el siguiente comando: cmake ..
4- dentro de la misma carpeta ejecutar cmake --build .
5- Para ejecutar el archivo resultante, ./ProyectoEjecutable.

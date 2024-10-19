# Simulador de Carrera de Autos en C++

## Descripción
Este proyecto es un simulador de una carrera de autos que utiliza hebras (threads) en C++. Cada automóvil corre en su propia hebra, avanzando de manera aleatoria y deteniéndose por periodos aleatorios de tiempo. La carrera concluye cuando todos los autos completan la distancia total.

## Requisitos
- C++11 o superior.
- Biblioteca de hebras (threads) estándar de C++.
- Sistema operativo Linux o Windows (con MinGW, WSL, etc.).
- Compilador g++ (en Linux o en MinGW para Windows).

### Compilación y Ejecución

** En Linux (o WSL en Windows)
1. Clona el repositorio o copia los archivos del proyecto.
2. Asegúrate de que tienes instalado el compilador `g++`:
   ```bash
   sudo apt update
   sudo apt install g++
3. Para compilar el programa se usa el comando make en terminal
4. Para ejecutar el programa, usa el siguiente comando, cambiando <largo_de_pista> y <cant_autos> por los valores deseados
	./carrera <largo_de_pista> <cant_autos>
	ejemplo:
	//si quiero que 3 autos tengan una carrera en 100 metros seria
	./carrera 100 3
5. Para limpiar los archivos generados se usa make clean

** En windows (usando MinGW o Visual Studio Code)
1. Instala MinGW y agrega g++ al PATH (consulta la documentación de MinGW para más detalles).
2. Abre una terminal y navega al directorio del proyecto.
3. Para compilar el programa, usa el siguiente comando en la terminal de MinGW:
	g++ -std=c++11 -pthread carrera.cpp -o carrera.exe
4. Se ejecuta el programa:
	//una carrera de 100 metros de 3 autos
	carrera.exe 100 3

#### Archivos
carrera.cpp: Archivo fuente que contiene la implementación del simulador de carrera de autos.
Makefile: Archivo para automatizar la compilación del programa en Linux.
README.md: Este archivo, que contiene las instrucciones de uso

##### Funcionalidad

El programa genera una simulación en la terminal donde se muestra el progreso de cada auto en tiempo real. 

Cada auto:
	Tiene un identificador único (Auto0, Auto1, Auto2, etc.).
	Avanza una cantidad aleatoria de metros por iteración (entre 1 y 10 metros).
	Se detiene por un tiempo aleatorio entre 100 y 500 ms.
	La carrera termina cuando todos los autos han recorrido la distancia total.
	El orden de llegada se muestra al final de la carrera.

###### Autores

Este proyecto fue realizado como parte de una tarea de la asignatura Sistemas Operativos, para la Universidad del Bio-bio. Los autores del proyecto son David Delgado y Bairon Sanhueza.
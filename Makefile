# Nombre del ejecutable
TARGET = carrera

# Compilador
CXX = g++

# Opciones de compilación
CXXFLAGS = -std=c++11 -pthread

# Archivo fuente
SRCS = carrera.cpp

# Regla para compilar el programa
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET)
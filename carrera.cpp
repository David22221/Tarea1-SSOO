#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>
#include <random>

std::mutex mtx; // Mutex para proteger la salida a la consola
std::vector<int> posiciones_finales;
int lugar = 1;

void carrera(int id, int M) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> avance_dist(1, 10); // Avance entre 1 y 10 metros
    std::uniform_int_distribution<> tiempo_dist(100, 500); // Tiempo entre 100 y 500 ms

    int distancia = 0;

    while (distancia < M) {
        int avance = avance_dist(gen);
        distancia += avance;

        if (distancia > M) distancia = M; // No ir mas allá de la meta

        std::this_thread::sleep_for(std::chrono::milliseconds(tiempo_dist(gen))); // Pausa

        // Mostrar avance
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Auto" << id << " avanza " << avance << " metros (total: " << distancia << " metros)" << std::endl;
    }

    // Guardar el lugar en que terminó
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Auto" << id << " termina la carrera en el lugar " << lugar << "!" << std::endl;
    posiciones_finales.push_back(id);
    lugar++;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Uso: " << argv[0] << " <largo_de_pista> <cant_autos>" << std::endl;
        return 1;
    }

    int M = std::stoi(argv[1]); // Distancia total de la carrera
    int N = std::stoi(argv[2]); // Cantidad de autos

    std::vector<std::thread> autos;

    for (int i = 0; i < N; ++i) {
        autos.emplace_back(carrera, i, M);
    }

    for (auto& auto_hilo : autos) {
        auto_hilo.join();
    }

    std::cout << "\nResultados finales:\n";
    for (size_t i = 0; i < posiciones_finales.size(); ++i) {
        std::cout << i + 1 << "º lugar: Auto" << posiciones_finales[i] << std::endl;
    }

    return 0;
}

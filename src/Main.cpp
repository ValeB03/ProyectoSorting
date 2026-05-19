#include <iostream>   // Entrada y salida
#include <vector>     // Uso de vectores
#include <chrono>     // Medir tiempo de ejecucion
#include <memory>
#include <fstream>    // Manejo de archivos
#include <sstream>
#include <algorithm>  // Funciones como min()
#include "algoritmos/AlgoritmoOrdenamiento.h"
#include "algoritmos/BubbleSort.h"
#include "algoritmos/InsertionSort.h"
#include "algoritmos/SelectionSort.h"
#include "algoritmos/MergeSort.h"
#include "algoritmos/QuickSort.h"
#include <cstdlib>    // rand()
#include <ctime>      // time()

// Clase principal de la aplicacion
class SortingApplication {
private:

    // Vector con los datos actuales
    std::vector<int> m_data;

    // Puntero al algoritmo actual
    AlgoritmoOrdenamiento* m_currentSorter;
    
public:

    // Constructor
    SortingApplication() : m_currentSorter(nullptr) {}
    
    // Destructor que libera memoria
    ~SortingApplication() {
        delete m_currentSorter;
    }
    
    // Carga datos desde un archivo
    void loadDataFromFile(const std::string& filename) {

        std::ifstream file(filename);

        // Verifica si el archivo se abrio correctamente
        if (!file.is_open()) {
            std::cout << "Error al abrir el archivo: " << filename << std::endl;
            return;
        }
        
        // Limpia datos anteriores
        m_data.clear();

        int value;

        // Lee numeros del archivo
        while (file >> value) {
            m_data.push_back(value);
        }

        file.close();

        std::cout << "Datos cargados: " 
                  << m_data.size() 
                  << " elementos" << std::endl;
    }
    
    // Genera numeros aleatorios
    void generateRandomData(int size, int maxValue = 1000) {

        m_data.clear();

        srand(static_cast<unsigned int>(time(nullptr)));

        for (int i = 0; i < size; i++) {
            m_data.push_back(rand() % maxValue);
        }

        std::cout << "Generados " 
                  << size 
                  << " numeros aleatorios" << std::endl;
    }
    
    // Genera datos ordenados
    void generateSortedData(int size, bool ascending = true) {

        m_data.clear();

        for (int i = 0; i < size; i++) {
            m_data.push_back(ascending ? i : (size - i));
        }

        std::cout << "Generados " 
                  << size 
                  << " numeros "
                  << (ascending ? "ascendentes" : "descendentes") 
                  << std::endl;
    }
    
    // Selecciona el algoritmo de ordenamiento
    void selectAlgorithm(int choice) {

        // Elimina algoritmo anterior
        delete m_currentSorter;

        m_currentSorter = nullptr;
        
        // Crea el algoritmo seleccionado
        switch (choice) {

            case 1:
                m_currentSorter = new BubbleSort(m_data);
                break;

            case 2:
                m_currentSorter = new InsertionSort(m_data);
                break;

            case 3:
                m_currentSorter = new SelectionSort(m_data);
                break;

            case 4:
                m_currentSorter = new MergeSort(m_data);
                break;

            case 5:
                m_currentSorter = new QuickSort(m_data);
                break;

            default:
                std::cout << "Algoritmo no valido" << std::endl;
                return;
        }
        
        std::cout << "Seleccionado: " 
                  << m_currentSorter->nombre() 
                  << std::endl;
    }
    
    // Ejecuta el algoritmo seleccionado
    void runSorting() {

        // Verifica si existe un algoritmo seleccionado
        if (!m_currentSorter) {
            std::cout << "Primero seleccione un algoritmo" << std::endl;
            return;
        }
        
        // Inicia medicion de tiempo
        auto start = std::chrono::high_resolution_clock::now();
        
        int stepCount = 0;

        // Ejecuta pasos hasta terminar
        while (!m_currentSorter->terminado()) {
            m_currentSorter->paso();
            stepCount++;
        }
        
        // Finaliza medicion de tiempo
        auto end = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        
        // Muestra resultados
        std::cout << "\n=== Resultados ===" << std::endl;
        std::cout << "Algoritmo: " << m_currentSorter->nombre() << std::endl;
        std::cout << "Comparaciones: " << m_currentSorter->comparaciones() << std::endl;
        std::cout << "Intercambios: " << m_currentSorter->intercambios() << std::endl;
        std::cout << "Tiempo de ejecucion: " << duration.count() << " microsegundos" << std::endl;
        std::cout << "Pasos ejecutados: " << stepCount << std::endl;
    }
    
    // Muestra los datos actuales
    void printData() const {

        std::cout << "Datos actuales: ";

        // Muestra maximo 20 elementos
        for (size_t i = 0; i < std::min(m_data.size(), static_cast<size_t>(20)); i++) {
            std::cout << m_data[i] << " ";
        }

        // Indica si hay mas elementos
        if (m_data.size() > 20) {
            std::cout << "... (" 
                      << m_data.size() 
                      << " elementos totales)";
        }

        std::cout << std::endl;
    }
    
    // Muestra el menu principal
    void showMenu() {

        std::cout << "\n=== Aplicacion de Ordenamiento ===" << std::endl;
        std::cout << "1. Cargar datos desde archivo" << std::endl;
        std::cout << "2. Generar datos aleatorios" << std::endl;
        std::cout << "3. Generar datos ordenados (ascendente)" << std::endl;
        std::cout << "4. Generar datos ordenados (descendente)" << std::endl;
        std::cout << "5. Seleccionar algoritmo de ordenamiento" << std::endl;
        std::cout << "6. Ejecutar ordenamiento" << std::endl;
        std::cout << "7. Mostrar datos" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "Opcion: ";
    }
    
    // Muestra menu de algoritmos
    void showAlgorithmMenu() {

        std::cout << "\n=== Algoritmos de Ordenamiento ===" << std::endl;
        std::cout << "1. Bubble Sort" << std::endl;
        std::cout << "2. Insertion Sort" << std::endl;
        std::cout << "3. Selection Sort" << std::endl;
        std::cout << "4. Merge Sort" << std::endl;
        std::cout << "5. Quick Sort" << std::endl;
        std::cout << "Opcion: ";
    }
};

int main() {

    // Crea la aplicacion
    SortingApplication app;

    int option;
    
    // Ciclo principal del menu
    do {

        app.showMenu();

        std::cin >> option;
        
        // Ejecuta opcion seleccionada
        switch (option) {

            case 1: {

                std::string filename;

                std::cout << "Nombre del archivo: ";

                std::cin >> filename;

                app.loadDataFromFile(filename);

                break;
            }

            case 2: {

                int size;

                std::cout << "Cantidad de elementos: ";

                std::cin >> size;

                app.generateRandomData(size);

                break;
            }

            case 3: {

                int size;

                std::cout << "Cantidad de elementos: ";

                std::cin >> size;

                app.generateSortedData(size, true);

                break;
            }

            case 4: {

                int size;

                std::cout << "Cantidad de elementos: ";

                std::cin >> size;

                app.generateSortedData(size, false);

                break;
            }

            case 5: {

                app.showAlgorithmMenu();

                int algoOption;

                std::cin >> algoOption;

                app.selectAlgorithm(algoOption);

                break;
            }

            case 6:
                app.runSorting();
                break;

            case 7:
                app.printData();
                break;

            case 0:
                std::cout << "Saliendo..." << std::endl;
                break;

            default:
                std::cout << "Opcion no valida" << std::endl;
        }

    } while (option != 0);
    
    return 0;
}
#include <iostream>
#include <vector>
#include <chrono>
#include <memory>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "AlgoritmoOrdenamiento.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include <cstdlib>
#include <ctime>

class SortingApplication {
private:
    std::vector<int> m_data;
    AlgoritmoOrdenamiento* m_currentSorter;
    
public:
    SortingApplication() : m_currentSorter(nullptr) {}
    
    ~SortingApplication() {
        delete m_currentSorter;
    }
    
    void loadDataFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cout << "Error al abrir el archivo: " << filename << std::endl;
            return;
        }
        
        m_data.clear();
        int value;
        while (file >> value) {
            m_data.push_back(value);
        }
        file.close();
        std::cout << "Datos cargados: " << m_data.size() << " elementos" << std::endl;
    }
    
    void generateRandomData(int size, int maxValue = 1000) {
        m_data.clear();
        srand(static_cast<unsigned int>(time(nullptr)));
        for (int i = 0; i < size; i++) {
            m_data.push_back(rand() % maxValue);
        }
        std::cout << "Generados " << size << " numeros aleatorios" << std::endl;
    }
    
    void generateSortedData(int size, bool ascending = true) {
        m_data.clear();
        for (int i = 0; i < size; i++) {
            m_data.push_back(ascending ? i : (size - i));
        }
        std::cout << "Generados " << size << " numeros " 
                  << (ascending ? "ascendentes" : "descendentes") << std::endl;
    }
    
    void selectAlgorithm(int choice) {
        // Delete previous sorter
        delete m_currentSorter;
        m_currentSorter = nullptr;
        
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
        
        std::cout << "Seleccionado: " << m_currentSorter->nombre() << std::endl;
    }
    
    void runSorting() {
        if (!m_currentSorter) {
            std::cout << "Primero seleccione un algoritmo" << std::endl;
            return;
        }
        
        auto start = std::chrono::high_resolution_clock::now();
        
        int stepCount = 0;
        while (!m_currentSorter->terminado()) {
            m_currentSorter->paso();
            stepCount++;
        }
        
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        
        std::cout << "\n=== Resultados ===" << std::endl;
        std::cout << "Algoritmo: " << m_currentSorter->nombre() << std::endl;
        std::cout << "Comparaciones: " << m_currentSorter->comparaciones() << std::endl;
        std::cout << "Intercambios: " << m_currentSorter->intercambios() << std::endl;
        std::cout << "Tiempo de ejecucion: " << duration.count() << " microsegundos" << std::endl;
        std::cout << "Pasos ejecutados: " << stepCount << std::endl;
    }
    
    void printData() const {
        std::cout << "Datos actuales: ";
        for (size_t i = 0; i < std::min(m_data.size(), static_cast<size_t>(20)); i++) {
            std::cout << m_data[i] << " ";
        }
        if (m_data.size() > 20) {
            std::cout << "... (" << m_data.size() << " elementos totales)";
        }
        std::cout << std::endl;
    }
    
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
    SortingApplication app;
    int option;
    
    do {
        app.showMenu();
        std::cin >> option;
        
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

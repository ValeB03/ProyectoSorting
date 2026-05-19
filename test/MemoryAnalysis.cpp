#include <iostream>
#include <vector>
#include <chrono>
#include <memory>
#include "AlgoritmoOrdenamiento.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include <cstdlib>
#include <ctime>

int main() {
    // tipos básicos
    std::cout << "=== Tipos que usa el algoritmo ===\n";
    std::cout << "int :  " << sizeof(int) << " bytes\n";
    std::cout << "bool :  " << sizeof(bool) << " bytes\n";
    std::cout << "vector<int> :  " << sizeof(std::vector<int>) << " bytes\n";
    std::cout << "puntero :  " << sizeof(void*) << " bytes\n";

    // tamaño de objetos
    std::cout << "\n=== Objeto BubbleSort ===\n";
    std::cout << "sizeof(BubbleSort) :  "
              << sizeof(BubbleSort) << " bytes\n";
    std::cout << "sizeof(AlgoritmoOrdenamiento) :  "
              << sizeof(AlgoritmoOrdenamiento) << " bytes\n";
    // TODO: suma manual de atributos vs sizeof (padding / vtable)

    // stack vs heap
    std::cout << "\n=== Stack vs Heap ===\n";
    std::vector<int> datos = {5, 3, 8, 1, 9, 2, 7, 4, 6};

    BubbleSort a1(datos); // stack
    AlgoritmoOrdenamiento* a2 = new BubbleSort(datos); // heap

    std::cout << "Direccion a1 (stack):  " << &a1 << "\n";
    std::cout << "Direccion a2 (heap) :  " << a2 << "\n";

    // memoria del arreglo interno
    std::cout << "\n=== Memoria del arreglo interno ===\n";
    std::cout << "Elementos :  " << a1.tamano() << "\n";
    std::cout << "sizeof(vector<int>) (estructura):  "
              << sizeof(std::vector<int>) << " bytes\n";
    std::cout << "Datos reales en heap:  "
              << a1.tamano() * sizeof(int) << " bytes\n";

    delete a2;

    // pruebas de algoritmos
    std::cout << "\n=== Pruebas de Algoritmos ===\n";

    std::vector<int> sizes = {10, 50, 100};

    for (int size : sizes) {
        std::cout << "\n--- Prueba con " << size << " elementos ---\n";

        // datos aleatorios
        std::vector<int> randomData;
        srand(static_cast<unsigned int>(time(nullptr)));

        for (int i = 0; i < size; i++) {
            randomData.push_back(rand() % 1000);
        }

        // algoritmos
        std::vector<std::string> algorithmNames = {
            "Bubble Sort", "Insertion Sort", "Selection Sort",
            "Merge Sort", "Quick Sort"
        };

        for (const std::string& name : algorithmNames) {
            AlgoritmoOrdenamiento* sorter = nullptr;

            if (name == "Bubble Sort") {
                sorter = new BubbleSort(randomData);
            } else if (name == "Insertion Sort") {
                sorter = new InsertionSort(randomData);
            } else if (name == "Selection Sort") {
                sorter = new SelectionSort(randomData);
            } else if (name == "Merge Sort") {
                sorter = new MergeSort(randomData);
            } else if (name == "Quick Sort") {
                sorter = new QuickSort(randomData);
            }

            auto start = std::chrono::high_resolution_clock::now();

            while (!sorter->terminado()) {
                sorter->paso();
            }

            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

            std::cout << name
                      << " - Comparaciones: " << sorter->comparaciones()
                      << ", Intercambios: " << sorter->intercambios()
                      << ", Tiempo: " << duration.count() << " microsegundos\n";

            delete sorter;
        }
    }

    return 0;
}